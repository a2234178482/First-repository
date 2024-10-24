#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//typedef int SLdatatype;
//typedef struct VAL {
//	SLdatatype x;//系数
//	SLdatatype y;//指数
//}VAL;
//typedef struct SLNode {
//	VAL val;
//	struct SLNode* next;
//}SLNode;
//
//SLNode* Buynode(SLdatatype x, SLdatatype y) {
//	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
//	newnode->val.x = x;
//	newnode->val.y = y;
//	newnode->next = NULL;
//	return newnode;
//}
//
//void add_node(SLNode** head, SLdatatype x, SLdatatype y) {
//	SLNode* newnode = Buynode(x, y);
//	if (*head == NULL) {
//		*head = newnode;
//	}
//	else {
//		SLNode* tmp = *head;
//		while (tmp->next != NULL) {
//			tmp = tmp->next;
//		}
//		tmp->next = newnode;
//	}
//}
//
//SLNode* add_val(SLNode* phead, SLNode* pcur) {
//	SLNode* result = NULL;
//	SLNode* c1 = phead;
//	SLNode* c2 = pcur;
//	while (c1 != NULL && c2 != NULL) {
//		if (c1->val.y == c2->val.y) {
//			add_node(&result, c1->val.x + c2->val.x, c1->val.y);
//		}
//		c1 = c1->next;
//		c2 = c2->next; 1
//	}
//	else if (c1->val.y > c2->val.y) {
//		add_node(&result, c1->val.x, c1->val.y);
//	}
//	c1 = c1->next;
//}
//else{
//	add_node(&result, c2->val.x, c2->val.y);
//	c2 = c2->next;
//}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"heap.h"

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);
		HPPop(&hp);
	}
	printf("\n");

	// 找出最大的前k个
	/*int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");*/

	HPDestroy(&hp);
}

// 堆排序    O(N*logN)
// 冒泡排序  O(N^2) 
void HeapSort(int* a, int n)
{
	// 降序，建小堆
	// 升序，建大堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeap2();

	return 0;
}