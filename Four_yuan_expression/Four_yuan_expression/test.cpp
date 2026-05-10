#define CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

/* ========== 四元式结构 ========== */
struct Quad {
    int index;
    string op, arg1, arg2, result;
};

vector<Quad> quads;
int nextQuad = 100;
int tempCnt = 1;

/* ========== 工具函数 ========== */
string newTemp() {
    return "t" + to_string(tempCnt++);
}

int emit(string op, string a1, string a2, string res) {
    quads.push_back({ nextQuad, op, a1, a2, res });
    return nextQuad++;
}

void backpatch(int idx, int target) {
    for (auto& q : quads) {
        if (q.index == idx) {
            q.result = to_string(target);
            return;
        }
    }
}

/* ========== 词法分析 ========== */
vector<string> tokens;
int pos;

void tokenize(const string& s) {
    tokens.clear();
    pos = 0;
    for (int i = 0; i < s.size();) {
        if (isspace(s[i])) i++;
        else if (isalpha(s[i])) {
            string id;
            while (i < s.size() && isalnum(s[i])) id += s[i++];
            tokens.push_back(id);
        }
        else if (isdigit(s[i])) {
            string num;
            while (i < s.size() && isdigit(s[i])) num += s[i++];
            tokens.push_back(num);
        }
        else {
            if (s.substr(i, 2) == "==") {
                tokens.push_back("==");
                i += 2;
            }
            else {
                tokens.push_back(string(1, s[i++]));
            }
        }
    }
}

/* ========== 表达式分析 ========== */
string expression();

string factor() {
    if (tokens[pos] == "(") {
        pos++;
        string t = expression();
        pos++;  // )
        return t;
    }
    return tokens[pos++];
}

string term() {
    string left = factor();
    while (pos < tokens.size() &&
        (tokens[pos] == "*" || tokens[pos] == "/")) {
        string op = tokens[pos++];
        string right = factor();
        string t = newTemp();
        emit(op, left, right, t);
        left = t;
    }
    return left;
}

string expression() {
    string left = term();
    while (pos < tokens.size() &&
        (tokens[pos] == "+" || tokens[pos] == "-")) {
        string op = tokens[pos++];
        string right = term();
        string t = newTemp();
        emit(op, left, right, t);
        left = t;
    }
    return left;
}

/* ========== 赋值语句 ========== */
void parseAssign() {
    string lhs = tokens[pos++];
    pos++; // =
    string rhs = expression();
    emit("=", rhs, "-", lhs);
}

/* ========== if 语句 ========== */
void parseIf() {
    pos++; // if
    pos++; // (
    string a = tokens[pos++];
    string relop = tokens[pos++];
    string b = tokens[pos++];
    pos++; // )

    int q1 = emit("j" + relop, a, b, "-");
    int q2 = emit("j", "-", "-", "-");

    int thenBegin = nextQuad;
    backpatch(q1, thenBegin);

    parseAssign(); // then 只有一条赋值语句

    int next = nextQuad;
    backpatch(q2, next);
}

/* ========== while 语句 ========== */
void parseWhile() {
    pos++; // while
    int begin = nextQuad;

    pos++; // (
    string a = tokens[pos++];
    string relop = tokens[pos++];
    string b = tokens[pos++];
    pos++; // )

    int q1 = emit("j" + relop, a, b, "-");
    int q2 = emit("j", "-", "-", "-");

    int bodyBegin = nextQuad;
    backpatch(q1, bodyBegin);

    parseAssign(); // 循环体一条赋值

    emit("j", "-", "-", to_string(begin));

    int next = nextQuad;
    backpatch(q2, next);
}

/* ========== 语句分派 ========== */
void parseStmt(const string& line) {
    tokenize(line);
    if (tokens[0] == "if")
        parseIf();
    else if (tokens[0] == "while")
        parseWhile();
    else
        parseAssign();
}

/* ========== 主函数 ========== */
int main() {
    cout << "请输入程序（每行一条语句，end 结束）：\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line == "end") break;
        parseStmt(line);
    }

    cout << "\n生成的四元式：\n";
    for (auto& q : quads) {
        cout << q.index << ": ("
            << q.op << ", "
            << q.arg1 << ", "
            << q.arg2 << ", "
            << q.result << ")\n";
    }
    return 0;
}
