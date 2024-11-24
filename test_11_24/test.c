#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//* Definition for singly - linked list.
//* struct ListNode {
//    *int val;
//    *struct ListNode* next;
//    *
//};

//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow) {
//            return true;
//        }
//    }
//    return false;
//}

//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* pcur = NULL;
//    while (fast && fast->next) {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast) {
//            pcur = fast;
//            struct ListNode* cur = head;
//            while (pcur != cur) {
//                pcur = pcur->next;
//                cur = cur->next;
//            }
//        }
//        return pcur;
//    }
//    return NULL;
//}