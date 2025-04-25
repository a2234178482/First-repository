#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
////int main() {
////	int x, y, z;
////	cin >> x >> y >> z;
////	int sum = 0;
////	for (int i = 1; i < y; i++) {
////		sum += month[i - 1];
////	}
////	sum += z;
////	if (((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) && y > 2)
////	{
////		sum++;
////	}
////	cout << sum;
////}
//class A {
//public:
//	A(int a1 = 0, int a2 = 0)
//		:_a1(a1),
//		_a2(a2){
//		cout << "A(int a1 = 0, int a2 = 0)" << endl;
//	}
//	A(const A& aa)
//	:_a1(aa._a1){
//		cout << "A(const A & aa)" << endl;
//	}
//	A& operator=(const A& aa) {
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa) {
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A() {
//		cout << "~A()" << endl;
//	}
//	void Print() {
//		cout << "A::Print()" << endl;
//	}
//	A& operator++() {
//		_a1 += 100;
//		return *this;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//void func1(A aa) {
//}
//A f2() {
//	A aa(1);
//	return aa;
//}
//class B {
//public:
//	~B() {
//		cout << "2" << endl;
//	}
//private:
//	int _b1 = 2;
//	int _b2 = 2;
//};
//class Sum {
//	Sum() {
//		_ret += _i;
//		_i++;
//	}
//	static int Get() {
//		return _ret;
//	}
//private:
//	static int _i;
//	static int _ret;
//};
//class solution {
//	int sum(int n) {
//		Sum a[n];
//		return Sum::Get();
//	}
//};
//int main() {
//	////A aa1 = 1;
//	////const A& aa2 = 1;
//	////A aa1(1);
//	////func1(aa1);
//	////return 0;
//	//f2().Print();
//	////新定义一个整数类型的空间
//	//int* p1 = new int;
//	////新定义一个整数类型的空间并且赋值为10
//	//int* p2 = new int(10);
//	////新定义10个整数类型的空间
//	//int* p3 = new int[10];
//	//int* p4 = new int[4] {1, 2, 3, 4};
//	//A aa1(1);
//	//A aa2(2);
//	//A* p5 = new A[3]{ aa1,aa2 };
//	////new 和delete要成套使用
//	//delete p1;
//	//delete p2;
//	//delete[] p3;
//	//delete[] p4;
//	//delete[] p5;
//	////抛出异常 throw try catch
//	//try {
//	//	void* p1 = new char[1024 * 1024 * 1024];
//	//	void* p2 = new char[1024 * 1024 * 1024];
//	//}
//	//catch (const exception& e) {
//	//	cout << e.what() << endl;
//	//}
//	B* p2 = new B[10];
//	delete p2;
//	//对于自定义类型，new除了开空间还会调用构造函数 Delete会调用析构
//	A* p3 = new A[10];
//	delete p3;
//	//会程序崩溃，B没有写析构，A写了析构，A实际上开了84字节的空间，往前偏移了4个字节取到了开空间的个数
//	//如果写了B的析构，也会崩溃
//}
//int main() {
//	std::string dateStr1;
//	std::string dateStr2;
//	std::cin >> dateStr1;
//	std::cin >> dateStr2;
//	int x = std::stoi(dateStr1.substr(0, 4));  
//	int y = std::stoi(dateStr1.substr(4, 2)); 
//	int z = std::stoi(dateStr1.substr(6, 2));
//	int a = std::stoi(dateStr2.substr(0, 4));
//	int b = std::stoi(dateStr2.substr(4, 2));
//	int c = std::stoi(dateStr2.substr(6, 2));
//	int r = 0;
//	if (((r % 4 == 0 && r % 100 != 0) || r % 400 == 0))
//	{
//		r += 1;
//	}
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int sum1 = 0, sum2 = 0;
//	for (int i = 1; i < y; i++) {
//			sum1 += month[i - 1];
//		}
//	sum1 += z;
//	if (((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) && y > 2)
//	{
//			sum1++;
//	}
//	for (int i = 1; i < b; i++) {
//		sum2 += month[i - 1];
//	}
//	sum2 += c;
//	if (((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) && b > 2)
//	{
//		sum2++;
//	}
//	int count = 0;
//	for (int i = x + 1; i < a; i++) {
//		if (((i % 4 == 0 && i % 100 != 0) || i % 400 == 0))
//		{
//			count++;
//		}
//	}
//	cout << count + (a - x - 1) * 365 + sum2 + 365 - sum1 + r   << endl;
//}
//#include <iostream>
//#include <istream>
//#include <iomanip>  
//using namespace std;
//int monthArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//class Date {
//public:
//    friend istream& operator>>(istream& is, Date& d1);
//    friend ostream& operator<<(ostream& out, Date& d1);
//    int GetMonthDay(int year, int month) {
//        if (month == 2 && ((year % 4 == 0) && year % 100 != 0) || (year % 400 == 0)) {
//            return 29;
//        }
//        return monthArray[month];
//    }
//    Date(int year = 1, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    Date(const Date& d1) {
//        _year = d1._year;
//        _month = d1._month;
//        _day = d1._day;
//    }
//    Date& operator+=(int day) {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            ++_month;
//            if (_month == 13) {
//                _year++;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//    Date& operator+(int day) {
//        Date tmp = *this;
//        tmp += day;
//        return tmp;
//    }
//    int Get_year() {
//        return _year;
//    }
//    int Get_month() {
//        return _month;
//    }
//    int Get_day() {
//        return _day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//ostream& operator<<(ostream& out, Date& d1) {
//    out << d1._year << setw(2) << setfill('0') << d1._month
//        << setw(2) << setfill('0') << d1._day;
//    return out;
//}
//istream& operator>>(istream& in, Date& d1) {
//    in >> d1._year >> d1._month >> d1._day;
//    return in;
//}
//int main() {
//    Date d1;
//    int a;
//    int x;
//    cin >> a;
//    while (a--) {
//        cin >> d1 >> x;
//        Date d2 = d1 + x;
//        cout << d2 << endl;
//    }
//}
#include <iostream>
#include <iomanip>
using namespace std;
int monthArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
    int year, count;
    cin >> year >> count;
    if (((year % 4 == 0) && year % 100 != 0) || (year % 400 == 0))
    {
        monthArray[3] += 1;
    }
    int month = 1;
    int day = 0;
    while (day + count > monthArray[month])
    {
        count -= monthArray[month];
        month++;
    }
    day = count;
    cout << year << "-" << setw(2) << setfill('0') << month <<"-" << setw(2) << setfill('0') << day;
}
