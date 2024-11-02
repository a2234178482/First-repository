#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
int main() {
	printf("hello world");
	return 0;
}
typedef struct ListNode {
    int val;
    ListNode* next;
}ListNode;
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

struct hashTable {
    struct ListNode* key;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(struct ListNode* ikey) {
    struct hashTable* tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct ListNode* ikey) {
    struct hashTable* tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashtable, key, tmp);
}

struct ListNode* detectCycle(struct ListNode* head) {
    hashtable = NULL;
    while (head != NULL) {
        if (find(head) != NULL) {
            return head;
        }
        insert(head);
        head = head->next;
    }
    return false;
}

char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        }
        else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* temp = &dummyHead;
    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
}

typedef struct {
    char key[32];
    int val;
    UT_hash_handle hh;
} HashItem;

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int m = wordsSize, n = strlen(words[0]), ls = strlen(s);
    int* res = (int*)malloc(sizeof(int) * ls);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (i + m * n > ls) {
            break;
        }
        HashItem* diff = NULL;
        char word[32] = { 0 };
        for (int j = 0; j < m; j++) {
            snprintf(word, n + 1, "%s", s + i + j * n);
            HashItem* pEntry = NULL;
            HASH_FIND_STR(diff, word, pEntry);
            if (NULL == pEntry) {
                pEntry = (HashItem*)malloc(sizeof(HashItem));
                strcpy(pEntry->key, word);
                pEntry->val = 0;
                HASH_ADD_STR(diff, key, pEntry);
            }
            pEntry->val++;
        }
        for (int j = 0; j < m; j++) {
            HashItem* pEntry = NULL;
            HASH_FIND_STR(diff, words[j], pEntry);
            if (NULL == pEntry) {
                pEntry = (HashItem*)malloc(sizeof(HashItem));
                strcpy(pEntry->key, words[j]);
                pEntry->val = 0;
                HASH_ADD_STR(diff, key, pEntry);
            }
            pEntry->val--;
            if (pEntry->val == 0) {
                HASH_DEL(diff, pEntry);
                free(pEntry);
            }
        }
        for (int start = i; start < ls - m * n + 1; start += n) {
            if (start != i) {
                char word[32];
                snprintf(word, n + 1, "%s", s + start + (m - 1) * n);
                HashItem* pEntry = NULL;
                HASH_FIND_STR(diff, word, pEntry);
                if (NULL == pEntry) {
                    pEntry = (HashItem*)malloc(sizeof(HashItem));
                    strcpy(pEntry->key, word);
                    pEntry->val = 0;
                    HASH_ADD_STR(diff, key, pEntry);
                }
                pEntry->val++;
                if (pEntry->val == 0) {
                    HASH_DEL(diff, pEntry);
                    free(pEntry);
                }
                snprintf(word, n + 1, "%s", s + start - n);
                pEntry = NULL;
                HASH_FIND_STR(diff, word, pEntry);
                if (NULL == pEntry) {
                    pEntry = (HashItem*)malloc(sizeof(HashItem));
                    strcpy(pEntry->key, word);
                    pEntry->val = 0;
                    HASH_ADD_STR(diff, key, pEntry);
                }
                pEntry->val--;
                if (pEntry->val == 0) {
                    HASH_DEL(diff, pEntry);
                    free(pEntry);
                }
            }
            if (HASH_COUNT(diff) == 0) {
                res[pos++] = start;
            }
        }
        HashItem* curr, * tmp;
        HASH_ITER(hh, diff, curr, tmp) {
            HASH_DEL(diff, curr);
            free(curr);
        }
    }
    *returnSize = pos;
    return res;
}
