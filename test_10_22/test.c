#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
typedef int STDataType;
typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestroy(ST* pst);

void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);
int STSize(ST* pst);
void STInit(ST* pst) {
	assert(pst);
	pst->a = NULL;
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
STDataType STTop(ST* pst) {
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
//int isvalid(char* s) {
//	ST st;
//	STInit(&st);
//	while (*s) {
//		if (*s == '(' || *s == '[' || *s == '{') {
//			STPush(&st, *s);
//		}
//		else {
//			if (STEmpty(&st)) {
//				return 0;
//			}
//			char top = STTop(&st);
//			STPop(&st);
//			if ((top == '(' && *s != ')')
//				|| (top == '{' && *s != '}')
//				|| (top == '[' && *s != ']')) {
//				return 0;
//			}
//		}
//		++s;
//	}
//	int result = STEmpty(&st);
//	STDestroy(&st);
//	return result;
//}
//int main() {
//	char a[100];
//	if (fgets(a, 100, stdin) == NULL) {
//		printf("Error reading input\n");
//		return 1;
//	}
//	a[strcspn(a, "\n")] = 0;
//	int ret = isvalid(a);
//	printf("%d", ret);
//	return 0;
//}
typedef int QDataType;
typedef struct QueueNode {
	struct QueueENode* next;
	QDataType val;
}QNode;
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
//两个队列实现栈
typedef struct {
	Queue q1;
	Queue q2;
}MyStack; 
MyStack* mystackcreat() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(pst->q1));
	QueueInit(&(pst->q2));
	return pst;
}
void mystackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&(obj->q1))) {
		QueuePush(&(obj->q1), x);
	}
	else {
		QueuePush(&(obj->q2), x);
	}
}
int mystackPop(MyStack* obj) {
	Queue* empty = &(obj->q1);
	Queue* nonEmpty = &(obj->q2);
	if (!QueueEmpty(&(obj->q1))) {
		nonEmpty = &(obj->q1);
		empty = &(obj->q2);
	}
	while (QueueSize(nonEmpty) > 1) {
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}
	int top = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return top;
}

int mystacktop(MyStack* obj) {
	if (!QueueEmpty(&(obj->q1))) {
		return QueueBack(&(obj->q1));
	}
	else {
		return QueueBack(&(obj->q2));
	}
}

bool mystackempty(MyStack* obj) {
	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void Mystackfree(MyStack* obj) {
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}