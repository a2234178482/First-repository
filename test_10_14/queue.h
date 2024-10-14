#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool  QueueEmpty(Queue* pq);

//// 队尾插入
//void QueuePush(QNode** pphead, QNode** pptail, QDataType x);
//// 队头删除
//void QueuePop(QNode** pphead, QNode** pptail);