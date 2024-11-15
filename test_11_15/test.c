#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char QElemType;
typedef int Status;

/***队列的顺序存储结构***/
typedef struct {
	QElemType* base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
} SqQueue;

/***循环队列基本操作***/

//算法3.11　循环队列的初始化
Status InitQueue(SqQueue* Q) {//构造一个空队列Q
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));//为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q->base)
		exit(OVERFLOW); //存储分配失败
	Q->front = Q->rear = 0; //头指针和尾指针置为零，队列为空
	return OK;
}

//算法3.12　求循环队列的长度
int QueueLength(SqQueue Q) {//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//算法3.13　循环队列的入队
Status EnQueue(SqQueue* Q, QElemType e) {//插入元素e为Q的新的队尾元素
	if ((Q->rear + 1) % MAXQSIZE == Q->front) //尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q->base[Q->rear] = e; //新元素插入队尾
	Q->rear = (Q->rear + 1) % MAXQSIZE; //队尾指针加1
	return OK;
}

//算法3.14　循环队列的出队
Status DeQueue(SqQueue* Q, QElemType* e) {//删除Q的队头元素，用e返回其值
	if (Q->front == Q->rear)
		return ERROR; //队空
	*e = Q->base[Q->front]; //保存队头元素
	Q->front = (Q->front + 1) % MAXQSIZE; //队头指针加1
	return OK;
}

//算法3.15　取循环队列的队头元素
QElemType GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

//释放内存 
void DestroySqQueue(SqQueue* Q) {
	free(Q->base);
}

int main() {
	SqQueue Q;
	InitQueue(&Q);

	char input[MAXQSIZE];
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			if (EnQueue(&Q, input[i]) == ERROR) {
				printf("队列已满，无法继续输入。\n");
				break;
			}
		}
	}
	while (Q.front != Q.rear) {
		QElemType e;
		DeQueue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");

	DestroySqQueue(&Q);
	return 0;
}
#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	//int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	//int a[] = { 2,4,1,7,8,3,9,2 };
	int a[] = { 9,1,2,5,7,4,6,3 };

	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		// ÖØ¸´²»¶à
		a1[i] = rand() + i;
		// ÖØ¸´½Ï¶à
		//a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	PrintArray(a2, N);

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestQuickSort();

	TestOP();

	return 0;
}