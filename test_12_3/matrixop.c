#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include  <limits.h>
//void rightShift(int arr[], int n, int m) {
//    if (m >= n) {
//        m = m % n;
//    }
//    int temp[m];
//    for (int i = 0; i < m; i++) {
//        temp[i] = arr[n - m + i];
//    }
//    for (int i = n - 1; i >= m; i--) {
//        arr[i] = arr[i - m];
//    }
//    for (int i = 0; i < m; i++) {
//        arr[i] = temp[i];
//    }
//}
//
//int main() {
//    int N, M;
//    scanf("%d %d", &N, &M);
//    int A[N];
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &A[i]);
//    }
//    rightShift(A, N, M);
//    for (int i = 0; i < N; i++) {
//        printf("%d", A[i]);
//        if (i < N - 1) {
//            printf(" ");
//        }
//    }
//    return 0;
//}
void printMatrix(int matrix[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int N;
    scanf("%d", &N);
    int matrix[10][10];
    int sum = 0;
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    int result[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = sum;
        }
    }
    for (int i = 0; i < N; i++) {
        result[0][i] = minVal;
        result[N - 1][i] = minVal;
        result[i][0] = minVal;
        result[i][N - 1] = minVal;
    }
    result[N / 2][N / 2] = maxVal;
    printMatrix(result, N);
    return 0;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 时间复杂度：O(N^2)  什么情况最坏：逆序
// 最好：顺序有序，O(N)
// 插入排序
void InsertSort(int* a, int n)
{
	//  [0, n-1]
	for (int i = 0; i < n - 1; i++)
	{
		// [0, n-2]是最后一组
		// [0,end]有序 end+1位置的值插入[0,end]，保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// O(N^1.3)
//void ShellSort(int* a, int n)
//{
//	/*int gap = 3;
//	for (int j = 0; j < gap; j++)
//	{
//		for (size_t i = j; i < n - gap; i += gap)
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
//	}*/
//
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
//		//printf("gap:%2d->", gap);
//		//PrintArray(a, n);
//	}
//}

// O(N ^ 1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		// +1保证最后一个gap一定是1
		// gap > 1时是预排序
		// gap == 1时是插入排序
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


void AdjustDown(int* a, int n, int parent)
{
	// 先假设左孩子小
	int child = parent * 2 + 1;

	while (child < n)  // child >= n说明孩子不存在，调整到叶子了
	{
		// 找出小的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// 向下调整建堆 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// O(N^2) 最坏
// O(N)   最好
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		// 单趟
		int flag = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}

// O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	// left midi right
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else // a[left] > a[midi]
	{
		if (a[midi] > a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// hoare
int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// 左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[keyi], &a[begin]);
	return begin;
}

// 前后指针
int PartSort2(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = left;

	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	return prev;
}

// 避免有序情况下，效率退化
// 1、随机选key
// 2、三数取中
// 21：14
// 面试手撕，不用三数取中和小区间优化
// 后续讲一下思路即可
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort1(a, left, right);

	// [left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

#include"Stack.h"

void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort2(a, begin, end);
		// [begin, keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}

	STDestroy(&st);
}

// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
// 17:13
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	// 如果[begin, mid][mid+1, end]有序就可以进行归并了
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	// 归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	// gap每组归并数据的数据个数
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [begin1, end1][begin2, end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);

			// 第二组都越界不存在，这一组就不需要归并
			if (begin2 >= n)
				break;

			// 第二的组begin2没越界，end2越界了，需要修正一下，继续归并
			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		printf("\n");

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}