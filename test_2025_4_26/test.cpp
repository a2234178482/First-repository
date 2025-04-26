#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class A {
public:
	A(int a = 0)
	:_a(a){}
	~A() {
		cout << "A()" << this << endl;
	}
private:
	int _a;
};
//template <class A,class B>
//int Add(A& a, B& b) {
//	return a + b;
//}
template <class T>
void Swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}
template <typename T1,typename T2>
void func(const T1& x, const T2& y) {

}
template <class T>
T add(const T& left, const T& right)
{
	return left + right;
}
template <class T1, class T2>
T1 Add(const T1& left, const T2& right) {
	return left + right;
}
template <class T>
T* fuc1(int n) {
	return new T[n];
}
//当写了一个模板和一个函数，优先调用函数
template <class T>
T add(const T& left, const T& right) {
	return left + right;
}
int add(const int& x, const int& y) {
	return (x + y) * 10;
}
template <class T>
class Stack {
public:
	Stack(int n = 4) 
		:_array(new T[n]),
		_capacity(n),
		_size(0)
	{}
	~Stack() {
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
	void Push(const T& x);
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
//没realloc ,手动扩容
template <class T>
void Stack<T>::Push(const T& x) {
	if (_size == _capacity) {
		T* tmp = new T[_capacity * 2];
		memcpy(tmp, _array, sizeof(T) * _size);
		delete[] _array;
		_array = tmp;
		_capacity *= 2;
	}
	_array[_size++] = x;
}
int main() {
	int a, b;
	cin >> a >> b;
	int ret = Add(a, b);
	cout << ret << endl;
	swap(a, b); //官方提供了swap 函数
	cout << a << b << endl;
	A* p1 = new A(1);
	delete p1;
	A* p2 = (A*) operator new(sizeof(A));
	new(p2)A(1);
	p2 ->~A();
	operator delete(p2);
	return 0;
	int h = add(a, b);
	cout << h << endl;
	int a1 = 10; 
	int a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	Add(d1, d2);
	Add(a1, a2);
	//推导实例化
	cout << Add(a1, (int)d1) << endl;
	cout << Add((double)a1, d1) << endl;
	//显示实例化
	cout << Add<int>(a1, d1) << endl;
	cout << Add<double>(a1, d1) << endl;
	double* p1 = fuc1<double>(10);
	int a1 = 10;
	int a2 = 20;
	cout << Add(a1, a2) << endl;
	//类模板都是显示实例化
	Stack <int> st1;
	st1.Push(1);
	st1.Push(2);

	Stack <double> st2;
	st2.Push(1.1);
	st2.Push(1.2);

	Stack<double>* pst = new Stack<double>;
	delete pst;
	//字符串初始化的几种方式
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(s2, 6, 15);
	string s5(s2, 6);
	string s6("hello world", 5);
	string s7(10, 'x');
	cout << s1 << endl << s2 << endl << s3 << endl
		<< s4 << endl << s5 << endl << s6 << endl << s7;
}