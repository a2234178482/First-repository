import tkinter as tk
from tkinter import filedialog, messagebox, ttk, scrolledtext
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import os
import numpy as np

class ItemSet:
    """表示一个项集，包含三个物品及其第三项的价值/重量比"""
    def __init__(self, items):
        self.items = items  # [(weight, value), ...]
        self.ratio = items[2][1] / items[2][0] if items[2][0] != 0 else 0

class DKP:
    """核心业务逻辑类：数据加载、求解、排序、结果管理"""
    def __init__(self):
        self.item_sets = []
        self.capacity = 0
        self.best_value = 0
        self.best_selection = []
        self.solve_time = 0.0
        self.is_sorted = False  # 标记是否已排序

    def load_from_file(self, filename):
        """从文件读取数据，格式要求见原说明"""
        self.item_sets.clear()
        try:
            with open(filename, 'r') as f:
                lines = [line.strip() for line in f if line.strip()]
            if len(lines) < 1:
                raise ValueError("文件为空")
            self.capacity = int(lines[0])
            i = 1
            while i + 2 < len(lines):
                w1, v1 = map(int, lines[i].split())
                w2, v2 = map(int, lines[i+1].split())
                w3, v3 = map(int, lines[i+2].split())
                item_set = ItemSet([(w1, v1), (w2, v2), (w3, v3)])
                self.item_sets.append(item_set)
                i += 3
            self.is_sorted = False
        except Exception as e:
            raise RuntimeError(f"读取文件失败: {e}")

    def solve_dp(self):
        """动态规划求解，返回 (最优值, 选择列表, 耗时)"""
        start_time = time.time()
        n = len(self.item_sets)
        cap = self.capacity
        dp = [0] * (cap + 1)
        path = [[-1] * (cap + 1) for _ in range(n)]

        for i in range(n):
            items = self.item_sets[i].items
            for j in range(cap, -1, -1):
                best_val = dp[j]
                best_choice = -1
                for k in range(3):
                    w, v = items[k]
                    if j >= w and dp[j - w] + v > best_val:
                        best_val = dp[j - w] + v
                        best_choice = k
                if best_val > dp[j]:
                    dp[j] = best_val
                    path[i][j] = best_choice

        self.best_value = dp[cap]
        self.best_selection = [-1] * n
        remaining_cap = cap
        for i in range(n - 1, -1, -1):
            choice = path[i][remaining_cap]
            self.best_selection[i] = choice
            if choice != -1:
                w = self.item_sets[i].items[choice][0]
                remaining_cap -= w
        self.solve_time = time.time() - start_time
        return self.best_value, self.best_selection, self.solve_time

    def sort_by_ratio(self):
        """按第三项价值/重量比非递增排序"""
        self.item_sets.sort(key=lambda x: x.ratio, reverse=True)
        self.is_sorted = True

    def get_solution_details(self):
        """生成结果文本描述"""
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
        """保存结果到文本或Excel"""
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
                raise RuntimeError("未安装openpyxl库")
        else:
            raise ValueError("仅支持 .txt 或 .xlsx 格式")

    def get_scatter_data(self):
        """获取所有物品的重量和价值列表"""
        weights, values = [], []
        for item_set in self.item_sets:
            for w, v in item_set.items:
                weights.append(w)
                values.append(v)
        return weights, values

    def get_selected_items_positions(self):
        """获取最优解中选中物品的索引（用于高亮）"""
        selected = []
        for i, choice in enumerate(self.best_selection):
            if choice != -1:
                # 计算该物品在全局列表中的位置（仅用于绘图标记）
                offset = i * 3 + choice
                selected.append(offset)
        return selected

class BatchProcessor:
    """扩展功能：批量处理多个文件"""
    def __init__(self):
        self.results = []  # 存储每个文件的求解结果

    def process_files(self, file_list, capacity_override=None):
        """批量处理文件列表，返回对比结果"""
        self.results.clear()
        for filepath in file_list:
            dkp = DKP()
            try:
                dkp.load_from_file(filepath)
                if capacity_override is not None:
                    dkp.capacity = capacity_override
                dkp.solve_dp()
                self.results.append({
                    'file': os.path.basename(filepath),
                    'capacity': dkp.capacity,
                    'best_value': dkp.best_value,
                    'time': dkp.solve_time,
                    'details': dkp.get_solution_details()
                })
            except Exception as e:
                self.results.append({
                    'file': os.path.basename(filepath),
                    'error': str(e)
                })
        return self.results

class Application:
    def __init__(self, root):
        self.root = root
        self.root.title("D{0-1}KP 问题求解器 - 扩展版")
        self.dkp = DKP()
        self.current_data_file = None

        # 创建菜单栏
        menubar = tk.Menu(root)
        filemenu = tk.Menu(menubar, tearoff=0)
        filemenu.add_command(label="打开数据文件", command=self.load_file)
        filemenu.add_command(label="批量处理", command=self.batch_process)
        filemenu.add_separator()
        filemenu.add_command(label="保存结果", command=self.save_result)
        filemenu.add_separator()
        filemenu.add_command(label="退出", command=root.quit)
        menubar.add_cascade(label="文件", menu=filemenu)

        optmenu = tk.Menu(menubar, tearoff=0)
        optmenu.add_command(label="按比值排序", command=self.sort_and_refresh)
        optmenu.add_command(label="求解最优解", command=self.solve)
        optmenu.add_command(label="排序前后对比", command=self.compare_sort_effect)
        menubar.add_cascade(label="操作", menu=optmenu)

        helpmenu = tk.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="关于", command=self.show_about)
        menubar.add_cascade(label="帮助", menu=helpmenu)

        root.config(menu=menubar)

        # 主框架
        main_frame = ttk.Frame(root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # 信息显示区域
        info_frame = ttk.LabelFrame(main_frame, text="信息", padding="5")
        info_frame.grid(row=0, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)
        self.info_text = scrolledtext.ScrolledText(info_frame, height=12, width=80)
        self.info_text.pack(fill=tk.BOTH, expand=True)

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
        """绘制散点图，并高亮最优解选中的物品"""
        if not self.dkp.item_sets:
            messagebox.showwarning("警告", "请先加载数据文件")
            return
        # 先求解（如果还没有求解）
        if self.dkp.best_value == 0 and self.dkp.item_sets:
            self.dkp.solve_dp()
        weights, values = self.dkp.get_scatter_data()
        fig, ax = plt.subplots(figsize=(7, 5))
        # 绘制所有物品
        ax.scatter(weights, values, c='blue', alpha=0.6, label='所有物品')
        # 高亮选中的物品
        selected_indices = self.dkp.get_selected_items_positions()
        if selected_indices:
            selected_weights = [weights[i] for i in selected_indices]
            selected_values = [values[i] for i in selected_indices]
            ax.scatter(selected_weights, selected_values, c='red', s=80, marker='o', label='最优解所选物品')
        ax.set_xlabel("重量")
        ax.set_ylabel("价值")
        ax.set_title("D{0-1}KP 物品散点图（红色为选中物品）")
        ax.legend()
        ax.grid(True)
        plt.show()

    def compare_sort_effect(self):
        """扩展功能：对比排序前后求解时间"""
        if not self.dkp.item_sets:
            messagebox.showwarning("警告", "请先加载数据文件")
            return
        # 保存原始顺序
        original_sets = self.dkp.item_sets.copy()
        # 求解原始顺序
        self.dkp.item_sets = original_sets
        _, _, time_original = self.dkp.solve_dp()
        # 排序后求解
        self.dkp.sort_by_ratio()
        _, _, time_sorted = self.dkp.solve_dp()
        # 恢复原始顺序（可选）
        self.dkp.item_sets = original_sets
        self.dkp.is_sorted = False

        result_text = f"排序前求解时间: {time_original:.6f} 秒\n排序后求解时间: {time_sorted:.6f} 秒\n"
        if time_sorted < time_original:
            result_text += "排序后求解更快，效率提升 {:.2f}%".format((time_original - time_sorted) / time_original * 100)
        else:
            result_text += "排序后求解未显著提升速度"
        self.info_text.insert(tk.END, "\n--- 排序前后对比 ---\n")
        self.info_text.insert(tk.END, result_text)
        self.info_text.insert(tk.END, "\n----------------\n")

    def batch_process(self):
        """批量处理多个文件"""
        files = filedialog.askopenfilenames(title="选择多个数据文件", filetypes=[("文本文件", "*.txt")])
        if not files:
            return
        processor = BatchProcessor()
        # 可选：询问是否统一背包容量
        capacity_override = None
        if messagebox.askyesno("批量处理", "是否统一设置背包容量（覆盖文件中的容量）？"):
            try:
                cap = tk.simpledialog.askinteger("输入容量", "请输入统一的背包容量：", initialvalue=100)
                if cap:
                    capacity_override = cap
            except:
                pass
        self.status.config(text=f"正在批量处理 {len(files)} 个文件...")
        self.root.update()
        results = processor.process_files(files, capacity_override)
        self.status.config(text="批量处理完成")
        # 显示结果汇总
        self.info_text.insert(tk.END, "\n--- 批量处理结果 ---\n")
        for res in results:
            if 'error' in res:
                self.info_text.insert(tk.END, f"{res['file']}: 错误 - {res['error']}\n")
            else:
                self.info_text.insert(tk.END, f"{res['file']}: 容量={res['capacity']}, 最优值={res['best_value']}, 耗时={res['time']:.6f}s\n")
        self.info_text.insert(tk.END, "--------------------\n")

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

    def show_about(self):
        messagebox.showinfo("关于", "D{0-1}KP 问题求解器 v2.0\n\n扩展功能：\n- 排序前后时间对比\n- 散点图高亮选中物品\n- 批量文件处理\n- 支持Excel导出\n\n开发语言：Python\n课程作业：软件工程个人项目")

def main():
    root = tk.Tk()
    app = Application(root)
    root.mainloop()

if __name__ == "__main__":
    main()