#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//typedef int datatype;
//typedef struct node {
//	datatype data;
//	struct node* lchild, * rchild;
//}Tree, * PTree;
//void visit(PTree p) {
//    if (p != NULL) {
//        printf("%d", p->data);
//    }
//}
//void visittree(PTree root) {
//    if (root == NULL) 
//        return; 
//    PTree* stack = (PTree*)malloc(sizeof(PTree) * 100); 
//    int top = -1; 
//    stack[++top] = root;
//    while (top >= 0) {
//        PTree current = stack[top--];
//        visit(current);
//        if (current->rchild != NULL) {
//            stack[++top] = current->rchild;
//        }
//        if (current->lchild != NULL) {
//            stack[++top] = current->lchild;
//        }
//    }
//}
//int iscompletebinarytree(PTree root) {
//    if (root == NULL) 
//        return 0; 
//    PTree queue[100];
//    int front = 0, rear = 0; 
//    queue[rear++] = root; 
//    int ret = 0;
//
//    while (front != rear) { 
//        PTree current = queue[front++]; 
//        if (current->lchild) {
//            if (ret) return 0;
//            queue[rear++] = current->lchild;
//        }
//        else {
//            ret = 1; 
//        }
//        if (current->rchild) {
//            if (ret || !current->lchild) 
//                return 0;
//            queue[rear++] = current->rchild; 
//        }
//        else {
//            ret = 1; 
//        }
//    }
//    return 1; 
//}
//void printdata(PTree root) {
//    if (root == NULL) return; 
//    PTree* stack1 = (PTree*)malloc(sizeof(PTree) * 100); 
//    PTree* stack2 = (PTree*)malloc(sizeof(PTree) * 100); 
//    int top1 = -1, top2 = -1;
//    stack1[++top1] = root;
//    while (top1 >= 0 || top2 >= 0) { 
//        while (top1 >= 0) {
//            PTree current = stack1[top1--]; 
//            print(current); 
//            if (current->rchild != NULL) {
//                stack2[++top2] = current->rchild;
//            }
//            if (current->lchild != NULL) {
//                stack2[++top2] = current->lchild;
//            }
//        }
//        PTree* temp = stack1;
//        stack1 = stack2;
//        stack2 = temp;
//        top1 = top2;
//        top2 = -1;
//    }
//}
//typedef int QDataType;
//
//typedef struct QueueNode {
//    struct QueueNode* next;
//    QDataType val;
//} QNode;
//
//typedef struct Queue {
//    QNode* phead;
//    QNode* ptail;
//    int size;
//} Queue;
//
//void QueueInit(Queue* pq) {
//    assert(pq);
//    pq->phead = NULL;
//    pq->ptail = NULL;
//    pq->size = 0;
//}
//
//void QueueDestroy(Queue* pq) {
//    assert(pq);
//    QNode* cur = pq->phead;
//    while (cur) {
//        QNode* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    pq->phead = pq->ptail = NULL;
//    pq->size = 0;
//}
//
//void QueuePush(Queue* pq, QDataType x) {
//    assert(pq);
//    QNode* newnode = (QNode*)malloc(sizeof(QNode));
//    if (newnode == NULL) {
//        perror("malloc fail");
//        return;
//    }
//    newnode->next = NULL;
//    newnode->val = x;
//    if (pq->ptail == NULL) {
//        pq->phead = pq->ptail = newnode;
//    }
//    else {
//        pq->ptail->next = newnode;
//        pq->ptail = newnode;
//    }
//    pq->size++;
//}
//
//QDataType QueueFront(Queue* pq) {
//    assert(pq);
//    assert(pq->phead);
//    return pq->phead->val;
//}
//
//int QueueSize(Queue* pq) {
//    assert(pq);
//    return pq->size;
//}
//
//bool QueueEmpty(Queue* pq) {
//    assert(pq);
//    return pq->size == 0;
//}
//
//typedef int STDataType;
//
//typedef struct Stack {
//    STDataType* a;
//    int top;
//    int capacity;
//} ST;
//
//void STInit(ST* pst) {
//    assert(pst);
//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;
//}
//
//void STDestroy(ST* pst) {
//    assert(pst);
//    free(pst->a);
//    pst->a = NULL;
//    pst->top = pst->capacity = 0;
//}
//
//void STPush(ST* pst, STDataType x) {
//    assert(pst);
//    if (pst->top == pst->capacity) {
//        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
//        if (tmp == NULL) {
//            perror("realloc fail");
//            return;
//        }
//        pst->a = tmp;
//        pst->capacity = newcapacity;
//    }
//    pst->a[pst->top] = x;
//    pst->top++;
//}
//
//void STPop(ST* pst) {
//    assert(pst);
//    assert(pst->top > 0);
//    pst->top--;
//}
//
//STDataType STTop(ST* pst) {
//    assert(pst);
//    assert(pst->top > 0);
//    return pst->a[pst->top - 1];
//}
//
//bool STEmpty(ST* pst) {
//    assert(pst);
//    return pst->top == 0;
//}
//
//int STSize(ST* pst) {
//    assert(pst);
//    return pst->top;
//}
//
//int main() {
//    Queue x;
//    QueueInit(&x);
//    ST s;
//    STInit(&s);
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        int y;
//        scanf("%d", &y);
//        QueuePush(&x, y);
//    }
//    while (!QueueEmpty(&x)) {
//        int l = QueueFront(&x);
//        STPush(&s, l);
//        QNode* to_free = x.phead;
//        x.phead = x.phead->next;
//        if (x.phead == NULL) {
//            x.ptail = NULL;
//        }
//        free(to_free);
//        x.size--;
//    }
//    while (!STEmpty(&s)) {
//        int val = STTop(&s);
//        STPop(&s);
//        printf("%d ", val);
//    }
//    STDestroy(&s);
//    return 0;
//}
int main() {
    char a[100] = { 0 };
    char b[100] = { 0 };
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        a[i++] = ch;
    }
    a[i] = '\0';
    i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        b[i++] = ch;
    }
    b[i] = '\0';
    const char* ret = strstr(a, b);
    if (ret) {
        printf("%ld", ret - a);
    }
    else {
        printf("-1");
    }
    return 0;
}
void InsertSort(int* a, int n) {
    for (int i = 0; i < n; i++) {
        int end;
        int tmp = a[end + 1];
        while (end >= 0) {
            if (tmp < a[end]) {
                a[end + 1] = a[end];
                end--;
            }
            else {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}
#include"Heap.h"
#include<time.h>

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);
		HPPop(&hp);
	}
	printf("\n");

	// 找出最大的前k个
	/*int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");*/

	HPDestroy(&hp);
}

// 堆排序    O(N*logN)
// 冒泡排序  O(N^2) 
void HeapSort(int* a, int n)
{
	// 降序，建小堆
	// 升序，建大堆
	// 向上调整建堆 O(N*logN)
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	// 向下调整建堆 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
}

void CreateNDate()
{
	// 造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 10000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void TestHeap3()
{
	int k;
	printf("请输入k>:");
	scanf("%d", &k);
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// 读取文件中前k个数
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}

	// 11:51继续
	// 建K个数的小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	// 读取剩下的N-K个数
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("最大前%d个数：", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");
}

//int main()
//{
//	//CreateNDate();
//
//	TestHeap3();
//
//	return 0;
//}

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

int fun(int n)
{
	if (n == 0)
		return 0;

	return fun(n - 1) + n;
}

// 错误示范
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++(*psize);
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left)
		+ TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ?
		leftHeight + 1 : rightHeight + 1;
}

// 有效率问题
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right) ?
//		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

//int fmax(int x, int y)
//{
//	return x > y ? x : y;
//}

//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
//}
// 二叉树第k层节点个数
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	// 子问题
	return TreeLevelKSize(root->left, k - 1)
		+ TreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

//BTNode* TreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->data == x)
//		return root;
//
//	BTNode* ret1 = TreeFind(root->left, x);
//	if (ret1)
//		return ret1;
//
//	return TreeFind(root->right, x);
//}

// 二叉树销毁
void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}

#include"Queue.h"

void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		// 遇到第一个空，就可以开始判断，如果队列中还有非空，就不是完全二叉树
		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		// 如果有非空，就不是完全二叉树
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

// 插入排序
void InsertSort(int* a, int n)
{
	//  [0, n-1]
	for (int i = 0; i < n - 1; i++)
	{
		// [0,end]有序 end+1位置的值插入[0,end]，保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

int main()
{

	int a[] = { 2,4,1,7,8,3,9,2 };
	InsertSort(a, 8);

	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	//printf("%d\n", fun(10000));

	/*int size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n",size);

	size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n", size);*/

	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root, 3));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root, 4));

	TreeLevelOrder(root);
	printf("\n");

	TreeDestory(root);
	root = NULL;

	return 0;
}