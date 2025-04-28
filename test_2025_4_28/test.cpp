#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
void test_string1() {
	string s("i love you");
	s.push_back(' ');
	s.push_back('x');
	s.push_back('a');
	cout << s << endl;
	s += ' ';
	s += 'sasf';
	cout << s << endl;
	s.insert(0, "hello world");
	cout << s << endl;
	s.insert(10, "zzz");
	cout << s << endl;
	char ch = 'a';
	s.insert(0, 1, ch);
	cout << s << endl;
	s.insert(s.begin(), ch);
	cout << s << endl;
}
void test_string2() {
	string s("computer sciense");
	s.erase(6, 1);
	cout << s << endl;
	//头删
	s.erase(0, 1);
	cout << s << endl;
	s.erase(s.begin());
	cout << s << endl;

	//尾删
	s.erase(--s.end());
	cout << s << endl;
	s.erase(s.size() - 1, 1);
	cout << s << endl;

	string ss("ai change world");
	ss.erase(6);
	cout << ss << endl;

	string sss("world is all");
	//size_t pos = sss.find(' ');
	//while (pos != string::npos)
	//{
	//	sss.replace(pos, 1, "%%");
	//	cout << sss << endl;
	//	pos = sss.find(' ', pos + 2);
	//}
	//cout << sss << endl;
	//sss.replace(2, 1, "%%");
	//cout << sss << endl;
	string tmp;
	tmp.reserve(sss.size());
	for (auto ch : sss)
	{
		if (ch == ' ') {
			tmp += "%%";
		}
		else {
			tmp += ch;
		}
	}
	cout << tmp << endl;
	sss.swap(tmp);
	cout << sss << endl;
	string file;
	cin >> file;
	FILE* fout = fopen(file.c_str(), "r");
	char ch = fgetc(fout);
	while (ch != EOF) {
		cout << ch;
		ch = fgetc(fout);
	}
	fclose(fout);
}
void SplitFileName(const std::string& str) {
	cout << "Spliting:" << str << endl;
	std::size_t found = str.find_last_of("/\\");
	cout << "path:" << str.substr(0, found) << endl;
	cout << "file :" << str.substr(found + 1) << endl;
}
void test_string3() {
	string s("testsfj.cpp.zip");
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
	cout << str << endl;
}
void test_string4()
{
	string s1("hello");
	string s2 = s1 + "world";
	cout << s2 << endl;
	string s3 = "world" + s1;
	cout << s3 << endl;
}
int main() {
	//test_string1();
	//test_string2();
	//string s1("D:\\Program Files\\Tencent\\QQNT\\QQ.exe");
	//SplitFileName(s1);
	//test_string3();
	string str;
	//比cin好，可以指定读到什么结束
	getline(cin, str, '*');//输入*才停止
	getline(cin, str);
	size_t pos = str.rfind(' ');
	cout << str.size() - (pos)+1 << endl;
	return 0;
}