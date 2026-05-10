#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

class NFA {
public:
    int stateCount;
    set<char> alphabet;
    int startState;
    set<int> finalStates;
    map<pair<int, char>, set<int>> transitions;

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "无法打开输入文件!" << endl;
            return;
        }

        // 读取状态数量
        file >> stateCount;

        // 读取字母表
        int alphabetSize;
        file >> alphabetSize;
        for (int i = 0; i < alphabetSize; i++) {
            char symbol;
            file >> symbol;
            alphabet.insert(symbol);
        }

        // 读取初始状态
        file >> startState;

        // 读取接受状态
        int finalCount;
        file >> finalCount;
        for (int i = 0; i < finalCount; i++) {
            int state;
            file >> state;
            finalStates.insert(state);
        }

        // 读取转移函数
        int transitionCount;
        file >> transitionCount;
        for (int i = 0; i < transitionCount; i++) {
            int from, to;
            char symbol;
            file >> from >> symbol >> to;
            transitions[{from, symbol}].insert(to);
        }

        file.close();
    }

    set<int> epsilonClosure(const set<int>& states) {
        set<int> closure = states;
        queue<int> q;
        for (int state : states) {
            q.push(state);
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // 查找ε转移
            auto it = transitions.find({ current, 'E' });
            if (it != transitions.end()) {
                for (int nextState : it->second) {
                    if (closure.find(nextState) == closure.end()) {
                        closure.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
        }
        return closure;
    }

    set<int> move(const set<int>& states, char symbol) {
        set<int> result;
        for (int state : states) {
            auto it = transitions.find({ state, symbol });
            if (it != transitions.end()) {
                for (int nextState : it->second) {
                    result.insert(nextState);
                }
            }
        }
        return result;
    }
};

class DFA {
public:
    set<set<int>> states;
    set<char> alphabet;
    set<int> startState;
    set<set<int>> finalStates;
    map<pair<set<int>, char>, set<int>> transitions;

    void convertFromNFA(NFA& nfa, ofstream& output) {
        alphabet = nfa.alphabet;

        // 计算初始状态的ε闭包
        startState = nfa.epsilonClosure({ nfa.startState });

        queue<set<int>> q;
        q.push(startState);
        states.insert(startState);

        // 检查初始状态是否为接受状态
        if (containsFinalState(startState, nfa.finalStates)) {
            finalStates.insert(startState);
        }

        output << "=== NFA转DFA过程 ===" << endl;
        output << "初始状态: ";
        printStateSet(startState, output);
        output << endl;

        int step = 1;

        while (!q.empty()) {
            set<int> currentState = q.front();
            q.pop();

            output << "步骤 " << step++ << " - 处理状态: ";
            printStateSet(currentState, output);
            output << endl;

            for (char symbol : alphabet) {
                if (symbol == 'E') continue; // 跳过ε转移

                set<int> nextState = nfa.epsilonClosure(nfa.move(currentState, symbol));

                if (!nextState.empty()) {
                    transitions[{currentState, symbol}] = nextState;

                    output << "  输入 '" << symbol << "' -> ";
                    printStateSet(nextState, output);
                    output << endl;

                    if (states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        q.push(nextState);

                        if (containsFinalState(nextState, nfa.finalStates)) {
                            finalStates.insert(nextState);
                        }
                    }
                }
            }
            output << endl;
        }
    }

    bool containsFinalState(const set<int>& stateSet, const set<int>& nfaFinalStates) {
        for (int state : stateSet) {
            if (nfaFinalStates.find(state) != nfaFinalStates.end()) {
                return true;
            }
        }
        return false;
    }

    void printStateSet(const set<int>& stateSet, ofstream& output) {
        output << "{";
        for (auto it = stateSet.begin(); it != stateSet.end(); ) {
            output << *it;
            if (++it != stateSet.end()) {
                output << ",";
            }
        }
        output << "}";
    }

    void minimize(ofstream& output) {
        output << "\n=== DFA最小化过程 ===" << endl;

        // 第一步：划分接受状态和非接受状态
        set<set<int>> partitions;
        set<set<int>> nonFinalStates;

        for (const auto& state : states) {
            if (finalStates.find(state) != finalStates.end()) {
                partitions.insert(state);
            }
            else {
                nonFinalStates.insert(state);
            }
        }

        if (!nonFinalStates.empty()) {
            partitions.insert(nonFinalStates);
        }

        output << "初始划分:" << endl;
        output << "  接受状态: ";
        for (const auto& part : partitions) {
            if (finalStates.find(part) != finalStates.end()) {
                printStateSet(part, output);
                output << " ";
            }
        }
        output << endl << "  非接受状态: ";
        for (const auto& part : partitions) {
            if (finalStates.find(part) == finalStates.end()) {
                printStateSet(part, output);
                output << " ";
            }
        }
        output << endl;

        // 继续划分直到不再变化
        bool changed = true;
        int iteration = 1;

        while (changed) {
            changed = false;
            set<set<int>> newPartitions;

            output << "迭代 " << iteration++ << ":" << endl;

            for (const auto& partition : partitions) {
                if (partition.size() == 1) {
                    newPartitions.insert(partition);
                    continue;
                }

                map<set<int>, set<set<int>>> equivalenceClasses;

                for (const auto& state : partition) {
                    set<int> signature;

                    for (char symbol : alphabet) {
                        if (symbol == 'E') continue;

                        auto transIt = transitions.find({ state, symbol });
                        if (transIt != transitions.end()) {
                            const set<int>& target = transIt->second;

                            // 找到目标状态所在的划分
                            for (const auto& part2 : partitions) {
                                if (part2.find(*target.begin()) != part2.end()) {
                                    // 这里简化处理，用划分的代表元素作为签名
                                    signature.insert(distance(partitions.begin(), partitions.find(part2)));
                                    break;
                                }
                            }
                        }
                    }

                    // 将签名转换为可比较的形式
                    set<int> sigSet(signature.begin(), signature.end());
                    equivalenceClasses[sigSet].insert(state);
                }

                for (const auto& eqClass : equivalenceClasses) {
                    newPartitions.insert(eqClass.second);
                    if (eqClass.second.size() < partition.size()) {
                        changed = true;
                    }
                }
            }

            partitions = newPartitions;

            output << "  当前划分: ";
            for (const auto& part : partitions) {
                printStateSet(part, output);
                output << " ";
            }
            output << endl;
        }

        // 构建最小化DFA
        buildMinimizedDFA(partitions, output);
    }

    void buildMinimizedDFA(const set<set<int>>& partitions, ofstream& output) {
        map<set<int>, int> stateMapping;
        int newStateId = 0;

        output << "\n最小化DFA构建:" << endl;

        // 为每个划分分配新状态编号
        for (const auto& partition : partitions) {
            stateMapping[partition] = newStateId;
            output << "  划分 ";
            printStateSet(partition, output);
            output << " -> 状态 " << newStateId << endl;
            newStateId++;
        }

        // 构建最小化DFA的转移
        map<pair<int, char>, int> minTransitions;
        set<int> minFinalStates;
        int minStartState = -1;

        for (const auto& partition : partitions) {
            int fromState = stateMapping[partition];

            // 检查是否为接受状态
            if (finalStates.find(*partition.begin()) != finalStates.end()) {
                minFinalStates.insert(fromState);
            }

            // 检查是否为初始状态
            if (partition == startState) {
                minStartState = fromState;
            }

            // 构建转移
            for (char symbol : alphabet) {
                if (symbol == 'E') continue;

                auto transIt = transitions.find({ *partition.begin(), symbol });
                if (transIt != transitions.end()) {
                    const set<int>& target = transIt->second;

                    // 找到目标状态所在的划分
                    for (const auto& targetPartition : partitions) {
                        if (targetPartition.find(*target.begin()) != targetPartition.end()) {
                            int toState = stateMapping[targetPartition];
                            minTransitions[{fromState, symbol}] = toState;

                            output << "  状态 " << fromState << " 输入 '" << symbol
                                << "' -> 状态 " << toState << endl;
                            break;
                        }
                    }
                }
            }
        }

        // 输出最终的最小化DFA
        output << "\n=== 最小化DFA结果 ===" << endl;
        output << "状态数量: " << partitions.size() << endl;
        output << "初始状态: " << minStartState << endl;
        output << "接受状态: ";
        for (int state : minFinalStates) {
            output << state << " ";
        }
        output << endl;
        output << "转移函数:" << endl;
        for (const auto& trans : minTransitions) {
            output << "  " << trans.first.first << " --" << trans.first.second
                << "--> " << trans.second << endl;
        }
    }
};

int main() {
    NFA nfa;
    DFA dfa;

    // 读取NFA
    nfa.readFromFile("input.txt");

    // 打开输出文件
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "无法创建输出文件!" << endl;
        return 1;
    }

    // 转换NFA到DFA
    dfa.convertFromNFA(nfa, output);

    // 最小化DFA
    dfa.minimize(output);

    output.close();
    cout << "转换完成！结果已保存到 output.txt" << endl;

    return 0;
}