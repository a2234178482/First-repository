#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int isleap_yeaer(int x)
//{
//	if ((x % 400 == 0) || (((x % 4) == 0) && (x % 100 != 0)))
//	{
//		printf("%d   ", x);
//		return 1;
//	}
//	else
//		return 0;
//	
//}
//
//int main()
//{
//	int a = 1;
//	int b = 1;
//	scanf("%d",&b);
//	for (int a = 1000; a < b; a++)
//	{
//		isleap_yeaer(a);
//	}
//	return 0;
//}
 // 求两个数的最大公约数
//int measure(int a, int b)
//{
//	int z = 0;
//	while (a % b != 0)
//	{
//		z = a % b;
//		a = b;
//		b = z;
//	}
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数");
//	scanf("%d %d", &a,&b);
//	int result = measure(a, b);
//	printf("%d", result);
//	return 0;
//}

//多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
//int main()
//{
//	int n;
//	printf("请输入要打印的行数");
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int m = 0; m < n; m++)
//			{
//				if (m == i || m + i == n - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	
//	return 0;
// }
//
//void bubble_sort(int arr[],int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int x = 0;
//				x = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = x;
//			}
//		}
//	}
//}


//  内存操作函数memset
//int main()
//{
//	int n, m;
//	int arr[10] = { 0 };
//	scanf("%d %d",&n,&m);
//	memset(arr, 1, 5);
//	for (int i = 0; i <= 9; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//int sort(int arr[], int x)
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int m = 0; m < x -1-i; m++)
//		{
//			if (arr[m] > arr[m + 1]) {
//				int temp = 0;
//				temp = arr[m];
//				arr[m] = arr[m + 1];
//				arr[m + 1] = temp;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	int m;
//	scanf("%d %d", &n, &m);
//	int arr1[n];
//	int arr2[m];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	int arr3[n + m];
//	for (int i = 0; i < n; i++)
//	{
//		arr3[i] = arr1[i];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		arr3[n+i] = arr2[i];
//	}
//	int sz = sizeof(arr3) / sizeof(arr3[0]);
//	sort(arr3, sz);
//	for (int x = 0; x < n + m; x++)
//	{
//		printf("%d ", arr3[x]);
//	}
//	return  0;
//}

//int is_prime(int x)
//{
//	if (x <= 1)
//	{
//		return 0;
//	}
//	for (int a = 2; a * a < x; a++)
//	{
//		if (x % a == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int x = 0;
//	for (int a = 100; a <= 200; a++)
//	{
//		if (is_prime(a))
//		{
//			printf("%d  ", a);
//		}
//	}
//	return 0;
//}

//int is_leap_Year(int x)
//{
//	if ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)))
//	{
//		printf("%d是闰年\n", x);
//	}
//	else
//		printf("%d不是闰年", x);
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//	while (scanf("%d", &year) != EOF )
//	{
//		is_leap_Year(year);
//	}
//}


//int Excel(int x)
//{
//	for (int i = 1; i <= x; i++)
//	{
//		for (int a = i; a <= x; a++)
//		{
//			printf("%d * %d =%d ", i, a, i * a);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a = 0;
//	printf("请输入要打印的乘法口诀表");
//	while (scanf("%d", &a) != EOF)
//	{
//		Excel(a);
//	}
//}

//int Init(int arr[],int sz)
//{
//	int i = 0;
//	for (int i = 0; i < sz; i++){
//		arr[i] = 0;
//	}
//	return 0;
//}
//
//int Print(int arr[],int sz)
//{
//	int i = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d	", arr[i]);
//	}
//	return 0;
//}
//
//
//void  Reverse(int arr[], int sz)
//{
//	int arr1[10] = { 0 };
//	for (int i = 0; i < sz; i++)
//	{
//		arr1[i] = arr[i];
//	}
//	for (int m = sz; m > 0 ; m--)
//	{
//		arr[sz - m] = arr1[m -1];
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr,sz);
//	Reverse(arr, sz);
//	printf("\n");
//	Print(arr, sz);
//	return 0;
//}
