#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;

//int main()
//{
//	// 去重+升序排序
//	//set<int> s;
//	set<int, greater<int>> s;
//	s.insert(5);
//	s.insert(2);
//	s.insert(7);
//	s.insert(5);
//	s.insert(7);
//	s.insert(3);
//
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		// error C3892: “it”: 不能给常量赋值
//		//*it = 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	s.insert({ 2,8,3,9,2 });
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// void insert (initializer_list<value_type> il);
//	set<string> strset = { "sort", "insert", "add" };
//	//set<string> strset({ "sort", "insert", "add" });
//	// 
//	// 遍历string比较ascll码大小顺序遍历的
//	for (auto& e : strset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	set<int> s = { 4,2,7,2,8,5,9 };
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// 删除最小值
//	s.erase(s.begin());
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// 直接删除x
//	int x;
//	/*cin >> x;
//	int num = s.erase(x);
//	if (num == 0)
//	{
//		cout << x << "不存在！" << endl;
//	}
//	else
//	{
//		cout << x << "删除成功！" << endl;
//	}*/
//
//	cin >> x;
//	auto pos = s.find(x);
//	if (pos != s.end())
//	{
//		// pos失效
//		s.erase(pos);
//		//cout << *pos << endl;
//	}
//	else
//	{
//		cout << x << "不存在！" << endl;
//	}
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// 算法库的查找 O(N)
//	auto pos1 = find(s.begin(), s.end(), x);
//
//	// set自身实现的查找 O(logN)
//	auto pos2 = s.find(x);
//
//	// 利用count间接实现快速查找
//	cin >> x;
//	if (s.count(x))
//	{
//		cout << x << "在！" << endl;
//	}
//	else
//	{
//	cout << x << "不存在！" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++)
//		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// [30, 50]值
//	// [25, 55]值
//	 
//	//// 返回 >= 30
//	//auto itlow = myset.lower_bound(30);
//	//// 返回 > 50
//	//auto itup = myset.upper_bound(50);
//
//	// 返回 >= 25
//	auto itlow = myset.lower_bound(25);
//	// 返回 > 55
//	auto itup = myset.upper_bound(55);
//
//	// 删除这段区间的值
//	myset.erase(itlow, itup);
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//int main()
//{
//	// 相比set不同的是，multiset是排序，但是不去重
//	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// 相比set不同的是，x可能会存在多个，find查找中序的第一个
//	int x;
//	cin >> x;
//	auto pos = s.find(x);
//	while (pos != s.end() && *pos == x)
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//	cout << endl;
//
//	// 相比set不同的是，count会返回x的实际个数
//	cout << s.count(x) << endl;
//
//	//pos = s.find(x);
//	//while (pos != s.end() && *pos == x)
//	//{
//	//	pos = s.erase(pos);
//	//}
//	//cout << endl;
//	s.erase(x);
//
//	it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<map>
//
//int main()
//{
//	//map<string, string> dict;
//	map<string, string> dict = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };
//
//	//pair<string, string> kv1("first", "第一个");
//	//map<string, string> dict = {kv1, pair<string, string>("second", "第二个")};
//
//	pair<string, string> kv1("first", "第一个");
//	dict.insert(kv1);
//
//	dict.insert(pair<string, string>("second", "第二个"));
//
//	dict.insert(make_pair("sort", "排序"));
//
//	// C++11
//	dict.insert({ "auto", "自动的" });
//
//	// 插入时只看key，value不相等不会更新
//	dict.insert({ "auto", "自动的xxxx" });
//
//	map<string, string>::iterator it = dict.begin();
//	while (it != dict.end())
//	{
//		// 可以修改value，不支持修改key
//		//it->first += 'x';
//		it->second += 'x';
//
//		//cout << (*it).first <<":"<< (*it).second<< endl;
//		cout << it->first << ":" << it->second << endl;
//		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}

//class Solution {
//public:
//    map<char, int> _operatorPrecedence = { { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };
//
//    int operatorPrecedence(char ch)
//    {
//        struct opPD
//        {
//            char _op;
//            int _pd;
//        };
//
//        static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
//        for (auto& e : arr)
//        {
//            if (e._op == ch)
//            {
//                return e._pd;
//            }
//        }
//
//        assert(false);
//        return -1;
//    }
//
//    void toRPN(const string& s, size_t& i, vector<string>& v)
//    {
//        stack<char> st;
//        while (i < s.size())
//        {
//            if (isdigit(s[i]))
//            {
//                // 操作数输出
//                string num;
//                while (i < s.size() && isdigit(s[i]))
//                {
//                    num += s[i];
//                    ++i;
//                }
//
//                v.push_back(std::move(num));
//            }
//            else
//            {
//                if (s[i] == ' ')
//                {
//                    ++i;
//                    continue;
//                }
//                else if (s[i] == '(')
//                {
//                    // 递归处理子表达式
//                    ++i;
//                    toRPN(s, i, v);
//                }
//                else if (s[i] == ')')
//                {
//                    ++i;
//                    // 栈中的运算符全部输出
//                    while (!st.empty())
//                    {
//                        v.push_back(string(1, st.top()));
//                        st.pop();
//                    }
//
//                    // 结束递归
//                    return;
//                }
//                else
//                {
//                    // 运算符
//                    // 1、如果栈为空，或者比栈顶运算符优先级高，则入栈
//                    // 2、如果栈不为为空且比栈顶运算符优先级低或相等，说明栈顶的运算符可以运算了
//                    if (st.empty() || _operatorPrecedence[s[i]] > _operatorPrecedence[st.top()])
//                    {
//                        st.push(s[i]);
//                        ++i;
//                    }
//                    else
//                    {
//                        v.push_back(string(1, st.top()));
//                        st.pop();
//                    }
//                }
//            }
//        }
//
//        // 栈中的运算符全部输出
//        while (!st.empty())
//        {
//            v.emplace_back(string(1, st.top()));
//            st.pop();
//        }
//    }
//
//    int evalRPN(const vector<string>& tokens) {
//        stack<int> s;
//        for (size_t i = 0; i < tokens.size(); ++i)
//        {
//            const string& str = tokens[i];
//
//            // str为数字
//            if (!("+" == str || "-" == str || "*" == str || "/" == str))
//            {
//                s.push(stoi(str));
//            }
//            else
//            {
//                // str为操作符
//                int right = s.top();
//                s.pop();
//
//                int left = s.top();
//                s.pop();
//
//                switch (str[0])
//                {
//                case '+':
//                    s.push(left + right);
//                    break;
//                case '-':
//                    s.push(left - right);
//                    break;
//                case '*':
//                    s.push(left * right);
//                    break;
//                case '/':
//                    s.push(left / right);
//                    break;
//                }
//            }
//        }
//
//        return s.top();
//    }
//
//    int calculate(string s)
//    {
//        // 1、去除所有空格
//        // 2、(-n) -> (0-n)
//        // 开头的-n -> 0-n
//        std::string news;
//        news.reserve(s.size());
//        for (auto ch : s)
//        {
//            if (ch != ' ')
//                news += ch;
//        }
//
//        s.swap(news);
//        news.clear();
//
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '-' && (i == 0 || s[i - 1] == '('))
//                news += "0-";
//            else if (s[i] == '-' && !isdigit(s[i - 1]))
//                news += "0-";
//            else
//                news += s[i];
//        }
//
//        size_t i = 0;
//        vector<string> v;
//        toRPN(news, i, v);
//
//        return evalRPN(v);
//    }
//};
//
////int main()
////{
////    size_t i = 0;
////    //vector<string> v = Solution().toRPN(" 2-1 + 3 ", i);
////    //vector<string> v = Solution().toRPN(" 2-1 + 3*4 ", i);
////    //vector<string> v = Solution().toRPN(" 2-(1 + 3 * 4) ", i);
////    //vector<string> v = Solution().toRPN(" (1+(4+5+2)-3)+(6+8) ", i);
////    //vector<string> v = Solution().toRPN(" (1+(4+5*2)/3)*(6+8) ", i);
////    vector<string> v = Solution().toRPN(" 1-(     -2)", i);
////    for (auto e : v)
////    {
////        cout << e << " ";
////    }
////    cout << endl;
////}
//
//int main()
//{
//    string s = "0";
//    for (size_t i = 0; i < 1000000; i++)
//    {
//        s += " + 1";
//    }
//
//    cout << Solution().calculate("1+2+-3") << endl;
//}

//int main()
//{
//	// 利用find和iterator修改功能，统计水果出现的次数
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		countMap[str]++;
//  
//		// 先查找水果在不在map中
//		// 1、不在，说明水果第一次出现，则插入{水果, 1}
//		// 2、在，则查找到的节点中水果对应的次数++
//		/*auto ret = countMap.find(str);
//		if (ret == countMap.end())
//		{
//			countMap.insert({ str, 1 });
//		}
//		else
//		{
//			ret->second++;
//		}*/
//
//	}
//
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//
//	// key不存在->插入 {"insert", string()}
//	dict["insert"];
//
//	// key不存在 -> 插入+修改
//	dict["left"] = "左边";
//
//	// key存在 -> 修改
//	dict["left"] = "左边，剩余";
//
//	// 查找，确定key在才能这么用，否则就是插入了
//	cout << dict["left"] << endl;
//
//	// 插入，因为sort不在
//	cout << dict["right"] << endl;
//
//	return 0;
//}

//int main()
//{
//	// g++ gdb
//	multimap<string, string> dict;
//	// 一定成功
//	dict.insert({ "sort", "排序" });
//	dict.insert({ "sort", "排序2" });
//	dict.insert({ "sort", "排序1" });
//	dict.insert({ "sort", "排序3" });
//	dict.insert({ "sort", "排序" });
//	dict.insert({ "string", "字符串" });
//	dict.erase("sort");
//
//	return 0;
//}