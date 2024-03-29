#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
////{
////	int n = 0;
////	while (n <= 10)
////	{
////		printf("%d\n", n);
////		n = n + 1;
////	}
////	return 0;
////}


//找到规律是关键，看作一条正斜杠和反斜杠
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)  //外循环为行
//        {
//            for (int j = 0; j < n; j++) //内循环为列
//            {
//                if (i == j || i + j == n - 1)
//                    //最关键的地方，正斜线为[i][i]处是*， 反斜杠为[i][n-1-j]处是*，一行打印1个或2个*
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n"); //打印完一行，换行
//        }
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//        for (int m = 0; m < n; m++)
//        {
//            for (int x = 0; x < n; x++) {
//                if (m == x || m + x == n - 1)
//                {
//                    printf("*");
//                }
//                else
//                    printf(" ");
//            }
//                printf("\n");
//            
//        }
//    return 0;
//}
//void leapyear(int year)
//{
//	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//	{
//		printf("%d是闰年", year);
//	}
//
//	else
//	{
//		printf("%d不是闰年", year);
//	}
//	return;
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	leapyear(year);
//	return 0;
//	}
//////
//int main()
//{
//
//	return 0;
//}
//
////
//
//void init(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//	return;
//}
//
//void Print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", i);
//	}
//	return;
//}          
//
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp;
//	while (left < right)
//	{
//		tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++;
//		right--;
//	}
//	return;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	printf("\n");
//	reverse(arr, sz);
//	Print(arr, sz);
//	printf("\n");
//	init(arr, sz);
//	Print(arr, sz);
//	return 0;
//
//}
//
//
//



//int main()
//{
//	int a = 20;
//	int* pc = a;
//
//	return 0;
//}


//
//
//
//int  is_prime(int n )
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return n;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) != 0)
//		{
//			printf("%d", i);
//			printf("\n");
//		}
//		
//	}
//	return 0;
//	
//		
//}
//


//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int arr[1000] = { 0 };
//	int arr[3000] = { 0 };
//	
//	return 0;
//}
//void Print(int n)
//{
//	int a = 0;
//	int b = 0;
//	for (a = 1; a <= n; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			printf("%d * %d = %d", a, b, a * b);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
////	return 0;
//}

//void seek(int key)
//{
//	int arr[] = { 12,15,17,52,67,84,91,102,153 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是:%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("%d",-1);
//	}
//}
//int main()
//{
//	int key = 0;
//	scanf("%d", &key);
//	seek(key);
//	return 0;
//}


//////实现扫雷游戏
//#include <stdlib.h>
//#include <time.h>
//#include <stdio.h>
//#define EASY_COUNT 10
//#define ROW 9
//#define COL 9
//#define ROWS  ROW+2
//#define COLS  COL+2
//
//void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = set;
//		}
//	}
//}
//void Displayboard(char board[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	printf("-------扫雷游戏-------\n");
//	for (i = 0; i <= row; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		int j = 0;
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void  SetMine(char board[ROWS][COLS], int row, int col)
//{
//	int count = EASY_COUNT;
//	while (count)
//	{
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] == '0')
//		{
//			board[x][y] = '1';
//			count--;
//		}
//	}
//}
//int get_mine_count(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y] +
//		mine[x - 1][y - 1] +
//		mine[x][y - 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] +
//		mine[x][y + 1] +
//		mine[x - 1][y + 1] - 8*'0';
//
//}
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	while (win < row * row - EASY_COUNT)
//	{
//		printf("请输入要查找的坐标：");
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("很遗憾，你死了");
//				Displayboard(mine, ROW, COL);
//				break;
//			}
//			else
//			{
//				int count = get_mine_count(mine, x, y);
//				show[x][y] = count + '0';
//				Displayboard(show, row, col);
//				win++;
//			}
//		}
//		else
//		{
//			printf("输入的坐标有误，请重新输入");
//		}
//	}
//	if (win == row * col - EASY_COUNT)
//	{
//		printf("恭喜你，排雷成功\n");
//		Displayboard(mine, ROW, COL);
//	}
//}
//void menu()
//{ 
//	printf("************************\n");
//	printf("****** 1.开始游戏 ******\n");
//	printf("****** 0.退出游戏 ******\n");
//	printf("************************\n");
//}
// void  game()
//{
//	 //完成扫雷的代码
//	 char mine[ROWS][COLS] = { 0 };
//	 char show[ROWS][COLS] = {0};
//	 Initboard(mine, ROWS, COLS ,'0');
//	 Initboard(show, ROWS, COLS , '*');
//	/* Displayboard(show,ROW,COL);*/
//	 Displayboard(mine, ROW, COL);
//	 SetMine(mine, ROW, COL);
//	 /*Displayboard(show, ROW, COL);*/
//	 FindMine(mine ,show,ROW,COL);
// }	
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:"); 
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("ganmeover");
//			break;
//		default:
//			printf("输入错误，请重新输入");
//			break;
//		}
//	} while (input);
//	return 0;
//}

void seek(int key)
{
	int arr[] = { 12,15,17,52,67,84,91,102,153 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;

		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标是:%d", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("%d", -1);
	}
}
int main()
{
	int key = 0;
	scanf("%d", &key);
	seek(key);
	return 0;
}