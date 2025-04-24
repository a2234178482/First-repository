#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream> 
#include <algorithm>
using namespace std;
class Time {
public:
	Time(int hour)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};
class Date {
public:
	Date(int& re, int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		, _n(1) //必须初始化常量限定类型的对象
		, _ret(re) //引用必须初始化
		, _t(1)
		//如果在Time类中，_hour没有缺省值，那么就没有合适的默认构造，所以要用初始化列表初始
		, _p((int*)malloc(12))
	{
		if (_p == nullptr) {
			perror("1");
		}
		else {
			memset(_p, 0, 12);
		}
	}
		void Print() const {
			cout << _year << _month << _day << endl;
		}
private:
	int _year;
	int _month;
	int _day;
	const int _n;
	int& _ret;
	Time _t;
	int* _p;
//private:
//	//声明 缺省值是初始化列表用的，如果显式传参，和缺省值无关
//	int _year = 1;
//	int _month = 1;
//	int _day;
//	Time _t = 1;
//	int* _p = (int*)malloc(12);
};
class A {
public:
	A(int a = 0){}
	void Print() {
		cout << _a1 << "" << _a2 << endl;
	}
private:
	int _a2 = 2;
	int _a1 = 2;
};
class B {
public:
	B() {
		++_count;
	}
	B(const B& b) {
		++_count;
	}
	~B() {
		--_count;
	}
	static int Getcount() {
		return _count;
	}
	void func() {
		cout << _count << endl;
		cout << Getcount() << endl;
	}
private:
    //类里面声明
	static int _count;
};
int B::_count = 1;//；类外面初始化
class D;
class C {
	friend void func(const C& cc, const D& dd);
private:
	int _a1 = 1;
	int _a2 = 2;
};
class D {
	friend void func(const C& cc, const D& dd);//友元声明，友元关系是单向的
private:
	int _d1 = 3;
	int _d2 = 4;
};
void func(const C& cc, const D& dd) {
	cout << cc._a1 << endl;
	cout << dd._d1 << endl;
}
//内部类
class E {
private:
	static int _k;
	int _a = 1;
public:
	class F { //默认F是E的友元
	public:
		void func(const E& e) {
			cout << _k << endl;
			cout << e._a << endl;
		}
	private:
		int _b = 1;
	};
};
int E::_k = 1;
//class Sum {
//public:
//	Sum() {
//		_re += _i;
//		++_i;
//		++_re;
//	 }
//	int Get() {
//		return _re;
//	}
//private:
//	int _i = 1;
//	int _re = 0;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		Sum a[n];
//		return Sum::Get();  //非静态函数不能通过类名调用，必须通过对象调用非静态成员函数
//	}
//};
class Sum {
public:
	Sum() {
		_re += _i;
		++_i;
	}
	static int Get() {
		return _re;
	}
private:
	static int _i;
	static int _re;
};
int Sum::_i = 1;
int Sum::_re = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		Sum a[n];
		return Sum::Get();
	}
};
int main() {
	int x = 0;
	Date d1(x, 2024, 7, 14);
	d1.Print();
	A aa;
	aa.Print();
	cout << B::Getcount() << endl;
	B a1, a2;
	{
		B a3(a1);
		cout << B::Getcount() << endl;
	}
	cout << B::Getcount() << endl;
	C cc;
	D dd;
	func(cc, dd);
	A aa1; //有名对象
	A();//匿名对象 生命周期只在当前这一行
	int a[] = { 1,34,41,513,5165,2461,134 };
	sort(a, a + 7);
	greater<int> gt;
	sort(a, a + 7, gt);
}