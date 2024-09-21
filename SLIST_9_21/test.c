#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListTest01()
{
	//链表是由一个一个的节点组成
	//创建几个节点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//将四个节点连接起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//调用链表的打印
	SLTNode* plist = node1;
	SLTPrint(plist);
}

void SListTest02()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//SLTPushBack(NULL, 5);
	//
	//测试头插
	//SLTPushFront(&plist, 6);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 7);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 8);
	//SLTPrint(plist);

	//测试尾删
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

}

int main()
{
	//SListTest01();
	SListTest02();
	return 0;
}