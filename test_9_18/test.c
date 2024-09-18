#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "add.h"
//int factorial(int n);
int factorial(int m)
{
	int i, fact = 1;
	for (i = 1; i <= m; i++)
	{
		fact = fact * i;
	}
	return fact;
}

//int  main()
//{
//	int m;
//	scanf("%d", &m);
//	printf("%d\n", factorial(n+m));
//	return 0;
//}
//void main()
//{
//	int m;
//	scanf("%d", &m);
//	printf("%d\n", factorial((n)+m));
//	
//}

//
//int main()
//{
//	printf("%s",__FILE__);
//	printf("%s", __DATE__);
//	printf("%s", __TIME__);
//	printf("%s", __LINE__);
//	printf("%s", __STDC__); //说明当前vs版本不支持ansic
//}

//#define DEBUG_PRINT printf("file:%s\tline:%d\t \
//date:%s\ttime:%s\n",\
//__FILE__,__LINE__,__DATE__,__TIME__)


#define SQUARE(x) x*x
int main()
{
	int a = 5;
	int ret = SQUARE(a + 1);
	int ret = a * a;
	printf("%d\n", ret);
	return 0;
}
int main()
{
	int a = 1;
	int b = 10;
	a = b + 1;
	a = ++b;
	return 0;
	return 0;
}

//写一个宏，求两个数的较大值
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int m = MAX(a++, b++);
//	/*int m = MAX((a++) > (b++) ? (a++) : (b++));*/
//	printf("m = %d\n", m);
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	return 0;
//}

//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//#define M 10
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int m = MAX(a, MAX(M, 3));
//	printf("M = %d\n", m);
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	return 0;
//}

#define MAX(a,b)  ((a)>(b)?(a):(b))

int Max(int x, int y)
{
	int r = x > y ? x : y;
	return r;
}

int main()
{
	int a = 3;
	int b = -6;
	int m1 = Max(a, b);
	int m2 = MAX(3, -6);
	int m2 = ((a) > (b) ? (a) : (b));
	printf("m1 = %d\n", m1);
	printf("m2 = %d\n", m2);
	return 0;
}

#define Malloc(n,type) (type*)malloc(n*sizeof(type))

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	int* ptr = Malloc(10, int);
	int* ptr = (int*)malloc(10 * sizeof(int));
	return 0;
}

int main()
{
	printf("hello""world\n");
	printf("helloworld\n");
	return 0;
}

#define Print(n,format)  printf("the value of "#n"if format")

int main()
{
	int a = 1;
	Print(a, "%d");
	printf("the value of "#n" is "format"\n", n);
	printf("the value of a is %d\n", a);
	
	int b = 20;
	Print(b, "%d");
	printf("the value of"#n"is "format"\n", n);
	printf("the value of b is %d\n");
	

	float f = 5.6f;
	Print(f, "%f");
	printf("the value of f is %f\n", f);
	return 0;
}

//#define GENERIC_MAX(type)\
//{
//type type##_max(type x, type y)\
//{     \
//return x > y ? x : y;\
//	}
//}

//GENERIC_MAX(int); // int_max
//GENERIC_MAX(float); // float_max

int main()
{
	int r1 = int_max(3, 5);
	printf("%d\n", r1);

	float r2 = float_max(3.1f, 4.5f);
	printf("%f\n", r2); 
	return 0;
}


//#define MAX 100
//int main()
//{
//	printf("%d\n", MAX);
//#undef MAX
//	printf("%d\n", MAX);
// 
// 
//	return 0;
//}


#if 0
#define M -10
int main()
{
	printf("hehe\n");
	return 0;
}

#endif



#define M 3

int main()
{
#if M==0
	printf("hehe\n");
#elif M==1
	printf("haha\n");
#elif M==2
	printf("heihei\n");
#else
	printf("ok");
#endif
	return 0;
}

#define MAX 1
int main()
{
#if defined(MAX)
	printf("hehe\n");
#endif


#ifdef MAX
	printf("hehe\n");
#endif

#if !defined(MAX)
	printf("hehe\n");
#endif

#ifndef MAX
	printf("hehe\n");
#endif
	return 0;
}

