#include<iostream>
#include <vector>
#include<list>
#include <deque>
using namespace std;
//class ID
//{
//public:
//	void identity()
//	{
//		cout << "void identity()" << endl;
//		cout << _age << endl;
//	}
//protected:
//	string _name = "张三";
//	string _address;
//	string _tel;
//private:
//	int _age = 18;
//};
//class Student : public ID
//{
//public:
//	void study()
//	{
//		identity();
//		cout << _tel << endl;
//	}
//protected:
//	int _studentid;
//};
//class Teacher : public ID
//{
//public:
//	void teaching(){
//	}
//protected:
//	string _title;
//};
//int main()
//{
//	Student s;
////	Teacher t;
////	s.identity();
////	t.identity();
////	return 0;
////}
//#define CONTAINER1 std::vector
////#define CONTAINER2 std::list
////#define CONTAINER3 std::deque
//namespace niuma {
//	template<class T>
//	class vector{};
//	template<class T>
//	class  stack : public CONTAINER1<T>
//	{
//	public:
//		void push(const T & x)
//		{
//			CONTAINER1<T>::push_back(x);
//		}
//		void pop()
//		{
//			CONTAINER1<T>::pop_back();
//		}
//		const T& top()
//		{
//			return CONTAINER1<T>::back();
//		}
//		bool empty()
//		{
//			return CONTAINER1<T>::empty();
//		}
//	};
//	template<class T>
//	class A
//	{
//	public:
//		A()
//		{}
//		void push(const T& x)
//		{
//			x.func();
//		}
//	};
//}
//int main()
//{
//	niuma::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	niuma::A<int> aa;
//	aa.push(1);
//	return 0;
//}
//class Man {
//protected:
//public:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student : public Man {
//public:
//	int _studentid;
//};
//int main()
//{
//	//子类对象可以赋值给父类对象//指针//引用
//	Student s;
//	Man m = s;
//	Man* m1 = &s;
//	Man& ma = s;
//	ma._name = "LISI";
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//
//	//父类对象不能赋值给子类对象，编译报错
//	s = (Student)m;
//}

//class man
//{
//protected:
//	string _name = "LISI";
//	int _num = 111;
//};
//class Woman : public man
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;
//		cout << man::_num << endl; 
//	}
//protected:
//	int _num = 999;
//};
//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void func(int i)
//	{
//		cout << "func(int i) " << endl; //和A中的func构成函数隐藏，不构成重载，因为作用域不同
//	}
//};
//int main()
//{
//	B b;
//	b.A::func();
//	b.func(1);
//}
//class ID
//{
//public:
//	ID(const char* name = "xxx")
//		:_name(name)
//	{
//		cout << "ID()" << endl;
//	}
//	ID(const ID& i)
//		:_name(i._name)
//	{
//		cout << "ID(const ID& i)" << endl;
//	}
//	ID& operator=(const ID& i)
//	{
//		cout << "ID& operator=(const ID& i)" << endl;
//		if (this != &i)
//		{
//			_name = i._name;
//		}
//		return *this;
//	}
//	~ID()
//	{
//		cout << "~ID()" << endl;
//	}
//protected:
//	string _name; 
//};
//class Man : public ID
//{
//public:
//	//默认生成的构造函数行为有三个
//	//1.内置类型
//	//2.自定义类型
//	//3.继承父类的成员看做一个整体对象，要求调用父类的默认构造
//	//总结：子类继承父类以后，可以不用写构造 拷贝构造 析构，除非有深拷贝
//	Man(const char* name, int num, const char* address)
//		:ID(name)
//		,_num(num)
//		,_address(address)
//	{}
//	Man(const Man& m)
//		:ID(m)
//		,_num(m._num)
//		,_address(m._address)
//	{
//	}
//	Man& operator=(const Man& i)
//	{
//		if (this != &i)
//		{
//			ID::operator=(i);
//			_num = i._num;
//			_address = i._address;
//		}
//		return *this;
//	}
//	//析构都会被特殊处理成destructor 析构顺序为先子后父
//	~Man()
//	{
//		ID::~ID();
//		delete _ptr;
//	}
//protected:
//	int _num = 1;
//	string _address = "兰州市安宁区";
//	int* _ptr = new int[10];
//};

////c++11 的方法 在类名后加final就表示不能继承了
//class Base1 final {
//public:
//	void func5() { cout << "Base1::func5()" << endl; }
//protected:
//	int _a = 1;
//private:
//	//c++ 98的方法 //构造函数私有，不能继承
//	Base1()
//	{
//	}
//};
//
//class Base2 : public Base1
//{
//public:
//	void func4()
//	{
//		cout << "Base2::func4()" << endl;
//	}
//};
//int main()
//{
//	Base2 b2;
//}

////友元关系不能被继承
//class Student;
//class ID
//{
//public:
//	friend void play(const ID& i, const Student& s);
//protected:
//	string _name;
//};
//class Student : public ID
//{
//	friend void play(const ID& i, const Student& s);
//protected:
//	int _idnumber;
//};
//void play(const ID& i, const Student& s)
//{
//	cout << i._name << endl;
//	cout << s._idnumber << endl;
//}
//int main()
//{
//	ID i;
//	Student s;
//	//play要变成Student和ID的友元才能执行
//	play(i, s);
//	return 0;
//}
//
//class ID
//{
//public:
//	string _name;
//	static int _number;
//};
//int ID::_number = 365;
//class Student : public ID
//{
//protected:
//	int _num;
//};
//int main()
//{
//	ID i;
//	Student s;
//	//非静态成员_name的地址不一样，说明子类和父类各有一份
//	//静态成员_number的地址一样，说明子类和父类共用一份静态成员
//	cout << &i._name << endl;
//	cout << &s._name << endl;
//	cout << &i._number << endl;
//	cout << &s._number << endl;
//	//公有的情况下，父类和子类都可以指定类域访问静态成员
//	cout << Student::_number << endl;
//	cout << ID::_number << endl;
//
//	ID::_number++;
//	cout << i._number << endl;
//	cout << s._number << endl;
//	return 0;
//}
//class ID
//{
//public:
//	ID(const char* name)
//		:_name(name)
//	{ }
//
//protected:
//	string _name;
//	int _age;
//	string _gender;
//	string _address;
//};
//class Student : virtual public ID
//{
//public:
//	Student(const char* name,int num = 0)
//		:ID(name)
//		,_num(num)
//	{ }
//protected:
//	int _num;
//};
//class Teacher : virtual public ID
//{
//public:
//	Teacher(const char* name ,int id = 1)
//		:ID(name)
//		,_id(id)
//	{ }
//protected:
//	int _id;
//};
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name,const char* name1,const char* name2)
//		:ID(name),      
//		Student(name1),
//		Teacher(name2) {
//	}
//	Assistant() : ID(""), Student("", 0), Teacher("", 1) {}
//protected:
//	string _major;
//};
//int main()
//{
//	Assistant a;
//	//需要显示指定访问哪个父类成员可以解决二义性问题，但是数据冗余需要用virtual
// //如果有一个父类 A,B C继承A,D继承了B，然后E继承了D和C，那么virtual应该在B C加
//	a.Student::_name = "peter";
//	a.Teacher::_name = "小李";
//}
//class Base1
//{
//public:
//	int _b1 = 1;
//};
//class Base2
//{
//public:
//	int _b2 = 2;
//};
//class Base3 :public Base1, public Base2
//{
//public:
//	int _d = 3;
//	int _e = 4;
//};
//int main()
//{
//	//bb3 == b1 != b2 因为先继承base1 base2与base1隔了base1大小个字节的空间
//	Base3 b3;
//	Base1* b1 = &b3;
//	Base2* b2 = &b3;
//	Base3* bb3 = &b3;
//	return 0;
//}

//is-a 和has-a
//public继承就是is-a,组合就是has-a
//is-a就是每个派生类都是一个基类对象，has-a就是每个派生类中都有一个基类对象
//低耦合高内聚