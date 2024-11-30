#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int search(int list[], int n, int x) {
//	for (int i = 0; i < n; i++) {
//		if (list[i] == x ) {
//			return i;
//		}
//	}
//	return -1;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	int arr[n];
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	int k;
//	scanf("%d", &k);
//	int ret = search(arr, n, k);
//	if (ret >= 0) {
//		printf("index = %d", ret);
//	}
//	else {
//		printf("Not found");
//	}
//}
//int main() {
//	int k;
//	scanf("%d", &k);
//	int arr[k];
//	for (int i = 0; i < k; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < k / 2; i++) {
//		if (arr[i] != arr[k - i - 1]) {
//			printf("0");
//			return 0;
//		}
//	}
//	printf("1");
//}
//int main() {
//    int k;
//    scanf("%d", &k);
//    int arr[k];
//    int result[k]; 
//    for (int i = 0; i < k; i++) {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 0; i < k; i++) {
//        int count = 0;
//        for (int j = 0; j < i; j++) {
//            if (arr[j] <= arr[i]) {
//                count++;
//            }
//        }
//        result[i] = count; 
//    }
//    for (int i = 0; i < k; i++) {
//        printf("%d ", result[i]); 
//    }
//    return 0;
//}
void ShellSort(int* a, int n)
{
	int gap = 3;
	for (int j = 0; j < gap; j++)
	{
		for (size_t i = j; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
#define MAX_NUM 100

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    // 读取输入的整数
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 使用哈希表记录每个整数出现的次数
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    int range = max_val - min_val + 1;
    int count[range];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i] - min_val]++;
    }

    // 找出出现次数最多的整数及其出现次数
    int max_count = 0;

    for (int i = 0; i < range; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    // 输出结果
    for (int i = 0; i < range; i++) {
        if (count[i] == max_count) {
            printf("%d %d\n", i + min_val, max_count);
        }
    }

    return 0;
}

//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//// 时间复杂度：O(N^2)  什么情况最坏：逆序
//// 最好：顺序有序，O(N)
//// 插入排序
//void InsertSort(int* a, int n)
//{
//	//  [0, n-1]
//	for (int i = 0; i < n - 1; i++)
//	{
//		// [0, n-2]是最后一组
//		// [0,end]有序 end+1位置的值插入[0,end]，保持有序
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//
//// O(N^1.3)
////void ShellSort(int* a, int n)
////{
////	/*int gap = 3;
////	for (int j = 0; j < gap; j++)
////	{
////		for (size_t i = j; i < n - gap; i += gap)
////		{
////			int end = i;
////			int tmp = a[end + gap];
////			while (end >= 0)
////			{
////				if (tmp < a[end])
////				{
////					a[end + gap] = a[end];
////					end -= gap;
////				}
////				else
////				{
////					break;
////				}
////			}
////			a[end + gap] = tmp;
////		}
////	}*/
////
////	int gap = n;
////	while (gap > 1)
////	{
////		// +1保证最后一个gap一定是1
////		// gap > 1时是预排序
////		// gap == 1时是插入排序
////		gap = gap / 3 + 1;
////
////		for (size_t i = 0; i < n - gap; ++i)
////		{
////			int end = i;
////			int tmp = a[end + gap];
////			while (end >= 0)
////			{
////				if (tmp < a[end])
////				{
////					a[end + gap] = a[end];
////					end -= gap;
////				}
////				else
////				{
////					break;
////				}
////			}
////			a[end + gap] = tmp;
////		}
////		//printf("gap:%2d->", gap);
////		//PrintArray(a, n);
////	}
////}
//
//// O(N ^ 1.3)
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		// +1保证最后一个gap一定是1
//		// gap > 1时是预排序
//		// gap == 1时是插入排序
//		gap = gap / 3 + 1;
//
//		for (size_t i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//
//
//void AdjustDown(int* a, int n, int parent)
//{
//	// 先假设左孩子小
//	int child = parent * 2 + 1;
//
//	while (child < n)  // child >= n说明孩子不存在，调整到叶子了
//	{
//		// 找出小的那个孩子
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HeapSort(int* a, int n)
//{
//	// 向下调整建堆 O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//
//// O(N^2) 最坏
//// O(N)   最好
//void BubbleSort(int* a, int n)
//{
//	for (int j = 0; j < n; j++)
//	{
//		// 单趟
//		int flag = 0;
//		for (int i = 1; i < n - j; i++)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//// O(N^2)
//void SelectSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//
//	while (begin < end)
//	{
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; ++i)
//		{
//			if (a[i] > a[maxi])
//			{
//				maxi = i;
//			}
//
//			if (a[i] < a[mini])
//			{
//				mini = i;
//			}
//		}
//
//		Swap(&a[begin], &a[mini]);
//		if (begin == maxi)
//			maxi = mini;
//
//		Swap(&a[end], &a[maxi]);
//		++begin;
//		--end;
//	}
//}
//
//int GetMidi(int* a, int left, int right)
//{
//	int midi = (left + right) / 2;
//	// left midi right
//	if (a[left] < a[midi])
//	{
//		if (a[midi] < a[right])
//		{
//			return midi;
//		}
//		else if (a[left] < a[right])
//		{
//			return right;
//		}
//		else
//		{
//			return left;
//		}
//	}
//	else // a[left] > a[midi]
//	{
//		if (a[midi] > a[right])
//		{
//			return midi;
//		}
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//}
//
//// 避免有序情况下，效率退化
//// 1、随机选key
//// 2、三数取中
//// 21：14
//// 面试手撕，不用三数取中和小区间优化
//// 后续讲一下思路即可
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	// 小区间优化，不再递归分割排序，减少递归的次数
//	if ((right - left + 1) < 10)
//	{
//		InsertSort(a + left, right - left + 1);
//	}
//	else
//	{
//		// 三数取中
//		int midi = GetMidi(a, left, right);
//		Swap(&a[left], &a[midi]);
//
//		int keyi = left;
//		int begin = left, end = right;
//		while (begin < end)
//		{
//			// 右边找小
//			while (begin < end && a[end] >= a[keyi])
//			{
//				--end;
//			}
//
//			// 左边找大
//			while (begin < end && a[begin] <= a[keyi])
//			{
//				++begin;
//			}
//
//			Swap(&a[begin], &a[end]);
//		}
//
//		Swap(&a[keyi], &a[begin]);
//		keyi = begin;
//		// [left, keyi-1] keyi [keyi+1, right]
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}