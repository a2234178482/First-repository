#define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	int arr[3][5] = { 0 };
//	int i = 0;
//	for (i = 0; i <= 3; i++) {
//
//		int j = 0;
//		for (j = 0; j <= 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//	}
//}
//	for (i = 0; i <= 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= 5; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9, };
//	int k = 0;
//	scanf("%d",&k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是%d", i);
//				break;
//		}
//		if (i == sz)
//			printf("找不到了\n");
//	}
//
//	return 0;
//}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	scanf("%d", &k);

	//在arr数组中找k
	int sz = sizeof(arr) / sizeof(arr[0]);//10

	int left = 0;
	int right = sz - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
		{
			printf("找到了,下标是：%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("找不到了\n");
	return 0;
}