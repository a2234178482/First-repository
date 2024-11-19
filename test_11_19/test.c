#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* new_node = NULL;
    int min_index = -1;
    int min_val = INT_MAX;

    for (int i = 0; i < listsSize; i++) // 寻找当前最小节点
    {
        if (lists[i])
        {
            if (lists[i]->val < min_val)
            {
                min_val = lists[i]->val;
                min_index = i;
            }
        }
    }

    if (min_index != -1) // 若存在当前最小节点
    {
        new_node = (struct ListNode*)malloc(1 * sizeof(struct ListNode));
        new_node->val = min_val;
        lists[min_index] = lists[min_index]->next; // 用完移动链表至下一个节点
        new_node->next = mergeKLists(lists, listsSize);
    }

    return new_node;
}


struct ListNode* link_list(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* min_list_node = NULL;

    if (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            min_list_node = list2;
            min_list_node->next = link_list(list1, list2->next);
        }
        else
        {
            min_list_node = list1;
            min_list_node->next = link_list(list1->next, list2);
        }
    }
    else if (list1 && !list2)
    {
        min_list_node = list1;
    }
    else if (!list1 && list2)
    {
        min_list_node = list2;
    }

    return min_list_node;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* sort_list = NULL;
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    if (!listsSize)
    {
        return sort_list;
    }

    for (int i = listsSize + 1; i > 0; i /= 2) // 分批拼接，防止一条链表过长的问题
    {
        int index = 0;
        for (int j = 0; j < listsSize; j += 2)
        {
            list1 = lists[j];
            if (j + 1 <= listsSize - 1)
            {
                list2 = lists[j + 1];
            }
            else
            {
                list2 = NULL;
            }
            lists[index++] = link_list(list1, list2);
        }
        listsSize = (listsSize + 1) / 2;
    }
    sort_list = lists[0];

    return sort_list;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1)return head;
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    dummyHead->val = 0;
    int now = 0;
    struct ListNode* prev = dummyHead;
    struct ListNode* cur = dummyHead;
    struct ListNode* p = dummyHead;
    for (int i = k;; i += k) {
        while (now != i && p != NULL) {
            p = p->next;
            now++;
        }
        if (p == NULL) {
            //结束遍历
            head = dummyHead->next;
            free(dummyHead);
            return head;
        }
        p = p->next;
        now++;
        struct ListNode* p0 = prev;//记录翻转链表的前一个节点
        cur = prev->next;
        struct ListNode* p1 = cur;//记录翻转链表的第一个节点
        while (cur != p) {
            struct ListNode* temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
        }
        p0->next = prev;
        p1->next = p;
        prev = p1;
    }
}
