#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <assert.h>  
#include <stdlib.h>  

typedef int SLdatatype;

//typedef struct SLNode {
//    SLdatatype val;
//    struct SLNode* next;
//    struct SLNode* prev;
//} SLNode;
//
//SLNode* LTBuyNode(SLdatatype x) {
//    SLNode* node = (SLNode*)malloc(sizeof(SLNode));
//    if (node == NULL) {
//        perror("malloc fail!");
//        exit(1);
//    }
//    node->val = x;
//    node->next = node->prev = node;
//    return node;
//}
//
//void LTPrint(SLNode* phead) {
//    SLNode* pcur = phead->next;
//    while (pcur != phead) {
//        printf("%d", pcur->val);
//        pcur = pcur->next;
//        if (pcur != phead) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//}
//
//void bubble_sort(SLNode* phead) {
//    if (phead == NULL || phead->next == phead) {
//        return;
//    }
//    int swapped;
//    do {
//        swapped = 0;
//        SLNode* pcur = phead->next;
//        while (pcur->next != phead) {
//            if (pcur->val > pcur->next->val) {
//                SLdatatype temp = pcur->val;
//                pcur->val = pcur->next->val;
//                pcur->next->val = temp;
//                swapped = 1;
//            }
//            pcur = pcur->next;
//        }
//    } while (swapped);
//}
//
//void insertInOrder(SLNode* phead, SLNode* newNode) {
//    SLNode* pcur = phead->next;
//    while (pcur != phead && pcur->val < newNode->val) {
//        pcur = pcur->next;
//    }
//    newNode->prev = pcur->prev;
//    newNode->next = pcur;
//    pcur->prev->next = newNode;
//    pcur->prev = newNode;
//}
//
//void LTErase(SLNode* pos) {
//    assert(pos);
//    pos->next->prev = pos->prev;
//    pos->prev->next = pos->next;
//    free(pos);
//}
//
//int main() {
//    int n;
//    if (scanf("%d", &n) != 1) {
//        return 1;  
//    }
//    if (n <= 0) {
//        return 0;
//    }
//
//    SLNode* phead = LTBuyNode(0);
//    for (int i = 0; i < n; ++i) {
//        int val;
//        if (scanf("%d", &val) != 1) {
//            return 1; 
//        }
//        SLNode* newNode = LTBuyNode(val);
//        newNode->next = phead;
//        newNode->prev = phead->prev;
//        phead->prev->next = newNode;
//        phead->prev = newNode;
//    }
//
//    bubble_sort(phead);
//
//    SLNode* lastNode = phead->prev;
//    SLNode* newLastNode = LTBuyNode(lastNode->val); 
//    LTErase(lastNode);
//
//    insertInOrder(phead, newLastNode);
//
//    LTPrint(phead);
//    SLNode* current = phead->next;
//    SLNode* toFree;
//    while (current != phead) {
//        toFree = current;
//        current = current->next;
//        free(toFree);
//    }
//    free(phead);
//
//    return 0;
//}

typedef struct SLNode {
	struct SLNode* next;
	SLdatatype val;
}SLNode;

int SLTFind(SLNode* phead, SLdatatype x)
{
    SLNode* pcur = phead;
    int count = 1;
    while (pcur)
    {
        if (count == x) {
            printf("%d", pcur->val);
            return 1;
        }
        pcur = pcur->next;
        count++;
    }
    return 0;
}
int num(SLNode* phead)
{
    SLNode* pcur = phead;
    int count = 0;
    while (pcur) 
    {
        pcur = pcur->next;
        count++;
    }
    return count;
}
SLNode* SLTBuyNode(SLdatatype x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}
int main() {
    int k;
    int val;
    scanf("%d", &k);
    SLNode* head = NULL;
    SLNode* pcur = NULL;
    while (scanf("%d", &val) != EOF) {
        SLNode* newnode = SLTBuyNode(val);
        if (head == NULL) {
            head = newnode;
            pcur = newnode;
        }
        else {
            pcur->next = newnode;
            pcur = newnode;
        }
    }
    int ret = num(head);
    if (k > ret) {
        printf("Not Found");
    }
    else {
        SLTFind(head, ret - k+1);
    }
    return 0;
}