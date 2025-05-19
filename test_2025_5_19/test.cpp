#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <assert.h>
using namespace std;
//class Solution
//{
//public:
//	map<char, int> _operatorPrecedence = { {'+',1},{'-',1},{'*',2},{'/',2} };
//	int operatorPrecedence(char ch)
//	{
//		struct opPD
//		{
//			char _op;
//			int  _pd;
//		};
//		static opPD arr[] = { {'+',1},{'-',1},{'*',2},{'/',2} };
//		for (auto& e : arr)
//		{
//			if (e._op == ch)
//			{
//				return e._pd;
//			}
//		}
//		assert(false);
//		return -1;
//	}
//	void toRPN(const string& s, size_t& i, vector<string>& v)
//	{
//		stack<char> st;
//		while (i < s.size())
//		{
//			if (isdigit(s[i]))
//			{
//				string num;
//				while (i < s.size() && isdigit(s[i]))
//				{
//					num += s[i];
//					++i;
//				}
//				v.push_back(std::move(num));
//			}
//			else
//			{
//				if (s[i] == ' ')
//				{
//					++i;
//					continue;
//				}
//				else if (s[i] == '(')
//				{
//					++i;
//					toRPN(s, i, v);
//				}
//				else if (s[i] == ')')
//				{
//					++i;
//					while (!st.empty())
//					{
//						v.push_back(string(1, st.top()));
//						st.pop();
//					}
//					return;
//				}
//				else
//				{
//					//运算符，
//					//1.如果栈为空，或者比栈顶运算符优先级高，则入栈
//					//如果栈不为空且比栈顶运算符优先级低或者相等，说明栈顶的运算符可以运算了
//					if (st.empty() || _operatorPrecedence[s[i]] > _operatorPrecedence[st.top()])
//					{
//						st.push(s[i]);
//						++i;
//					}
//					else
//					{
//						v.push_back(string(1, st.top()));
//						st.pop();
//					}
//				}
//			}
//		}
//		while (!st.empty())
//		{
//			v.emplace_back(string(1, st.top()));
//			st.pop();
//		}
//	}
//	int evalRPN(const vector<string>& tokens)
//	{
//		stack<int> s;
//		for (size_t i = 0; i < tokens.size(); ++i)
//		{
//			const string& str = tokens[i];
//			if (!("+" == str || "-" == str || "*" == str || "/" == str))
//			{
//				s.push(stoi(str));
//			}
//			else
//			{
//				int right = s.top();
//				s.pop();
//				int left = s.top();
//				s.pop();
//				switch (str[0])
//				{
//				case '+':
//					s.push(left + right);
//					break;
//				case '-':
//					s.push(left - right);
//					break;
//				case '*':
//					s.push(left * right);
//					break;
//				case '/':
//					s.push(left / right);
//					break;
//				}
//			}
//		}
//		return s.top();
//	}
//	int calculate(string s)
//	{
//		std::string news;
//		news.reserve(s.size());
//		for (auto ch : s)
//		{
//			if (ch != ' ')
//			{
//				news += ch;
//			}
//		}
//		s.swap(news);
//		news.clear();
//		for (size_t i = 0; i < s.size(); ++i)
//		{
//			if (s[i] == '-' && (i == 0 || s[i - 1] == '('))
//				news += "0-";
//			else if (s[i] == '-' && !isdigit(s[i - 1]))
//				news += "0-";
//			else
//				news += s[i];
//		}
//		size_t i = 0;
//		vector<string> v;
//		toRPN(news, i, v);
//		return evalRPN(v);
//	}
//};
//int main()
//{
//	size_t i = 0;
//	vector<string> v = Solution().toRPN("2-1 + 3", i);
//}
//
//int main()
//{
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		countMap[str]++;
//		//先查找水果在不在map中
//		//不在，说明水果第一次出现，则插入{水果，1}
//		//在，则查找到的节点中水果对应的次数++
//
//	}
//	for (const auto& e : countMap)
//	{
//		cout << e.first << e.second << endl;
//	}
//	return 0;
//}
int main()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	//key不存在，那么插入["insert",string()]
	dict["insert"];
	//插入+修改
	dict["left"] = "左边";
	//key存在，那么就是修改second
	dict["left"] = "左边，剩余";
	
	//查找，确定key在才能这么用，否则就是插入了
	cout << dict["left"] << endl;
	//插入
	cout << dict["right"] << endl;
	dict.erase("sort");
	for (auto e : dict)
	{
		cout << e.first << e.second << endl;
	}
	multimap<string, string> dict1;
	dict1.insert({ "sort", "排序" });
	dict1.insert({ "sort", "排序2" });
	dict1.insert({ "sort", "排序1" });
	dict1.insert({ "sort", "排序3" });
	dict1.insert({ "sort", "排序" });
	dict1.insert({ "string", "字符串" });
	dict1.erase("排序");
	for (auto e : dict1)
	{
		cout << e.first << e.second << endl;
	}
	return 0;
}