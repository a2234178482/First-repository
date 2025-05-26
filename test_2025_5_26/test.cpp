#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <assert.h>
using namespace std;
struct Point
{
	int _x;
	int _y;
};
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
template<class T>
void func(const T& x) {};

void f(int& x)
{
	std::cout << "左值引用重载f(" << x << ")" << endl;
}
void f(const int& x)
{
	std::cout << "到const的左值引用重载f(" << x << ")" << endl;
}
void f(int&& x)
{
	std::cout << "右值引用重载f(" << x << ")" << endl;
}
int main()
{
	int a1[] = { 1,2,3,4,5 };
	int a2[5] = {};
	//Point p = { 1,2 };

	int x1 = { 1 };
	int x2 = 2;
	//自定义类型支持
	//这里本质是用{2025,1,1}构造一个Date临时对象
	//临时对象再去拷贝构造d1,编译器后话后合二为一变成{2025,1,1}直接构造初始化d1
	Date d1 = { 2025,1,1 };
	Date d20{ 2025,1,1 };
	//这里d2引用的是{2024,6,3}构造的临时对象
	const Date& d2 = { 2024,6,3 };
	//c++98支持单参数类型转换，也可以不用{}
	Date d3 = { 2025 };
	Date d4 = 2025;
	string str = "111";

	//只有{}初始化时才可以省略=
	Point p1{ 1,2 };
	int x4{ 2 };
	Date d6{ 2024,5,26 };
	const Date& d8{ 2024,5,26 };
	vector<Date> v;
	v.push_back(d1);
	v.push_back(Date(2025, 5, 25));
	//比起有名对象和匿名对象传参，{}更方便
	v.push_back({ 2025,1,1 });
	map<string, string> dict;
	dict.insert({ "xxx","yyyy" });
	//构造+拷贝构造+优化
	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2 = { 1,34,155,626,764,6,7,8,23,1 };
	
	vector<int> v1{ 1,2,4,5 };
	const vector<int>& v4{ 10,230,4393,49 };
	vector<int> v3({ 1,2,3,4 });
	initializer_list<int> ill = { 10,20,2,3,0,4,7,545,5,5,4,5,5,100 };
	int aa1[] = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	//initializer_list+{}pair初始化隐式类型转换
	map<string, string> dict = { {"xxx","sfsfs"},{"sort","zzzz"} };

	//左值：可以取地址
	int* p = new int(0);
	int b = 1;
	const int c = b;
    *p =10;
	string s("111111");
	s[0] = 'x';
	cout << &c << endl;
	cout << (void*)&s[0] << endl;
	//左值引用就是给左值取别名
	int& r1 = b;
	int*& r2 = p;	
	int& r4 = *p;
	string& r4 = s;
	char& r5 = s[0];

	//右值：不能取地址
	double x = 1.1, y = 2.2;
	//以下都是常见的右值
	//10;
	//x+y;
	//fmin(x,y);
	//string("111");
	//cout << &10 << endl;
	//cout << &(x + y) << endl;
	//cout << &(fmin(x, y)) << endl;
	//cout << &string("1111") << endl;

	////右值引用给右值取别名
	//int&& r1 = 10;
	//double&& rr2 = x + y;
	//double&& r4 = fmin(x, y);
	//string&& rr5 = string("1111");

	////左值引用不能直接引用右值，但是const左值可以引用右值
	//const int& rx1 = 10;
	//const double& rx2 = x + y;
	//const double& rx3 = fmin(x, y);
	//const string& rx4 = string(" 1111");

	////右值引用不能直接引用左值，但是右值引用可以引用move(左值）
	//int&& rx1 = move(b);
	//int*&& tx2 = move(p);
	//int&& rx4 = move(*p);
	//string&& rrx4 = move(s);
	//string&& rrx5 = (string&&)s;
	////右值引用引用move(左值）后，变量就变成了左值
	//cout << &rx1 << endl;
	//cout << &tx2 << endl;
	////rx1的属性是左值，所以不能再被右值引用绑定，除非move一下
	//int& r5 = r1;
	//int&& rrx6 = move(r1);

	int i = 1;
	const int ci = 2;
	f(i); //调用f(int&)
	f(ci);//调用f(const int&)
	f(3); //调用f(int&&),如果没有f(int&&)重载则会调用f(const int&)
	f(std::move(i)); //调用f(int&&)
	//右值引用变量用于表达式时是左值
	//右值引用本身属性是左值
	int&& x = 1;
	f(x); //调用f(int&)
	f(std::move(x));//调用f(int&&)
}
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
		//string(string&& s)
		//{
		//	cout << "string(string&& s) -- 移动构造" << endl;
		//	// 转移掠夺你的资源
		//	swap(s);
		//}

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
int main()
{
	niuma::string ret;
	Solution s;
	ret = s.addStrings("11111", "2222222");
	cout << ret.c_str() << endl;
	return 0;
}
