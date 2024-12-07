#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

typedef struct Stack {
    int* arr;
    int x;
    int y;
} ST;

class STack {
public:
    void STInit(ST& phead) {
        phead.arr = NULL;
        phead.x = phead.y = 0;
    }
};

int main() {
    int a = 10;
    int b = 20;
    int c = a + b;
    int& m = c;
    cout << m << endl;
    double x = 12.541;
    int i = static_cast<int>(x);
    cout << i << endl;
    ST st;
    STack stack;
    stack.STInit(st);
    return 0;
}
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//  error C2652: “Date”: 非法的复制构造函数: 第一个参数不应是“Date”
//	// Date d2(d1)
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////void Func1(const Date& d)
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}

//int main()
//{
//	Date d1(2024, 7, 12);
//	d1.Print();
//
//	// C++的规定，传值传参要调用拷贝构造
//	Func1(d1);
//
//	Date d2(d1);
//	d2.Print();
//
//	return 0;
//}
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//
//		// 需要对_a指向资源创建同样大的资源再拷贝值
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2(st1);
//
//	return 0;
//}

//void func1(const Stack& st)
//{
//
//}
//
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	func1(st1);
//
//	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2(st1);
//	Stack st3 = st1;
//
//	MyQueue mq1;
//	// MyQueue自动生成的拷贝构造，会自动调用Stack拷贝构造完成pushst/popst
//	// 的拷贝，只要Stack拷贝构造自己实现了深拷贝，他就没问题
//	MyQueue mq2(mq1);
//
//	return 0;
//}

//Stack& func2(Stack& st)
//{
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//
//	return st;
//}
//
//int main()
//{
//	//Stack ret = func2();
//	Stack st1;
//	func2(st1);
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(A::*PF)(); //成员函数指针类型
//
//int main()
//{
//	// void(A::*pf)() = nullptr;
//	PF pf = nullptr;
//	// C++规定成员函数要加&才能取到函数指针
//
//	pf = &A::func;
//	A aa;
//	(aa.*pf)();
//}


//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d3 = d1
//	/*Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//	}*/
//
//	// 拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// 构造
//	Date(const Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	//d1 + 100;
//	Date operator+(int day);
//
//	//d1 - 100;
//	Date operator-(int day);
//
//	// d1 - d2;
//	int operator-(const Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	// 运算符重载函数可以显示调用
//	//operator==(d1, d2);
//	// 编译器会转换成 operator==(d1, d2);
//	//d1 == d2;
//
//	// 运算符重载函数可以显示调用
//	d1.operator==(d2);
//
//	// 编译器会转换成 d1.operator==(d2);
//	d1 == d2;
//
//	d1 + 100;
//	d1 - 100;
//	d1 - d2;
//
//	return 0;
//}

//int main()
//{
//	// 11：45继续
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	// 赋值重载拷贝
//	d1 = d2;
//
//	// 拷贝构造
//	Date d3(d2);
//	Date d4 = d2;
//
//	d4 = d3 = d1;
//
//	int i, j, k;
//	i = j = k = 1;
//
//	return 0;
//}

#include"Date.h"

void TestDate1()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;
	//Date d3(d1 + 100);
	d1.Print();
	d2.Print();

	//d1 += 100;
	//d1.Print();

	d1 += 30000;
	d1.Print();
}

void TestDate2()
{
	/*Date d1(2024, 7, 13);
	d1 -= 30000;
	d1.Print();*/

	Date d1(2024, 7, 13);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2024, 7, 13);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void TestDate3()
{
	Date d1(2024, 7, 12);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void TestDate4()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 31);

	cout << d1 - d2 << endl;
}

void TestDate5()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

	cout << d1 - d2 << endl;

	//cout << d1;
	//operator<<(cout, d1);

	//cout << d1 << d2;

	// 倒反天罡
	//d1 << cout;
	//d1.operator<<(cout);
}

void TestDate6()
{
	const Date d1(2024, 7, 13);
	d1.Print();

	Date d2(2024, 7, 13);
	d2.Print();

	cout << &d1 << endl;
	cout << &d2 << endl;
}

//int main()
//{
//	TestDate6();
//
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
public:
	//explicit A(int a = 0)
	A(int a = 0)
	{
		_a1 = a;
	}

	A(const A& aa)
	{
		_a1 = aa._a1;
	}

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1;
	int _a2;
};

class Stack
{
public:
	void Push(const A& aa)
	{
		//...
	}
private:
	A _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// 隐式类型转换
	// 2构造一个A的临时对象，再用这个临时对象拷贝构造aa2
	// 编译器遇到连续构造+拷贝构造->优化为直接构造
	A aa2 = 2;
	aa2.Print();

	A& raa1 = aa2;
	const A& raa2 = 2;

	int i = 1;
	double d = i;
	const double& rd = i;

	Stack st;

	A aa3(3);
	st.Push(aa3);

	st.Push(3);

	// C++11
	A aa5 = { 1, 1 };
	const A& raa6 = { 2,2 };
	st.Push(aa5);
	st.Push({ 2,2 });

	return 0;
}
