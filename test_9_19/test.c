#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	double r = sqrt(16);
	printf("%lf\n", r);
	return 0;
}

//函数的定义---实现
int Add(int x, int y)
{
	int z = x + y;
	return z;  //return ---返回
}

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	//写一个加法函数，实现两个数的加法操作
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//使用Add函数完成任务
	int c = Add(a, b);
	//输出
	printf("c = %d\n", c);
	return 0;
}

//写一个函数，这个函数只需要打印呵呵就行

void Print(void)
{
	printf("呵呵\n");
}

int main()
{
	Print();
	return 0;
}

//实现一个函数，求出两个整数的较大值
int get_max(int x, int y) // 函数定义中，函数名后面括号中的参数就是形式参数，简称形参
{
	return (x > y ? x : y);
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int m = get_max(a, b); // 调用函数时，传递给函数的参数就是实参，实际参数
	printf("%d\n", m);
	return 0;
}

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	//写一个加法函数，实现两个数的加法操作
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//使用Add函数完成任务
	int c = Add(a, b); //函数的调用
	//输出
	printf("c = %d\n", c);
	return 0;
}

int is_odd(int m)
{
	if (m % 2 == 1)
	{
		return 1;
	}
	else
		return 0;
}

int is_odd(int m)
{
	return m % 2;
}

int main()
{
	int n = 0;
	scanf("%d ", &n);
	//如果是奇数，就返回1，如果是偶数就返回0
	int r = is_odd(n);
	if (r == 1)
	{
		printf("是奇数\n");
	}
	else
	{
		printf("是偶数\n");
	}
	return 0;
}

//void test(int m)
//{
//	if (m <= 0)
//	{
//		return;
//	}
//	//打印
//	int i = 0;
//	for (i = 1; i <= m; i++)
//	{
//		printf("%d", i);
//	}
//}


int main()
{
	int n = 0;
	scanf("%d", &n);
	//如果n是正数，就打印1-n的数字
	test(n);
	return 0;
}


int test()
{
	int n = 0;
	scanf("%d", &n);
	if (n < 4)
	{
		return 3.5;
	}
}
int main()
{
	int r = test();
	printf("%d\n", r);
	return 0;
}

void set_arr(int arr[], int sz)
{
	int i = 0;
	for (int i = 0; i < sz; i++)
	{
		arr[i] = -1;
	}
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//写一个函数将arr数组的内容全部改成-1
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	set_arr(arr, sz);
	//写一个函数打印数组中所有内容
	print_arr(arr, sz);
	return 0;
}

void Print(int brr[][5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", brr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	Print(arr, 3, 5);
	return 0;
}

//计算某年某月有多少天
// 设计函数 get_days_of_months,来完成
//1   2    3   4  5   6   7   8   9   10  11  12
//31 28/29 31 30  31  30  31  31  30   31 30   31

//闰年的判断
//1.能被4整除，但是不能被100整除
//2.能被400整除
//是闰年返回1；不是返回0

int is_leap_year(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int get_days_of_month(int y, int m)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = days[m];
	if (is_leap_year(y) && m == 2)
	{
		day++;
	}
	return day;
}

int main()
{
	int year = 0;
	int month = 0;
	scanf("%d %d", &year, &month);
	int day = get_days_of_month(year, month);
	printf("%d\n", day);
	return 0;
}

//int get_days_of_month(int y, int m)
//{
//	//int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
//	//0  1  2  3  4 ...
//	int day = 0;
//	switch (m)
//	{
//	case 2:
//		day = 28;
//		break;
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		day = 31;
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		day = 30;
//	}
//
//	if (is_leap_year(y) && m == 2)
//		day += 1;
//
//	return day;
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	scanf("%d %d", &year, &month);//2024 1
//
//	int day = get_days_of_month(year, month);
//
//	printf("%d\n", day);
//
//	return 0;
//}

int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
}

int main()
{
	printf("%zd\n", strlen("abcdef"));
}

//函数的声明 - 是在告诉编译器，有一个函数叫什么，参数是什么，返回类型是什么
//int is_leap_year(int y);
//
//int main()
//{
//	int y = 0;
//	scanf("%d", &y);
//	int r = is_leap_year(y);//函数的调用
//	if (r == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}