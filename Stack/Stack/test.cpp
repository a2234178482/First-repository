#include <iostream>
using namespace std;
#include <stack>
#include <queue>

class Myqueue
{
private:
	stack<int> in;
	stack<int> out;
	int inout()
	{
		while (out.empty())
		{
			out.push(in.top());
			in.pop();
		}
	}
public:
	Myqueue() {};
	void push(int x)
	{
		in.push(x);
	}
	int pop()
	{
		inout();
		int val = out.top();
		out.pop();
		return val;
	}
	int	peek()
	{
		inout();
		return out.top();
	}
};
class mystack
{
private:
	queue<int> q1;
public:
	mystack() {};
	void push(int x)
	{
		int sz = q1.size();
		q1.push(x);
		for (int i = 0; i < sz; i++)
		{
			q1.push(q1.front());
			q1.pop();
		}
	}
	int pop()
	{
		int val = q1.front();
		q1.pop();
		return val;
	}
	int top()
	{
		return q1.front();
	}
	bool empty()
	{
		return q1.empty();
	}
};

class miniStack
{
private:
	stack<int> data;
	stack<int> min;
public:
	void push(int val)
	{
		if (min.empty() || val <= min.top())
		{
			data.push(val);
			min.push(val);
		}
		else
		{
			data.push(val);
			min.push(min.top());
		}
	}
	void pop()
	{
		data.pop();
		min.pop();
	}
	int top()
	{
		return data.top();
	}
	int getmin()
	{
		return min.top();
	}
};