#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
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
//int main() {
//    char a[100] = { 0 };
//    char b[100] = { 0 };
//    char c[200] = { 0 };
//    int i = 0;
//    char ch;
//    while ((ch = getchar()) != '#' && ch != EOF) {
//        a[i++] = ch;
//    }
//    a[i] = '\0';  
//    i = 0;
//    while ((ch = getchar()) != '#' && ch != EOF) {
//        b[i++] = ch;
//    }
//    b[i] = '\0';  
//    int j = 0;
//    while (b[j] != '\0') {
//        c[j] = b[j];
//        j++;
//    }
//    int k = 0;
//    while (a[k] != '\0') {
//        c[j + k] = a[k];
//        k++;
//    }
//    c[j + k] = '\0'; 
//    printf("%s\n", c);
//    return 0;
//}
//int main() {
//    char a[100] = { 0 };
//    char b[100] = { 0 };
//    char ch;
//    int i = 0;
//    while ((ch = getchar()) != '\n' && ch != EOF) {
//        a[i++] = ch;
//    }
//    a[i] = '\0';  
//    i = 0;
//    while ((ch = getchar()) != '\n' && ch != EOF) {
//        b[i++] = ch;
//    }
//    b[i] = '\0'; 
//    const char* ret = strstr(a, b);
//    if (ret) {
//        printf("%ld", ret-a);
//    }
//    else {
//        printf("-1");
//    }
//    return 0;
//}
//
//void reverse(char* str, int start, int end) {
//    while (start < end) {
//        char temp = str[start];
//        str[start] = str[end];
//        str[end] = temp;
//        start++;
//        end--;
//    }
//}
//
//void reverseWords(char* str) {
//    int len = strlen(str);
//    reverse(str, 0, len - 1);
//    int start = 0;
//    for (int i = 0; i <= len; i++) {
//        if (str[i] == ' ' || str[i] == '\0') {
//            reverse(str, start, i - 1);
//            start = i + 1;
//        }
//    }
//}
//void Print(char* arr, int sz) {
//    for (int i = 0; i < sz; i++) {
//        printf("%c", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    char a[100];
//    char ch;
//    int i = 0;
//    while ((ch = getchar()) != '\n' && ch != EOF) {
//        a[i++] = ch;
//    }
//    a[i] = '\0';
//
//    reverseWords(a);
//    int sz = strlen(a);
//    Print(a, sz);
//
//    return 0;
//}
//typedef int SLdatatype;
//typedef struct SLNode {
//    struct SLNode* next;
//    SLdatatype val;
//}SLNode;
//
//int SLTFind(SLNode* phead, SLdatatype x)
//{
//    SLNode* pcur = phead;
//    int count = 1;
//    while (pcur)
//    {
//        if (count == x) {
//            printf("%d", pcur->val);
//            return 1;
//        }
//        pcur = pcur->next;
//        count++;
//    }
//    return 0;
//}
//int num(SLNode* phead)
//{
//    SLNode* pcur = phead;
//    int count = 0;
//    while (pcur)
//    {
//        pcur = pcur->next;
//        count++;
//    }
//    return count;
//}
//SLNode* SLTBuyNode(SLdatatype x)
//{
//    SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
//    if (newnode == NULL)
//    {
//        perror("malloc fail!");
//        exit(1);
//    }
//    newnode->val = x;
//    newnode->next = NULL;
//    return newnode;
//}
//int main() {
//    int k;
//    int val;
//    scanf("%d", &k);
//    SLNode* head = NULL;
//    SLNode* pcur = NULL;
//    while (scanf("%d", &val) != EOF) {
//        if (val == '\n') {
//            break;
//        }
//        SLNode* newnode = SLTBuyNode(val);
//        if (head == NULL) {
//            head = newnode;
//            pcur = newnode;
//        }
//        else {
//            pcur->next = newnode;
//            pcur = newnode;
//        }
//    }
//    int ret = num(head);
//    if (k > ret) {
//        printf("Not Found");
//    }
//    else {
//        SLTFind(head, ret - k + 1);
//    }
//    return 0;
//}
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 10;
}
void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int Find_main_Elem(int arr[], int sz)
{
	if (sz == 0)
	{
		return -1;
	}
	if (sz == 1)
	{
		return arr[0];
	}
	int i = 0;
	int x = arr[sz / 2];
	int count = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}
	if (count > sz / 2)
	{
		return x;
	}
	else
	{
		return -1;
	}
}


int main()
{
	int* arr = (int*)malloc(10 * sizeof(int));
	if (arr == NULL)
	{
		perror("·ÖÅäÊ§°Ü");
		exit(0);
	}
	SL list;
	SLInit(&list);
	int count = 0;
	int i = 0;
	while (scanf("%d", &i) != EOF)
	{
		if (i == '\n') {
			break;
		}
		if (count >= list.capacity)
		{
			list.capacity *= 2;
			arr = (int*)realloc(arr, list.capacity * sizeof(int));
		}
		arr[count++] = i;
	}
	list.size = count;
	bubble_sort(arr, list.size);
	int result = Find_main_Elem(arr, list.size);
	printf("%d", result);
	free(arr);
	return 0;
}
