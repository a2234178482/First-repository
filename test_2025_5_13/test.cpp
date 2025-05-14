#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include <array>
using namespace std;
#include "PriorityQueue.h"
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
class DateLess
{
public:
	bool operator()(Date* d1, Date* d2)
	{
		return *d1 < *d2;
	}
};
//int main()
//{
//	niuma::priority_queue<Date> q1;
//	q1.push(Date(2025, 5, 14));
//	q1.push(Date(2025, 5, 15));
//	q1.push(Date(2025, 5, 16));
//	cout << q1.top() << endl;
//	q1.pop();
//	cout << q1.top() << endl;
//	q1.pop();
//	cout << q1.top() << endl;
//	q1.pop();
//	cout << endl;
//	//类类型不支持比较大小也需要自己写仿函数
//	//支持比较大小，但是比较的逻辑不是你想要的，需要自己实现仿函数
//	niuma::priority_queue<Date*, vector<Date*>, DateLess> q2;
//	//niuma::priority_queue<Date*> q2;
//	q2.push(new Date(2025, 5, 11));
//	q2.push(new Date(2025, 5, 15));
//	q2.push(new Date(2025, 5, 16));
//	cout << *q2.top() << endl;
//	q2.pop();
//	cout << *q2.top() << endl;
//	q2.pop();
//	cout << *q2.top() << endl;
//	q2.pop();
//	cout << endl;
//
//	niuma::priority_queue<int*> q3;
//	q3.push(new int(2));
//	q3.push(new int(1));
//	q3.push(new int(3));
//	cout << *q3.top() << endl;
//	q3.pop();
//	cout << *q3.top() << endl;
//	q3.pop();
//	cout << *q3.top() << endl;
//	q3.pop();
//	cout << endl;
//}
//template<size_t N = 10, bool flag = false>
//class Stack {
//private:
//	int _a[N];
//	int _top;
//};
////c++20
////template<double X>
//int main()
//{
//	Stack<> s0; //用的是缺省值
//	Stack<5> s1;
//	Stack<10> s2;
//}
//template<class T,size_t N = 10>
//class Array
//{
//public:
//	T& operator[](size_t index)
//	{
//		assert(index < N);
//		return _array[index];
//	}
//private:
//	T _array[N];
//	size_t _size;
//};
//int main()
//{
//	array<int, 10> a1;
//	array<int, 100> a2;
//	int a3[10];
//	//越界检查的问题
//	//越界读不检查，越界写检查
//	//静态数组抽查
//	//cout << a3[10] << endl;
//	//a3[11] = 0;
//	////array越界读写都可以检查
//	//a1[11] = 10;
//	vector<int> v(100, 1);
//	cout << sizeof(a2) << endl;
//	cout << sizeof(v) << endl;
//}

////函数模版 参数匹配
//template<class T>
//bool LessFunc(const T& left, const T& right)
//{
//	return left < right;
//}
////特化
//template<>
////bool LessFunc<const Date*>(const Date* const& left, const Date* const& right)
////{
////	return *left < *right;
////}
////template<>
////bool LessFunc<Date*>(Date* const& left, Date* const& right)
////{
////	return *left < *right;
////}
//bool LessFunc(const Date* left,const Date*  right)
//{
//	return *left < *right;
//}
//bool LessFunc(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << LessFunc(1, 2) << endl;
//	Date d1(2025, 5, 14);
//	Date d2(2025, 5, 15);
//	cout << LessFunc(d1, d2) << endl;
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << LessFunc(p1, p2) << endl;
//
//	const Date* p3 = &d1;
//	const Date* p4 = &d2;
//	cout << LessFunc(p3, p4) << endl;
//	//以上除了第三个都能正确比较得出结果
//}
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
};
// 半特化/偏特化
template<class T1>
class Data<T1, double>
{
public:
	Data()
	{
		cout << "Data<T1,double>" << endl;
	}
};
template<class T1>
class Data<T1, char>
{
public:
	Data()
	{
		cout << "Data<T1,char>" << endl;
	}
};
//偏特化 传的是指针
template<typename T1,typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
};
template<typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data()
	{
		cout << "Data<T1&,T2&>" << endl;
	}
};
template<typename T1,typename T2>
class Data<T1&, T2*>
{
public:
	Data()
	{
		cout << "Data<T1&,T2*>" << endl;
		int a = 0;
		T1& x = a;
		T2* y = &a;
		T1 z = a;
		cout << typeid(x).name() << endl;
		cout << typeid(y).name() << endl;
	}
	void Push(const T1& x)
	{ }
};
