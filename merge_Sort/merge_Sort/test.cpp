#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
int arr[MAXN];
int help[MAXN];
int n;
void merge(int l, int m, int r)
{
	int i = l, a = l, b = m + 1;
	while (a <= m && b <= r)
	{
		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while (a <= m)
	{
		help[i++] = arr[a++];
	}
	while (b <= r)
	{
		help[i++] = arr[b++];
	}
	for (int count = 0; count < r; count++)
	{
		arr[count] = help[count];
	}
}
void mergesort1(int l, int r)
{
		if (l == r) {return;}
		int mid = (l + r) / 2;
		mergesort1(l, mid);
		mergesort1(mid+1, r);
		merge(l,mid, r);
}
void mergesort2()
{
	for (int step = 1; step < n; step<<=1)
	{
		int l = 0;
		while (l < n)
		{
			int mid = l + step - 1;
			if (mid + 1 > n) { break; }
			int r = min(l + (step <<= 1) - 1, n - 1);
			merge(l, mid, r);
			l = r + 1;
		}
	}
}