#include <iostream>
#include <cstdio>
using namespace std;
const int maxi = 10000;
int arr[maxi];
int n;
void heapinsert(int i)
{
	while (arr[i] > arr[(i - 1) / 2])
	{
		swap(arr[i], arr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
void heapify(int i, int size)
{
	int l = i * 2 + 1;
	while (l < size)
	{
		int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
		best = arr[best] > arr[i] ? best : i;
		if (best == i)
		{
			break;
		}
		swap(arr[best], arr[i]);
		i = best;
		l = i * 2 + 1;
	}
}
void heapsort1()
{
	for (int i = 0; i < n; i++)
	{
		heapinsert(i);
	}
	int size = n;
	while (size > 1)
	{
		swap(arr[0], arr[--size]);
		heapify(0, size);
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 使用堆排序
	heapsort1();

	// 输出结果
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);

	return 0;
}