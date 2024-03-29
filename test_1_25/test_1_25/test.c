#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int sum = 0, i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum += i;
		if (i % 2 == 1)
			sum -= i;
	}
	printf("%d",sum);
	return 0;
} 