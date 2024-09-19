#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	printf("hehe\n");
	main();
	return 0;
}

int Fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Fact(n - 1);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int r = Fact(n);
	printf("%d\n", r);
	return 0;
}

void Print(int n)
{
	int arr[10] = { 0 };
	while (n)
	{
		printf("%d", n % 10);
		n = n / 10;
	}
}

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n); // 1234
	Print(n);
	return 0;
}


//递归层次太多会导致栈溢出
void test(int n)
{
	printf("%d ", n);
	if (n < 10000)
	{
		test(n + 1);
	}
}

int main()
{
	test(1);
	return 0;
}

int Fact(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int r = Fact(n);
	printf("%d\n", r);
	return 0;
}

int count = 0;

int Fib(int n)
{
	if (n == 3)
	{
		count++;
	}
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int r = Fib(n);
	printf("%d\n", r);

	return 0;
}