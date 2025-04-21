#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//this指针，实例化对象时可以不用取地址
class Date {
public:
	//void Init(Date* const this,int year,int month,int day)
	void Init(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void Print() {
		cout << _year << "" << _month << "" << _day << endl;
	}
private:
	//只是声明
	int _year;
	int _month;
	int _day;
};
class A {
public:
	void Print() {
		cout << this << endl;
		cout << "A::Print()" << endl;
	}
private:
	int _a;
};
class B {
public:
	void Print() {
		cout << "B::Print()" << endl;
	}
private:
	int _a;
};
class day {
public:
	//无参构造函数
	//day() {
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}
	//全缺省构造函数
	day(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	//带参构造函数
	//day(int year, int month, int day) {
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
private:
	int _year;
	int _month;
	int _day;
};
typedef int STdatatype;
class Stack {
public:
	Stack(int n = 4) {
		_a = (STdatatype*)malloc(sizeof(STdatatype) * n);
		if (nullptr == _a) {
			perror("0");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	~Stack(){
		free(_a);
	   _a = nullptr;
	    _top = _capacity = 0;
}
private:
	STdatatype* _a;
	size_t _capacity;
	size_t _top;
};
//两个栈实现队列
class MYqueue {
public:
	//编译器默认生成MYqueue的构造函数调用了Stack的构造，完成两个成员的初始化
	//编译器默认生成MYqueue的析构函数调用了Stack的析构，释放Stack内部的资源
	~MYqueue() {
		cout << "~MYqueue()" << endl;
	}
private:
	Stack push;
	Stack pop;
};
//运算符重载
class Grade {
public:
	Grade(int CH = 8,int MA = 8,int ENG = 5) {
		_CH = CH;
		_MA = MA;
		_ENG = ENG;
	}
	void Print() {
		cout << _CH << "" << _MA << "" << _ENG << endl;
	}
	/*int GetCH() {
		return _CH;
	}*/
	bool operator==(Grade a1) {
		return _CH == a1._CH
			&& _MA == a1._MA
			&& _ENG == a1._ENG;
	}
private:
	int _CH;
	int _MA;
	int _ENG;
};
//bool operator==(Date d1, Date d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
int main() {
	Date d1;
	Date d2;
	d1.Init(2025, 1, 1);
	d1.Print();
	d2.Init(2025, 4, 21);
	d2.Print();
	A a;
	cout << sizeof(a) << endl;
	//运行崩溃，相当于解引用
	A* p = nullptr;
	p->Print();
	//正常运行
	B* p = nullptr;
	p->Print();
	day d2(2024,1,2);
	MYqueue mq;
	Grade a1(10, 10, 10);
	Grade a2(8, 9, 10);
	a1.operator==(a2);
	a1 == a2;
	return 0;
}
