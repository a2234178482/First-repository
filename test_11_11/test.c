#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//#define MAXSIZE 100 // 顺序栈存储空间的初始分配量
//
//typedef int Status;
//typedef char SElemType;
//
//typedef struct {
//    SElemType* base; // 栈底指针
//    SElemType* top;  // 栈顶指针
//    int stacksize;   // 栈的最大容量
//} SqStack;
//
//// 算法3.1 顺序栈的初始化
//Status InitStack(SqStack* S) {
//    S->base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
//    if (!S->base) {
//        printf("Memory allocation failed\n");
//        exit(OVERFLOW);
//    }
//    S->top = S->base;
//    S->stacksize = MAXSIZE;
//    return OK;
//}
//
//// 算法3.2 顺序栈的入栈
//Status Push(SqStack* S, SElemType e) {
//    if (S->top - S->base == S->stacksize)
//        return ERROR;
//    *(S->top++) = e;
//    return OK;
//}
//
//// 算法3.3 顺序栈的出栈
//Status Pop(SqStack* S, SElemType* e) {
//    if (S->base == S->top)
//        return ERROR;
//    *e = *(--S->top);
//    return OK;
//}
//
//// 算法3.4 取顺序栈的栈顶元素
//SElemType GetTop(SqStack S) {
//    if (S.top != S.base)
//        return *(S.top - 1);
//    return ERROR; // 如果栈为空，返回ERROR
//}
//
////释放内存空间
//void DestroyStack(SqStack S) {
//    free(S.base);
//}
//int main() {
//    SqStack s;
//    SElemType e_in[] = { 'a', 'b', 'c', 'd', 'e' };
//    SElemType e_out;
//
//    InitStack(&s);
//    for (int i = 0; i < 5; i++) {
//        Push(&s, e_in[i]);
//    }
//    while (Pop(&s, &e_out) == OK) {
//        printf("%c ", e_out);
//    }
//    printf("\n");
//
//    DestroyStack(s);
//
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

int sort(const void* a, const void* b) {
    Triplet* ta = (Triplet*)a;
    Triplet* tb = (Triplet*)b;
    if (ta->row != tb->row) return ta->row - tb->row;
    return ta->col - tb->col;
}

void ret(Triplet* A, int m, Triplet* B, int n, Triplet** result, int* resultSize) {
    *resultSize = 0;
    *result = (Triplet*)malloc((m + n) * sizeof(Triplet));
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            (*result)[(*resultSize)++] = A[i++];
        }
        else if (A[i].row > B[j].row || (A[i].row == B[j].row && A[i].col > B[j].col)) {
            (*result)[(*resultSize)++] = B[j++];
        }
        else { 
            int sum = A[i].value + B[j].value;
            if (sum != 0) {
                (*result)[(*resultSize)].row = A[i].row;
                (*result)[(*resultSize)].col = A[i].col;
                (*result)[(*resultSize)++].value = sum;
            }
            i++; j++;
        }
    }
    while (i < m) 
        (*result)[(*resultSize)++] = A[i++];
    while (j < n) 
        (*result)[(*resultSize)++] = B[j++];
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    Triplet* A = (Triplet*)malloc(m * sizeof(Triplet));
    Triplet* B = (Triplet*)malloc(n * sizeof(Triplet));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
    }
    Triplet* result;
    int size;
    ret(A, m, B, n, &result, &size);
    qsort(result, size, sizeof(Triplet), sort);
    for (int i = 0; i < size; i++) {
            printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
        }
    return 0;
}