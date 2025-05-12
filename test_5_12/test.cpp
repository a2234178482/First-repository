#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
#include <vector>
void test();
void test_op1();
void test_op2();
int main()
{
	//niuma::test_list1();
	void test();
	void test_op1();
	void test_op2();
}
void test()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);
	for (int i = 1; i <= 3; i++)
		mylist2.push_back(i);
	it = mylist1.begin();
	++it;
	mylist1.splice(it, mylist2);
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	for (auto e : lt)
	{
		cout << e << endl;
	}
	int x = 0;
	cin >> x;
	it = find(lt.begin(), lt.end(), x);
	if (it != lt.end())
	{
		lt.splice(lt.begin(), lt, it, lt.end());
	}
}
void test_op1()
{
	srand(time(0));
	const int N = 1000000;
	list<int> lt1;
	vector<int> v;
	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		lt1.push_back(e);
		v.push_back(e);
	}
	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();
	int begin2 = clock();
	lt1.sort();
	int end2 = clock();
	cout << end1 - begin1 << " ";
	cout << end2 - begin2 << "  ";
}
void test_op2()
{
	srand(time(0));
	const int N = 1000000;
	list<int> lt1;
	list<int> lt2;
	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		lt1.push_back(e);
		lt2.push_back(e);
	}
	int begin1 = clock();
	vector<int> v(lt2.begin(), lt2.end());
	sort(v.begin(), v.end());
	lt2.assign(v.begin(), v.end());
	int end1 = clock();
	int begin2 = clock();
	lt1.sort();
	int end2 = clock();
	cout << end1 - begin1 << " ";
	cout << end2 - begin2 << "  ";
}