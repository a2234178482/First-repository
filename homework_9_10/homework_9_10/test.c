#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int sum_number(int a)
//{
//	int sum = 0;
//	int b = 0;
//	while (a > 0)
//	{
//		b = a % 10;
//		sum = sum + b;
//		a = a / 10;
//	}
//	return sum;
//}
//int main()
//{
//	long int a = 0;
//	int result = 0;
//	do
//	{
//		scanf("%ld", &a);
//		if (a < 0)
//		{
//			printf("输入有误，请重新输入");
//		}
//	} while (a < 0);
//	result = sum_number(a);
//	printf("%d", result);
//	return 0;
//}
//
//int main()
//{
//	int a = 20;
//	printf("%p", &a);  //打印地址
//	int* p = &a; // 地址-- 指针
//	// p是指针变量 ——>存放指针（地址）的变量
//	return 0;
//}


//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	return 0;
//}

//int main()
//{
//	int a = 20;
//	int* p = &a;
//	// *p = 100   解引用操作（间接访问操作）*p 等价于a
//	// * 解引用操作符
//	a = 100;
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	printf("%zd\n", sizeof(pa));
//	printf("%zd\n", sizeof(int*));
//	printf("%p\n", pa);
//}


//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	printf("%zd\n", sizeof(pc));
//	printf("%zd\n", sizeof(char*));
//	printf("%p\n", pc);
//	return 0;
//}


//int main() {
//	int a = 0x11223344;
//	char* pa = &a;
//	*pa = 0;
//	
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pc = (char*)&a;
//	printf("pa = %p\n", pa);
//	printf("pa +1 = %p\n", pa + 1);
//	printf("pc = %p\n", pc);
//	printf("pc +1 = %p", pc + 1);
//	return 0;
//}


//int main() {
//	int* pi;
//	char* pc;
//	double* pd;
//	void* pv;
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pc = &a;
//	void* pv = &a;
//	double d = 3.14;
//	void* pv = &d;
//	// pv+1 ----err
//	// *pv ----err
//	return 0;
//}


//int main()
//{
//	const int n = 10;
//	//const 修饰变量后，变量就不能被修改了
//}

//int fib(int n)
//{
//	if (n == 1 )
//	{
//		return 1;
//	}
//	else if (n == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n -2);
//	}
//	}
//
//int main() {
//	int n;
//	printf("请输入斐波那契数列的项数：");
//	scanf("%d", &n);
//	printf("斐波那契数列的第%d项是：%lld\n", n, fib(n));
//	return 0;
//}


//int main() {
//    int a = 0;
//    int m; int c = 1; int d = 0;
//    scanf("%d", &a);
//    for (int i = 0; i < a; i++)
//    {
//        if (a >= 2)
//        {
//            m = c + d;
//            d = c;
//            c = m;
//        }
//        else
//        {
//            printf("值为1");
//        }
//        printf("%d", m);
//    }
//    return 0;
//}


////递归实现阶乘
//int jiechen(int x)
//{
//	if (x == 0 || x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return x * jiechen(x - 1);
//	}
//}
//
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	int result = jiechen(m);
//	printf("%d", result);
//}

// 递归求一个十进制的各位和
//int Digitsum(int x)
//{
//	int sum = 0;
//	if (x > 0)
//	{
//		int m = 0;
//		int n = 0;
//		m = x % 10;
//		n = x / 10;
//		sum =  m + Digitsum(n);
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", a);
//	int result = Digitsum(a);
//	printf("%d", result);
//	return 0;
//}

//// 非递归求n的阶乘
//
//int jiecheng(int m)
//{
//	int i = 0;
//	int m = 1;
//	for (i = 1; i <= m; i++)
//	{
//		m *= i;
//	}
//	return m;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int result = jiecheng(a);
//	printf("%d", result);
//	return 0;
//}

//  递归打印一个十进制整数的每一位
char Print(int x)
{
	int m = 0;
	int n = 0;
	if (x < 10)
	{
		printf("%d\n", x);
	}
	else
	{
		m = x % 10;
		printf("%d\n", m);
		n = x / 10;
		return Print(n);
	}
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	Print(m);
	return 0;
}