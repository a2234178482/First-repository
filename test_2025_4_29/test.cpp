#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "string.h"
using namespace std;
int main() {
	string str;
	while (getline(cin, str)) {
		int pos = str.rfind(' ');
		cout << str.size() - pos - 1 << endl;
	}
	char16_t str16[] = u"niuma";
	char32_t str32[] = U"niuma";
	wchar_t wstr[] = L"niuma";
}