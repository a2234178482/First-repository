#include <iostream>
#include <time.h>
#include <vector>
#include "Myset.h"
#include "Mymap.h"
void Print(const Niuma::set<int>& s)
{
	Niuma::set<int>::const_iterator it = s.begin();
	while (it != s.begin())
	{
		--it;
		cout << *it << endl;
	}
}
int main()
{
	Niuma::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.insert(6);
	Niuma::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << endl;
		++sit;
	}
	for (auto& e : s)
	{
		cout << e << endl;
	}
	cout << endl;
	Print(s);
	Niuma::map<string, string> dict;
	dict.insert({ "sort", "ÅÅÐò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	dict["left"] = "×ó±ß£¬Ê£Óà";
	dict["insert"] = "²åÈë";
	dict["string"];
	auto it = dict.begin();
	while (it != dict.end())
	{
		it->second += 'x';
		cout << it->first << it->second << endl;
		++it;
	}
	for (auto& e : dict)
	{
		cout << e.first << e.second << endl;
	}
	return 0;
}