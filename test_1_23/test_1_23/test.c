#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			sum += i;
//	}
//	printf("%d", sum);
//	return 0;
//	
//}
#include <stdlib.h>
#include <string.h>
//int main()
//{
//
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑将在1分钟内关机，如果输入:我是猪,就取消关机\n");
//	scanf("%s",input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//#include <time.h>
//void game()
//{
//	int r = rand() % 100 + 100;
//	int guess = 0;
//	int count = 3;
//	while (count)
//	{
//		printf("还剩%d次机会", count);
//		printf("请猜数字;>");
//		scanf("%d", &guess);
//		if (guess > r)
//			printf("猜大了\n");
//		else if ("guess < r")
//			printf("猜小了\n");
//
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//		count--;
//	}
//	if (count == 0)
//		printf("很抱歉");
//}
//void menu()
//	{
//		printf("*****************\n");
//		printf("**** 1. play ****\n");
//		printf("**** 0. exit ****\n");
//		printf("*****************\n");
//	}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择;>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case  0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//
//
//
//
//	} while (input);
//	return 0;
//}
//int main()
//{
//	int i = 1, j = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//			printf("%d * %d = %d  ", i, j, i * j);
//			printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//    int i,max,j;
//    printf("请输入第1个整数");
//    scanf("%d", &j);
//    max = j;
//    for (i = 2; i <= 10; i++)
//    {
//        printf("请输入第%d个整数", i);
//        scanf("%d", &j);
//        if (j > max)
//        {
//            max = j;
//        }
//    }
//    printf("最大值是:%d\n", max);
//
//    return 0;
//    }
//
//  
//int main()
//{
//	int fu = 1, i = 0;
//	double sum = 0.0;
//	
//	for (i = 1; i <= 100; i++)
//	{
//		sum += fu * 1.0 / i;
//		fu = -fu;
//	}
//	printf("%lf\n", sum);
//
//	return 0;
//}
// 
//sqrt 函数是开平方的
/*int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)
	{
		
		int flag = 1;
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);

	return 0;
}*/
//使用while循环在屏幕上打印1~10

//int main()
//{
//	//1~10
//	int i = 1;//初始化部分
//
//
//	while (i<=10) //判断部分
//	{
//		printf("%d ", i);
//
//		i++;//调整部分
//	}
//
//	return 0;
//}

//使用for循环，在屏幕上打印1~10的值

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{	
//		printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//判断i是否是3的倍数
//		if (i % 3 == 0)
//			sum += i;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	//+ +=
//	for (i = 3; i <= 100; i+=3)
//	{
//		sum += i;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}

//使用do while在屏幕上打印1~10的值


//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i<=10);
//
//	return 0;
//}


//输入一个正整数，计算这个整数是几位数？
//例如：
//输入：1234   输出：4
//输入：12      输出：2

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int cnt = 0;
//
//	do
//	{
//		cnt++;
//		n = n / 10;
//	} while (n);
//
//	printf("%d\n", cnt);
//
//	return 0;
//}
//





//int main()
//{
//	//1~10
//	int i = 1;//初始化部分
//	while (i<=10) //判断部分
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);
//
//		i++;//调整部分
//	}
//	
//	//....
//	return 0;
//}

//int main()
//{
//	//1~10
//	int i = 1;//初始化部分
//	while (i <= 10) //判断部分
//	{
//		i++;//调整部分
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);	
//	}
//
//	//....
//	return 0;
//}


//int main()
//{
//	int i = 0;
//
//	for (i = 1; i <= 10; i++)
//	{	
//		if (i == 5)
//			break;
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//
//	return 0;
//}


#include <stdio.h>

//
//int main()
//{
//    int i = 1;
//    do
//    {
//        if (i == 5)
//            continue;
//        printf("%d ", i);
//        i = i + 1;
//    } while (i <= 10);
//
//    return 0;
//}
//



//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否是素数
//		//产生2~i-1之间的数字
//		int flag = 1;//假设i是素数
//		int j = 0;
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//不是素数
//				break;
//			}
//		}
//
//		if (flag == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//
//#include <math.h>
////sqrt 函数是开平方的
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否是素数
//		//产生2~i-1之间的数字
//		int flag = 1;//假设i是素数
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//不是素数
//				break;
//			}
//		}
//
//		if (flag == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//int main()
//{
//zhangsan:
//	printf("hehe\n");
//	goto zhangsan;
//
//	printf("哈哈\n");
//
//	printf("嘿嘿\n");
//
//	return 0;
//}

//system 是一个库函数，可以执行系统命令

#include <stdlib.h>
#include <string.h>

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑在1分钟内关机，如果输入:我是猪，就取消关机\n");
//	scanf("%s", input);
//	//判断input中放的是不是我是猪
//	// 两个字符串的比较不能使用==，而应该使用strcmp函数
//	//strcmp 如果判断两个字符串的内容相同，则返回0
//	if (strcmp(input, "我是猪") == 0) 
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("请注意，你的电脑在1分钟内关机，如果输入:我是猪，就取消关机\n");
//		scanf("%s", input);
//		//判断input中放的是不是我是猪
//		// 两个字符串的比较不能使用==，而应该使用strcmp函数
//		//strcmp 如果判断两个字符串的内容相同，则返回0
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//
//	return 0;
//}
//


//RAND_MAX;

//#include <stdlib.h>

//int main()
//{
//	srand(2);
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//
//	return 0;
//}
//

//
//#include <time.h>
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	printf("%d\n", rand()%100+1);
//	printf("%d\n", rand() % 100 + 1);
//	printf("%d\n", rand() % 100 + 1);
//	printf("%d\n", rand() % 100 + 1);
//	printf("%d\n", rand() % 100 + 1);
//
//	return 0;
//}
//
//#include <time.h>
//#include <stdlib.h>
//
//void game()
//{
//	//1. 生成随机值
//	int r = rand()%100+1;
//	//2. 猜数字
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &guess);
//		if (guess > r)
//			printf("猜大了\n");
//		else if (guess < r)
//			printf("猜小了\n");
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		printf("*****************\n");
//		printf("**** 1. play ****\n");
//		printf("**** 0. exit ****\n");
//		printf("*****************\n");
//		printf("请选择:>");
//		scanf("%d", &input);//1 0
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}



#include <time.h>
#include <stdlib.h>

void game()
{
	//1. 生成随机值
	int r = rand() % 100 + 1;
	//2. 猜数字
	int guess = 0;
	int count = 5;

	//system("cls");

	while (count)
	{
		printf("还剩下%d次机会", count);
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > r)
			printf("猜大了\n");
		else if (guess < r)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		count--;
	}
	if (count == 0)
		printf("很遗憾，在规定的次数内没能猜出结果\n");

}

void menu()
{
	printf("*****************\n");
	printf("**** 1. play ****\n");
	printf("**** 0. exit ****\n");
	printf("*****************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//1 0
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}

	} while (input);

	return 0;
}