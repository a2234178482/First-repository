#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//斐波那契数列求解
/*long long fib(size_t N)
{
	if (N < 3)
		return 1;
	return fib(N - 1) + fib(N - 2);
}*/
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
//int main()
//{
//	printf("%d", fib(50));
//}

struct ListNode {
	int val;
	struct ListNode* next;
};
//取出链表的倒数第k个元素
//1.快慢指针
int kthtolast(struct ListNode* head, int k)
{
	struct ListNode* fast = head, *slow = head;
	//快指针先走k步
	while (k--)
	{
		fast = fast->next;
	}
	//同时走
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	} 
	return slow->val;
}