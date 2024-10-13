#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////合并两个有序链表
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//struct ListNode* mergetwolist(struct ListNode* list1, struct ListNode* list2)
//{
//	if (list1 == NULL)
//	{
//		return list2;
//	}
//	if (list2 == NULL)
//	{
//		return list1;
//	}
//	ListNode* l1 = list1;
//	ListNode* l2 = list2;
//	ListNode* newhead;
//	ListNode* newtail;
//	newhead = newtail = NULL;
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l1;
//			}
//			else {
//				newtail->next = l1;
//				newtail = newtail->next;
//			}
//			l1 = l1->next;
//		}
//		else{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l2;
//			}
//			else {
//				newtail->next = l2;
//				newtail = newtail->next;
//			}
//		}
//		l2 = l2->next;
//	}
//	if (l2)
//	{
//		newtail->next = l2;
//	}
//	if (l1)
//	{
//		newtail->next = l1;
//	}
//	return newhead;
//}
////约瑟夫环问题
//typedef struct ListNode ListNode;
//ListNode* buyNode(int x)
//{
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	if (node == NULL)
//	{
//		exit(1);
//	}
//	node->val = x;
//	node->next = NULL;
//	return node;
//}
//ListNode* createCircle(int n)
//{
//	ListNode* phead = buyNode(1);
//	ListNode* ptail = phead;
//	for (int i = 2; i <= n; i++)
//	{
//		ptail->next = buyNode(i);
//		ptail = ptail->next;
//	}
//	ptail->next = phead;
//	return ptail;
//}
//int ysf(int n, int m) {
//	ListNode* prev = createCircle(n);
//	ListNode* pcur = prev->next;
//	int count = 1;
//	while (pcur->next != pcur)
//	{
//		if (count == m) {
//			prev->next = pcur->next;
//			free(pcur);
//			pcur = prev->next;
//			count = 1;
//		}
//		else {
//			prev = pcur;
//			pcur = pcur->next;
//			count++;
//		}
//	
// }
//}

#include<stdio.h>
#include<stdlib.h>
//
//int main()
//{
//	// 原地扩容
//	// 异地扩容
//	int* p1 = (int*)malloc(8);
//	printf("%p\n", p1);
//
//	int* p2 = (int*)realloc(p1, 80);
//	printf("%p\n", p2);
//
//	free(p2);
//
//
//	int i = 0;
//	int ret1 = ++i;
//
//	int ret2 = i++;
//
//
//
//	return 0;
//}

#include"Stack.h"

//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//
//	//printf("%d\n", STTop(&s));
//
//	STDestroy(&s);
//
//	return 0;
//}

int main()
{
	// 入栈：1 2 3 4
	// 出栈：4 3 2 1  /  2 4 3 1
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);

	printf("%d ", STTop(&s));
	STPop(&s);

	STPush(&s, 3);
	STPush(&s, 4);

	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}

	STDestroy(&s);
}