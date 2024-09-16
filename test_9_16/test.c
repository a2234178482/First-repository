#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", n);
//	return 0;
//}
//
//
//int main()
//{
//	int a = 1000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);  // 二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
//int main()
//{
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//
//	// 关闭文件；
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputc('a', pf);
//	fputc('b',pf);
//	fputs('c', pf);
//	char ch = 0;
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", 'r');
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("text.txt", 'r');
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c", ch);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("test.txt", 'w');
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("hello world\n", pf);
//	fputs("hello  world", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//

//int main()
//{
//	//1.打开文件
//	FILE* pf = fopen("test.txt", 'r');
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 读文件
//	char arr[20] = { 0 };
//	while (fgets(arr, 20, pf) != NULL)
//	{
//		printf("%s", arr);
//	}
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}
//int  b_print(int x)
//{
//	int arr[32] = { 0 };
//	int i = 0;
//	while (x > 0)
//	{
//		arr[i++] = x % 2;
//		x = x / 2;
//	}
//	for (int j = i-1; j>=0; j-=2)
//	{
//		printf("%d", arr[j]);
//	}
//	printf("\n");
//	for (int k = i - 2; k >= 0; k-=2)
//	{
//		printf("%d", arr[k]);
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	b_print(n);
//	return 0;
//}

//int b_dif(int x, int y)
//{
//    int arr1[64] = { 0 };
//    int arr2[64] = { 0 };
//    int i = 0;
//    int m = 0;
//    while (x > 0)
//    {
//        arr1[i++] = x % 2;
//        x = x / 2;
//    }
//    while (y > 0)
//    {
//        arr2[m++] = y % 2;
//        y = y / 2;
//    }
//    int count = 0;
//    for (int j = 0; j < 64; j++)
//    {
//        if (arr1[j] != arr2[j])
//        {
//            count += 1;
//        }
//    }
//    return count;
//}
//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    int result = b_dif(a, b);
//    printf("%d", result);
//    return 0;
//}


//int main()
//{
//	int arr[9] = { 1,2,3,4,5,4,3,2,1 };
//	int result = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		result ^= arr[i];
//	}
//	printf("%d", result);
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%d", sizeof(a));
//	printf("\n");
//	printf("%d", sizeof(p));
//}


//指针

// 字符串逆序输出
//int main()
//{
//	char ch[100] = {0};
//	gets(ch);
//	int sz = strlen(ch);
//	char* p = ch+sz - 1;
//	while (p >= ch)
//	{
//		printf("%c", *p);
//		p--;
//	}
//	return 0;
//}

//字符逆序
//int main()
//{
//	char ch[100] = {0};
//	gets(ch);
//	int sz = strlen(ch);
//	char a[100] = { 0 };
//	for (int i = 0; i < sz; i++)
//	{
//		a[i] = ch[i];
//	}
//	for (int i = 99; i > 0; i--)
//	{
//		ch[sz - i] = a[i];
//	}
//	int* m = ch + sz - 1;
//	while (m >= ch)
//	{
//		printf("%c", *m);
//		m--;
//	}
//	return 0;
//}
void left_char(char *str, int x)
{
	int len = strlen(str);
	if (x > len)
	{
		x = x % len;
	}
	char arr[x];
	for (int i = 0; i < x; i++)
	{
		arr[i] = str[i];
	}
	for (int i = x; i < len; i++)
	{
		str[i - x] = str[i];
	}
	for (int i = len - x, j = 0; i < len; i++,j++)
	{
		str[i] = arr[j];
	}
	for(int i = 0; i < len; i++)
	{
		printf("%c",str[i]);
	}
}

int main()
{
	char a[50] = "hello world";
	gets(a);
	int n = 10;
	printf("请输入需要左移的个数");
	scanf("%d", &n);
	left_char(a, n);
	return 0;
}
