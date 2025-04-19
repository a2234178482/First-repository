#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
namespace zsp {
	int rand = 10;
}
//嵌套命名空间
namespace st {
	namespace xh {
		int rand = 20;
	}
}
typedef struct Stack {
	int a[10];
	int top;
}ST;
void STINIT(ST* ph);
void STPush(ST* pd);
namespace sd {
	typedef struct Stack {
		int a[20];
		int top;
	}SK;
	void STINIT(SK* ph);
	void STPush(SK* pd);
}
namespace sp {
	int a = 10;
	int b = 0;
}
using namespace sp;
using sp::a;
void func1(int a = 10, int b = 20, int c = 30) {
	cout << a << "" << b << "" << c << endl;
}
int Add(int left, int right) {
	return left + right;
}
double Add(double left, double right) {
	return left + right;
}
int Add(int left, int right, int mid) {
	return left + right + mid;
}
//参数顺序不同也可函数重载
int add(int a, char b) {
	cout << a << "" << b << endl;
}
int add(char b, int a) {
	cout << b << "" << a << endl;
}
//以下也可函数重载，但在调用时会出现问题
//void funct(int a = 10) {
//	cout << a << endl;
//}
//void funct() {
//	int a = 10;
//	cout << a << endl;
//}
namespace skt {
	typedef struct Stack {
		char a[10];
		char top;
	}SA;
	void SAINIT(SA& c);
}
int main() {
	int a;
	cin >> a ;
	cout << zsp::rand << endl;
	cout << st::xh::rand << endl;
	cout << "hello world" << endl;
	ST s1;
	STINIT(&s1);
	sd::SK s2;
	sd::STINIT(&s2);
	sd::STPush(&s2);
	cout << sp::a << endl;
	int i = 123456;
	int j = -123456;
	std::cout << i << endl;
	int q = 0;
	double w = 0.1;
	char e = 'y';
	cout << q << "" << w << "" << e << endl;
	cin >> q;
	cin >> w;
	cin >> e;
	//io需求比较高时，可以输入以下三行代码提高效率
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	func1();
	func1(1);
	func1(1, 2);
	func1(1, 2, 3);
	int i = 1000;
	int& b = i;
	int& c = b;
	int& d = c;
	++d;
	cout << i << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	return 0;
	skt::SA s0;
	skt::SA& s9 = s0;
	skt::SAINIT(s9);
	skt::SAINIT(s0);
}