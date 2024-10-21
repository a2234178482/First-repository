#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>  
#include <assert.h>  

typedef int SLdatatype;

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* SLBuyNode(SLdatatype x) {
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    if (newnode == NULL) {
        perror("malloc fail!");
        exit(1);
    }
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

void Print(ListNode* phead) {
    ListNode* pcur = phead;
    while (pcur != NULL) {
        printf("%d ", pcur->val);
        pcur = pcur->next;
    }
}

ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;
    ListNode* l1 = list1;
    ListNode* l2 = list2;
    while (l1 != NULL && l2 != NULL) {
        ListNode* nextNode = NULL;
        if (l1->val < l2->val) {
            nextNode = l1;
            l1 = l1->next;
        }
        else {
            nextNode = l2;
            l2 = l2->next;
        }

        if (newhead == NULL) {
            newhead = newtail = nextNode;
        }
        else {
            newtail->next = nextNode;
            newtail = newtail->next;
        }
    }

    if (l1 != NULL) {
        newtail->next = l1;
    }
    if (l2 != NULL) {
        newtail->next = l2;
    }
    return newhead;
}

void SLTErase(ListNode* phead) {
    ListNode* pcur = phead;
    while (pcur != NULL) {
        ListNode* nextNode = pcur->next;
        while (nextNode != NULL && nextNode->val == pcur->val) {
            ListNode* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        pcur->next = nextNode;
        pcur = nextNode;
    }
}

int main() {
    ListNode* phead = NULL;
    ListNode* pphead = NULL;
    int val, value;
    while (scanf("%d", &val) == 1) {
        ListNode* newNode = SLBuyNode(val);
        if (phead == NULL) {
            phead = newNode;
        }
        else {
            ListNode* temp = phead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    while (scanf("%d", &value) == 1) {
        ListNode* newnode = SLBuyNode(value);
        if (pphead == NULL) {
            pphead = newnode;
        }
        else {
            ListNode* temp = pphead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    ListNode* l1 = merge_two_lists(phead, pphead);
    SLTErase(l1);
    Print(l1);
    ListNode* current = l1;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
#include"List.h"

void ListTest01()
{
    //LTNode* plist = NULL;
    //LTInit(&plist);
    LTNode* plist = LTInit();

    LTPushBack(plist, 1);
    LTPushBack(plist, 2);
    LTPushBack(plist, 3);
    LTPrint(plist);

    LTNode* find = LTFind(plist, 3);
    //LTInsert(find, 66);
    LTErase(find);
    find = NULL;

    LTPrint(plist);
    LTDesTroy(plist);
    //plist = NULL;


    //if (find == NULL)
    //{
    //	printf("’“≤ªµΩ£°\n");
    //}
    //else {
    //	printf("’“µΩ¡À£°\n");
    //}

    //LTPushFront(plist, 1);
    //LTPrint(plist);
    //LTPushFront(plist, 2);
    //LTPrint(plist);
    //LTPushFront(plist, 3);
    // 
    //
    ////≤‚ ‘Œ≤…æ
    //LTPopBack(plist);
    //LTPrint(plist);
    //LTPopBack(plist);
    //LTPrint(plist);
    //LTPopBack(plist);
    //LTPrint(plist);

    ////≤‚ ‘Õ∑…æ
    //LTPopFront(plist);
    //LTPrint(plist);
    //LTPopFront(plist);
    //LTPrint(plist);
    //LTPopFront(plist);
    //LTPrint(plist);
    //LTPopBack(plist);
    //LTPrint(plist);
}

int main()
{
    ListTest01();
    return 0;
}