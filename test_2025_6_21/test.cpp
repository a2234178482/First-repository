#include <iostream>
using namespace std;

//int count(int duihuan,int bottle)
//{
//	if (bottle < duihuan)
//		return 0;
//	int x = bottle / 2;
//	int remain = bottle % duihuan;
//	return  x + count(2, x+remain);
//}
//int main()
//{
//	int money = 20;
//	int danjia = 1;
//	int ret = money / danjia;
//	int s = ret + count(2, 20);
//	cout << s << endl;
//	return 0;
//}

//
//void Print()
//{
//    // 上半部分：1到13的奇数行
//    for (int i = 1; i <= 13; i += 2)
//    {
//        // 打印空格（居中效果）
//        /*for (int j = 0; j < (13 - i) / 2; j++)
//            printf(" ");*/
//
//        // 打印星号
//        for (int j = 0; j < i; j++)
//            printf("*");
//
//        printf("\n");
//    }
//
//    // 下半部分：11到1的奇数行（避免重复13行）
//    for (int i = 11; i >= 1; i -= 2)
//    {
//        // 打印空格（居中效果）
//        for (int j = 0; j < (13 - i) / 2; j++)
//            printf(" ");
//
//         /*打印星号*/
//        for (int j = 0; j < i; j++)
//            printf("*");
//
//        printf("\n");
//    }
//}
//
//int main()
//{
//    Print();
//    return 0;
//}
//bool isFlowerNumber(int x)
//{
//	if (x == 0) return 1;
//	int sum = 0;
//	int ret = x;
//	int digit = 0;
//	while (x > 0)
//	{
//		digit++;
//		x = x / 10;
//	}
//	x = ret;
//	while (x>0)
//	{
//		int j = x % 10;
//		sum += pow(j, digit);
//		x = x / 10;
//	}
//	if (ret == sum)
//		return 1;
//	else
//		return 0;
//}
//
//void Print()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		if (isFlowerNumber(i))
//			cout << i << endl;
//	}
//}
//int main()
//{
//	Print();
//	return 0;
//}
int main()
{
	int x;
	scanf("%d", x);
	int sum = 5 * x + 4 * x * 10 + 3 * x * 100 + 2 * x * 1000 + x * 10000;
	printf("%d", sum);
}