#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;

//class string
//{
//private:
//	char _buff[16];
//	char*  _str;
//
//	size_t _size;
//	size_t _capacity;
//};

void test_string1()
{
	string s1;
	string s2("hello world");

	cout << s1 << s2 << endl;

	s2[0] = 'x';
	cout << s1 << s2 << endl;

	// 1、下标 + []
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	// 2、迭代器
	//string::iterator it = s2.begin();
	auto it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << s2 << endl;

	map<string, string> dict;
	//map<string, string>::iterator mit = dict.begin();
	auto mit = dict.begin();

	/*list<int> lt = { 1,2,3,4,5,6,7 };
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;*/

	// 3、字符赋值，自动迭代，自动判断结束
	// 底层就是迭代器
	//for (auto ch : s2)
	for (auto& ch : s2)
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;

	cout << s2 << endl;
}

void test_string2()
{
	string s2("hello world");
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const string s3("hello world");
	//string::const_iterator cit = s3.begin();
	auto cit = s3.begin();
	while (cit != s3.end())
	{
		//*cit += 2;
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//string::const_reverse_iterator rcit = s3.rbegin();
	auto rcit = s3.rbegin();
	while (rcit != s3.rend())
	{
		// *rcit += 2;
		cout << *rcit << " ";
		++rcit;
	}
	cout << endl;
}

void TestPushBack()
{
	// reverse 反转  逆置
	// reserve 保留、预留
	string s;
	// 提前开空间，避免扩容，提高效率
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_string3()
{
	string s2("hello world");
	cout << s2.length() << endl;
	cout << s2.size() << endl;

	cout << s2.max_size() << endl;

	cout << s2.capacity() << endl;
	TestPushBack();

	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//cout << sizeof(s2) << endl;
	//cout << sizeof(s3) << endl;
}

void test_string4()
{
	string s2("hello worldxxxxxxxxxxxxx");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(28);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(40);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	cout << typeid(string::iterator).name() << endl;
	cout << typeid(string::reverse_iterator).name() << endl;
}

void test_string5()
{
	string s("hello world");
	s.push_back(' ');
	s.push_back('x');
	s.append("yyyyyy");

	cout << s << endl;

	s += ' ';
	s += "33333333333";
	cout << s << endl;

	s.insert(0, "hello bit ");
	cout << s << endl;

	s.insert(10, "zzzz");
	cout << s << endl;

	s.insert(0, "p");
	cout << s << endl;

	char ch = 't';
	s.insert(0, 1, ch);
	s.insert(s.begin(), ch);

	cout << s << endl;
}

void test_string6()
{
	string s("hello world");
	s.erase(6, 1);
	cout << s << endl;

	// 头删
	s.erase(0, 1);
	cout << s << endl;

	s.erase(s.begin());
	cout << s << endl;

	// 尾删
	s.erase(--s.end());
	cout << s << endl;

	s.erase(s.size() - 1, 1);
	cout << s << endl;

	string ss("hello world");
	ss.erase(6);
	cout << ss << endl;

	string sss("hello                 world hello bit");
	/*size_t pos = sss.find(' ');
	while (pos != string::npos)
	{
		sss.replace(pos, 1, "%%");
		cout << sss << endl;

		pos = sss.find(' ', pos+2);
	}
	cout << sss << endl;*/

	//sss.replace(5, 1, "%%");
	//cout << sss << endl;

	string tmp;
	tmp.reserve(sss.size());
	for (auto ch : sss)
	{
		if (ch == ' ')
			tmp += "%%";
		else
			tmp += ch;
	}
	cout << tmp << endl;
	//sss = tmp;
	sss.swap(tmp);
	cout << sss << endl;

	string file;
	cin >> file;
	FILE* fout = fopen(file.c_str(), "r");
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
	fclose(fout);
}

void SplitFilename(const std::string& str)
{
	std::cout << "Splitting: " << str << '\n';
	std::size_t found = str.find_last_of("/\\");

	std::cout << " path: " << str.substr(0, found) << '\n';
	std::cout << " file: " << str.substr(found + 1) << '\n';
}
// 16：10
void test_string7()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string suffix = s.substr(pos);
	cout << suffix << endl;

	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::cout << str << '\n';

	std::size_t found = str.find_first_not_of("abcdef");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abcdef", found + 1);
	}

	std::cout << str << '\n';

	std::string str1("/usr/bin/man");
	std::string str2("D:\\1-教学服务团队\\1-比特课件\\4.C++课件\\C++课件V6-2022年修订\\C++课件--2022修订\\C++进阶课件");

	SplitFilename(str1);
	SplitFilename(str2);
}

void test_string8()
{
	string s1("hello");

	string s2 = s1 + "world";
	cout << s2 << endl;

	string s3 = "world" + s1;
	cout << s3 << endl;
}

//int main()
//{
//	test_string8();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;

//int main()
//{
//	string str;
//	getline(cin, str, '*');
//
//	size_t pos = str.rfind(' ');
//	cout << str.size() - (pos + 1) << endl;
//
//	return 0;
//}

//int func1()
//{
//	return 10;
//}
//
//// 不能做参数
////void func0(auto a = 0)
////{}
//
//auto func2()
//{
//	//...
//	return func1();
//}
//
//auto func3()
//{
//	//...
//	return func2();
//}

//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = func1();
//	// 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
//	//auto e;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto array[] = { 4, 5, 6 };
//
//	auto ret = func3();
//
//	int array[] = { 1, 2, 3, 4, 5 };
//	// C++98的遍历
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		cout << array[i] << endl;
//	}
//	
//	// yyds
//	// 范围for适用于容器 和 数组
//	// C++11的遍历
//	for (auto& e : array)
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " " << endl;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////
// 模拟实现
#include"string.h"

namespace bit
{
	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 2;
		}

		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			//*it += 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		s1 += "hello bit";
		cout << s1.c_str() << endl;

		s1.insert(5, '$');
		cout << s1.c_str() << endl;

		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.insert(5, "$$$");
		cout << s2.c_str() << endl;

		s2.insert(0, "$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		cout << s2.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

		string s3("hello world");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;
	}

	void test_string4()
	{
		string s("test.cpp.zip");
		size_t pos = s.find('.');
		string suffix = s.substr(pos);
		cout << suffix.c_str() << endl;

		string copy(s);
		cout << copy.c_str() << endl;

		s = suffix;
		cout << suffix.c_str() << endl;
		cout << s.c_str() << endl;

		s = s;
		cout << s.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		string s2("hello world");

		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
		cout << ("hello world" < s2) << endl;
		cout << (s1 == "hello world") << endl;
		//cout << ("hello world" == "hello world") << endl;

		cout << s1 << s2 << endl;

		string s0;
		cin >> s0;
		cout << s0 << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		string s2 = s1;

		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxx");
		s1 = s3;

		cout << s1 << endl;
		cout << s3 << endl;
	}

	void test_string7()
	{
		string s1("hello world");
		string s2("xxxxxxxxxxxxxxxxxxxxxxxx");

		std::swap(s1, s2);
		s1.swap(s2);
	}
}

int main()
{
	//bit::test_string6();

	// 编码 值和符号映射编码关系
	// 文字 -- 符号
	// 内存和磁盘只有0101

	//char buff[] = "apple sort";
	/*char buff[4];
	buff[0] = 97;
	buff[1] = 98;
	buff[2] = 99;
	buff[3] = 0;

	cout << buff << endl;

	char str[] = "牛马";
	cout << strlen(str) << endl;
	str[1]++;
	cout << str << endl;

	str[3]--;
	cout << str << endl;

	str[1]++;
	cout << str << endl;

	str[3]--;
	cout << str << endl;

	char16_t str16[] = u"牛马";
	char32_t str32[] = U"牛马";
	wchar_t wstr[] = L"牛马";

	cout << sizeof(str) << endl;
	cout << sizeof(str16) << endl;
	cout << sizeof(str32) << endl;
	cout << sizeof(wstr) << endl;*/

	std::string s1("111111111111111111111111");
	std::string s2(s1);
	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());

	return 0;
}