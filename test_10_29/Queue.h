#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Qdatatype;
typedef struct QueueNode {
	struct QueueNode* next;
	Qdatatype val;
}QNode;
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//队尾插入
void QueuePush(Queue* pq, Qdatatype x);
//队头删除
void QueuePop(Queue* pq);

//取队头和队尾的数据
Qdatatype QueueFront(Queue* pq);
Qdatatype QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

//队尾插入
//void QueuePush(QNode** pphead,QNode** ptail,Qdatatype x);
//队头删除
//void QueuePop(QNode** phead, QNode** pptail);