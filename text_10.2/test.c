#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <math.h>
#define PI 3.1415926
/*int main()
{
	double m = 0;
	while(scanf("%lf",&m) == 1)
	{
		if (m < 0)
		{
			printf("Invaid value");
		}
		else if (m < 50)
		{
			double x = m * 0.53;
			printf("%lf", x);
		}
		else
		{
			double result = 26.5 + (m - 50) * 0.58;
			printf("%lf", result);
		}
	}
	return 0;
}

int main()
{
	int x = 1;
	int n;
	scanf("%d", n);
	double sum;
	while (x > n)
	{
		int m = ((-1) ^ (x - 1)) * (x / (2 * x - 1));
		sum += m;
		x++;
	}
	printf("%lf", sum);
	return 0;
}


double fact(int n)
{
	return n * fact(n - 1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	double result = fact(n);
	printf("%lf", result);
	return 0;
}              */    

//int main()
//{
//	int n, m, a;
//	do {
//		scanf("%d %d %d", &n, &m, &a);
//	} while (n < 0 || m < 0 || a < 0);
//	double l = (n + m + a) / 3.0;
//	printf("%.3f", l);
//	return 0;
//}
//int main()
//{
//	double  r, h;
//	scanf("%lf %lf", &r, &h);
//	double v = (PI * r * r * h) / 3;
//	printf("%.3f", v);
//	return 0;
//}


//int main()
//{
//	float a;
//	do
//	{
//		scanf("%f", &a);
//	} while (a < 0);
//	if (a - 0.5 >= (int)a)
//	{
//		a = a + 1;
//	}
//	printf("%d", (int)a);
//	return 0;
//}

//#include <stdio.h>
//int main() {
//	int sum = 0;
//	for (int i = 1; i <= 100; i++) {
//		if (i % 6 == 0) { 
//			sum += i; 
//		}
//	}
//	printf("100以内能被6整除的所有整数的和为: %d\n", sum);
//	return 0;
//}

//int main()
//{
//	int d, h, m;
//	scanf("%d %d %d", &d, &h, &m);
//	int result = (d * 24 + h) * 60 + m;
//	printf("%d", result);
//	return 0;
//}

//int main()
//{
//	signed int C = 0;
//	scanf("%d", &C);
//	double F = 0;
//	F = C * 9.0 / 5 + 32;
//	printf("%.1f", F);
//	return 0;
//}

//int main()
//{
//	double r, v;
//	scanf("%lf", &r);
//	v = (4.0  * PI * r*r*r)/3;
//	printf("%.3f", v);
//	return 0;
//}

//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	if (m < 0)
//	{
//		m = -m;
//	}
//	int j, k, s;
//	j = m % 10;
//	m = m / 10;
//	k = m % 10;
//	m = m / 10;
//	s = m % 10;
//	printf("%d%d%d", j, k, s);
//	return 0;
//}


//int main()
//{
//	int month = 0;
//	scanf("%d", &month);
//	switch (month)
//	{
//	case 3:
//	case 4:
//	case 5:
//		printf("Spring");
//		break;
//	case 6:
//	case 7:
//	case 8:
//		printf("Summer");
//		break;
//	case 9:
//	case 10:
//	case 11:
//		printf("Autumn");
//		break;
//	case 12:
//	case 1:
//	case 2:
//		printf("Winter");
//		break;
//	default:
//		printf("输入错误");
//	}
//}

//#include <stdio.h>  
//
//int main() {
//	int n, m, j;
//	scanf("%d %d %d", &n, &m, &j);
//	int max = n;
//	int min = n; 
//	if (m > max) {
//		max = m;
//	}
//	if (j > max) {
//		max = j;
//	}
//	if (m < min) {
//		min = m;
//	}
//	if (j < min) {
//		min = j;
//	} 
//	printf("%d ", max);
//	printf("%d", min);
//
//	return 0;
//}

//int  shuixianhua_number(int x)
//{
//	int j, k, m;
//	int result = x;
//	j = x % 10;
//	x = x / 10;
//	k = x % 10;
//	x = x / 10;
//	m = x % 10;
//	if (j * j*j + k * k*k + m * m*m == result)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i = 100;
//	do {
//		scanf("%d", &i);
//	} while (i < 100 || i > 999);
//	if(shuixianhua_number(i))
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}
//
//int main()
//{
//	double a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		if (a * a + b * b == c * c || b*b + c*c == a*a || a*a + c*c == b*b)
//		{
//			printf("1");
//		}
//		else
//		{
//			printf("0");
//		}
//	}
//	else
//	{
//		printf("-1");
//	}
//}

//int main()
//{
//	int height, weight;
//	scanf("%d %d", &height, &weight);
//	int st = height - 110;
//	if (weight >= st + 5)
//	{
//		printf("fat\n");
//	}
//	else if (weight <= st - 5)
//	{
//		printf("thin\n");
//	}
//	else
//	{
//		printf("good");
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n % 3 == 0 && n % 5 == 0 && n % 7 == 0)
//	{
//		printf("Can be divisible by 3,5,7.");
//	}
//	else if (n % 3 == 0 && n % 5 == 0 && n % 7 != 0)
//	{
//		printf("Can be divisible by 3,5.");
//	}
//	else if (n % 3 == 0 && n % 5 != 0 && n % 7 == 0)
//	{
//		printf("Can be divisible by 3,7.");
//	}
//	else if (n % 3 != 0 && n % 5 == 0 && n % 7 == 0)
//	{
//		printf("Can be divisible by 5,7.");
//	}
//	else if (n % 3 == 0 && n % 5 != 0 && n % 7 != 0)
//	{
//		printf("Can be divisible by 3.");
//	}
//	else if (n % 3 != 0 && n % 5 == 0 && n % 7 != 0)
//	{
//		printf("Can be divisible by 5.");
//	}
//	else if (n % 3 != 0 && n % 5 != 0 && n % 7 == 0)
//	{
//		printf("Can be divisible by 7.");
//	}
//	else
//	{
//		printf("Can not be divisible by 3,5,7.");
//	}
//	return 0;
//}

//void  fuhao(int a, int b,char fuhao)
//{
//	if (fuhao == '*')
//	{
//		printf("%d", a * b);
//	}
//	else if (fuhao == '/')
//	{
//		if( b != 0)
//		{
//			if (a % b == 0)
//			{
//				printf("%d", a / b);
//			}
//			else
//			{
//				printf("%.2f", (float)a / b);
//			}
//		}
//	}
//	else if (fuhao == '+')
//	{
//		printf("%d", a + b);
//	}
//	else if (fuhao  == '-')
//	{
//		printf("%d", a - b);
//	}
//}
//int main()
//{
//	int data1 = 0;
//	int data2 = 0;
//	char a = '0';
//	scanf("%d %d %c", &data1, &data2, &a);
//	fuhao(data1, data2, a);
//	return 0;
//}



#include <stdio.h>  

int main() {
	int hours, minutes, seconds;
	scanf("%d:%d:%d", &hours, &minutes, &seconds);
	seconds++;
	if (seconds >= 60) {
		seconds = 0;
		minutes++;
	}
	if (minutes >= 60) {
		minutes = 0;
		hours++;
	}
	if (hours >= 24) {
		hours = 0;
	}
	printf("%02d:%02d:%02d", hours, minutes, seconds);
	return 0;
}