#include <iostream>
using namespace std;
//class Adult
//{
//public:
//	virtual void Ticket()
//	{
//		cout << "全价票" << endl;
//	}
//};
//class Student : public Adult
//{
//public:
//	virtual void Ticket()
//	{
//		cout << "半价票" << endl;
//	}
//};
//void Price(Adult& a)
//{
//	a.Ticket();
//}
//int main()
//{
//	Adult a;
//	Student s;
//   虽然都是Adult指针a在调用Ticket
//   但是和a没关系，而是由a指向的对象决定的
//	Price(a);
//	Price(s);
//}
//class Animal
//{
//public:
//	virtual void voice() const
//	{
//	}
//};
//class Dog : public Animal
//{
//public:
//	virtual void voice() const
//	{
//		cout << "汪汪" << endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//	virtual void voice() const
//	{
//		cout << "喵" << endl;
//	}
//};
//void Voice(Animal& a)
//{
//	a.voice();
//}
//int main()
//{
//	Dog d;
//	Cat c;
//	Voice(d);
//	Voice(c);
//}
//class A
//{
//public:
//	virtual void func(int val = 1)
//	{
//		cout << "A->" << val << endl;
//	}
//	virtual void test()
//	{
//		func();
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0)
//	{
//		cout << "B->" << val << endl;
//	}
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	//执行结果为B->1
//	//重写只是对函数的内部进行重写，缺省值还是A的
//	p->test();
//	//执行结果为B->0
//	//直接执行B的func函数
//	p->func();
//}
//class A{};
//class B : public A {};
////协变
//class Adult
//{
//public:
//	virtual A* Ticket()
//	{
//		cout << "全价" << endl;
//		return nullptr;
//	}
//};
//class Student :public Adult
//{
//public:
//	virtual B* Ticket()
//	{
//		cout << "半价" << endl;
//		return nullptr;
//	}
//};
//void func(Adult& a)
//{
//	a.Ticket();
//}
//int main()
//{
//	Adult a;
//	Student s;
//	func(a);
//	func(s);
//}
//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	//不加virtual也构成重写
//	virtual ~B()
//	{
//		cout << "~B()" << endl;
//	}
//protected:
//	int* _p = new int[10];
//};
//int main()
//{
//	A* a = new B;
//	//基类中的析构建议设置为虚函数是因为
//	//在多态中，存在基类指针指向派生类，
//	//如果不设置为虚函数，会发生内存泄漏
//	delete a;
//}
//override和final
//class A
//{
//public:
//	//如果不想让派生类重写这个虚函数，用final修饰
//	virtual void Test() final {}
//	virtual void Ticket()
//	{}
//};
//class B : public A
//{
//public:
//	//override能够检测是否构成重写
//	virtual void Ticket() override
//	{
//		cout << "B::Ticket()" << endl;
//	}
//};
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//class Benchi : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "奔驰" << endl;
//	}
//};
//class aodi : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "奥迪" << endl;
//	}
//};
//int main()
//{
//	Car* b = new Benchi;
//	b->Drive();
//	Car* c = new aodi;
//	c->Drive();
//	return 0;
//}
//class Adult
//{
//public:
//	virtual void Ticket()
//	{
//		cout << "全价" << endl;
//	}
//};
//class Student : public Adult
//{
//public:
//	virtual void Ticket() override
//	{
//		cout << "半价" << endl;
//	}
//};
//class Soldier : public Adult
//{
//public:
//	virtual void Ticket() override
//	{
//		cout << "免费" << endl;
//	}
//};
//void func(Adult& a)
//{
//	a.Ticket();
//}
//int main()
//{
//	//多态不仅发生在派生类对象之间，多个派生类继承基类，重写虚函数后
//	//多态也发生在多个派生类之间
//	Adult a;
//	Student s;
//	Soldier s1;
//	func(a);
//	func(s);
//	func(s1);
//}
//class Base
//{
//public:
//	virtual void test()
//	{
//		cout << "Base()" << endl;
//	}
//protected:
//	int _a1;
//	char _c;
//};
//int main()
//{
//	//32位环境下只有12字节，因为除了_a1,_c外
//	//还有一个虚表指针，4个字节大小
//	Base b1;
//	cout << sizeof(b1) << endl;
//}
class Base {
public:
	virtual void func1()
	{
		cout << "1" << endl;
	}
	virtual void func3()
	{
		cout << "2" << endl;
	}
	void func5()
	{
		cout << "3" << endl;
	}
protected:
	int _a = 1;
};
class Base1 : public Base
{
public:
	virtual void func1()
	{
		cout << "4" << endl;
	}
	virtual void func2()
	{
		cout << "5" << endl;
	}
	void func4()
	{
		cout << "6" << endl;
	}
protected:
	int _b = 2;
};

int main()
{
	int i = 0;
	static int j = 1;
	int* p1 = new int;
	const char* p2 = "xxxxx";
	printf("%p", &i);
	cout << endl;
	printf("%p", &j);
	cout << endl;
	printf("%p", p1);
	cout << endl;
	printf("%p", p2);
	cout << endl;
	Base b;
	Base1 d;
	Base* p3 = &b;
	Base1* p4 = &d;
	printf("%p", *(int*)p3);
	cout << endl;
	printf("%p", *(int*)p4);
	cout << endl;
	printf("%p", &Base::func1);
	cout << endl;
	printf("%p", &Base1::func5);
}