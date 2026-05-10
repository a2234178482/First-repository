#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 全局变量
char lookahead;          // 当前查看的字符
string input;            // 输入字符串
int position = 0;        // 当前读取位置

// 函数声明
void match(char expected);
void E();
void E_prime();
void T();
void T_prime();
void F();
void error();
char nexttoken();
void parseExpression();

// 匹配当前字符
void match(char expected) {
    if (lookahead == expected) {
        lookahead = nexttoken();
    }
    else {
        error();
    }
}

// 获取下一个token
char nexttoken() {
    if (position < input.length()) {
        return input[position++];
    }
    return '#'; // 输入结束
}

// 错误处理
void error() {
    cout << "语法错误! 在位置 " << position << " 附近" << endl;
    exit(1);
}

// E -> T E'
void E() {
    cout << "E -> T E'" << endl;
    T();
    E_prime();
}

// E' -> + T E' | ε
void E_prime() {
    if (lookahead == '+') {
        cout << "E' -> + T E'" << endl;
        match('+');
        T();
        E_prime();
    }
    else {
        cout << "E' -> ε" << endl; // 空产生式
    }
}

// T -> F T'
void T() {
    cout << "T -> F T'" << endl;
    F();
    T_prime();
}

// T' -> * F T' | ε
void T_prime() {
    if (lookahead == '*') {
        cout << "T' -> * F T'" << endl;
        match('*');
        F();
        T_prime();
    }
    else {
        cout << "T' -> ε" << endl; // 空产生式
    }
}

// F -> ( E ) | i
void F() {
    if (lookahead == '(') {
        cout << "F -> ( E )" << endl;
        match('(');
        E();
        match(')');
    }
    else if (lookahead == 'i') {
        cout << "F -> i" << endl;
        match('i');
    }
    else {
        error();
    }
}

// 解析表达式
void parseExpression() {
    cout << "\n开始分析表达式: " << input << endl;
    position = 0;
    lookahead = nexttoken();
    E();

    // 检查是否以#结束
    if (lookahead != '#') {
        cout << "错误: 表达式应以#结束" << endl;
        error();
    }
    else {
        cout << "分析成功! 表达式语法正确" << endl;
    }
}

// 主程序
int main() {
    string userInput;

    cout << "=== 递归下降语法分析器 ===" << endl;
    cout << "支持的文法:" << endl;
    cout << "E -> T E'" << endl;
    cout << "E' -> + T E' | ε" << endl;
    cout << "T -> F T'" << endl;
    cout << "T' -> * F T' | ε" << endl;
    cout << "F -> ( E ) | i" << endl;
    cout << "请输入表达式并以#结束，输入0000退出程序" << endl;

    // 使用do-while循环
    do {
        cout << "\n请输入表达式: ";
        getline(cin, userInput);

        // 检查是否为退出条件
        if (userInput == "0000") {
            cout << "程序退出" << endl;
            break;
        }

        // 设置输入并开始分析
        input = userInput;
        parseExpression();

    } while (true); // 一直循环，直到输入0000

    return 0;
}