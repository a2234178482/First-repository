#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

//void func1(int& x)
//{
//	x++;
//}
//
////int& func2()
////{}
//
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//
//	func1(a);
//
//	int& b = a;
//	int& c = b;
//
//	int d = 20;
//	b = d;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &d << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<assert.h>
//
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//
//void STModityTop(ST& rs, int x)
//{
//	rs.a[rs.top-1] = x;
//}
//
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top-1];
//}
//
//int& func()
//{
//	int a = 0;
//	return a;
//}
//
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//
//	STModityTop(st1, 3);
//
//	STTop(st1) = 4;
//
//	/*vector<int> v;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		v[i] = i;
//	}*/
//	//operator[]
//	
//
//	return 0;
//}

// 函数模版，T可以任意类型
//template<class T>
//void func(const T& val)
//{
//
//}

//void func(const int& val)
//{
//
//}
//
//int main()
//{
//	const int a = 10;
//	//int rd = a;
//	//int& ra = a;
//
//	const int& ra = a;
//
//	// 引用的时候权限可以缩小，但是不能放大
//	int b = 20;
//	const int& rb = b;
//	b++;
//	//rb++;
//
//	const int& rc = 30;
//	const int& rd = (a + b);
//
//	double d = 12.34;
//	int i = d;
//	const int& ri = d;
//	//double& rd = d;
//
//	func(a);
//	func(b);
//	func(30);
//	func(a+b);
//	func(d);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int* p = &a;
//	*p = 1;
//
//	int& ra = a;
//	ra = 2;
//
//	// 空引用
//	int* ptr = NULL;
//	int& rb = *ptr;
//	rb++;
//
//	const int& rc = a + 2;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////
// inline

// 实现一个ADD宏函数的常见问题
//#define ADD(int a, int b) return a + b;
//#define ADD(a, b) a + b;
//#define ADD(a, b) (a + b)

// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 为什么不能加分号?
//// 为什么要加外面的括号?
//// 为什么要加里面的括号?
//
//int main()
//{
//	int ret = ADD(1, 2); // int ret = ((1)+(2));
//	cout << ADD(1, 2) << endl;
//
//	cout << ADD(1, 2) * 5 << endl;
//
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y+x|y)
//
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//
//	return ret;
//}
//
//#include"F.h"
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	cout << ret << endl;
//
//	f(10);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	//f((void*)0);
//
//	f(nullptr);
//
//	// C++
//	void* p1 = NULL;
//	int* p2 = (int*)p1;
//
//	int* p2 = nullptr;
//	//int i = nullptr;
//
//	return 0;
//}

#include<iostream>
using namespace std;

//class Queue
//{
//public:
//	void Push(int x)
//	{}
//};

//class Stack
//{
//public:
//	void Push(int x)
//	{}
////public:
//	void Pop()
//	{}
//
//	int Top()
//	{
//		return 0;
//	}
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Pop();
//	st.Push(1);
//	//st.a;
//
//	return 0;
//}

// class Date
struct Date
{
public:
	void Init(int year, int month, int day);

	//private:
		// 为了区分成员变量，一般习惯上成员变量
		// 会加一个特殊标识，如_ 或者 m开头
		// 声明
	int _year; // year_ m_year
	int _month;
	int _day;
};

void Date::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 兼容C的struct用法
typedef struct ListNodeC
{
	int val;
	struct ListNodeC* next;
}LTNodeC;

// CPP
struct ListNodeCPP
{
	int val;
	ListNodeCPP* next;
};

int main()
{
	Date d2;
	Date d3;

	d2.Init(2024, 7, 9);

	struct Date d1;

	ListNodeCPP node;

	//Date::_year = 2024;

	return 0;
}