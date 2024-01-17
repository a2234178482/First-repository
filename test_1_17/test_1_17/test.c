#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

{
	int a = 0;
	int b = 0;
	int zhengshushang = 0;
	int yushu = 0;
	scanf("%d %d", &a,&b);
	zhengshushang = a / b;
	yushu = a % b;
	printf("%d %d", zhengshushang,yushu);
	return 0;
}