#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef char STDataType;

typedef struct Stack {
    STDataType* a;
    int top;
    int capacity;
} ST;

void STInit(ST* pst) {
    assert(pst);
    pst->a = NULL;
    pst->top = 0;
    pst->capacity = 0;
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
bool STEmpty(ST* pst) {
    assert(pst);
    return pst->top == 0;
}
int panduanhuiwen(ST* phead) {
    if (STEmpty(phead)) {
        return 0;
    }
    ST pcur;
    STInit(&pcur);
    while (!STEmpty(phead)) {
        STDataType data = STTop(phead);
        STPop(phead);
        STPush(&pcur, data);
    }
    int result = 1;
    while (!STEmpty(phead) && !STEmpty(&pcur)) {
        if (STTop(phead) != STTop(&pcur)) {
            result = 0;
            break;
        }
        STPop(phead);
        STPop(&pcur);
    }
    while (!STEmpty(&pcur)) {
        STPush(phead, STTop(&pcur));
        STPop(&pcur);
    }
    return result;
}

int main() {
    ST s;
    STInit(&s);
    char tmp;
    while ((tmp = getchar()) != '#' && tmp != '\n') {
        if (tmp != '\n') {
            STPush(&s, tmp);
        }
    }
    if (panduanhuiwen(&s)) {
        printf("yes\n");
    }
    else {
        printf("字符串tmp不是回文\n");
    }
    while (!STEmpty(&s)) {
        STPop(&s);
    }
    free(s.a);
    return 0;
}

#define MAX_SIZE 100  

typedef struct Stack {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}
 
int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = item;
    }
}
 
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return -1;
}


int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; 
}

int main() {
    int n;
    scanf("%d", &n);
    int input[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    int output[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &output[i]);
    }
    Stack stack;
    initStack(&stack);
    int inIndex = 0, outIndex = 0, popCount = 0;
    while (outIndex < n) {  
        while (inIndex < n && (isEmpty(&stack) || peek(&stack) != output[outIndex])) {
            push(&stack, input[inIndex++]);
        } 
        if (!isEmpty(&stack) && peek(&stack) == output[outIndex]) {
            pop(&stack);
            popCount++;
            outIndex++;
        }
        else {  
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n", popCount);
    return 0;
}