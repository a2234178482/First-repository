#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class mycirclequeue {
private:
	vector<int> q;
	int l, r, sz, limit;
public:
    bool empty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == limit;
    }
    int rear()
    {
        if (empty()) { return -1 };
		int last = (r == 0) : limit - 1 : r - 1;
    }
    int front()
    {
        if (empty()) { return -1 };
        return q[l];
    }
    int dequeue()
    {
		if (empty()) { return -1; }
        l = (l + 1) % limit;
        sz--;
        return true;
    }
    int enqueue(int x)
    {
        if (isFull()) { return -1; }
        q[r] = x;
        r = (r + 1) % limit;
        sz++;
        return true;
	}
};
