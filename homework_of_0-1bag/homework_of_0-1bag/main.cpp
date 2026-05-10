#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <windows.h>

// 项集结构
struct ItemSet {
    int id;               // 项集ID
    int value1;           // 第一项价值
    int weight1;          // 第一项重量
    int value2;           // 第二项价值
    int weight2;          // 第二项重量
    int value3;           // 第三项价值
    int weight3;          // 第三项重量
    double ratio3;        // 第三项价值重量比
};

// 动态规划求解D{0-1}背包问题
class KnapsackSolver {
private:
    std::vector<ItemSet> itemsets;
    int capacity;

public:
    KnapsackSolver(const std::vector<ItemSet>& items, int cap) : itemsets(items), capacity(cap) {}

    // 求解最优解
    std::pair<int, std::vector<int>> solve() {
        int n = itemsets.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

        // 填充DP表
        for (int i = 1; i <= n; ++i) {
            for (int w = 0; w <= capacity; ++w) {
                // 不选当前项集
                dp[i][w] = dp[i - 1][w];

                // 选当前项集的第一项
                if (w >= itemsets[i - 1].weight1) {
                    dp[i][w] = std::max(dp[i][w], dp[i - 1][w - itemsets[i - 1].weight1] + itemsets[i - 1].value1);
                }

                // 选当前项集的第二项
                if (w >= itemsets[i - 1].weight2) {
                    dp[i][w] = std::max(dp[i][w], dp[i - 1][w - itemsets[i - 1].weight2] + itemsets[i - 1].value2);
                }

                // 选当前项集的第三项
                if (w >= itemsets[i - 1].weight3) {
                    dp[i][w] = std::max(dp[i][w], dp[i - 1][w - itemsets[i - 1].weight3] + itemsets[i - 1].value3);
                }
            }
        }

        // 回溯找出选择的项
        std::vector<int> selection(n, 0); // 0: 不选, 1: 选第一项, 2: 选第二项, 3: 选第三项
        int w = capacity;
        for (int i = n; i > 0; --i) {
            if (dp[i][w] != dp[i - 1][w]) {
                // 确定选的是哪一项
                if (w >= itemsets[i - 1].weight3 && dp[i][w] == dp[i - 1][w - itemsets[i - 1].weight3] + itemsets[i - 1].value3) {
                    selection[i - 1] = 3;
                    w -= itemsets[i - 1].weight3;
                } else if (w >= itemsets[i - 1].weight2 && dp[i][w] == dp[i - 1][w - itemsets[i - 1].weight2] + itemsets[i - 1].value2) {
                    selection[i - 1] = 2;
                    w -= itemsets[i - 1].weight2;
                } else if (w >= itemsets[i - 1].weight1 && dp[i][w] == dp[i - 1][w - itemsets[i - 1].weight1] + itemsets[i - 1].value1) {
                    selection[i - 1] = 1;
                    w -= itemsets[i - 1].weight1;
                }
            }
        }

        return {dp[n][capacity], selection};
    }
};

// 数据处理类
class DataHandler {
public:
    // 读取D{0-1}KP数据
    static std::pair<std::vector<ItemSet>, int> readData(const std::string& filename) {
        std::vector<ItemSet> itemsets;
        int capacity = 0;

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "无法打开文件: " << filename << std::endl;
            return {itemsets, capacity};
        }

        std::string line;
        int lineCount = 0;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (lineCount == 0) {
                // 第一行是容量和项集数
                int n;
                iss >> capacity >> n;
            } else {
                // 后续行是项集数据
                ItemSet itemset;
                itemset.id = lineCount - 1;
                iss >> itemset.value1 >> itemset.weight1 >> itemset.value2 >> itemset.weight2 >> itemset.value3 >> itemset.weight3;
                itemset.ratio3 = static_cast<double>(itemset.value3) / itemset.weight3;
                itemsets.push_back(itemset);
            }
            lineCount++;
        }

        file.close();
        return {itemsets, capacity};
    }

    // 按第三项价值重量比排序
    static void sortByRatio(std::vector<ItemSet>& itemsets) {
        std::sort(itemsets.begin(), itemsets.end(), [](const ItemSet& a, const ItemSet& b) {
            return a.ratio3 > b.ratio3;
        });
    }

    // 保存结果到文件
    static void saveResult(const std::string& filename, const std::vector<ItemSet>& itemsets, int capacity, int maxValue, const std::vector<int>& selection, double timeTaken) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "无法创建文件: " << filename << std::endl;
            return;
        }

        file << "D{0-1}KP 问题求解结果" << std::endl;
        file << "背包容量: " << capacity << std::endl;
        file << "项集数量: " << itemsets.size() << std::endl;
        file << "最大价值: " << maxValue << std::endl;
        file << "求解时间: " << std::fixed << std::setprecision(6) << timeTaken << " 秒" << std::endl;
        file << "\n选择结果:" << std::endl;
        file << "项集ID\t选择项\t价值\t重量" << std::endl;

        int totalWeight = 0;
        for (int i = 0; i < itemsets.size(); ++i) {
            if (selection[i] > 0) {
                int value = 0, weight = 0;
                std::string itemStr = "";
                if (selection[i] == 1) {
                    value = itemsets[i].value1;
                    weight = itemsets[i].weight1;
                    itemStr = "第一项";
                } else if (selection[i] == 2) {
                    value = itemsets[i].value2;
                    weight = itemsets[i].weight2;
                    itemStr = "第二项";
                } else if (selection[i] == 3) {
                    value = itemsets[i].value3;
                    weight = itemsets[i].weight3;
                    itemStr = "第三项";
                }
                file << itemsets[i].id << "\t" << itemStr << "\t" << value << "\t" << weight << std::endl;
                totalWeight += weight;
            }
        }

        file << "\n总重量: " << totalWeight << std::endl;
        file.close();
    }
};

// 简单的用户界面
void displayMenu() {
    std::cout << "============================================" << std::endl;
    std::cout << "D{0-1}背包问题求解程序" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "1. 读取D{0-1}KP数据文件" << std::endl;
    std::cout << "2. 显示数据散点图" << std::endl;
    std::cout << "3. 按第三项价值重量比排序" << std::endl;
    std::cout << "4. 求解最优解" << std::endl;
    std::cout << "5. 保存结果" << std::endl;
    std::cout << "6. 退出" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "请选择操作: ";
}

// 模拟散点图显示
void displayScatterPlot(const std::vector<ItemSet>& itemsets) {
    std::cout << "\n数据散点图 (重量 vs 价值):" << std::endl;
    std::cout << "项集ID\t第一项(重量,价值)\t第二项(重量,价值)\t第三项(重量,价值)" << std::endl;
    for (const auto& itemset : itemsets) {
        std::cout << itemset.id << "\t(" << itemset.weight1 << "," << itemset.value1 << ")\t\t(" << itemset.weight2 << "," << itemset.value2 << ")\t\t(" << itemset.weight3 << "," << itemset.value3 << ")" << std::endl;
    }
}

int main() {
    std::vector<ItemSet> itemsets;
    int capacity = 0;
    int maxValue = 0;
    std::vector<int> selection;
    double timeTaken = 0;

    int choice;
    std::string filename;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入数据文件路径: ";
            std::cin >> filename;
            auto result = DataHandler::readData(filename);
            itemsets = result.first;
            capacity = result.second;
            if (!itemsets.empty()) {
                std::cout << "成功读取 " << itemsets.size() << " 个项集，背包容量: " << capacity << std::endl;
            }
            break;
        }
        case 2:
            if (itemsets.empty()) {
                std::cout << "请先读取数据文件" << std::endl;
            } else {
                displayScatterPlot(itemsets);
            }
            break;
        case 3:
            if (itemsets.empty()) {
                std::cout << "请先读取数据文件" << std::endl;
            } else {
                DataHandler::sortByRatio(itemsets);
                std::cout << "已按第三项价值重量比排序" << std::endl;
            }
            break;
        case 4:
            if (itemsets.empty()) {
                std::cout << "请先读取数据文件" << std::endl;
            } else {
                KnapsackSolver solver(itemsets, capacity);
                auto start = std::chrono::high_resolution_clock::now();
                auto result = solver.solve();
                auto end = std::chrono::high_resolution_clock::now();
                maxValue = result.first;
                selection = result.second;
                timeTaken = std::chrono::duration<double>(end - start).count();
                std::cout << "最优解价值: " << maxValue << std::endl;
                std::cout << "求解时间: " << std::fixed << std::setprecision(6) << timeTaken << " 秒" << std::endl;
            }
            break;
        case 5:
            if (itemsets.empty()) {
                std::cout << "请先读取数据文件" << std::endl;
            } else if (maxValue == 0) {
                std::cout << "请先求解最优解" << std::endl;
            } else {
                std::cout << "请输入保存文件路径: ";
                std::cin >> filename;
                DataHandler::saveResult(filename, itemsets, capacity, maxValue, selection, timeTaken);
                std::cout << "结果已保存到 " << filename << std::endl;
            }
            break;
        case 6:
            std::cout << "退出程序..." << std::endl;
            break;
        default:
            std::cout << "无效选择，请重新输入" << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}
