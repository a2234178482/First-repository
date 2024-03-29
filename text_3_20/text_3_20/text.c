#define _CRT_SECURE_NO_WARNINGS 1
void  is_prinme(int n)
{
	int i = 0;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{

			return 1;
		}

	}
	return 0;
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	if (is_prime(m))
	{
		printf("不是素数");
	}
	else
		printf("是素数");;

}

