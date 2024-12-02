#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define M 100
//int c(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n < 1 || n > M) {
//        return 1;
//    }
//    int a[M];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    qsort(a, n, sizeof(int), c);
//    int m = 0;
//    int k = 1;
//    int p = a[0];
//    int r[M];
//    int t = 0;
//    for (int i = 1; i < n; i++) {
//        if (a[i] == p) {
//            k++;
//        }
//        else {
//            if (k > m) {
//                m = k;
//                t = 0;
//                r[t++] = p;
//            }
//            else if (k == m) {
//                r[t++] = p;
//            }
//            p = a[i];
//            k = 1;
//        }
//    }
//    if (k > m) {
//        m = k;
//        t = 0;
//        r[t++] = p;
//    }
//    else if (k == m) {
//        r[t++] = p;
//    }
//    for (int i = 0; i < t; i++) {
//        printf("%d %d\n", r[i], m);
//    }
//    return 0;
//}
//typedef struct {
//    int v;
//    int i;
//}P;
//int c(const void* a, const void* b) {
//    P pa = *(P*)a;
//    P pb = *(P*)b;
//    if (pa.v != pb.v) {
//        return pb.v - pa.v;
//    }
//    return pa.i - pb.i; 
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n < 1 || n > M) {
//        return 0;
//    }
//    int a[M];
//    P p[M];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//        p[i].v = a[i];
//        p[i].i = i;
//    }
//    qsort(p, n, sizeof(P), c);
//    int r[M] = { 0 };
//    int cr = 1;
//    for (int i = 0; i < n; i++) {
//        if (i == 0 || p[i].v != p[i - 1].v) {
//            cr = i + 1;
//        }
//        r[p[i].i] = cr;
//    }
//    for (int i = 0; i < n; i++) {
//        printf("%d", r[i]);
//        if (i < n - 1) {
//            printf(" ");
//        }
//    }
//    return 0;
//}
void Swap(int* a, int* b);
//void QuickSort(int* a, int left, int right) {
//	int begin = left, end = right;
//	int keyi = left;
//	while (begin < end) {
//		while (begin < end && a[end] >= keyi) {
//			end--;
//		}
//		while (begin < end && a[begin] <= keyi) {
//			begin++;
//		}
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[keyi], &a[begin]);
//	keyi = begin;
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi+1, right);
//}
//void QuickSort(int* a, int left, int right) {
//	int begin = left, end = right;
//	int keyi = left;
//	while (begin < end) {
//		while (begin < end && a[end] >= keyi) {
//			end--;
//		}
//		while (begin < end && a[begin] <= keyi) {
//			begin++;
//		}
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[begin], &a[keyi]);
//	keyi = begin;
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}
void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				--end;
			}
		}
		a[end + 1] = tmp;
	}
}
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
