#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//    int n = 0;
//    int m = 0;
//    int arr[10][10] = { 0 };
//    scanf("%d %d", &n, &m);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", arr[j][i]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//int main()
//{
//    int arr[10] = { 0 };
//    for (int i = 0; i <= 9; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 9; i >= 0; i--)
//    {
//        printf("%d", arr[i]);
//    }
//
//    return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sum = 0;
//	float ave = 0;
//	printf("请输入10个整数：\n");
//	for (int i = 0; i <= 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 10; i++) {
//		sum += arr[i];
//	}
//	ave = sum / 10;
//	printf("%lf", ave);
//
//	return 0;
//}
//int main()
//{
//    int i;
//    int A[10];
//    int B[10];
//    int t[10];
//    printf("请输入数组A：");
//    for (i = 0; i < 10 ; i++)
//    {
//        scanf(" %d", &A[i]);
//    }
//    printf("请输入数组B：");
//    for (i = 0; i < 10; i++)
//    {
//        scanf(" %d", &B[i]);
//    }
//    for (i = 0; i < 10; i++)
//    {
//        t[i] = A[i];
//        A[i] = B[i];
//        B[i] = t[i];
//    }
//    printf("数组A是\n");
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", A[i]);
//    }
//    printf("\n");
//    printf("数组B是\n");
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", B[i]);
//    }
//    printf("\n");
//    return 0;
//}
//#include <math.h>
//int main()
//{
//	double r = sqrt(16);
//	printf("%lf", r);
//	return 0;
//
//}
//函数的定义-实现
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//
//}
//int Add(int x, int y)
//{
//	return x + y;
//
//}
//int main()
//{
//	int a;
//	int b;
//	scanf("%d %d",&a ,& b);
//	int c = Add(a, b);
//	printf("c = %d\n", c);
//}
//int is_old(int m)
//{
//	if (m % 2 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int is_old(int m) 
//{
//	return (m % 2);
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//如果是奇数，就返回1，如果是偶数，就返回0
//	int r = is_old(n);
//	if (r == 1)
//		printf("是奇数\n");
//	else
//		printf("是偶数\n");
//	return 0;
//
//
//}
//void test(int m) 
//{
//	if (m <= 0)
//		return;
//	int i = 0;
//	for (i = 0; i <= m; i++)
//	{
//		printf("%d", i);
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9.10 };
//	for (i = 0; i <= 12; i++) {
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//
//}
//
//
//int count = 0;
//int Fib(int n)
//{
//	if (n == 3)
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int r = Fib(n);
//	printf("%d", r);
//	printf("count=%d\n",count);
//	return 0;
//}
​
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n > 0) {
//		printf("%d是正数", n);
//	}
//	else if (n == 0) {
//		printf("%d", n);
//	}
//	else {
//		printf("%d is 负数", n);
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n > 0) {
//		printf("%d是正数", n);
//	}
//	else if (n == 0) {
//		printf("%d", n);
//	}
//	else {
//		printf("%d is 负数", n);
//	}
//
//}​;

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n) {
//	case1:
//	case2:
//	case3:
//	case4:
//	case5:
//		printf("hardworking");
//		break;
//	case6:
//	case7:
//		printf("take a rest");
//		break;
//	}
//}

int main()
{
	int n = 0;
	while (n <= 10)
	{
		printf("%d\n",n);
		n = n+1;
	}
	return 0;
}