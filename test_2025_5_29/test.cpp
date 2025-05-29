#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<assert.h>
using namespace std;

struct Point
{
	int _x;
	int _y;
};

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// C++98支持的
//	int a1[] = { 1, 2, 3, 4, 5 };
//	int a2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	// C++11支持的
//	// 内置类型支持
//	int x1 = { 2 };
//	int x2 = 2;
//
//	// 自定义类型支持
//	// 这里本质是用{ 2025, 1, 1}构造一个Date临时对象
//	// 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化d1
//	// 运行一下，我们可以验证上面的理论，发现是没调用拷贝构造的
//	Date d1 = { 2025, 1, 1 };
//	Date d20(2025, 1, 1);
//
//	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
//	const Date& d2 = { 2024, 7, 25 };
//
//	// 需要注意的是C++98支持单参数时类型转换，也可以不用{}
//	Date d3 = { 2025 }; // C++11
//	Date d4 = 2025;     // C++98
//	string str = "1111";
//
//	// 可以省略掉=
//	Point p1{ 1, 2 };
//	int x3{ 2 };
//	Date d6{ 2024, 7, 25 };
//	const Date& d7{ 2024, 7, 25 };
//
//	// 不支持，只有{}初始化，才能省略=
//	// Date d8 2025;
//
//	vector<Date> v;
//	v.push_back(d1);
//	v.push_back(Date(2025, 1, 1));
//	// 比起有名对象和匿名对象传参，这里{}更有性价比
//	v.push_back({ 2025, 1, 1 });
//	map<string, string> dict;
//	dict.insert({ "xxx", "yyyy" });
//
//	// 构造+拷贝构造+优化
//	//vector<int> v1 = { 1,2,3,4 };
//	//vector<int> v2 = { 10,20,30,1,1,1,1,1,1,1,1,1};
//	//const vector<int>& v4 = { 10,20,30,1,1,1,1,1,1,1,1,1 };
//
//	vector<int> v1{ 1,2,3,4 };
//	vector<int> v2{ 10,20,30,1,1,1,1,1,1,1,1,1 };
//	const vector<int>& v4 { 10,20,30,1,1,1,1,1,1,1,1,1 };
//
//	// 构造
//	vector<int> v3({ 10,20,30,1,1,1,1,1,1,1,1,1 });
//
//	initializer_list<int> il1 = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//	int aa1[] = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
//
//	// initializer_list + {}pair初始化隐式类型转换
//	map<string, string> dict = { { "xxx", "yyyy" }, { "sort", "zzzz" } };
//
//	return 0;
//}

//template<class T>
//void func(const T& x)
//{}
//
//int main()
//{
//	// 左值：可以取地址
//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//
//	cout << &c << endl;
//	cout << (void*)&s[0] << endl;
//
//	// 左值引用给左值取别名
//	int& r1 = b;
//	int*& r2 = p;
//	int& r3 = *p;
//	string& r4 = s;
//	char& r5 = s[0];
//
//	// 右值：不能取地址
//	double x = 1.1, y = 2.2;
//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//
//	//cout << &10 << endl;
//	//cout << &(x+y) << endl;
//	//cout << &(fmin(x, y)) << endl;
//	//cout << &string("11111") << endl;
//
//	// 右值引用给右值取别名
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	string&& rr4 = string("11111");
//
//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	const int& rx1 = 10;
//	const double& rx2 = x + y;
//	const double& rx3 = fmin(x, y);
//	const string& rx4 = string("11111");
//
//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	int&& rrx1 = move(b);
//	int*&& rrx2 = move(p);
//	int&& rrx3 = move(*p);
//	string&& rrx4 = move(s);
//	string&& rrx5 = (string&&)s;
//
//	// b、r1、rr1都是变量表达式，都是左值
//	cout << &b << endl;
//	cout << &r1 << endl;
//	cout << &rr1 << endl;
//
//	int i = 1;
//	int* ptr = (int*)i;
//
//	// int&& rr1 = 10;
//	// 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
//	int& r6 = rr1;
//
//	//int&& rrx6 = rr1;
//	int&& rrx6 = move(rr1);
//
//	return 0;
//}

//template<class T>
//void func(const T& x)
//{}

//void f(int& x)
//{
//	std::cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//
//void f(int&& x)
//{
//	std::cout << "右值引用重载 f(" << x << ")\n";
//}
//
//int main()
//{
//	/*int&& rr1 = 10;
//	int a = 20;
//	int& r2 = a;*/
//
//	int i = 1;
//	const int ci = 2;
//
//	f(i); // 调用 f(int&)
//	f(ci); // 调用 f(const int&)
//	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)
//	f(std::move(i)); // 调用 f(int&&)
//
//	// 右值引用变量在用于表达式时是左值
//	// 右值引用本身的属性是左值
//	int&& x = 1;
//	f(x); // 调用 f(int& x)
//	f(std::move(x)); // 调用 f(int&& x)
//
//	return 0;
//}

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
		char* _str = new char('\0');
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

//int main()
//{
//	niuma::string ret;
//	// ...
//
//	ret = Solution().addStrings("11111111111111111111", "222222222222222222222222222");
//	cout << ret.c_str() << endl;
//	//cout << &ret<< endl;
//
//	return 0;
//}

//int main()
//{
//	//string ret = Solution().addStrings("11111111111111111111", "222222222222222222222222222");
//	//cout << ret << endl;
//
//	niuma::string s1("11111111111111111");
//
//	niuma::string s3 = s1;
//	niuma::string s4 = niuma::string("222222222");
//	niuma::string s5 = move(s1);
//
//	return 0;
//}

//int main()
//{
//	const niuma::string& lr = niuma::string("111111");
//	niuma::string&& rr = niuma::string("111111");
//	cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
//
//	return 0;
//}

//class Solution {
//public:
//	// 这里的传值返回拷贝代价就太大了
//	/*vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			vv[i].resize(i + 1, 1);
//		}
//		for (int i = 2; i < numRows; ++i)
//		{
//			for (int j = 1; j < i; ++j)
//			{
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//			}
//		}
//		return vv;
//	}*/
//
//	void generate(int numRows, vector<vector<int>>& vv) {
//		vector<vector<int>> vv(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			vv[i].resize(i + 1, 1);
//		}
//		for (int i = 2; i < numRows; ++i)
//		{
//			for (int j = 1; j < i; ++j)
//			{
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//			}
//		}
//	}
//};

//int main()
//{
//	vector<vector<int>> ret = Solution().generate(100);
//	vector<vector<int>> ret;
//	Solution().generate(100, ret);
//
//	/*niuma::string ret;
//	Solution().addStrings("1111111", "222222", ret);*/
//
//	return 0;
//}
//
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	niuma::string ret = Solution().addStrings("11111111111111111111", "222222222222222222222222222");
//	cout << ret.c_str() << endl;
//
//	vector<vector<int>> ret = Solution().generate(100);
//
//	return 0;
//}

// 由于引用折叠限定，f1实例化以后总是一个左值引用
//template<class T>
//void f1(T& x)
//{}
//
//// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{}
//
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//
//	// 引用折叠
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	//f1<int>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	//f1<int&>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	//f1<int&&>(0); // 报错
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//
//	// 没有折叠->实例化为void f2(int&& x)
//	//f2<int>(n); // 报错
//	f2<int>(0);
//
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	//f2<int&>(0); // 报错
//
//	// 折叠->实例化为void f2(int&& x)
//	//f2<int&&>(n); // 报错
//	f2<int&&>(0);
//
//	return 0;
//}

// 万能引用 
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	//Function(10);
//
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	//Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	//Function(std::move(a));
//
//	const int b = 8;
//	// b是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
//	// 所以Function内部会编译报错，x不能++
//	//Function(b);    // const 左值
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//template < class T>
//void Function(T&& t)
//{
//	Fun(forward<T>(t));
//}
//
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//
//	const int b = 8;
//	// a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int&t)
//	Function(b);
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
//	Function(std::move(b)); // const 右值
//
//	return 0;
//}

//#include<list>
//#include"List.h"

//int main()
//{
//	niuma::list<niuma::string> lt;
//	niuma::string s1("11111111111");
//	lt.push_back(s1);
//
//	niuma::string s2("33333333333");
//	lt.push_back(move(s2));
//
//	lt.push_back("22222222222");
//
//	return 0;
//}

//template <class ...Args>
//void Print(Args&&... args)
//{
//	// 不支持
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		// 不支持
//		cout << args[i] << " ";
//	}
//	cout << endl;
//}

//template <class ...Args>
//void Print(Args&&... args)
//{
//	// 不支持
//	for (auto&& e : args...)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

// 包扩展（解析出参数包的内容）
//void ShowList()
//{
//	// 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T&& x, Args&&... args)
//{
//	// 运行时
//	/*if (sizeof...(args) == 0)
//		return;*/
//
//	cout << x << " ";
//	// args是N个参数的参数包
//	// 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//	ShowList(args...);
//}

//template <class ...Args>
//void Print(Args&&... args)
//{
//	ShowList(args...);
//}


////////////////////////////////////////////////////////////
// 包扩展
//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}

template <class T>
int GetArg(const T& x)
{
	cout << x << " ";
	return 0;
}

template <class ...Args>
void Arguments(Args... args)
{
}

template <class ...Args>
void Print(Args... args)
{
	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
	//Arguments(GetArg(args)...);
}

//void Print(int x, string y, double z)
//{
// Arguments(GetArg(x), GetArg(y), GetArg(z));
//}

//int main()
//{
//	double x = 2.2;
//	Print(); // 包里有0个参数
//	Print(1); // 包里有1个参数
//	Print(1, string("xxxxx")); // 包里有2个参数
//	Print(1.1, string("xxxxx"), x); // 包里有3个参数
//
//	return 0;
//}

//int main()
//{
//	list<niuma::string> lt;
//	// 传左值，跟push_back一样，走拷贝构造
//	niuma::string s1("111111111111");
//	niuma::string s2("111111111111");
//
//	lt.emplace_back(s1);
//	cout << "*********************************" << endl;
//
//	lt.push_back(s1);
//	cout << "*********************************" << endl;
//
//	// 右值，跟push_back一样，走移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//
//	lt.push_back(move(s2));
//	cout << "*********************************" << endl;
//	
//	lt.emplace_back("111111111111");
//	cout << "*********************************" << endl;
//
//	// 直接传参，隐式类型转换
//	lt.push_back("111111111111");
//	cout << "*********************************" << endl;
//
//	return 0;
//}

//int main()
//{
//	niuma::list<pair<niuma::string, int>> lt1;
//	// 跟push_back一样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<niuma::string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	cout << "*********************************" << endl;
//
//	// 21:15
//	// 跟push_back一样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//
//	// 这里达到的效果是push_back做不到的
//	//lt1.emplace_back({ "苹果", 1 }); // 不支持
//	lt1.emplace_back("苹果", 1 ); // 
//	cout << "*********************************" << endl;
//
//	lt1.push_back({ "苹果", 1 });
//	cout << "*********************************" << endl;
//
//	return 0;
//}

//int main()
//{
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 2) << endl;
//
//	// 1、捕捉为空也不能省略
//	// 2、参数为空可以省略
//	// 3、返回值可以省略，可以通过返回对象自动推导
//	// 4、函数体不能省略
//	auto func1 = []
//	{
//		cout << "hello niuma" << endl;
//		return 0;
//	};
//
//	func1();
//
//	return 0;
//}

#include<algorithm>

struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	// ...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{
	}
};

struct Compare1
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct Compare2
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//
//	// 价格升序
//	//sort(v.begin(), v.end(), Compare1());
//
//	// 价格降序
//	//sort(v.begin(), v.end(), Compare2());
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price;});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}
//int y = 0;
//auto func2 = []()
//{
//		y++;
//};
//int main()
//{
//	//只能用当前lambda局部域和捕捉的对象和全局对象
//	int a = 0, b = 1, c = 2, d = 3;
//	auto func1 = [a, &b](int x)mutable
//	{
//			//值捕捉的变量不能修改，加了mutable可以修改，引用捕捉的变量可以修改
//			a++;
//			b++;
//			int ret = a + b + x + y;
//			return ret;
//	};
//	cout << func1(1) << endl;
//
//	//隐式值捕捉
//	//用了哪些变量就捕捉哪些变量
//	auto func2 = [=]
//	{
//			int ret = a + b + c;
//			return ret;
//	};
//	cout << func2() << endl;
//
//	//隐式引用捕捉
//	//用了哪些变量就捕捉哪些变量
//	auto func3 = [&]
//	{
//			a++;
//			c++;
//			d++;
//	};
//	func3();
//	cout << a << c << d << endl;
//
//	//混合捕捉
//	auto func4 = [&,a,b]
//	{
//			//a++;
//			//b++;
//			c++;
//			d++;
//	};
//	func4();
//	cout <<  a  <<   b  <<  c <<  d << endl;
//
//}
class Rate
{
public:
	Rate(double rate)
		:_rate(rate)
	{ }
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};
//int main()
//{
//	double rate = 0.49;
//	auto r2 = [rate](double money, int year) {
//		return money * rate * year;
//	};
//	Rate r1(rate);
//	r1(10000, 2);
//	r2(100000, 2);
//	auto func1 = [] {cout << "hello world" << endl; };
//	func1();
//	return 0;
//}
class Person
{
public:
	Person(const char* name = "张三", int age = 1)
		:_name(name)
		, _age(age)
	{
	}

	Person(const Person& p) = default;
	Person(Person&& p) = default;

	~Person()
	{
	}
private:
	niuma::string _name;
	int _age;
};
void func(ostream& out) {};
//int main()
//{
//	Person s1;
//	Person s2 = std::move(s1);
//	func(cout);
//	return 0;
//}
#include <functional>
int f(int a, int b)
{
	return a + b;
}
struct Functor
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
class Plus
{
public:
	Plus(int n = 10)
		:_n(n)
	{ }
	static int plusi(int a, int b)
	{
		return a + b;
	}
	double plusd(double a, double b)
	{
		return a + b * _n;
	}
private:
	int _n;
};
//int main()
//{
//	//包装各种可调用对象
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//
//	//(*Fptr)(1, 2);
//	//包装静态成员函数
//	//成员函数要指定类域
//	function<int(int, int)> f4 = &Plus::plusi;
//	Plus p1;
//	cout << f4(1,1) << endl;
//	function<double(Plus*, double, double)> f5 = &Plus::plusd;
//	cout << f5(&p1, 1.111, 1.1) << endl;
//
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	cout << f6(Plus(), 1.1, 1.1) << endl;
//
//	function<double(Plus&&, double, double)> f7 = &Plus::plusd;
//	cout << f7(move(p1), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 1.1, 1.1) << endl;
//	map<string, function<int(int, int)>> opFuncMap = {
//		{"+",[](int x ,int y) {return x + y; }},
//		{"-",[](int x ,int y) {return x - y; }},
//		{"*",[](int x ,int y) {return x * y; }},
//		{"/",[](int x ,int y) {return x / y; }}
//	};
//}
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;
int Sub(int a, int b)
{
	return (a - b) * 10;
}
int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}
int main()
{
	auto sub1 = bind(Sub, _1, _2);
	cout << sub1(10, 5) << endl;

	auto sub2 = bind(Sub, _2, _1);
	cout << sub2(10, 5) << endl;

	//调整参数个数（常用）
	auto sub3 = bind(Sub, 100, _1);
	cout << sub3(5) << endl;

	auto sub4 = bind(Sub, _1, 100);
	cout << sub4(5) << endl;

	//分别绑死第1,2,3个参数
	auto sub5 = bind(SubX, 100, _1, _2);
	auto sub6 = bind(SubX, _1, 100, _2);
	auto sub7 = bind(SubX, _1, _2, 100);
	cout << sub5(5, 1) << "  " << sub6(5, 1) << "  " << sub7(5, 1) << endl;

	//成员函数对象进行绑死，就不需要每次都传递了
	//function<double(Plus&&, double, double)> f6 = &Plus::plusd;
	//Plus pd;
	//cout << f6(move(pd), 1.1, 1.1) << endl;
	//cout << f6(Plus(), 1.1, 1.1) << endl;
	function<double(double, double)> f6 = bind(&Plus::plusd, Plus(), _1, _2);
	cout << f6(1.1, 1.1) << endl;

	//计算复利的lambda
	auto func1 = [](double rate, double money, int year)->double {
		double ret = money;
		for (int i = 0; i < year; i++)
		{
			ret += ret * rate;
		}
		return ret - money;
	};
	cout << func1(0.05, 10000000000, 30) << endl;
	//绑死一些参数，实现出支持不同年化利率，不同金额和不同年份计算出复利的结算利息
	function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
	function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
	function<double(double)> func10_1_5 = bind(func1, 0.015, _1, 10);

	function<double(double)> func3_2_5 = bind(func1, 0.025, _1, 3);
	function<double(double)> func5_2_5 = bind(func1, 0.025, _1, 5);
	function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);

	cout << func3_1_5(1000000) << endl;
	cout << func5_1_5(1000000) << endl;
	cout << func10_1_5(1000000) << endl;

	cout << func3_2_5(1000000) << endl;
	cout << func5_2_5(1000000) << endl;
	cout << func10_2_5(1000000) << endl;
	return 0;
}