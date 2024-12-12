#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <algorithm> 
using namespace std;

//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int& xx, int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_n(1)
//		,_ref(xx)
//		,_t(1)
//		,_ptr((int*)malloc(12))
//	{
//		if (_ptr == nullptr)
//		{
//			perror("malloc fail");
//		}
//		else
//		{
//			memset(_ptr, 0, 12);
//		}
//	}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	// 声明
//	int _year;
//	int _month;
//	int _day;
//
//	// error C2512: “Time”: 没有合适的默认构造函数可用
//	// error C2530 : “Date::_ref” : 必须初始化引用
//	// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	const int _n;
//	int& _ref;
//	Time _t;
//
//	int* _ptr;
//};
//
//int main()
//{
//	int x = 0;
//	// 对象定义
//	Date d1(x, 2024, 7, 14);
//	d1.Print();
//
//	//const int x = 1;
//	// x = 1;
//
//	//int& rx;
//
//	return 0;
//}


//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//	{}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	// C++11
//	// 声明，缺省值->初始化列表用的
//	int _year = 1;
//	int _month = 1;
//	int _day;
//
//	int* _ptr = (int*)malloc(12);
//	Time _t = 1;
//};
//
//int main()
//{
//	// 对象定义
//	Date d1(2024, 7, 14);
//	d1.Print();
//
//	//Date d2;
//	//d2.Print();
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//
//int main()
//{
//	A aa;
//
//	aa.Print();
//}


//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t)
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;
//	}
//
//	static int GetACount()
//	{
//		//_a++;
//		return _scount;
//	}
//
//	void func()
//	{
//		cout << _scount << endl;
//		cout << GetACount() << endl;
//	}
//
//private:
//	// 类里面声明
//	static int _scount;
//
//
//	int _a = 1;
//};
//
//// 类外面初始化
//int A::_scount = 0;
//
//int main()
//{
//	//cout << A::_scount << endl;
//	//cout << sizeof(A) << endl;
//
//	cout << A::GetACount() << endl;
//	A a1, a2;
//
//	{
//		A a3(a1);
//		cout << A::GetACount() << endl;
//	}
//
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//
//	return 0;
//}

// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//
//class A
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//
//	return 0;
//}

//class A
//{
//	// 友元声明
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	void func1(const A& aa)
//	{
//		cout << aa._a1 << endl;
//		cout << _b1 << endl;
//	}
//
//	void func2(const A& aa)
//	{
//		cout << aa._a2 << endl;
//		cout << _b2 << endl;
//	}
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _k << endl; //OK
//			cout << a._h << endl; //OK
//		}
//	private:
//		int _b = 1;
//	};
//};
//int A::_k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//
//	A aa;
//	b.foo(aa);
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};

bool myfunction(int i, int j) { return (i > j); }

int main()
{
	A aa1;  //有名对象

	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
	//A aa2();

	// 生命周期只在当前一行
	A(); // 匿名对象
	A(1);

	Solution st;
	cout << st.Sum_Solution(10) << endl;

	// 为了更方便
	cout << Solution().Sum_Solution(10) << endl;

	int a[] = { 32,71,12,45,26,80,53,33 };
	// < 升序
	sort(a, a + 8);

	// > 降序
	//sort(a, a + 8, myfunction);

	/*greater<int> gt;
	sort(a, a + 8, gt);*/

	sort(a, a + 8, greater<int>());

	return 0;
}