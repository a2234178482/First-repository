#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>

//int main()
//{
//	//int begin1 = clock();
//	//int n = 100000000;
//	//int x = 10;
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	++x;
//	//}
//	//int end1 = clock();
//
//	// 16:00继续
//	int x = 0;
//	int begin2 = clock();
//	int n1 = 100000;
//	for (int i = 0; i < n1; ++i)
//	{
//		for (int j = 0; j < n1; j++)
//		{
//			for (int k = 0; k < n1; k++)
//			{
//				++x;
//			}
//		}
//	}
//	int end2 = clock();
//
//	printf("%d\n", x);
//	//printf("%d ms\n", end1-begin1);
//	printf("%d ms\n", end2 - begin2);
//
//	return 0;
//}

void func(int n)
{
	int x = 0;
	for (int i = 1; i < n; i *= 2)
	{
		++x;
	}
	printf("%d\n", x);
}


//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	// 区间查找
//	// [begin, end]  -> 保持左闭右闭区间
//	int begin = 0;
//	int end = n - 1;
//	// begin   mid   end
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

int BinarySearch(int* a, int n, int x)
{
	//assert(a);

	// 区间查找
	// [begin, end）  -> 保持左闭右开区间
	int begin = 0;
	int end = n;
	// begin  mid   end
	while (begin < end)
	{
		//int mid = begin + ((end - begin) >> 1);
		int mid = (begin + end) / 2;
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}

int main()
{
	/*func(8);
	func(1024);
	func(1024*1024);*/

	int  a[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}

	return 0;
}
//int main()
//{
//	//int begin1 = clock();
//	//int n = 100000000;
//	//int x = 10;
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	++x;
//	//}
//	//int end1 = clock();
//
//	// 16:00继续
//	int x = 0;
//	int begin2 = clock();
//	int n1 = 100000;
//	for (int i = 0; i < n1; ++i)
//	{
//		for (int j = 0; j < n1; j++)
//		{
//			for (int k = 0; k < n1; k++)
//			{
//				++x;
//			}
//		}
//	}
//	int end2 = clock();
//
//	printf("%d\n", x);
//	//printf("%d ms\n", end1-begin1);
//	printf("%d ms\n", end2 - begin2);
//
//	return 0;
//}

void func(int n)
{
	int x = 0;
	for (int i = 1; i < n; i *= 2)
	{
		++x;
	}
	printf("%d\n", x);
}


//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	// 区间查找
//	// [begin, end]  -> 保持左闭右闭区间
//	int begin = 0;
//	int end = n - 1;
//	// begin   mid   end
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

int BinarySearch(int* a, int n, int x)
{
	//assert(a);

	// 区间查找
	// [begin, end）  -> 保持左闭右开区间
	int begin = 0;
	int end = n;
	// begin  mid   end
	while (begin < end)
	{
		//int mid = begin + ((end - begin) >> 1);
		int mid = (begin + end) / 2;
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}

int main()
{
	/*func(8);
	func(1024);
	func(1024*1024);*/

	int  a[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}

	return 0;
}
//消失的数字
//求和0-N；在减去数组中值，剩下的就是消失的
int missNumber(int* nums, int numsize) {
	int N = numsize;
	int ret = (0 + N) * (N + 1) / 2;
	for (int i = 0; i < numsize; ++i) {
		ret -= nums[i];
	}
	return ret;
}

int missNumber(int* nums, int numsize) {
	int N = numsize;
	int x = 0;
	for (int i = 0; i < numsize; ++i) {
		x ^= nums[i];
	}
	for (int j = 0; j <= N; ++j) {
		x ^= j;
	}
	return x;
}

void rotate(int* nums, int numsize, int k) {
	k %= numsize;
	while (k--) {
		int tmp = nums[numsize - 1];
		for (int i = numsize - 2; i >= 0; i--) {
			nums[i + 1] = nums[i];
		}
		nums[0] = tmp;
	}
}