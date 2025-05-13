#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include "PriorityQueue.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
int main()
{
	niuma::PriorityQueue<int, vector<int>, Greater<int>> pq;
	pq.push(4);
	pq.push(5);
	pq.push(6);
	pq.push(7);
	pq.push(8);
	niumo::stack<int, vector<int>> s;
	s.push(1);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	//仿函数 :本质是一个类，这个类重载operator()，他的对象可以像函数一样使用
	//使用仿函数之前要先创建仿函数对象
	Less<int> less;
	int ret = less(s.top(), pq.top());

}