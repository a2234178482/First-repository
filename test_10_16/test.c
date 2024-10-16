#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//int fac(int n)
//{
//	if (n == 0) {
//		return 0;
//	}
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return fac(n - 1) + fac(n - 2);
//	}
//}
//
//
//
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//}

//long long fib(size_t N)
//{
//	long long f1 = 1;
//	long long f2 = 1;
//	long long f3 = 0;
//	for (size_t i = 3; i <= N; i++)
//	{
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	return f3;
//}
//
//
//int main() {
//	size_t N = 0;
//	scanf("%zd", &N);
//	int ret = fib(N);
//	printf("%d", ret);
//}
//
//int max_number(int x, int y) {
//	if (x == 0) {
//		return x;
//	}
//	else if (y == 0) {
//		return y;
//	}
//	else
//	{
//		while (y != 0)
//		{
//			int r = x % y;
//			x = y;
//			y = r;
//		}
//		return x;
//	}
//}
//
//int main() {
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int ret = max_number(a, b);
//	printf("%d %d", ret, (a * b) / ret);
//	return 0;
//}


//int main() {
//	int n;
//	scanf("%d", &n);
//	int  arr[n];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int j = 1;
//	int max_number = arr[0];
//	int min_number = arr[0];
//	if (n == 1) {
//		printf("%d %d", max_number, min_number);
//	}
//	else {
//		for (j = 1; j < n; j++) {
//			if (arr[j ] > max_number) {
//				max_number = arr[j];
//			}
//			if(arr[j]<min_number){
//				min_number = arr[j];
//			}
//		}
//		printf("%d %d", max_number, min_number);
//	}
//	return 0;
//}
//
//int main() {
//	int n; 
//	int m;
//	scanf("%d %d", &n, &m);
//	long long int sum1 = 0;
//	long long int sum2 = 0;
//	for (int j = n; j <= m; j++)
//	{
//		if (j % 2 == 0) {
//			sum2 += j * j;
//		}
//		if (j % 2 != 0)
//		{
//			sum1 += j * j*j;
//		}
//	}
//	printf("%lld %lld", sum2, sum1);
//	return 0;
//}
//

#include <stdio.h>  

//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n < 0) {
//        printf("n must be non-negative.\n");
//        return 1;
//    }
//
//    for (int m = 0; 4 * m <= n; m++) {
//        for (int w = 0; 3 * w <= n - 4 * m; w++) {
//            int k = n - 4 * m - 3 * w;
//            if (k >= 0) {
//                int c = 2 * k;
//                if(m +w+c == n)
//                {
//                    printf("%d %d %d\n", m, w, c);
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//int  max_number(int arr[],int sz)
//{
//	if (sz == 0) {
//		return -1;
//	}
//	int max_number = arr[0];
//	for (int j = 1; j < sz; j++) {
//		if (arr[j] > max_number)
//		{
//			max_number = arr[j];
//		}
//	}
//	return max_number;
//}
//int natural_number(int x) {
//	int sum = 0;
//	for (int i = 1; i < x; i++) {
//		if (x % i == 0)
//		{
//			sum += i;
//		}
//	}
//	if (sum == x) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//int main() {
//	int m = 0;
//	scanf("%d", &m);
//	if (m <= 0) {
//		return -1;
//	}
//	int arr[m] ;
//	int j = 0;
//	for (int i = 1; i <= m; i++)
//	{
//		if (natural_number(i))
//		{
//			arr[j] = i;
//			j++;
//		}
//	}
//	int ret = max_number(arr, j);
//	printf("%d", ret);
//	return 0;
//}

#include <stdio.h>  
#include <math.h>  

int main() {
    int n;
    double sum = 0.0; 
    scanf("%d", &n); 
    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 1) {
            sum += (1.0 / i);
        }
        else {
            sum -= (1.0 / i);
        }
    }
    printf("%.2f\n", round(sum * 100) / 100);
    return 0;
}