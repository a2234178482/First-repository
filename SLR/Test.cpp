#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;

// 产生式类
class Production {
public:
    string left;  // 左部符号
    string right; // 右部符号串

    Production(string l, string r) : left(l), right(r) {}

    string toString() const {
        return left + " -> " + right;
    }
};

// LR(0)项目类
class LR0Item {
public:
    int prodIndex;  // 产生式索引
    int dotPos;     // 点的位置

    LR0Item(int idx, int pos) : prodIndex(idx), dotPos(pos) {}

    bool operator<(const LR0Item& other) const {
        if (prodIndex != other.prodIndex) return prodIndex < other.prodIndex;
        return dotPos < other.dotPos;
    }

    bool operator==(const LR0Item& other) const {
        return prodIndex == other.prodIndex && dotPos == other.dotPos;
    }
};

// 项集类
class ItemSet {
public:
    set<LR0Item> items;
    int id;

    ItemSet(int i) : id(i) {}

    bool operator<(const ItemSet& other) const {
        return items < other.items;
    }

    void addItem(int prodIndex, int dotPos) {
        items.insert(LR0Item(prodIndex, dotPos));
    }
};

class SLRParser {
private:
    vector<Production> productions;
    string startSymbol;
    set<string> nonTerminals;
    set<string> terminals;
    map<string, set<string>> firstSets;
    map<string, set<string>> followSets;
    vector<ItemSet> itemSets;
    map<pair<int, string>, string> actionTable;
    map<pair<int, string>, int> gotoTable;

public:
    SLRParser() {
        // 用户输入文法
        inputGrammar();

        // 计算非终结符和终结符
        computeSymbols();

        // 计算FIRST集和FOLLOW集
        computeFirstSets();
        computeFollowSets();

        // 构造LR(0)项集规范族
        constructLR0ItemSets();

        // 构造SLR(1)分析表
        constructSLRTable();
    }

    void inputGrammar() {
        cout << "请输入文法的产生式数量: ";
        int n;
        cin >> n;
        cin.ignore(); // 忽略换行符

        cout << "请输入产生式（格式：左部 -> 右部，例如：E -> E+T）:" << endl;
        for (int i = 0; i < n; i++) {
            string line;
            cout << "产生式 " << (i + 1) << ": ";
            getline(cin, line);

            // 解析产生式
            size_t arrowPos = line.find("->");
            if (arrowPos == string::npos) {
                cout << "错误：产生式格式不正确，缺少 '->'" << endl;
                i--;
                continue;
            }

            string left = line.substr(0, arrowPos);
            // 去除左部空格
            left.erase(remove(left.begin(), left.end(), ' '), left.end());

            string right = line.substr(arrowPos + 2);
            // 去除右部空格
            right.erase(remove(right.begin(), right.end(), ' '), right.end());

            if (left.empty() || right.empty()) {
                cout << "错误：产生式左部或右部为空" << endl;
                i--;
                continue;
            }

            productions.push_back(Production(left, right));
        }

        if (productions.empty()) {
            cout << "错误：没有有效的产生式，使用默认文法" << endl;
            // 使用默认文法
            productions = {
                Production("S", "E"),  // 增广文法
                Production("E", "E+T"),
                Production("E", "T"),
                Production("T", "T*F"),
                Production("T", "F"),
                Production("F", "(E)"),
                Production("F", "i")
            };
            startSymbol = "S";
        }
        else {
            // 设置开始符号为第一个产生式的左部
            startSymbol = productions[0].left;

            // 询问用户是否要指定开始符号
            cout << "当前开始符号为: " << startSymbol << endl;
            cout << "是否要指定其他开始符号? (y/n): ";
            char choice;
            cin >> choice;
            cin.ignore();

            if (choice == 'y' || choice == 'Y') {
                cout << "请输入开始符号: ";
                getline(cin, startSymbol);
                // 去除空格
                startSymbol.erase(remove(startSymbol.begin(), startSymbol.end(), ' '), startSymbol.end());
            }

            // 添加增广文法 S' -> startSymbol
            string augmentedStart = startSymbol + "'";
            productions.insert(productions.begin(), Production(augmentedStart, startSymbol));
            startSymbol = augmentedStart;
        }

        cout << "\n输入的文法:" << endl;
        for (int i = 0; i < productions.size(); i++) {
            cout << i << ": " << productions[i].toString() << endl;
        }
        cout << "开始符号: " << startSymbol << endl;
    }

    void computeSymbols() {
        for (const auto& prod : productions) {
            nonTerminals.insert(prod.left);
        }

        for (const auto& prod : productions) {
            // 将右部拆分为符号
            vector<string> symbols = splitSymbols(prod.right);
            for (const string& symbol : symbols) {
                if (nonTerminals.find(symbol) == nonTerminals.end() && symbol != "ε") {
                    terminals.insert(symbol);
                }
            }
        }
        terminals.insert("$"); // 结束符
    }

    vector<string> splitSymbols(const string& str) {
        vector<string> symbols;
        string current;

        for (char c : str) {
            if (isalnum(c) || c == '_') {
                current += c;
            }
            else {
                if (!current.empty()) {
                    symbols.push_back(current);
                    current.clear();
                }
                if (c != ' ' && c != '\t') {
                    symbols.push_back(string(1, c));
                }
            }
        }

        if (!current.empty()) {
            symbols.push_back(current);
        }

        return symbols;
    }

    void computeFirstSets() {
        // 初始化
        for (const string& nt : nonTerminals) {
            firstSets[nt] = set<string>();
        }

        bool changed = true;
        while (changed) {
            changed = false;
            for (const auto& prod : productions) {
                string left = prod.left;
                vector<string> rightSymbols = splitSymbols(prod.right);

                if (rightSymbols.empty() || (rightSymbols.size() == 1 && rightSymbols[0] == "ε")) {
                    if (firstSets[left].find("ε") == firstSets[left].end()) {
                        firstSets[left].insert("ε");
                        changed = true;
                    }
                    continue;
                }

                size_t i = 0;
                bool canBeEpsilon = true;

                while (i < rightSymbols.size() && canBeEpsilon) {
                    string symbol = rightSymbols[i];

                    if (terminals.find(symbol) != terminals.end() || symbol == "ε") {
                        if (symbol == "ε") {
                            // 空串，继续检查下一个符号
                            i++;
                            continue;
                        }
                        if (firstSets[left].find(symbol) == firstSets[left].end()) {
                            firstSets[left].insert(symbol);
                            changed = true;
                        }
                        canBeEpsilon = false;
                    }
                    else {
                        // 非终结符
                        for (const string& c : firstSets[symbol]) {
                            if (c != "ε" && firstSets[left].find(c) == firstSets[left].end()) {
                                firstSets[left].insert(c);
                                changed = true;
                            }
                        }

                        if (firstSets[symbol].find("ε") == firstSets[symbol].end()) {
                            canBeEpsilon = false;
                        }
                    }
                    i++;
                }

                if (canBeEpsilon && firstSets[left].find("ε") == firstSets[left].end()) {
                    firstSets[left].insert("ε");
                    changed = true;
                }
            }
        }
    }

    void computeFollowSets() {
        // 初始化
        for (const string& nt : nonTerminals) {
            followSets[nt] = set<string>();
        }
        followSets[startSymbol].insert("$");

        bool changed = true;
        while (changed) {
            changed = false;

            for (const auto& prod : productions) {
                string left = prod.left;
                vector<string> rightSymbols = splitSymbols(prod.right);

                for (size_t i = 0; i < rightSymbols.size(); i++) {
                    string B = rightSymbols[i];
                    if (nonTerminals.find(B) == nonTerminals.end()) continue;

                    // 情况3: A -> αBβ
                    if (i + 1 < rightSymbols.size()) {
                        string beta = rightSymbols[i + 1];

                        if (terminals.find(beta) != terminals.end()) {
                            // β是终结符
                            if (followSets[B].find(beta) == followSets[B].end()) {
                                followSets[B].insert(beta);
                                changed = true;
                            }
                        }
                        else {
                            // β是非终结符
                            for (const string& c : firstSets[beta]) {
                                if (c != "ε" && followSets[B].find(c) == followSets[B].end()) {
                                    followSets[B].insert(c);
                                    changed = true;
                                }
                            }
                        }
                    }

                    // 情况2: A -> αB 或 A -> αBβ 且 β =>* ε
                    bool allEpsilon = true;
                    for (size_t j = i + 1; j < rightSymbols.size(); j++) {
                        string symbol = rightSymbols[j];
                        if (terminals.find(symbol) != terminals.end()) {
                            allEpsilon = false;
                            break;
                        }
                        if (firstSets[symbol].find("ε") == firstSets[symbol].end()) {
                            allEpsilon = false;
                            break;
                        }
                    }

                    if (i + 1 >= rightSymbols.size() || allEpsilon) {
                        for (const string& c : followSets[left]) {
                            if (followSets[B].find(c) == followSets[B].end()) {
                                followSets[B].insert(c);
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }

    set<LR0Item> closure(const set<LR0Item>& I) {
        set<LR0Item> closureSet = I;
        bool changed = true;

        while (changed) {
            changed = false;
            set<LR0Item> newItems;

            for (const auto& item : closureSet) {
                const Production& prod = productions[item.prodIndex];
                vector<string> rightSymbols = splitSymbols(prod.right);

                if (item.dotPos < rightSymbols.size()) {
                    string nextSymbol = rightSymbols[item.dotPos];
                    if (nonTerminals.find(nextSymbol) != nonTerminals.end()) {
                        // 对于每个以nextSymbol为左部的产生式，添加项目
                        for (int i = 0; i < productions.size(); i++) {
                            if (productions[i].left == nextSymbol) {
                                LR0Item newItem(i, 0);
                                if (closureSet.find(newItem) == closureSet.end() &&
                                    newItems.find(newItem) == newItems.end()) {
                                    newItems.insert(newItem);
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }

            for (const auto& item : newItems) {
                closureSet.insert(item);
            }
        }

        return closureSet;
    }

    set<LR0Item> gotoSet(const set<LR0Item>& I, const string& X) {
        set<LR0Item> J;

        for (const auto& item : I) {
            const Production& prod = productions[item.prodIndex];
            vector<string> rightSymbols = splitSymbols(prod.right);

            if (item.dotPos < rightSymbols.size() && rightSymbols[item.dotPos] == X) {
                J.insert(LR0Item(item.prodIndex, item.dotPos + 1));
            }
        }

        return closure(J);
    }

    void constructLR0ItemSets() {
        // 初始项集：S' -> .E
        set<LR0Item> initial;
        initial.insert(LR0Item(0, 0));
        set<LR0Item> I0 = closure(initial);

        itemSets.push_back(ItemSet(0));
        itemSets[0].items = I0;

        vector<set<LR0Item>> allItemSets;
        allItemSets.push_back(I0);

        bool changed = true;
        while (changed) {
            changed = false;
            vector<set<LR0Item>> newItemSets;

            for (const auto& I : allItemSets) {
                // 对所有符号X计算GOTO(I, X)
                set<string> allSymbols;
                for (const string& c : nonTerminals) allSymbols.insert(c);
                for (const string& c : terminals) allSymbols.insert(c);
                allSymbols.erase("$"); // 结束符不用于GOTO

                for (const string& X : allSymbols) {
                    set<LR0Item> gotoI = gotoSet(I, X);
                    if (!gotoI.empty()) {
                        auto it = find(allItemSets.begin(), allItemSets.end(), gotoI);
                        if (it == allItemSets.end()) {
                            // 新项集
                            auto it2 = find(newItemSets.begin(), newItemSets.end(), gotoI);
                            if (it2 == newItemSets.end()) {
                                newItemSets.push_back(gotoI);
                                changed = true;
                            }
                        }
                    }
                }
            }

            for (const auto& newSet : newItemSets) {
                allItemSets.push_back(newSet);
                ItemSet newItemSet(itemSets.size());
                newItemSet.items = newSet;
                itemSets.push_back(newItemSet);
            }
        }
    }

    void constructSLRTable() {
        // 初始化分析表
        for (int i = 0; i < itemSets.size(); i++) {
            for (const string& a : terminals) {
                actionTable[{i, a}] = "error";
            }
            for (const string& A : nonTerminals) {
                gotoTable[{i, A}] = -1;
            }
        }

        // 填充ACTION和GOTO表
        for (int i = 0; i < itemSets.size(); i++) {
            const auto& I = itemSets[i];

            for (const auto& item : I.items) {
                const Production& prod = productions[item.prodIndex];
                vector<string> rightSymbols = splitSymbols(prod.right);

                if (item.dotPos < rightSymbols.size()) {
                    // 移进项目
                    string a = rightSymbols[item.dotPos];
                    if (terminals.find(a) != terminals.end() && a != "ε") {
                        set<LR0Item> gotoI = gotoSet(I.items, a);
                        for (int j = 0; j < itemSets.size(); j++) {
                            if (itemSets[j].items == gotoI) {
                                actionTable[{i, a}] = "s" + to_string(j);
                                break;
                            }
                        }
                    }
                }
                else {
                    // 规约项目
                    if (item.prodIndex == 0) {
                        // 接受项目
                        actionTable[{i, "$"}] = "acc";
                    }
                    else {
                        // 规约项目
                        string left = prod.left;
                        for (const string& a : followSets[left]) {
                            if (a == "$") {
                                if (actionTable[{i, "$"}] == "error") {
                                    actionTable[{i, "$"}] = "r" + to_string(item.prodIndex);
                                }
                            }
                            else {
                                if (actionTable[{i, a}] == "error") {
                                    actionTable[{i, a}] = "r" + to_string(item.prodIndex);
                                }
                                else if (actionTable[{i, a}] != "r" + to_string(item.prodIndex)) {
                                    cout << "SLR冲突在状态" << i << "，符号" << a << endl;
                                }
                            }
                        }
                    }
                }
            }

            // 填充GOTO表
            for (const string& A : nonTerminals) {
                set<LR0Item> gotoI = gotoSet(I.items, A);
                if (!gotoI.empty()) {
                    for (int j = 0; j < itemSets.size(); j++) {
                        if (itemSets[j].items == gotoI) {
                            gotoTable[{i, A}] = j;
                            break;
                        }
                    }
                }
            }
        }
    }

    void printItemSets() {
        cout << "LR(0)项集规范族:" << endl;
        cout << "==================" << endl;

        for (int i = 0; i < itemSets.size(); i++) {
            cout << "I" << i << ":" << endl;
            for (const auto& item : itemSets[i].items) {
                const Production& prod = productions[item.prodIndex];
                vector<string> rightSymbols = splitSymbols(prod.right);

                cout << "  " << prod.left << " -> ";
                for (int j = 0; j < rightSymbols.size(); j++) {
                    if (j == item.dotPos) cout << ".";
                    cout << rightSymbols[j];
                }
                if (item.dotPos == rightSymbols.size()) cout << ".";
                cout << endl;
            }
            cout << endl;
        }
    }

    void printAnalysisTable() {
        cout << "SLR(1)分析表:" << endl;
        cout << "==================" << endl;

        // 打印表头
        cout << "状态\t";
        vector<string> termList(terminals.begin(), terminals.end());
        vector<string> nonTermList(nonTerminals.begin(), nonTerminals.end());

        for (const string& a : termList) {
            cout << a << "\t";
        }
        for (const string& A : nonTermList) {
            if (A != startSymbol) cout << A << "\t";
        }
        cout << endl;

        // 打印表内容
        for (int i = 0; i < itemSets.size(); i++) {
            cout << i << "\t";

            // ACTION部分
            for (const string& a : termList) {
                string action = actionTable[{i, a}];
                if (action == "error") cout << "\t";
                else cout << action << "\t";
            }

            // GOTO部分
            for (const string& A : nonTermList) {
                if (A == startSymbol) continue; // 跳过增广文法的开始符号
                int gotoState = gotoTable[{i, A}];
                if (gotoState != -1) cout << gotoState << "\t";
                else cout << "\t";
            }
            cout << endl;
        }
    }

    vector<string> tokenizeInput(const string& input) {
        vector<string> tokens;
        string current;

        for (char c : input) {
            if (isalnum(c) || c == '_') {
                current += c;
            }
            else {
                if (!current.empty()) {
                    tokens.push_back(current);
                    current.clear();
                }
                if (c != ' ' && c != '\t') {
                    tokens.push_back(string(1, c));
                }
            }
        }

        if (!current.empty()) {
            tokens.push_back(current);
        }

        return tokens;
    }

    bool parse(const string& input) {
        cout << "分析输入字符串: " << input << endl;
        cout << "==================" << endl;

        vector<string> inputTokens = tokenizeInput(input);
        inputTokens.push_back("$"); // 添加结束符

        stack<int> stateStack;
        stack<string> symbolStack;
        stateStack.push(0);
        symbolStack.push("$");

        int ip = 0;

        cout << "步骤\t状态栈\t符号栈\t输入串\t动作" << endl;
        cout << "--------------------------------------------------" << endl;

        int step = 0;

        while (true) {
            // 打印当前状态
            cout << step++ << "\t";

            // 打印状态栈
            stack<int> tempState = stateStack;
            vector<int> states;
            while (!tempState.empty()) {
                states.push_back(tempState.top());
                tempState.pop();
            }
            for (auto it = states.rbegin(); it != states.rend(); ++it) {
                cout << *it;
            }
            cout << "\t";

            // 打印符号栈
            stack<string> tempSym = symbolStack;
            vector<string> syms;
            while (!tempSym.empty()) {
                syms.push_back(tempSym.top());
                tempSym.pop();
            }
            for (auto it = syms.rbegin(); it != syms.rend(); ++it) {
                cout << *it;
            }
            cout << "\t";

            // 打印输入串
            for (int i = ip; i < inputTokens.size(); i++) {
                cout << inputTokens[i];
            }
            cout << "\t";

            int s = stateStack.top();
            string a = inputTokens[ip];

            string action = actionTable[{s, a}];

            if (action[0] == 's') {
                // 移进
                int nextState = stoi(action.substr(1));
                cout << "移进，" << a << "，转到状态" << nextState;

                stateStack.push(nextState);
                symbolStack.push(a);
                ip++;
            }
            else if (action[0] == 'r') {
                // 规约
                int prodIndex = stoi(action.substr(1));
                Production prod = productions[prodIndex];
                vector<string> rightSymbols = splitSymbols(prod.right);

                cout << "按" << prod.toString() << "规约";

                // 弹出右部长度的符号
                for (int i = 0; i < rightSymbols.size(); i++) {
                    stateStack.pop();
                    symbolStack.pop();
                }

                // 将左部符号压入栈
                string left = prod.left;
                symbolStack.push(left);

                // 查GOTO表
                s = stateStack.top();
                int nextState = gotoTable[{s, left}];
                if (nextState == -1) {
                    cout << "\n错误: GOTO表未定义" << endl;
                    return false;
                }
                stateStack.push(nextState);
            }
            else if (action == "acc") {
                cout << "接受" << endl;
                cout << "分析成功!" << endl;
                return true;
            }
            else {
                cout << "\n错误: 分析表动作未定义" << endl;
                return false;
            }

            cout << endl;

            // 防止无限循环
            if (step > 100) {
                cout << "错误: 分析步骤过多，可能陷入无限循环" << endl;
                return false;
            }
        }
    }

    void printFirstFollowSets() {
        cout << "FIRST集:" << endl;
        for (const string& nt : nonTerminals) {
            cout << "FIRST(" << nt << ") = { ";
            for (const string& s : firstSets[nt]) {
                cout << s << " ";
            }
            cout << "}" << endl;
        }

        cout << "\nFOLLOW集:" << endl;
        for (const string& nt : nonTerminals) {
            cout << "FOLLOW(" << nt << ") = { ";
            for (const string& s : followSets[nt]) {
                cout << s << " ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }
};

int main() {
    SLRParser parser;

    // 打印FIRST和FOLLOW集
    parser.printFirstFollowSets();

    // 打印LR(0)项集规范族
    parser.printItemSets();

    // 打印SLR(1)分析表
    parser.printAnalysisTable();

    // 测试输入字符串
    while (true) {
        cout << "\n请输入要分析的字符串（输入quit退出）: ";
        string input;
        getline(cin, input);

        if (input == "quit" || input == "exit") {
            break;
        }

        if (input.empty()) {
            continue;
        }

        cout << "\n\n";
        cout << "=========================================" << endl;
        bool result = parser.parse(input);
        cout << "结果: " << (result ? "接受" : "拒绝") << endl;
        cout << "=========================================" << endl;
    }

    return 0;
}