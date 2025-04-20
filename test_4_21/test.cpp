#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int& func()
{
	int b = 10;
	return b;
}
//实现一个函数宏
#define ADD(x,y) ((x)+(y)) 
//为什么不加分号  cout << ADD(x,y) <<endl时会出现问题
//为什么要加里面和外面的括号  都是为了运算的优先级

//内联函数
inline int ADD(int x, int y) {
	int ret = x + y;
	ret += 1;
	return ret;
}
//内联不建议声明和定义在两个文件，可能导致链接错误

//nullptr
void f(int x) {
	cout << f"(int x)" << endl;
}
void f(int* ptr)
{
	cout << f"(int* ptr)" << endl;
}
//类和对象
class Queue
{
public:
	void PUSH(int x){}
};
class Stack {
public:
	void PUSH(int x){}
public:
	void Pop(){}
private:
	int* a;
	int top;
	int capacity;
};
//class如果不做限定，那么是private，而struct不做限定，那么默认是public
class Date {
	void Init(int year, int month, int day);
private:
	int _year;
	int _month;
	int _day;
};
struct Date {
	void Init(int year, int month, int day);
private:
	int _year;
	int _month;
	int _day;
};
void Date::Init(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}
//cpp定义结构体更加简单
struct ListNode {
	int val;
	ListNode* next;
};
int main() {
	double d = 12.34;
	int i = d;
	const int& ri = d;
	cout << ri << endl;
	//引用时权限可以缩小，不可以放大
	/*const int a = 10;
	int& b = a;*/
	//上面为错误代码
	int x = 10;
	const int y = x;
	const int& ra = (a + x);
	//临时变量有常性
	int rq = 1;
	int* rm = &rq;
	*rm = 2;
	int& rb = rq;
	rb = 2;
	cout << rb << endl;
	//引用不能改变指向对象，指针可以
	int* ptr = NULL;
	int& ri = *ptr;
	ri++;
	//空引用
	f(NULL);
	//会出现调用问题
	void* p1 = NULL;
	int* p2 = (int*)p1;
	int* p2 = nullptr;
	int i = nullptr;
	Stack st;
	st.Pop();
	st.PUSH(1);
	Date d1;
	d1.Init(2025, 4, 20);
	return 0;
}
