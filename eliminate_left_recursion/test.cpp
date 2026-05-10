#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map> 
#include<set>
using namespace std;

struct node
{
	string left;
	set<string> right;
};
vector<node> v;
vector<string> notend;

bool allend(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return false;
	}
	return true;
}

// 检查是否还有左递归
bool hasLeftRecursion()
{
	for (int i = 0; i < v.size(); i++)
	{
		set<string>::iterator it = v[i].right.begin();
		for (; it != v[i].right.end(); it++)
		{
			string str = *it;
			// 检查直接左递归
			if (str.find(v[i].left) == 0 && str.size() >= v[i].left.size())
			{
				// 确保是精确匹配，不是部分匹配
				if (str.substr(0, v[i].left.size()) == v[i].left)
					return true;
			}
		}
	}
	return false;
}

void getnotend()
{
	set<string> tempset;
	for (int i = 0; i < v.size(); i++)
	{
		tempset.insert(v[i].left);
	}

	notend.clear(); // 清空后重新填充
	set<string>::iterator it = tempset.begin();
	for (; it != tempset.end(); it++)
	{
		notend.push_back(*it);
	}
}

vector<node> mysplit(string str)
{
	string vleft;
	set<string> vright;
	string temp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '>') continue;
		if (str[i] == '-')
		{
			vleft = temp;
			temp = "";
			continue;
		}
		if (str[i] == '|')
		{
			vright.insert(temp);
			temp = "";
			continue;
		}
		temp += str[i];
	}
	if (temp != "") vright.insert(temp);
	vector<node> ret;
	struct node N = { vleft, vright };
	ret.push_back(N);
	return ret;
}

void getproduction()
{
	printf("若一个非终结符可推出多个结果，请直接以 | 分隔，不必分开输入\n");
	printf("输入产生式,以$为结束标志:\n");
	string str;
	while (cin >> str && str[0] != '$')
	{
		vector<node> ret = mysplit(str);
		v.push_back(ret[0]);
	}
}

string myreplace(string str, string s, string t)
{
	size_t pos = str.find(s);
	if (pos != string::npos && pos == 0) // 只在开头替换
	{
		str.replace(pos, s.size(), t);
	}
	return str;
}

void erasedirect(int posi)
{
	set<string>::iterator it = v[posi].right.begin();

	vector<string> va, vb;
	for (; it != v[posi].right.end(); it++)
	{
		string str = *it;
		// 检查直接左递归
		if (str.find(v[posi].left) == 0 && str.size() >= v[posi].left.size())
		{
			if (str.substr(0, v[posi].left.size()) == v[posi].left)
			{
				str.erase(0, v[posi].left.size());
				va.push_back(str);
				continue;
			}
		}
		vb.push_back(str);
	}

	if (va.empty()) return; // 没有直接左递归，直接返回

	v[posi].right.clear();
	for (int i = 0; i < vb.size(); i++)
	{
		v[posi].right.insert(vb[i] + v[posi].left + "'");
	}

	set<string> ans;
	for (int i = 0; i < va.size(); i++)
	{
		ans.insert(va[i] + v[posi].left + "'");
	}
	ans.insert("ε"); // 使用标准的ε表示空串

	// 检查是否已存在该非终结符
	bool exists = false;
	for (int k = 0; k < v.size(); k++)
	{
		if (v[k].left == v[posi].left + "'")
		{
			v[k].right = ans; // 更新现有的
			exists = true;
			break;
		}
	}

	if (!exists)
	{
		struct node N = { v[posi].left + "'", ans };
		v.push_back(N);
	}
}

void myoperate()
{
	bool changed;
	int maxIterations = 10; // 防止无限循环

	do {
		changed = false;
		getnotend(); // 每次重新获取非终结符列表

		for (int i = 0; i < notend.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				int posi = -1, posj = -1;
				for (int k = 0; k < v.size(); k++)
				{
					if (v[k].left == notend[i]) posi = k;
					if (v[k].left == notend[j]) posj = k;
				}
				if (posi == -1 || posj == -1) continue;

				set<string> tempset;
				vector<string> toRemove;

				set<string>::iterator it = v[posi].right.begin();
				for (; it != v[posi].right.end(); it++)
				{
					string tempstr = *it;
					// 只在开头替换
					if (tempstr.find(notend[j]) == 0 &&
						tempstr.size() >= notend[j].size() &&
						tempstr.substr(0, notend[j].size()) == notend[j])
					{
						set<string>::iterator it2 = v[posj].right.begin();
						for (; it2 != v[posj].right.end(); it2++)
						{
							string ss = tempstr;
							ss = myreplace(ss, notend[j], *it2);
							tempset.insert(ss);
						}
						toRemove.push_back(tempstr);
						changed = true;
					}
				}

				// 移除旧产生式，添加新产生式
				for (int x = 0; x < toRemove.size(); x++)
				{
					it = v[posi].right.find(toRemove[x]);
					if (it != v[posi].right.end())
						v[posi].right.erase(it);
				}
				for (it = tempset.begin(); it != tempset.end(); it++)
					v[posi].right.insert(*it);
			}

			// 消除当前非终结符的直接左递归
			int posi = -1;
			for (int k = 0; k < v.size(); k++)
			{
				if (v[k].left == notend[i])
				{
					posi = k;
					break;
				}
			}
			if (posi != -1)
			{
				int oldSize = v[posi].right.size();
				erasedirect(posi);
				if (v[posi].right.size() != oldSize)
					changed = true;
			}
		}

		maxIterations--;
	} while (changed && maxIterations > 0 && hasLeftRecursion());
}


void clearData()
{
	v.clear();
	notend.clear();
}

void displayMenu()
{
	cout << "==============================" << endl;
	cout << "  文法左递归消除系统" << endl;
	cout << "==============================" << endl;
	cout << "1. 输入文法并消除左递归" << endl;
	cout << "2. 退出系统" << endl;
	cout << "==============================" << endl;
	cout << "请选择操作 (1-2): ";
}

int main()
{
	int choice;

	while (true)
	{
		displayMenu();
		cin >> choice;

		if (choice == 1)
		{
			clearData();

			cout << "\n=== 输入文法 ===" << endl;
			getproduction();

			if (v.empty())
			{
				cout << "未输入任何产生式，请重新选择！" << endl;
				continue;
			}

			cout << "\n=== 处理中... ===" << endl;
			getnotend();
			myoperate();

			cout << "\n=== 消除一切左递归后的结果 ===" << endl;
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i].left << "->";
				set<string>::iterator it = v[i].right.begin();
				int cnt = 0;
				for (; it != v[i].right.end(); it++)
				{
					cout << *it;
					cnt++;
					if (cnt != v[i].right.size())
						cout << '|';
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "感谢使用，再见！" << endl;
			break;
		}
		else
		{
			cout << "无效选择，请重新输入！" << endl;
		}
	}

	return 0;
}