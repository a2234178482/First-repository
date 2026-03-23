import tkinter as tk
from tkinter import filedialog, messagebox, ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import os

class ItemSet:
    """表示一个项集，包含三个物品（重量，价值）"""
    def __init__(self, items):
        # items: list of (weight, value)
        self.items = items  # 三个物品，索引0,1,2
        self.ratio = items[2][1] / items[2][0] if items[2][0] != 0 else 0  # 第三项的价值/重量比

class DKP:
    def __init__(self):
        self.item_sets = []     # 项集列表
        self.capacity = 0       # 背包容量
        self.best_value = 0     # 最优解价值
        self.best_selection = [] # 最优选择：每个项集选择的物品索引（-1表示不选）
        self.solve_time = 0.0

    def load_from_file(self, filename):
        """读取数据文件，格式要求：
        第一行：背包容量
        之后每三行对应一个项集，每行两个整数：重量 价值
        每个项集恰好三个物品，其中第三个物品价值等于前两个之和，重量小于前两个之和
        """
        self.item_sets.clear()
        try:
            with open(filename, 'r') as f:
                lines = [line.strip() for line in f if line.strip()]
            if not lines:
                raise ValueError("文件为空")
            self.capacity = int(lines[0])
            i = 1
            while i + 2 < len(lines):
                # 读取三个物品
                w1, v1 = map(int, lines[i].split())
                w2, v2 = map(int, lines[i+1].split())
                w3, v3 = map(int, lines[i+2].split())
                # 验证数据完整性（可选）
                if v3 != v1 + v2:
                    # 仅警告，不强制，因为题目说第三项价值是前两项之和
                    pass
                item_set = ItemSet([(w1, v1), (w2, v2), (w3, v3)])
                self.item_sets.append(item_set)
                i += 3
        except Exception as e:
            raise RuntimeError(f"读取文件失败: {e}")

    def solve_dp(self):
        """动态规划求解 D{0-1}KP"""
        start_time = time.time()
        n = len(self.item_sets)
        cap = self.capacity
        # dp[j] 表示容量 j 时的最大价值，choice[j] 记录最后一个物品的选择以便回溯
        dp = [0] * (cap + 1)
        # 选择记录：每个容量下，最后一个项集选择的物品索引（-1表示不选）和上一个容量
        # 由于需要回溯具体每个项集的选择，我们记录选择路径
        # 简化：记录每个状态是由哪个物品转移来的，但为了回溯所有项集，用二维数组
        # 这里为了清晰，使用二维数组 path[i][j] 记录第 i 个项集在容量 j 时的选择
        path = [[-1] * (cap + 1) for _ in range(n)]

        for i in range(n):
            items = self.item_sets[i].items
            # 从后往前更新一维dp
            for j in range(cap, -1, -1):
                best_val = dp[j]
                best_choice = -1
                # 尝试三种选择
                for k in range(3):
                    w, v = items[k]
                    if j >= w and dp[j - w] + v > best_val:
                        best_val = dp[j - w] + v
                        best_choice = k
                if best_val > dp[j]:
                    dp[j] = best_val
                    path[i][j] = best_choice
                # 注意：如果best_choice为-1，表示不选，path保留为-1

        self.best_value = dp[cap]
        # 回溯选择
        self.best_selection = [-1] * n
        remaining_cap = cap
        for i in range(n-1, -1, -1):
            choice = path[i][remaining_cap]
            self.best_selection[i] = choice
            if choice != -1:
                w = self.item_sets[i].items[choice][0]
                remaining_cap -= w
        self.solve_time = time.time() - start_time

    def sort_by_ratio(self):
        """按第三项的价值重量比非递增排序"""
        self.item_sets.sort(key=lambda x: x.ratio, reverse=True)

    def get_solution_details(self):
        """生成求解结果的文本描述"""
        lines = []
        lines.append(f"背包容量: {self.capacity}")
        lines.append(f"最大总价值: {self.best_value}")
        lines.append(f"求解耗时: {self.solve_time:.6f} 秒")
        lines.append("所选物品:")
        total_weight = 0
        for i, item_set in enumerate(self.item_sets):
            choice = self.best_selection[i]
            if choice != -1:
                w, v = item_set.items[choice]
                total_weight += w
                lines.append(f"  项集 {i+1}: 选择物品 {choice+1} (重量={w}, 价值={v})")
        lines.append(f"总重量: {total_weight}")
        return "\n".join(lines)

    def save_result(self, filename):
        """保存结果到文本文件或Excel"""
        ext = os.path.splitext(filename)[1].lower()
        details = self.get_solution_details()
        if ext == '.txt':
            with open(filename, 'w', encoding='utf-8') as f:
                f.write(details)
        elif ext == '.xlsx':
            try:
                import openpyxl
                wb = openpyxl.Workbook()
                ws = wb.active
                ws.title = "DKP Result"
                for row_idx, line in enumerate(details.split('\n'), 1):
                    ws.cell(row=row_idx, column=1, value=line)
                wb.save(filename)
            except ImportError:
                messagebox.showerror("错误", "未安装openpyxl，无法保存为Excel文件。")
                return
        else:
            messagebox.showerror("错误", "仅支持 .txt 或 .xlsx 格式。")

    def get_scatter_data(self):
        """获取所有物品的重量和价值列表（用于散点图）"""
        weights = []
        values = []
        for i, item_set in enumerate(self.item_sets):
            for k, (w, v) in enumerate(item_set.items):
                weights.append(w)
                values.append(v)
        return weights, values

class Application:
    def __init__(self, root):
        self.root = root
        self.root.title("D{0-1}KP 问题求解器")
        self.dkp = DKP()
        self.current_data_file = None

        # 创建菜单栏
        menubar = tk.Menu(root)
        filemenu = tk.Menu(menubar, tearoff=0)
        filemenu.add_command(label="打开数据文件", command=self.load_file)
        filemenu.add_command(label="保存结果", command=self.save_result)
        filemenu.add_separator()
        filemenu.add_command(label="退出", command=root.quit)
        menubar.add_cascade(label="文件", menu=filemenu)

        optmenu = tk.Menu(menubar, tearoff=0)
        optmenu.add_command(label="按比值排序", command=self.sort_and_refresh)
        optmenu.add_command(label="求解最优解", command=self.solve)
        menubar.add_cascade(label="操作", menu=optmenu)

        root.config(menu=menubar)

        # 主框架
        main_frame = ttk.Frame(root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # 信息显示区域
        info_frame = ttk.LabelFrame(main_frame, text="信息", padding="5")
        info_frame.grid(row=0, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)
        self.info_text = tk.Text(info_frame, height=12, width=80)
        self.info_text.pack()

        # 按钮区
        btn_frame = ttk.Frame(main_frame)
        btn_frame.grid(row=1, column=0, columnspan=2, pady=5)
        ttk.Button(btn_frame, text="加载数据", command=self.load_file).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="按比值排序", command=self.sort_and_refresh).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="求解最优解", command=self.solve).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="绘制散点图", command=self.plot_scatter).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="保存结果", command=self.save_result).pack(side=tk.LEFT, padx=5)

        # 状态栏
        self.status = ttk.Label(root, text="就绪", relief=tk.SUNKEN, anchor=tk.W)
        self.status.grid(row=1, column=0, sticky=(tk.W, tk.E))

        root.columnconfigure(0, weight=1)
        root.rowconfigure(0, weight=1)

    def load_file(self):
        filename = filedialog.askopenfilename(title="选择数据文件", filetypes=[("文本文件", "*.txt"), ("所有文件", "*.*")])
        if not filename:
            return
        try:
            self.dkp.load_from_file(filename)
            self.current_data_file = filename
            self.status.config(text=f"已加载: {filename}, 项集数: {len(self.dkp.item_sets)}, 容量: {self.dkp.capacity}")
            self.info_text.delete(1.0, tk.END)
            self.info_text.insert(tk.END, f"文件加载成功\n项集数量: {len(self.dkp.item_sets)}\n背包容量: {self.dkp.capacity}\n")
        except Exception as e:
            messagebox.showerror("错误", str(e))
            self.status.config(text="加载失败")

    def sort_and_refresh(self):
        if not self.dkp.item_sets:
            messagebox.showwarning("警告", "请先加载数据文件")
            return
        self.dkp.sort_by_ratio()
        self.status.config(text="已按第三项价值/重量比非递增排序")
        self.info_text.insert(tk.END, "已执行排序操作\n")

    def solve(self):
        if not self.dkp.item_sets:
            messagebox.showwarning("警告", "请先加载数据文件")
            return
        self.status.config(text="求解中...")
        self.root.update()
        self.dkp.solve_dp()
        self.status.config(text="求解完成")
        details = self.dkp.get_solution_details()
        self.info_text.insert(tk.END, "\n--- 求解结果 ---\n")
        self.info_text.insert(tk.END, details)
        self.info_text.insert(tk.END, "\n----------------\n")

    def plot_scatter(self):
        if not self.dkp.item_sets:
            messagebox.showwarning("警告", "请先加载数据文件")
            return
        weights, values = self.dkp.get_scatter_data()
        # 创建新窗口显示图形
        fig, ax = plt.subplots(figsize=(6, 5))
        ax.scatter(weights, values, c='blue', alpha=0.6)
        ax.set_xlabel("重量")
        ax.set_ylabel("价值")
        ax.set_title("D{0-1}KP 物品散点图")
        ax.grid(True)
        plt.show()

    def save_result(self):
        if not self.dkp.item_sets or self.dkp.best_value == 0:
            messagebox.showwarning("警告", "请先加载数据并求解")
            return
        filename = filedialog.asksaveasfilename(defaultextension=".txt", filetypes=[("文本文件", "*.txt"), ("Excel文件", "*.xlsx")])
        if not filename:
            return
        try:
            self.dkp.save_result(filename)
            self.status.config(text=f"结果已保存至 {filename}")
        except Exception as e:
            messagebox.showerror("错误", f"保存失败: {e}")

def main():
    root = tk.Tk()
    app = Application(root)
    root.mainloop()

if __name__ == "__main__":
    main()