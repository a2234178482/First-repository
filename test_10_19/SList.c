#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>  
#include <stdlib.h>  

//typedef int SLdatatype;
//
//typedef struct student {
//    SLdatatype nums;
//    SLdatatype score;
//} student;
//
//typedef struct SList {
//    student val;
//    struct SList* next;
//} SL;
//
//void SLTPrint(SL* phead) {
//    SL* pcur = phead;
//    while (pcur != NULL) { 
//        printf("[num=%d,score=%d]\n", pcur->val.nums, pcur->val.score); 
//        pcur = pcur->next;
//    }
//}
//
//void SListTest01() {
//    SL* node1 = (SL*)malloc(sizeof(SL)); 
//    scanf("%d,%d", &node1->val.nums, &node1->val.score);  
//
//    SL* node2 = (SL*)malloc(sizeof(SL));
//    scanf("%d,%d", &node2->val.nums, &node2->val.score); 
//
//    SL* node3 = (SL*)malloc(sizeof(SL));
//    scanf("%d,%d", &node3->val.nums, &node3->val.score);   
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = NULL;  
//
//    SLTPrint(node1); 
//}
//
//int main() {
//    SListTest01();
//    return 0; 
//}

//思路：写一函数，循环构建节点，在写一个函数，创建新链表，然后遍历链表中所有元素，找出最大的值，移动至链表末尾
typedef int DataType;

typedef struct node {
	DataType data;
	struct node* link;
}node;
void SLTPrint(node* phead)
{
	node* pcur = phead;
	while (pcur)
	{
		printf("%d ", pcur->data);
		pcur = pcur->link;
	}
}
node* SLTBuyNode(DataType x)
{
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->link = NULL;
	return newnode;
}
void SLTistDesTroy(node** pphead)
{
	assert(pphead && *pphead);
	node* pcur = *pphead;
	while (pcur)
	{
		node* link = pcur->link;
		free(pcur);
		pcur = link;
	}
	*pphead = NULL;
}
void SLTMove(node** head) {
    if (*head == NULL || (*head)->link == NULL) {
        return; 
    }

    node* max_value = *head;
    node* pre_max = NULL;   
    node* cur = *head;
    node* pre = NULL;       

  
    while (cur != NULL) {
		if (cur->data > max_value->data) {
			max_value = cur;
			pre_max = pre;
		}
			pre = cur;  
			cur = cur->link;  
    }

    if (max_value != *head) {
        if (max_value == pre) {   
            pre_max->link = NULL; 
        }
        else {
            pre_max->link = max_value->link;  
        }
        max_value->link = NULL;  

 
        if (pre != NULL) {
            pre->link = max_value;   
        }
        max_value->link = NULL;   
    }  
    else {
        *head = max_value->link;  
        max_value->link = NULL;  

         
        node* tail = *head;
        while (tail && tail->link) {
            tail = tail->link;
        }
        if (tail) {
            tail->link = max_value;   
        }
        else {
            *head = max_value;  
        }
    }
}
int main()
{
	node* head = NULL;
	node* tail = NULL;
	int number;
	while (scanf("%d", &number) != EOF) {
		node* newNode = SLTBuyNode(number);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->link = newNode;
			tail = newNode;
		}

	}
	SLTMove(&head);
	SLTPrint(head);
	SLTistDesTroy(&head);
}
