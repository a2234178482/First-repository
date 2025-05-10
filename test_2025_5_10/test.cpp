#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
struct A
{
public:
	A(int a1 = 1, int a2 = 2)
		:_a1(a1),
		_a2(a2)
	{}
	A(const A& aa)
		:_a1(aa._a1),
		_a2(aa._a2)
	{
	}
private:
	int _a1;
	int _a2;
};
void test()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	auto it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << "";
		++it;
	}
	cout << endl;
	for (auto e : lt)
	{
		cout << e << endl;
	}
	cout << endl;
	sort(lt.begin(), lt.end());//不支持，要随机迭代器才行
	list<A> lt;
	A aa1(1, 1);
	lt.push_back(aa1);

}


class Solution {
public:
	string reverseWords(string s) {
		int length = s.length();
		int i = 0;
		while (i < length)
		{
			int start = i;
			while (i < length && s[i] != ' ')
			{
				i++;
			}
			std::reverse(s.begin() + start, s.begin() + i - 1);
			while (i < length && s[i] != ' ')
			{
				i++;
			}

		}
	}
};