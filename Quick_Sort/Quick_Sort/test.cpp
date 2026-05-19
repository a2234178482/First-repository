#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
class Quick_Sort
{
public:
	vector<int> sortArr(vector<int>& nums)
	{
		if (nums.size() > 1)
		{
			Quicksort(nums, 0, nums.size() - 1);
		}
		return nums;
	}
private:
	void swap(vector<int>& arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	void Quicksort(vector<int>& arr,int l,int r)
	{
		if (l >= r)
		{
			return;
		}
		int x = arr[l + rand() % (r - l + 1)];
		int mid = partition(arr, l, r, x);
		Quicksort(arr, 0, mid);
		Quicksort(arr, mid+1, arr.size()-1);
	}
	int partition(vector<int>& arr,int l,int r,int x)
	{
		int left = l, right = r;
		while (left <= right)
		{
			/*while (arr[left] < x&&left<=right)left++;
			while (arr[right] > x && left <= right)right++;
			swap(arr[left], arr[right]);*/
			int a = l, xi = 0;
			for (int i = l; i <= r; i++)
			{
				if (arr[i] <= x)
					swap(arr, a, i);
					if (arr[a] == x)
					{
						xi = a;
					}
					a++;
			}
			swap(arr, xi, a - 1);
			return a - 1;
		}
	}
	int first, last;
	void Quicksort1(vector<int>& arr, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int x = arr[l + rand() % (r - l + 1)];
		partition1(arr, l, r, x);
		int left = first, right = last;
		Quicksort1(arr, l, left -1);
		Quicksort1(arr, right+1, r);
	}
	int partition1(vector<int>& arr, int l, int r, int x)
	{
		first = l;
		last = r;
		int i = l;
		while (l < last)
		{
			if (arr[i] == x)
			{
				i++;
			}
			else if (arr[i] < x)
			{
				swap(arr, first++, i++);
			}
			else
			{
				swap(arr, i, last--);
			}
		}
	}
};
vector<int> sortArray(vector<int>& nums) {
	srand(time(nullptr));          // 随机种子
	Quick_Sort solution1;
	return solution1.sortArr(nums);
}
class randomizedSelect
{
private:
	static int first, last;
	static void swap(vector<int>& arr, int i, int j)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = arr[i];
	}
	static void partition(vector<int>& arr, int l, int r, int x)
	{
		first = l;
		last = r;
		int i = l;
		while (i <= last)
		{
			if (arr[i] == x)
			{
				i++;
			}
			else if (arr[i] < x)
			{
				swap(arr, first++, i++);
			}
			else
			{
				swap(arr, i, last--);
			}
		}
	}
	static int randomizedselect(vector<int>& arr, int i)
	{
		int ans = 0;
		for (int l = 0, r = arr.size() - 1; l <= r)
		{
			int x = arr[l + rand() % (r - l + 1)];
			partition(arr, l, r, x);
			if (i < first)
			{
				r = first - 1;
			}
			else if (i > last)
			{
				l = last + 1;
			}
			else
			{
				ans = arr[i];
				break;
			}
		}
		return ans;
	}
};