#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 1, n = 1;
//
//	for (n; n <= 9; n++)
//	{
//		for (i; i <= 9; i++)
//			printf("%d*%d=%d\t", n, i, n * i);
//		printf("\n");
//
//	}
////}
//
//int main()
//{
//	int i, n = 1;
//
//	for (n; n <= 9; n++)
//	{
//		for (i = n; i <= 9; i++)
//			printf("%d*%d=%d\t", n, i, n * i);
//		printf("\n");
//
//	}return 0;
//}
//

//int main()
//{
//    int i = 0;
//    
//    while (scanf("%d",&i) != EOF)
//    {
//        
//        if (i >= 140)
//
//            printf("Genius");
//    }
//    return 0;
//}
//int main()
//{
//    int i = 0;
//
//    while (scanf("%d", &i) != EOF)
//    {
//
//        if (i >= 140)
//
//            printf("Genius");
//    }
//    return 0;
//}
//int main()
//{
//    int i;
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 1; i <= n; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//
//    }
//
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//
//	scanf("%d%*c%d%*c%d", &year, &month, &day);//2024-1-20
//
//	printf("%d-%d-%d\n", year, month, day);
//	return 0;
//}
//int main()
//{
//	int a = 5;
//	//a++;//后置++
//	++a;
//
//	printf("%d\n", a);//
//
//	return 0;
//}

//前置++
//int main()
//{
//	int a = 5;
//	int b = ++a;//先+1，后使用
//  //a=a+1, b=a
//	printf("a=%d b=%d\n", a, b);
//
//	return 0;
//}

//后置++
//int main()
//{
//	int a = 5;
//	int b = a++;//先使用，再+1
//	//b=a, a=a+1
//	printf("a=%d b=%d\n", a, b);//a=6 b=5
//
//	return 0;
//}


//int main()
//{
//	int a = 5;
//	int b = --a;//先-1，再使用
//	//a=a-1, b=a
//	printf("a=%d b=%d\n", a, b);//
//
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = a--;//先使用，后-1
//	//b=a, a=a-1
//	printf("a=%d b=%d\n", a, b);//
//
//	return 0;
//}


//int main()
//{
//	int a = 5;
//	printf("%d\n", a--);//
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", +a);
//
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", -a);
//
//	return 0;
//}

//直接写出的字面浮点数，会被编译器直接识别为double
//int main()
//{
//	3.14;//double
//	3.24f;//float
//
//	int a = (int)3.14;
//	printf("%d\n", a);
//	return 0;
//}

//standard
//input
//output

//int main()
//{
//	printf("hehe\n");
//	printf("haha\n");
//	return 0;
//}


//int main()
//{
//	printf("hello \nworld\n");
//
//	printf("hello ");
//	printf("\n");
//	printf("world");
//
//	return 0;
//}




//int main()
//{
//	printf("hehe");
//	return 0;
//}
//
#include <stdio.h>
//


//int main()
//{
//	printf("there are 5 apples\n");
//
//	int n = 0;
//	//给n输入一个值
//
//	printf("there are %d apples\n", n);
//
//	return 0;
//}

//int main()
//{
//	printf("zhangsan will come tonight\n");
//
//	printf("%s will come tonight\n", "zhangsan");
//	printf("%s will come tonight\n", "lisi");
//	printf("%s will come tonight\n", "wangwu");
//	printf("%s will come tonight\n", "cuihua");
//
//
//	return 0;
//}
//
//int main()
//{
//	printf("%s says it is %d o'clock\n", "wangwu", 20);
//
//	return 0;
//}


//int main()
//{
//	int a = -10;
//	printf("%d\n", a);
//	printf("%u\n", a);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%f", &a);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", 123);
//	printf("%5d\n", 123);
//	printf("%-5d\n", 123);
//	printf("%5d\n", 1234567);
//
//	return 0;
//}
//


//#include <stdio.h>
//int main()
//{
//    printf("%f\n", 123.45);
//    printf("%12f\n", 123.45);
//
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    printf("%+d\n", 12);
//    printf("%+d\n", -12);
//
//    return 0;
//}


//int main()
//{
//	//printf("%f\n", 123.45);
//	//printf("%.2f\n", 123.45);
//	//printf("%.1f\n", 123.45);
//
//	printf("%f\n", 0.5);
//	printf("%.2f\n", 0.5);
//	printf("%6.2f\n", 123456.5);
//
//	printf("%*.*f\n", 6, 2, 0.5);
//
//	return 0;
//}


//https://legacy.cplusplus.com/reference/cstdio/printf/?kw=printf
//https://zh.cppreference.com/w/c/io/fprintf


//int main()
//{
//	printf("hello world\n");
//	printf("%s", "hello world\n");
//	printf("%.3s", "hello world\n");
//
//
//	return 0;
//}




//int main()
//{
//	int score = 0;
//	//输入一个成绩
//
//	printf("请输入成绩:");
//	scanf("%d", &score);//& - 取地址符号
//	printf("成绩是: %d\n", score);
//
//	return 0;
//}
//

//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	float x = 0.0f;
//	float y = 0.0f;
//
//	scanf("%d%d%f%f", &i, &j, &x, &y);
//
//	printf("i=%d\n", i);
//	printf("j=%d\n", j);
//	printf("x=%f\n", x);
//	printf("y=%f\n", y);
//
//	return 0;
//}



#include <stdio.h>
//
//int main()
//{
//    int x;
//    float y;
//
//    // 用户输入 "    -13.45e12# 0"
//    scanf("%d", &x);
//    printf("%d\n", x);
//    scanf("%f", &y);
//    printf("%f\n", y);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int x;
//    float y;
//
//    // 用户输入 "    -13.45e12# 0"
//    scanf("%d%f", &x, &y);
//    printf("x=%d\n", x);
//    printf("y=%f\n", y);
//    return 0;
//}
//
//


//int main()
//{
//	int a = 0;
//	int b = 0;
//	float f = 0.0f;
//	int ret = scanf("%d %d %f", &a, &b, &f);
//
//	printf("ret = %d\n", ret);
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("f = %f\n", f);
//
//	return 0;
//}
//



//int main()
//{
//	int a = 0;
//	float b = 0.0f;
//	scanf("%d %f", &a, &b);
//	printf("%d %f\n", a, b);
//
//	return 0;
//}



//int main()
//{
//	char c1 = 0;
//	char c2 = 0;
//	char c3 = 0;
//	scanf(" %c%c%c", &c1, &c2, &c3);
//
//	printf("%c %c %c", c1, c2, c3);
//	
//	return 0;
//}
//



//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxxxxx";
//	char arr2[20] = "xxxxxxxxxxxxxxxxx";
//
//	scanf("%s %s", arr1, arr2);//这里没有写&arr,为什么呢？因为数组名arr就是地址
//	printf("%s %s\n", arr1, arr2);
//
//	return 0;
//}


//int main()
//{
//	char arr[5] = { 0 };
//	scanf("%4s", arr);
//	printf("%s\n", arr);
//
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("a = %d\n", a);
//	return 0;
//}

//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//
//	scanf("%d %d %d", &year, &month, &day);
//
//	printf("%d-%d-%d\n", year, month, day);
//	return 0;
//}