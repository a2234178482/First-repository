#include <iostream>
#include <vector>
using namespace std;
class reversePairs
{
public:
	static int reversePairs1(vector<int> arr)
	{
		vector<int>  help(arr.size());
		return counts(arr, 0, arr.size() - 1,help);
	}
private:
	static int counts(vector<int>& arr, int l,int r, vector<int> help)
	{
		if (l > r)
		{
			return 0;
		}
		int m = (l + r) / 2;
		return counts(arr, l, m, help)
			+ counts(arr, m + 1, r, help)
			+ merge(arr, l, m, r, help);
	}
	static int merge(vector<int>& arr, int l, int m, int r, vector<int>& help)
	{
		int ans = 0;
		for (int i = l, j = m + 1; i <= m; i++)
		{
			while (j <= r && (long long)arr[i] > (long long)arr[j]*2)
			{
				j++;
			}
			ans += j - (m + 1);
		}
		int i = l;
		int a = l;
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
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
		return ans;
	}
};