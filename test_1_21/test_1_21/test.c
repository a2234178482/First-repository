#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a  = 1;
//	int b = 2 ;
//	int c = 3;
//	(void)scanf("%d,%d, %d", &a, &b, &c);
//	if ((a > b) && (a > c) && (b > c))
//	{
//		printf("%d%d%d", a, b, c);
//	}
//	else if ((a > b) && (a < c))
//	{
//		printf("%d%d%d", c, a, b);
//	}
//	else if ((a < b) && (a > c))
//	{
//		printf("%d%d%d", b, a, c);
//	}
//	else if ((a < b) && (a < c) && (b > c))
//	{
//		printf("%d%d%d", b, c, a);
//	}
//	else if ((a > b) && (a > c) && (b < c))
//	{
//		printf("%d%d%d", a, c, b);
//	}
//	else
//	{
//		printf("%d%d%d", c, b, a);
//	}
//	return  0;
//}
//int main()
//{
//    int a = 1, b = 1, c = 1;
//
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if (a + b > c && a + c > b && b + c > a)
//        {
//            if (a == b && b == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || b == c || a == c)
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}
//int main()
//{
//	int i = 1;
//	int j = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if ((i / 10==9) || (i % 10 == 9))
//			
//			j++;
//	}
//	printf("%d", j);
//
//
//	return 0;
//
//}
//int main()
//{
//	int a, b, c, t;
//	(void)scanf("%d, %d, %d", &a, &b, &c);
//	if (a > b)
//	{
//		t = a; a = b; b = t;
//	}
//	if (a > c)
//	{
//		t = a; a = c; c = t;
//	}
//	if (b > c)
//	{
//		t = b; b = c; c = t;
//	}
//	printf("%d%d%d", a, b, c);
//	return 0;
//}
//
//int main()
//{
//	int a, b, c, t;
//	(void)scanf("%d,%d,%d", &a, &b, &c);
//	if(a > b) { t = a; a = b; b = t; }
//	if(a > c) { t = a; a = c; c = t; }
//	if(b > c) { t = b; b = c; c = t; }
//	printf("%d %d %d", a, b, c);
//}
 
 
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("a = %d\n b = %d\n c =%d\n d =%d\n",a,b,c,d);
//
//	printf("i =%d\n",i);
//
//
//
//
//	return 0;
//
//
//}
//输入一个整数，判断是否为奇数
//int main()
//{
//	int num = 0;
//	//输入
//	scanf("%d", &num);
//	//判断
//	if (num % 2 == 1)//==  是判断相等    = 是赋值
//		printf("%d 是奇数\n", num);
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	//输入
//	scanf("%d", &num);
//	//判断
//	if (num % 2)//==  是判断相等    = 是赋值
//		printf("%d 是奇数\n", num);
//
//	return 0;
//}

//输入一个整数，判断是否为奇数，如果是奇数打印是奇数，否则打印偶数。

//int main()
//{
//	int num = 0;
//	//输入
//	scanf("%d", &num);
//	//判断
//	if (num % 2 == 1)
//		printf("%d 是奇数\n", num);
//	else
//		printf("%d 是偶数\n", num);
//
//	return 0;
//}

//输入一个年龄，>= 18岁就输出：成年，否则就输出：未成年

//int main()
//{
//	int age = 0;
//	//输入
//	scanf("%d", &age);
//	//判断
//	if (age >= 18)
//	{//代码块
//		printf("成年\n");
//		printf("可以谈恋爱\n");
//	}
//	else
//	{
//		printf("未成年\n");
//		printf("好好学习\n");
//	}
//
//	return 0;
//}


//要求输入一个整数，判断输入的整数是0，还是正数或者负数。

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//判断
//	if (n == 0)
//		printf("输入的值是0\n");
//	else
//	{
//		if (n > 0)
//			printf("输入的值是正数\n");
//		else  //<0
//			printf("输入的值是负数\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//判断
//	if (n == 0)
//		printf("输入的值是0\n");
//	else if (n > 0)
//		printf("输入的值是正数\n");
//	else  //<0
//		printf("输入的值是负数\n");
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n >= 0) //> ==0
//	{
//		if (n == 0)
//			printf("输入的值是0\n");
//		else
//			printf("输入的值是正数\n");
//	}
//	else
//	{
//		printf("输入的值是负数\n");
//	}
//
//	return 0;
//}


//输入一个人的年龄
//如果年龄<18岁，打印"少年"
//如果年龄在18岁至44岁打印"青年"
//如果年龄在45岁至59岁打印"中老年"
//如果年龄在60岁至89岁打印"老年"
//如果90岁及以上打印"老寿星"


//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	//判断
//	if (age < 18)
//		printf("少年\n");
//	else //>=18
//	{
//		if (age <= 44)
//			printf("青年\n");
//		else //>44
//		{
//			if (age <= 59)
//				printf("中老年\n");
//			else //>=60
//			{
//				if (age <= 89)
//					printf("老年\n");
//				else
//					printf("老寿星\n");
//			}
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	//判断
//	if (age < 18)
//		printf("少年\n");
//	else if (age <= 44) //18~44
//		printf("青年\n");
//	else if (age <= 59)//45~59
//		printf("中老年\n");
//	else if (age <= 89)//60~89
//		printf("老年\n");
//	else  //>=90
//		printf("老寿星\n");
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//
//	return 0;
//}


//《高质量C/C++编程》


//int main()
//{
//	int a = 10;
//	return 0;
//}
//


//Tab   / shift+Tab
//Ctrl+K+C
//Ctrl+K+U
//Ctrl+C
//Ctrl+V
//Ctrl+D
//

//int main()
//{
//	int a = 5;
//	printf("%d\n", a == 6);//0
//	printf("%d\n", a == 5);//1
//
//	return 0;
//}
//
//


//
//int main()
//{
//	int x = 0;
//	if (x = 3)//赋值
//		printf("hehe\n");
//
//	return 0;
//}


//当我们拿一个变量和一个常量比较是否相等的时候

//int main()
//{
//	int x = 0;
//	//if (x == 3)
//	//	printf("hehe\n");
//
//	if (3 == x)
//		printf("hehe\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 20;
//	int c = 5;
//
//	if (a < b < c)//err
//		printf("hehe\n");
//	else
//		printf("haha\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 20;
//	int c = 5;
//
//	if (a < b && b < c)
//		printf("hehe\n");
//	else
//		printf("haha\n");
//
//	return 0;
//}

//我们输入一个年龄，如果年龄在18岁~36岁之间，我们输出青年

//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	//if (18 <= age <= 36)//err
//	//	printf("青年\n");
//
//	if(age>=18 && age<=36)//&& 并且
//		printf("青年\n");
//	return 0;
//}



//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d", &a);
//    if (a > 5)
//        b = 3;
//    else
//        b = -3;
//
//    b = (a > 5 ? 3 : -3);
//
//    printf("%d\n", b);
//
//	return 0;
//}

//练习2：使用条件表达式实现找两个数中较大值。
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//输入
//	scanf("%d%d", &a, &b);
//	int m = 0;
//	//if (a > b)
//	//	m = a;
//	//else
//	//	m = b;
//
//	m = (a > b ? a : b);
//	printf("%d\n", m);
//
//	return 0;
//}
//


//int main()
//{
//	int flag = 5;
//	
//	if (!flag)
//		printf("do some thing\n");
//
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	printf("%d\n", a);
//
//	return 0;
//}


//int main()
//{
//	int month = 0;
//	scanf("%d", &month);
//	if (month >= 3 && month <= 5)//6 1 4
//		printf("春季\n");
//
//	return 0;
//}


//int main()
//{
//	int month = 0;
//	scanf("%d", &month);
//	if (month == 12 || month == 1 || month == 2)
//		printf("冬季\n");
//
//	return 0;
//}

//输入一个年份year，判断year是否是闰年
//闰年判断的规则：
//1. 能被4整除，并且不能被100整除是闰年
//2. 能被400整除是闰年
//
//int main()
//{
//	int year = 0;
//	//输入
//	scanf("%d", &year);
//	//判断
//	if (year % 4 == 0)
//	{
//		if (year % 100 != 0)
//			printf("闰年\n");
//	}
//
//	if (year % 400 == 0)
//		printf("闰年\n");
//
//
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		printf("闰年\n");
//
//	return 0;
//}



//int main()
//{
//	int year = 0;
//	//输入
//	scanf("%d", &year);
//	//判断
//	if ((year % 4 == 0) && (year % 100 != 0))
//	{
//			printf("闰年\n");
//	}
//	else if (year % 400 == 0)
//		printf("闰年\n");
//
//
//	return 0;
//}

#include <stdio.h>

//int main()
//{
//    int i = 0, a = 0, b = 2, c = 3, d = 4;
//    //i = a++ && ++b && d++;
//
//    i = a++||++b||d++;
//
//    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//
//    printf("i = %d\n", i);
//
//
//    return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//n%3 ---> 0 1 2
//	if (n % 3 == 0)
//		printf("整除了，余数是0\n");
//	else if (n % 3 == 1)
//		printf("余数是1\n");
//	else
//		printf("余数是2\n");
//
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n % 3)
//	{
//	case 0:
//		printf("整除了，余数是0\n");
//		break;
//	case 1:
//		printf("余数是1\n");
//		break;
//	case 2:
//		printf("余数是2\n");
//		break;
//	}
//
//	return 0;
//}
//

//
//int main()
//{
//	//float f = 5.0f;
//	int f = 5;
//	int n = 1;
//	switch (f)
//	{
//	case n://err：case 后边必须是整型常量表达式
//		break;
//	}
//	return 0;
//}
//

//练习：
//输入一个1~7的数字，打印对应的星期几
//例如：
//输入：1   输出：星期一
//输入：2   输出：星期二
//输入：3   输出：星期三
//输入：4   输出：星期四
//输入：5   输出：星期五
//输入：6   输出：星期六
//输入：7   输出：星期天
//
//int main()
//{
//	int day = 0;
//	//输入
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期天\n");
//		break;
//	}
//	return 0;
//}


//
//int main()
//{
//	int day = 0;
//	//输入
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//	default:
//		printf("输入错误\n");
//		break;
//	}
//	return 0;
//}


//int main()
//{
//	while (1)
//		printf("hehe\n");
//
//	return 0;
//}
//
//在屏幕上打印 1~10 的值

//1 2 3 4 5 6 7 8 9 10

//i=1
//
// prinf()
// i++
//
//
//int main()
//{
//	int i = 1;//循环变量
//
//	while (i<=10)
//	{
//		printf("%d ", i);//1 2 3 4 ...
//		i++;
//	}
//
//	return 0;
//}


int main()
{
	int n = 0;
	scanf("%d", &n);//123

	while (n)
	{
		printf("%d ", n % 10);//获取一个数的最低位
		n = n / 10;//去掉一个数的最低位
	}

	return 0;
}
