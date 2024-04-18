#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int arr1[5] = { 1,23,4,5,6 }; //完全初始化
//	int arr2[100] = { 1,23,4,56,7,5,6,8,9, };//不完全初始化
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int arr[10];//int 是数组元素的类型
//	//数组arr的类型是int[10]
//
//	return 0;
//}
//int main()
//{
//	int arr1[5];//int [5]
//	int arr2[6]; //int [6]
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[5]);//[] --下标引用操作符
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	//printf("%d",arr[10]); --err
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &i);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);
//	}
//
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	scanf("%d %d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 1,2,3,4,5 };
//	int arr3[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr4[] = { 0 };   这个数组几个元素
//
//	return 0;
//}
//%p是专门用来打印地址的
//特点：16进制的形式打印的，同时最前面的0不会省略
//%x是16进制形式的打印
//int main()
//{
//	
//	int arr[10] = { 0,1,2,3,4,5,6,7,8 };
//	for (int i = 0; i < 10; i++)
//	{
//		printf("&arr[%d] = %#x\n,i,&arr[i]");
//	}
//	return 0;
//}
//strlen求字符串长度，只针对求字符串
//int main()
//{
//	int arr[10] = { 1,2,3,4,5 };
//	printf("%zd\n", sizeof(arr));  //计算的是整个数组，单位是字节
//	printf("%zd", sizeof(int[10]));
//	printf("%zd\n", sizeof(arr[0])); //计算的是一个元素占据的空间的大小，单位是字节
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[10]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	//int arr1[3][5] = {1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7};//完全初始化
//	//int arr2[3][5] = { 1,2 };//完全初始化，剩余的元素默认初始化为0
//	//int arr3[3][5] = { 1,2,3,4,5,6,7 };
//	//int arr4[3][5] = { {1,2},{3,4,5 }, { 6,7 }};
//
//	//int arr[3][5] = { (1,2),(3,4)};//err
//
//	return 0;
//}
//

//int main()
//{
//	//int arr[][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
//
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	printf("%d\n", arr[1][2]);
//	printf("%d\n", arr[0][0]);
//	//printf("%d\n", arr[3][5]);//err
//
//	return 0;
//}

//
//int main()
//{
//	int arr[3][5] = { 0 };
//	//输入
//	int i = 0;
//	for (i = 2; i >=0; i--)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//输出
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][5] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	//int arr1[10];
//	//int arr2[3+5];
//	//int arr3[] = {1,2,3,4};
//
//	//int score[40];
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//30
//	int arr[n];//
//
//	return 0;
//}

#include <windows.h>
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	char arr1[] = "welcome to bit!!!!!";
//	char arr2[] = "###################";
//
//	int left = 0;
//	int right = strlen(arr1)-1;
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//单位是毫秒
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}


//题目：
//在一个有序的数组中查找指定的数，是否存在，存在则打印下标，不存在则说明不存在！
//

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);//7
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是:%d\n", i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("找不到了\n");
//
//	return 0;
//}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz -1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		
		else
		{
			printf("找到了，下标是%d", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到了");
	}
	return 0;
}