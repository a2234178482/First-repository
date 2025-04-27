#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;
//class string {
//private:
//	char _buff[16]; //VS处理
//	char* str;
//	size_t size;
//	size_t capacity;
//};
//void test_string1() {
//	string s1;
//	string s2("hello world");
//	cout << s1 <<endl << s2 << endl;
//	//s2[0] = 'x';
//	cout << s1 <<endl << s2 << endl;
//	//遍历字符串的3种方式
//	//1.下标+[]
//	//for (int i = 0; i < s2.size(); i++) {
//	//	cout << s2[i] << "";
//	//}
//	cout << endl;
//	//2.迭代器 end指向的是最后一个字符的下一个字符
//	//string::iterator it = s2.begin();
//	//auto it = s2.begin();
//	//while (it != s2.end()) {
//	//	*it += 2;
//	//	cout << *it << "";
//	//	++it;
//	//}
//	//cout << endl;
//	//cout << s2 << endl;
//	//map<string, string > dict;
//	//map<string,string>::iterator mit = dict.begin();
//	//auto mit = dict.begin();
//	/*list<int> lt = { 1,2,3,4,5,6,7 };
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end()) {
//		cout << *lit << "";
//		++lit;
//	}*/
//	//3.字符赋值 自动迭代，自动判断结束，底层就是迭代器，也叫范围for
//	for (auto& ch : s2) {
//		ch -= 1;
//		cout << ch << "";
//	}
//	cout << endl;
//	cout << s2;
//}
void test_string2() {
	string s2("hello world");
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		*it += 2;
		cout << *it << "";
		++it;
	}
	cout << endl;
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend()) {
		cout << *rit << "";
		++rit;
	}
	cout << endl;
	const string s3("hello world");
	//string::const_iterator cit = s3.begin;
	auto cit = s3.begin();
	while (cit != s3.end()) {
		/*cit += 2;*/
		cout << *cit << "";
		++cit;
	}
	cout << endl;
	//string::const_reverse_iterator rcit = s3.rbegin()
	auto rcit = s3.rbegin();
	while (rcit != s3.rend()) {
		cout << *rcit << endl;
		++rcit;
	}
	cout << endl;
}
void testpushback() {
	string s;
	s.reserve(100);
	//提前开空间，避免扩容，提高效率
	size_t sz = s.capacity();
	s.push_back('c');
}
//auto不能做函数参数，但是可以做函数返回值
auto Add(int x, int y) {
	return x + y;
}
int main() {
	//test_string1();
	test_string2();
	int a = 10;
	auto b = a;
	auto c = 'a';
	//auto类型必须有初始值设定项
	int array[] = { 1,2,3,4,5 };
	for (auto& e : array) {
		e *= 2;
	}
	for (auto e : array) {
		cout << e << "" << endl;
	}
	return 0;
}