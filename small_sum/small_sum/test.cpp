#include <iostream>
using namespace std;
const int MAXI = 1000000;
int n;
int arr[MAXI];
int help[MAXI];
long long small_sum(int l, int r)
{
	if (l == r)
	{
		return 0;
	}
	int mid = (l + r) >> 1;
	return small_sum(l, mid) + small_sum(mid + 1, r) + merge(l, m, r);
}
long long merge(int l, int m, int r)
{
	long long ans = 0;
	for (int j = m + 1, i = l, sum = 0; j <= r; j++)
	{
		while (i <= m && arr[i] <= arr[j])
		{
			sum += arr[i++];
		}
		ans += sum;
	}
	int i = l; 
	int a =l ;
	int b = m + 1;
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
		help[i++] = arr[r++];
	}
	for (i = l; i <= r; i++) {
		arr[i] = help[i];
	}

	return ans;
}
