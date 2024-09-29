#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 10;
}
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = 0; 
//				temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//}
//
//int Find_main_Elem(int arr[], int sz)
//{
//	if (sz == 0)
//	{
//		return -1;
//	}
//	if (sz == 1)
//	{
//		return arr[0];
//	}
//	int i = 0;
//	int x = arr[sz/2];
//	int count = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == x)
//		{
//			count++;
//		}
//	}
//	if (count > sz / 2)
//	{
//		return x;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//
//int main()
//{
//	int *arr = (int*)malloc(10*sizeof(int));
//	if (arr == NULL)
//	{
//		perror("·ÖÅäÊ§°Ü");
//		exit(0);
//	}
//	SL list;
//	SLInit(&list);
//	int count = 0;
//	int i = 0;
//	while (scanf("%d", &i) != EOF)
//	{
//		if (count >= list.capacity)
//		{
//			list.capacity *= 2;
//			arr = (int*)realloc(arr, list.capacity * sizeof(int));
//		}
//		arr[count++] = i;
//	}
//	list.size = count;
//	bubble_sort(arr, list.size);
//	int result = Find_main_Elem(arr, list.size);
//	printf("%d", result);
//	free(arr);
//	return 0;
//}


void move_arr(int arr[], int sz, int n)
{
	if ( n == 0|| sz == 0)
	{
		return;
	}
	n = n % sz;
	if (n == sz)
	{
		return;
	}
	int temp[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[sz - n + i];
	}
	for (int i = sz-1; i >= n; i--)
	{
		arr[i] = arr[i-n];
	}
	for (int m = 0; m < n; m++)
	{
		arr[m] = temp[m];
	}
}
void Print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[m];
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr[i]);
	}
	move_arr(arr, m, n);
	Print(arr, m);
	return 0;
}

























