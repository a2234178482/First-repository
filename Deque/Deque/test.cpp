#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class MycircularQueue
{
private:
	deque<int> dq;
	int size;
	int limit;
public:
	MycircularQueue(int k) :size(0), limit(k) {}
	bool isfull()
	{
		return size == limit;
	}
	bool isempty()
	{
		return size == 0;
	}
	bool insertfront(int val)
	{
		if (isfull())
		{
			return false;
		}
		dq.push_front(val);
		size++;
		return true;
	}
	bool insertback(int val)
	{
		if (isfull())
		{
			return false;
		}
		dq.push_back(val);
		size++;
	}
	bool deletefront()
	{
		if (isempty())
		{
			return false;
		}
		dq.pop_front();
		size--;
		return true;
	}
	bool deleterear()
	{
		if (isempty())
		{
			return false;
		}
		dq.pop_back();
		return true;
	}
	int getfront()
	{
		if (isempty())
		{
			return -1;
		}
		int val=dq.front();
		return val;
	}
	int getrear()
	{
		if (isempty())
		{
			return false;
		}
		int val = dq.back();
		return val;
	}
};
class arraycircularqueue
{
private:
	vector<int> arr;
	int front, rear, limit, size;
public:
	arraycircularqueue(int k) : arr(k), front(0), rear(0), limit(k), size(0) {}
	bool isfull()
	{
		return limit == size;
	}
	bool isempty()
	{
		return size == 0;
	}
	int getfront()
	{
		if (isempty())
		{
			return -1;
		}
		return arr[front];
	}
	int getrear()
	{
		if (isempty())
		{
			return -1;
		}
		return arr[rear];
	}
	bool insertfront(int val)
	{
		if (isfull())
		{
			return false;
		}
		if (isempty())
		{
			front = rear = 0;
			arr[0] = val;
		}
		else
		{
			front = (front == 0) ? limit - 1 : front - 1;
			arr[front] = val;
		}
		size++;
		return true;
	}
	bool insertrear(int val)
	{
		if (isfull()) {
			return -1;
		}
		if (isempty())
		{
			front = rear = 0;
			arr[0] = val;
		}
		else
		{
			rear = (rear == limit - 1) ? 0 : rear + 1;
			arr[rear] = val;
		}
		size++;
		return true;
	}
	bool deletefront()
	{
		if (isempty()) {
			return false;
		}
		front = (front == limit - 1) ? 0 : front + 1;
		size--;
		return true;
	}
	bool deletefront()
	{
		if (isempty()) {
			return false;
		}
		rear = (rear == 0) ? (limit - 1) : (rear - 1);
		size--;
		return true;
	}
};