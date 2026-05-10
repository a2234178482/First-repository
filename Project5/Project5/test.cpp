#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cctype>
#define MAX 507

using namespace std;

class WF {
public:
    string left;
    vector<string> right;

    WF(const string& str) { left = str; }

    void insert(char str[]) {
        right.push_back(str);
    }

    void print() {
        printf("%s->%s", left.c_str(), right[0].c_str());
        for (int i = 1; i < right.size(); i++)
            printf("|%s", right[i].c_str());
        puts("");
    }
};

char relation[MAX][MAX];
vector<char> VT;
vector<WF> VN_set;
map<string, int> VN_dic;
set<char> first[MAX];
set<char> last[MAX];
int used[MAX];
int vis[MAX];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    for (int i = 0; i < VN_set[x].right.size(); i++) {
        string& str = VN_set[x].right[i];
        if (isupper(str[0])) {
            int y = VN_dic[str.substr(0, 1)] - 1;
            if (str.length() > 1 && !isupper(str[1]))
                first[x].insert(str[1]);
            dfs(y);
            for (auto c : first[y]) first[x].insert(c);
        }
        else first[x].insert(str[0]);
    }
}

void make_first() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < VN_set.size(); i++)
        if (!vis[i]) dfs(i);

    puts("------------FIRSTVT集-------------------");
    for (int i = 0; i < VN_set.size(); i++) {
        printf("%s : ", VN_set[i].left.c_str());
        for (auto c : first[i]) printf("%c ", c);
        printf("\n");
    }
}

void dfs1(int x) {
    if (vis[x]) return;
    vis[x] = 1;

    for (int i = 0; i < VN_set[x].right.size(); i++) {
        string& str = VN_set[x].right[i];
        int n = str.length() - 1;

        if (isupper(str[n])) {
            int y = VN_dic[str.substr(n, 1)] - 1;

            if (n - 1 >= 0 && !isupper(str[n - 1]))
                last[x].insert(str[n - 1]);   // 修正了你原代码的 bug

            dfs1(y);
            for (auto c : last[y]) last[x].insert(c);
        }
        else last[x].insert(str[n]);
    }
}

void make_last() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < VN_set.size(); i++)
        if (!vis[i]) dfs1(i);

    puts("--------------LASTVT集---------------------");
    for (int i = 0; i < VN_set.size(); i++) {
        printf("%s : ", VN_set[i].left.c_str());
        for (auto c : last[i]) printf("%c ", c);
        printf("\n");
    }
}

void make_table() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            relation[i][j] = ' ';

    for (int i = 0; i < VN_set.size(); i++)
        for (int j = 0; j < VN_set[i].right.size(); j++) {
            string& str = VN_set[i].right[j];
            for (int k = 0; k < str.length() - 1; k++) {

                if (!isupper(str[k]) && !isupper(str[k + 1]))
                    relation[str[k]][str[k + 1]] = '=';

                if (!isupper(str[k]) && isupper(str[k + 1])) {
                    int x = VN_dic[str.substr(k + 1, 1)] - 1;
                    for (auto c : first[x])
                        relation[str[k]][c] = '<';
                }

                if (isupper(str[k]) && !isupper(str[k + 1])) {
                    int x = VN_dic[str.substr(k, 1)] - 1;
                    for (auto c : last[x])
                        relation[c][str[k + 1]] = '>';
                }

                if (k + 2 < str.length() &&
                    !isupper(str[k]) && !isupper(str[k + 2]) && isupper(str[k + 1]))
                    relation[str[k]][str[k + 2]] = '=';
            }
        }

    for (int i = 0; i < VT.size() * 5; i++) printf("-");
    printf("算符优先关系表");
    for (int i = 0; i < VT.size() * 5; i++) printf("-");
    puts("");

    printf("|%8s|", "");
    for (auto t : VT) printf("%5c%5s", t, "|");
    puts("");

    for (int i = 0; i < (VT.size() + 1) * 10; i++) printf("-");
    puts("");

    for (auto a : VT) {
        printf("|%4c%5s", a, "|");
        for (auto b : VT)
            printf("%5c%5s", relation[a][b], "|");
        puts("");

        for (int i = 0; i < (VT.size() + 1) * 10; i++) printf("-");
        puts("");
    }
}

int fa[MAX];

int _find(int x) { return x == fa[x] ? x : fa[x] = _find(fa[x]); }

bool judge(char x, char y) { return _find(x) == _find(y); }

void _union(char x, char y) {
    x = _find(x);
    y = _find(y);
    fa[x] = y;
}

void print_step(string s1, string s2, string s3, string s4, string s5, string s6) {
    printf("%-14s|%-15s%-15s%-15s%-15s%-15s\n",
        s1.c_str(), s2.c_str(), s3.c_str(), s4.c_str(), s5.c_str(), s6.c_str());
}

void init_union() {
    for (int i = 0; i < MAX; i++) fa[i] = i;

    for (auto& wf : VN_set)
        if (wf.left.length() == 1)
            for (auto& r : wf.right)
                if (r.length() == 1)
                    _union(wf.left[0], r[0]);

    print_step("步骤", "栈", "优先关系", "当前符号", "剩余符号", "动作");
}

string get_stk(vector<char>& stk) {
    return string(stk.begin(), stk.end());
}

bool check(const string& A, const string& B) {
    if (A.length() != B.length()) return false;

    for (int i = 0; i < A.length(); i++) {
        if (isupper(A[i])) {
            if (!judge(A[i], B[i])) return false;
        }
        else if (A[i] != B[i]) return false;
    }
    return true;
}

string reduction(string src) {
    for (int i = 0; i < VN_set.size(); i++)
        for (auto& r : VN_set[i].right)
            if (check(r, src))
                return VN_set[i].left;
    return "";
}

bool is_success_reduce(vector<char>& stk, string start) {
    return (stk.size() == 2 && stk[0] == '#' && stk[1] == start[0]);
}

void move_reduction(string src) {

    init_union();

    vector<char> stk;
    stk.push_back('#');
    src += "#";

    int steps = 1;

    for (int i = 0; i < src.length(); i++) {
        char a = src[i];

        char top = '#';
        for (int j = stk.size() - 1; j >= 0; j--)
            if (!isupper(stk[j])) { top = stk[j]; break; }

        char rel = relation[top][a];
        string rest = (i == src.length() - 1 ? "" : src.substr(i + 1));

        if (rel == '<' || rel == '=') {
            print_step(to_string(steps), get_stk(stk), string(1, rel),
                string(1, a), rest, "移进");
            stk.push_back(a);
        }
        else {
            print_step(to_string(steps), get_stk(stk), string(1, rel),
                string(1, a), rest, "归约");

            string tmp = "";
            int x = stk.size() - 2;

            while (x >= 0) {
                if (!isupper(stk[x]) && relation[stk[x]][top] == '<') break;
                x--;
            }

            for (int j = stk.size() - 1; j > x; j--) {
                tmp += stk[j];
                stk.pop_back();
            }

            string A = reduction(tmp);
            if (A == "") {
                cout << "错误：无法归约 " << tmp << endl;
                return;
            }

            stk.push_back(A[0]);
            i--;
        }
        steps++;
    }

    string start = VN_set[0].left;

    cout << "\n最终栈: " << get_stk(stk) << endl;

    if (is_success_reduce(stk, start))
        cout << "句子合法，成功归约到：" << start << endl;
    else
        cout << "句子非法，无法归约！" << endl;
}

int main() {
    int n;
    char s[MAX];

    while (~scanf_s("%d", &n)) {

        VT.clear();
        VN_set.clear();
        VN_dic.clear();

        memset(used, 0, sizeof(used));
        memset(first, 0, sizeof(first));
        memset(last, 0, sizeof(last));

        for (int i = 0; i < n; i++) {
            scanf_s("%s", s);
            int len = strlen(s), j;

            for (j = 0; j < len; j++)
                if (s[j] == '-') break;

            s[j] = 0;

            if (!VN_dic[s]) {
                VN_set.push_back(WF(s));
                VN_dic[s] = VN_set.size();
            }

            int x = VN_dic[s] - 1;
            VN_set[x].insert(s + j + 2);

            for (int k = 0; k < len; k++)
                if (!isupper(s[k])) {
                    VT.push_back(s[k]);
                }
        }

        puts("************VT集*******************");
        for (auto t : VT) printf("%c ", t);
        puts("");

        puts("*************产生式*****************");
        for (auto& wf : VN_set) wf.print();
        puts("************************************");

        make_first();
        make_last();
        make_table();

        string input;
        cout << "\n请输入要识别的句子：";
        cin >> input;

        move_reduction(input);
    }
}
