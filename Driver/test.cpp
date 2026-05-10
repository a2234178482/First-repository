#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 文法符号类型
enum SymbolType {
    TERMINAL,    // 终结符
    NON_TERMINAL // 非终结符
};

// 文法符号
struct Symbol {
    string name;
    SymbolType type;

    Symbol(string n, SymbolType t) : name(n), type(t) {}

    bool operator<(const Symbol& other) const {
        if (type != other.type) return type < other.type;
        return name < other.name;
    }

    bool operator==(const Symbol& other) const {
        return name == other.name && type == other.type;
    }
};

// 产生式
struct Production {
    Symbol left;  // 左部
    vector<Symbol> right; // 右部符号序列

    Production(Symbol l, vector<Symbol> r) : left(l), right(r) {}
};

// LL(1)分析器类
class LL1Parser {
private:
    vector<Production> productions;  // 产生式集合
    Symbol startSymbol;              // 开始符号
    set<Symbol> terminals;           // 终结符集合
    set<Symbol> nonTerminals;        // 非终结符集合
    map<Symbol, set<Symbol>> firstSets;   // FIRST集合
    map<Symbol, set<Symbol>> followSets;  // FOLLOW集合
    map<pair<Symbol, Symbol>, int> parsingTable; // 分析表

public:
    LL1Parser(Symbol start) : startSymbol(start, NON_TERMINAL) {}

    // 添加产生式
    void addProduction(Symbol left, vector<Symbol> right) {
        productions.push_back(Production(left, right));
        nonTerminals.insert(left);

        for (const auto& sym : right) {
            if (sym.type == TERMINAL) {
                terminals.insert(sym);
            }
            else {
                nonTerminals.insert(sym);
            }
        }
    }

    // 计算FIRST集合
    void calculateFirstSets() {
        bool changed = true;

        // 初始化FIRST集合
        for (const auto& nt : nonTerminals) {
            firstSets[nt] = set<Symbol>();
        }
        for (const auto& t : terminals) {
            firstSets[t] = { t };
        }

        while (changed) {
            changed = false;

            for (const auto& prod : productions) {
                Symbol left = prod.left;
                const vector<Symbol>& right = prod.right;

                if (right.empty()) { // ε产生式
                    Symbol epsilon("ε", TERMINAL);
                    if (firstSets[left].insert(epsilon).second) {
                        changed = true;
                    }
                    continue;
                }

                bool canBeEpsilon = true;
                for (const auto& sym : right) {
                    // 将sym的FIRST(除了ε)加入left的FIRST
                    for (const auto& firstSym : firstSets[sym]) {
                        if (firstSym.name != "ε") {
                            if (firstSets[left].insert(firstSym).second) {
                                changed = true;
                            }
                        }
                    }

                    // 如果当前符号不能推出ε，停止
                    if (firstSets[sym].find(Symbol("ε", TERMINAL)) == firstSets[sym].end()) {
                        canBeEpsilon = false;
                        break;
                    }
                }

                // 如果所有符号都能推出ε，将ε加入FIRST(left)
                if (canBeEpsilon) {
                    Symbol epsilon("ε", TERMINAL);
                    if (firstSets[left].insert(epsilon).second) {
                        changed = true;
                    }
                }
            }
        }
    }

    // 计算FOLLOW集合
    void calculateFollowSets() {
        bool changed = true;

        // 初始化FOLLOW集合
        for (const auto& nt : nonTerminals) {
            followSets[nt] = set<Symbol>();
        }

        // 将$加入开始符号的FOLLOW集
        Symbol dollar("$", TERMINAL);
        followSets[startSymbol].insert(dollar);

        while (changed) {
            changed = false;

            for (const auto& prod : productions) {
                Symbol left = prod.left;
                const vector<Symbol>& right = prod.right;

                for (int i = 0; i < right.size(); i++) {
                    if (right[i].type == NON_TERMINAL) {
                        Symbol B = right[i];

                        // 规则2：A → αBβ，将FIRST(β)-{ε}加入FOLLOW(B)
                        if (i + 1 < right.size()) {
                            Symbol nextSym = right[i + 1];
                            for (const auto& sym : firstSets[nextSym]) {
                                if (sym.name != "ε") {
                                    if (followSets[B].insert(sym).second) {
                                        changed = true;
                                    }
                                }
                            }
                        }

                        // 规则3：A → αB 或 A → αBβ且β能推出ε
                        bool remainingCanBeEpsilon = true;
                        for (int j = i + 1; j < right.size(); j++) {
                            if (firstSets[right[j]].find(Symbol("ε", TERMINAL)) == firstSets[right[j]].end()) {
                                remainingCanBeEpsilon = false;
                                break;
                            }
                        }

                        if (i + 1 >= right.size() || remainingCanBeEpsilon) {
                            for (const auto& sym : followSets[left]) {
                                if (followSets[B].insert(sym).second) {
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 构建LL(1)分析表
    void buildParsingTable() {
        Symbol epsilon("ε", TERMINAL);
        Symbol dollar("$", TERMINAL);

        for (int i = 0; i < productions.size(); i++) {
            const Production& prod = productions[i];
            Symbol left = prod.left;

            if (prod.right.empty() || (prod.right.size() == 1 && prod.right[0] == epsilon)) {
                // ε产生式：对于FOLLOW(left)中的每个终结符a，添加M[left, a] = 产生式i
                for (const auto& a : followSets[left]) {
                    if (a.type == TERMINAL) {
                        parsingTable[{left, a}] = i;
                    }
                }
            }
            else {
                // 计算产生式右部的FIRST集
                set<Symbol> firstOfRight;
                bool canBeEpsilon = true;

                for (const auto& sym : prod.right) {
                    for (const auto& firstSym : firstSets[sym]) {
                        if (firstSym.name != "ε") {
                            firstOfRight.insert(firstSym);
                        }
                    }

                    if (firstSets[sym].find(epsilon) == firstSets[sym].end()) {
                        canBeEpsilon = false;
                        break;
                    }
                }

                if (canBeEpsilon) {
                    firstOfRight.insert(epsilon);
                }

                // 对于FIRST(α)中的每个终结符a，添加M[left, a] = 产生式i
                for (const auto& a : firstOfRight) {
                    if (a.type == TERMINAL && a != epsilon) {
                        parsingTable[{left, a}] = i;
                    }
                }

                // 如果ε在FIRST(α)中，对于FOLLOW(left)中的每个终结符b，添加M[left, b] = 产生式i
                if (firstOfRight.find(epsilon) != firstOfRight.end()) {
                    for (const auto& b : followSets[left]) {
                        if (b.type == TERMINAL) {
                            parsingTable[{left, b}] = i;
                        }
                    }
                }
            }
        }
    }

    // 分析输入串
    bool parse(const vector<Symbol>& input) {
        stack<Symbol> analysisStack;
        Symbol dollar("$", TERMINAL);

        // 初始化分析栈
        analysisStack.push(dollar);
        analysisStack.push(startSymbol);

        size_t inputIndex = 0;
        Symbol currentInput = inputIndex < input.size() ? input[inputIndex] : dollar;

        cout << "分析过程:" << endl;
        cout << "栈顶\t\t输入\t\t动作" << endl;
        cout << "----------------------------------------" << endl;

        while (!analysisStack.empty()) {
            Symbol top = analysisStack.top();

            // 显示当前状态
            cout << symbolToString(top) << "\t\t"
                << symbolToString(currentInput) << "\t\t";

            if (top.type == TERMINAL) {
                if (top == currentInput) {
                    // 匹配成功
                    cout << "匹配 " << symbolToString(top) << endl;
                    analysisStack.pop();
                    inputIndex++;
                    currentInput = inputIndex < input.size() ? input[inputIndex] : dollar;
                }
                else {
                    // 错误：栈顶终结符与输入不匹配
                    cout << "错误：期望 " << symbolToString(top)
                        << "，但遇到 " << symbolToString(currentInput) << endl;
                    return false;
                }
            }
            else { // 非终结符
                auto tableEntry = parsingTable.find({ top, currentInput });
                if (tableEntry != parsingTable.end()) {
                    int prodIndex = tableEntry->second;
                    const Production& prod = productions[prodIndex];

                    cout << "应用 " << productionToString(prod) << endl;

                    analysisStack.pop();

                    // 将产生式右部逆序压入栈（ε产生式不压入）
                    if (!(prod.right.size() == 1 && prod.right[0] == Symbol("ε", TERMINAL))) {
                        for (auto it = prod.right.rbegin(); it != prod.right.rend(); ++it) {
                            analysisStack.push(*it);
                        }
                    }
                }
                else {
                    // 错误：分析表项为空
                    cout << "错误：分析表M[" << symbolToString(top)
                        << ", " << symbolToString(currentInput) << "]为空" << endl;
                    return false;
                }
            }

            // 显示栈内容
            if (!analysisStack.empty()) {
                cout << "栈: ";
                stack<Symbol> temp = analysisStack;
                vector<string> stackContent;
                while (!temp.empty()) {
                    stackContent.push_back(symbolToString(temp.top()));
                    temp.pop();
                }
                for (auto it = stackContent.rbegin(); it != stackContent.rend(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

        return currentInput == dollar;
    }

    // 显示分析表
    void displayParsingTable() {
        cout << "LL(1)分析表:" << endl;

        // 收集所有终结符（包括$）
        vector<Symbol> allTerminals(terminals.begin(), terminals.end());
        allTerminals.push_back(Symbol("$", TERMINAL));

        // 表头
        cout << "\t";
        for (const auto& t : allTerminals) {
            cout << symbolToString(t) << "\t";
        }
        cout << endl;

        // 表内容
        for (const auto& nt : nonTerminals) {
            cout << symbolToString(nt) << "\t";
            for (const auto& t : allTerminals) {
                auto entry = parsingTable.find({ nt, t });
                if (entry != parsingTable.end()) {
                    cout << productionToString(productions[entry->second]) << "\t";
                }
                else {
                    cout << "\t";
                }
            }
            cout << endl;
        }
    }

private:
    string symbolToString(const Symbol& sym) {
        return sym.name;
    }

    string productionToString(const Production& prod) {
        string result = symbolToString(prod.left) + " → ";
        for (const auto& sym : prod.right) {
            result += symbolToString(sym);
        }
        return result;
    }
};

// 测试函数
void testArithmeticExpression() {
    cout << "=== 算术表达式文法测试 ===" << endl;

    Symbol E("E", NON_TERMINAL);
    Symbol T("T", NON_TERMINAL);
    Symbol F("F", NON_TERMINAL);
    Symbol plus("+", TERMINAL);
    Symbol times("*", TERMINAL);
    Symbol lparen("(", TERMINAL);
    Symbol rparen(")", TERMINAL);
    Symbol id("id", TERMINAL);
    Symbol epsilon("ε", TERMINAL);

    LL1Parser parser(E);

    // E → TE'
    parser.addProduction(E, { T, Symbol("E'", NON_TERMINAL) });
    // E' → +TE' | ε
    parser.addProduction(Symbol("E'", NON_TERMINAL), { plus, T, Symbol("E'", NON_TERMINAL) });
    parser.addProduction(Symbol("E'", NON_TERMINAL), { epsilon });
    // T → FT'
    parser.addProduction(T, { F, Symbol("T'", NON_TERMINAL) });
    // T' → *FT' | ε
    parser.addProduction(Symbol("T'", NON_TERMINAL), { times, F, Symbol("T'", NON_TERMINAL) });
    parser.addProduction(Symbol("T'", NON_TERMINAL), { epsilon });
    // F → (E) | id
    parser.addProduction(F, { lparen, E, rparen });
    parser.addProduction(F, { id });

    // 计算集合和分析表
    parser.calculateFirstSets();
    parser.calculateFollowSets();
    parser.buildParsingTable();

    parser.displayParsingTable();

    // 测试输入：id + id * id
    vector<Symbol> input = { id, plus, id, times, id, Symbol("$", TERMINAL) };

    cout << "\n输入: id + id * id" << endl;
    bool result = parser.parse(input);
    cout << (result ? "分析成功！" : "分析失败！") << endl;
}

int main() {
    testArithmeticExpression();
    return 0;
}