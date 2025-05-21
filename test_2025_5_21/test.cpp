#include "RBTree.h"
#include <iostream>
using namespace std;
int main()
{
	RBTree<int, int> t;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.Insert({e,e});
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}