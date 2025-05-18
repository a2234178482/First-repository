#include <iostream>
#include <set>
#include <map>
using namespace std;

//int main()
//{
//	//set<int> s;
//	set<int, less<int>> s;
//	s.insert(4);
//	s.insert(5);
//	s.insert(4);
//	s.insert(6);
//	s.insert(1);
//	s.insert(7);
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//	s.insert({ 2,8,3,9,2 });
//	for (auto e : s)
//	{
//		cout << e  << endl;
//	}
//	cout << endl;
//	//void insert(initializer_list<value_type> il);
//	set<string> strset = { "sort","insert","add" };
//	//按照ASCII码的大小顺序比较
//	for (auto e : strset)
//	{
//		cout << e << endl;
//	}
//}
//int main()
//{
//	set<int> s = { 4,2,7,2,8,5,9 };
//	for (auto e : s)
//	{
//		cout << e << endl;
//	}
//	s.erase(s.begin());
//	cout << endl;
//	for (auto e : s)
//	{
//		cout << e << endl;
//	}
//
//	int x;
//	/*cin >> x;
//	int num = s.erase(x);
//	if (num == 0)
//	{
//		cout << x << "不存在" << endl;
//	}
//	else
//	{
//		cout << x << "删除成功" << endl;
//	}*/
//	
//	//cin >> x;
//	//auto pos = s.find(x);
//	//if (pos != s.end())
//	//{
//	//	s.erase(pos);
//	//}
//	//else
//	//{
//	//	cout << x << "不存在" << endl;
//	//}
//	//cout << endl;
//	//for (auto e : s)
//	//{
//	//	cout << e << endl;
//	//}
//	//cout << endl;
//	////算法库的查找 O(N)
//	//auto pos1 = find(s.begin(), s.end(), x);
//	////set自身的查找O(logN)
//	//auto pos2 = s.find(x);
//
//	//利用count实现快速查找
//	cin >> x;
//	if (s.count(x))
//	{
//		cout << x << endl;
//	}
//	else
//	{
//		cout << "不存在" << endl;
//	}
//	return 0;
//}

//int main()
//{
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++)
//	{
//		myset.insert(i*10);
//	}
//	/*for (auto e : myset)
//	{
//		cout << e << endl;
//	}*/
//	//大于等于
//	auto itlow = myset.lower_bound(30);
//	/*while (itlow != myset.end())
//	{
//		cout << *itlow << endl;
//		++itlow;
//	}
//	cout << endl;*/
//	//大于
//	auto itup = myset.upper_bound(40);
//	/*while (itup != myset.end())
//	{
//		cout << *itup << endl;
//		++itup;
//	}*/
//	myset.erase(itlow, itup);
//	for (auto e : myset)
//	{
//		cout << e << endl;
//	}
//}
//int main()
//{
//	//和set不同的是 multiset不去重但是排序
//	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
//	auto it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << endl;
//	//	++it;
//	//}
//	int x;
//	cin >> x;
//	//x可能存在多个，find查找中序的第一个
//	auto pos = s.find(x);
//	while (pos != s.end() && *pos == x)
//	{
//		cout << *pos << endl;
//		++pos;
//	}
//	cout << endl;
//	//count会返回x的实际个数
//	cout << s.count(x) << endl;
//	pos = s.find(x);
//	while (pos != s.end() && *pos == x)
//	{
//		pos = s.erase(pos);
//	}
//	cout << endl;
//	s.erase(x);
//	it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	return 0;
//}
int main()
{
	
	map<string,string> dict = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };
	pair<string, string> kv1("first", "第一个");
	dict.insert(kv1);
	dict.insert(pair<string, string>("second", "第二个"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert({ "auto", "自动的xxxx" });
	//插入时只看key value不相等不会更新
	dict.insert({ "auto","自动的" });
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//可以修改value，不可以修改Key
		cout << it->first << (*it).second << endl;
		++it;
	}
	cout << endl;
	return 0;
}