#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//int main() {
//    int n = 9;
//    float* pFloat = (float*)&n; // int* 转换为 float*
//    printf("n的值为: %d\n", n);
//    printf("*pFloat的值为: %f\n", *pFloat);
//
//
//    *pFloat = 9.0; // 将 *pFloat 的值设置为 9.0
//    printf("num的值为: %d\n", n);
//    printf("*pFloat的值为: %f\n", *pFloat);
//    return 0;
//}
//void move_elem(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	for (int i = 0; i < sz && left < right;)
//	{
//		if (arr[left] % 2 != 0)
//		{
//			left++;
//			i++;
//		}
//		else
//		{
//			if (arr[right] % 2 == 0)
//			{
//				right--;
//			}
//			else
//			{
//				int a = 0;
//				a = arr[left];
//				arr[left] = arr[right];
//				arr[right] = a;
//				left++;
//				right--;
//				i++;
//			}
//		}
//	}
//}
//void Print(int arr[], int sz)
//{
//	
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d，", arr[i]);
//		}
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int arr[a];
//	for (int i = 0; i < a; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move_elem(arr, sz);
//	Print(arr, sz);
//	return 0;
//}



//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		for (int m = 0; m < sz - 1 - i; m++)
//		{
//			if (arr[m] > arr[m + 1])
//			{
//				int temp = 0;
//				temp = arr[m];
//				arr[m] = arr[m+1];
//				arr[m+1] =temp;
//			}
//		}
//	}
//}
//void bin_search(int arr[], int left,int right,int key)
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("下标为%d", mid);
//			return;
//		}
//	}
//	
//	if (left > right)
//	{
//		printf("找不到了");
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,5,7,8,9,3,4,78,15,47 } ;
//	printf("请输入你要查找的元素");
//	int key = 0;
//	scanf("%d", &key);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	bubble_sort(arr, sz);
//	bin_search(arr,left,right,key);
//	return 0;
//}
//
//
//int drink_sum(int money, int prize)
//{
//	int sum = 0;
//	int ret = 0;
//	int temp = 0;
//	sum = money / prize;
//	ret = sum;
//	while (ret / 2 != 0)
//	{
//		temp = ret;
//		ret = ret / 2;
//		sum += ret;
//		ret = temp % 2 + ret;
//	}
//	return sum;
//}
//
//
//int main()
//{
//	int money = 0;
//	int prize = 0;
//	scanf("%d %d", &money, &prize);
//	int m = drink_sum(money, prize);
//	printf("一共能买%d瓶水", m);
//	return 0;
//}



//int main()
//{
//	int i = 13;
//	for(int i = 1; i <=13; i+=2)
//	{
//		for (int j = (13 - i) / 2; j > 0; --j)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= i; ++k)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 11; i >= 1; i -= 2)
//	{
//		for (int j = (13 - i) / 2; j > 0; --j)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= i; ++k)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int naic_number(int n,int digit)
//{
//	double sum = 0;
//	int x = 0;
//	int temp = n;
//	while (n != 0)
//	{
//		x = n % 10;
//		sum += pow(x, digit);
//		n = n / 10;
//	}
//	return sum == temp;
//}
//
//
//int main()
//{
//	int i;
//	int digit;
//	for (i = 100; i < 1000; i++)
//	{
//		digit = 3;
//		if (naic_number(i, digit))
//		{
//			printf("%d\n", i);
//		}
//	}
//	for (i = 1000; i < 10000; i++)
//	{
//		digit = 4;
//		if (naic_number(i, digit))
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//
//}

//int sum_number(int x)
//{
//	int y = x;
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		sum += x;
//		x = x * 10 + y;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int result = sum_number(n);
//	printf("%d", result);
//	return 0;
//}

//int main()
//{
//	int x = 12;
//	int y = 5;
//	printf("%d\n", x ^ y);
//	printf("%d", x & y);
//}
// 不使用中间变量交换两个变量的值
//void change(int x, int y)
//{
//	int x = 10; 
//	int y = 12;
//	x = x + y;
//	y = x - y;
//	x = x - y;
//}

//void change(int* a, int* b)
//{
//	*a = *a ^ *b;
//	*b = *a ^ *b;
//	*a = *a ^ *b;
//}


int NumberOf1(int n) {
	int count = 0;
	while (n)
	{
		n &=n - 1;
		count++;
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int result = NumberOf1(n);
	printf("%d", result);
	return 0;
}