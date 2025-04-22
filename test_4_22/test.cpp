#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Date {
public:
	Date(int year,int month ,int day) {
		_year = year;
		_month = month ;
		_day = day;
	}
	//拷贝构造函数的第一个形参必须是类类型对象的引用
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Stack {
public:
	Stack(int n = 4) {
		_a = (int*)malloc(sizeof(int) * n);
		if (nullptr == _a) {
			perror("1");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	Stack(const Stack& st) {
		cout << "Stack(const Stack& st)" << endl;
		//需要对_a指向的资源申请同样大的资源再进行值拷贝
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (nullptr == _a)
		{
			perror("1");
			return;
		}
		memcpy(_a, st._a, sizeof(int) * st._top);
		_capacity = st._capacity;
		_top = st._top;
	}
	void Push(int x) {
		if (_top == _capacity) {
			int newcapacity = _capacity * 2;
			int* tmp = (int*)realloc(_a, newcapacity * sizeof(int));
			if (tmp == NULL) {
				perror("1");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}
	~Stack() {
		cout << "~Stack" << endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int *_a;
	int _top;
	int _capacity;
};
//两个栈实现队列
class MYqueue {
public:
private:
	Stack push;
	Stack pop;
};
void F(Date& d1) {
	cout << &d1 << endl;
	d1.Print();
}
class A {
public:
	void Print() {
		cout << "A::Print()" << endl;
	}
};
typedef void(A::* PF)();
class cac {
public:
	cac(int year = 1, int  month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	cac(const cac& c) {
		_year = c._year;
		_month = c._month;
		_day = c._day;
	}
	void Print() {
		cout << _year << "" << _month << "" << _day << endl;
	}
	bool operator==(const cac& c1) {
		return _year == c1._year &&
			_month == c1._month &&
			_day == c1._day;
	//c2 +100
	//	cac operator+(int day);
	//c2 -100
	// cac operator-(int day)
	// int operator-(const cac& c4)
	// c2 -c3
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1(2025, 4, 22);
	d1.Print();
	//传值传参要调用拷贝构造
	Date d2(d1);
	d2.Print();
	Date d3 = d2;
	Stack st;
	st.Push(1);
	st.Push(2);
	//Stack不显示拷贝构造，用自动生成的拷贝构造完成浅拷贝会导致st 和 st1里面的_a指向同一块资源，析构函数运行时会析构两次，导致程序崩溃
	Stack st1(st);

	MYqueue mq1;
	MYqueue mq2;
	//MYqueue自动生成的拷贝构造，会调用Stack拷贝构造push pop的拷贝，只要Stack拷贝构造自己完成了深拷贝，就没问题
	void (A:: * pf)() = nullptr;
	PF pf = nullptr;
	//成员函数要加&才能取到函数指针
	pf = &A::Print;
	A a;
	(a.*pf)(); 
}