#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <assert.h>
using namespace std;
namespace niuma
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		void swap(string& ss)
		{
			::swap(_str, ss._str);
			::swap(_size, ss._size);
			::swap(_capacity, ss._capacity);
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			// 转移掠夺你的资源
			swap(s);
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
				endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			//cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
					2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}
class Solution {
public:
	// 传值返回需要拷贝
	niuma::string addStrings(niuma::string num1, niuma::string num2) {
		niuma::string str;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		// 进位
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
			int ret = val1 + val2 + next;
			next = ret / 10;
			ret = ret % 10;
			str += ('0' + ret);
		}
		if (next == 1)
			str += '1';
		reverse(str.begin(), str.end());
		//cout << &str << endl;

		return str;
	}
};
class Solution1
{
public:
	//传值返回的拷贝代价太大
	vector<vector<int>> generate(int numsRow)
	{
		vector<vector<int>> vv(numsRow);
		for (int i = 0; i < numsRow; ++i)
		{
			vv[i].resize(i + 1, 1);
		}
		for (int i = 2; i < numsRow; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
	void generate1(int numsRows, vector<vector<int>>& vv)
{
	vector<vector<int>> vv1(numsRows);
	for (int i = 0; i < numsRows; ++i)
	{
		vv1[i].resize(i + 1, 1);
	}
	for (int i = 2; i < numsRows; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv1[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}
};
//void generate(int numsRows, vector<vector<int>>& vv)
//{
//	vector<vector<int>> vv(numsRows);
//	for (int i = 0; i < numsRows; ++i)
//	{
//		vv[i].resize(i + 1, 1);
//	}
//	for (int i = 2; i < numsRows; ++i)
//	{
//		for (int j = 1; j < i; ++j)
//		{
//			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//		}
//	}
//}
//int main()
//{
//	const niuma::string& lr = niuma::string("111111");
//	niuma::string&& rr = niuma::string("111111");
//	cout << "xxxxxxxxxxxxxxx" << endl;
//
//	//vector<vector<int>> ret = Solution1().generate(100);
//	//vector<vector<int>> ret;
//	//Solution1().generate1(100, ret);
//	//niuma::string ret;
//	//Solution().addStrings("111111", "2222222");
//
//	niuma::string ret = Solution().addStrings("1111111", "12314234");
//	cout << ret.c_str() << endl;
//	vector<vector<int>> ret = Solution1().generate(100);
//
//
//	return 0;
//}
//由于引用折叠，f1实例化以后总是一个左值引用
template<class T>
void f1(T& x) {}

//由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
template<class T>
void f2(T&& x) {}

#include "List.h"
#include <list>
//万能引用
template<class T>
void function(T&& t)
{
	int a = 0;
	T x = a;
	x++;
	cout << &a << endl;
	cout << &x << endl;	
}
int main()
{
	//typedef int& lref;
	//typedef int&& rref;
	//int n = 0;
	////引用折叠
	//lref& r1 = n;  //类型 int& 
	//lref&& r2 = n;//类型 int& 
	//rref& r3 = n;//类型 int& 
	////rref&& r4 = n;//类型 int&& 
	////没有折叠->实例化为void f1(int& x)
	//f1<int>(n);
	//f1<int>(0); //报错

	////折叠->实例化为void f1(int& x)
	//f1<int&>(n);
	//f1<int&>(0);

	////折叠->实例化为void f1(int& x)
	//f1<int&&>(n);
	//f1<int&&>(0);

	////折叠 实例化为void f1(const int& x)
	//f1<const int&>(n);
	//f1<const int&>(0);

	////折叠 ->实例化为void f1(const int& x)
	//f1<const int&& >(n);
	//f1<const int&&>(0);

	////没有折叠->实例化为void f2(int&& x)
	//f2<int>(n);
	//f2<int>(0);

	////折叠 ->实例化为void f2(int& x)
	//f2<int& >(n);
	//f2<int&>(0);

	////折叠 ->实例化为void f2(int&& x)
	//f2<int&&>(n);
	//f2<int&&>(0);

	function(10);
	//10是右值，推导出T为int，模版实例化为void function(int&& t)

	int a;
	//a是左值，推导出T为int&，引用折叠，模版实例化为void function(int& t)
	function(a);

	std::move(a); //是右值，推导出T为int，模版实例化为void function(int&& t)
	function(move(a));

	const int b = 8;
	//b是左值，推导出T为const int&,引用折叠，模版实例化为void function(const int& t)
	//function内部编译会出错，因为const常量不支持修改
	function(b);

	//std::move(b) 右值，推导出T为const int ,模版实例化为void function(const int&& t)
	function(std::move(b));

	niumo::list<niuma::string> lt;
	niuma::string s1("111111");
	lt.push_back(s1);
	niuma::string s2("333333");
	lt.push_back(move(s2));
	lt.push_back("222222");
}