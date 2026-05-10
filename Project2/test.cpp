#include <iostream>
using namespace std;

// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
int main()
{
	cout << Add(1, 2) << endl;
}