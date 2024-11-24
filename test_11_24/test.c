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
void STInit(ST* pst) {
	assert(pst);
	pst->a = NULL;
	//top指向栈顶数据的下一个
	pst->top = 0;
	pst->capacity = 0;
}

void STDestroy(ST* pst) {
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void STPush(ST* pst, STDataType x) {
	assert(pst);
	if (pst->top == pst->capacity) {
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst) {
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

bool  STEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;
}

int STSize(ST* pst) {
	assert(pst);
	return pst->top;
}

typedef int STDataType;
typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;
void STInit(ST* pst) {
	assert(pst);
	pst->a = NULL;
	//top指向栈顶数据的下一个
	pst->top = 0;
	pst->capacity = 0;
}

void STDestroy(ST* pst) {
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void STPush(ST* pst, STDataType x) {
	assert(pst);
	if (pst->top == pst->capacity) {
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst) {
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}
bool  STEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;
}

int STSize(ST* pst) {
	assert(pst);
	return pst->top;
}
bool isValid(char* s) {
	ST st;
	STInit(&st);
	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			STPush(&st, *s);
		}
		else {
			if (STEmpty(&st)) {
				return false;
			}
			char top = STTop(&st);
			STPop(&st);
			if (top == '(' && *s != ')' ||
				top == '[' && *s != ']' ||
				top == '{' && *s != '}')
				return false;
		}
		++s;
	}
	int ret = STEmpty(&st);
	return ret;
}