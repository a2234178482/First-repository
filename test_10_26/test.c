#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义栈结构
typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

// 创建一个新的栈
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// 销毁栈
void destroyStack(Stack* stack) {
    free(stack->items);
    free(stack);
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// 入栈操作
void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    }
}

// 出栈操作
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // 返回-1表示错误
}

// 获取栈顶元素
int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    }
    return -1; // 返回-1表示错误
}

int main() {
    int n, i, input, out, count = 0;
    scanf("%d", &n); // 读取输入序列的长度
    Stack* stack = createStack(n);

    for (i = 0; i < n; i++) {
        scanf("%d", &input); // 读取输入序列
        push(stack, input); // 将输入序列的元素压入栈中
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &out); // 读取输出序列
        // 当栈顶元素与输出序列的当前元素相同，执行出栈
        while (!isEmpty(stack) && peek(stack) == out) {
            pop(stack);
            count++;
        }
    }

    // 如果栈为空，说明可以形成给定的输出序列
    if (isEmpty(stack)) {
        printf("%d\n", count);
    }
    else {
        printf("0\n");
    }

    destroyStack(stack); // 释放栈资源
    return 0;
}



// 判断字符串是否为回文
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // 如果有任何一对字符不匹配，则不是回文
        }
    }
    return 1; // 所有字符都匹配，是回文
}

int main() {
    char str[100]; // 定义一个长度小于100的字符串数组

    // 提示用户输入字符串
    printf("请输入一个字符串: ");
    scanf("%s", str);

    // 调用函数判断字符串是否为回文
    if (isPalindrome(str)) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 定义队列结构
typedef struct Queue {
    int* items;
    int front;
    int rear;
    int capacity;
} Queue;

// 定义栈结构
typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

// 创建队列
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// 销毁队列
void destroyQueue(Queue* queue) {
    free(queue->items);
    free(queue);
}

// 判断队列是否为空
int isQueueEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

// 判断队列是否已满
int isQueueFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// 入队操作
void enqueue(Queue* queue, int item) {
    if (!isQueueFull(queue)) {
        queue->items[++queue->rear] = item;
    }
}

// 出队操作
int dequeue(Queue* queue) {
    if (!isQueueEmpty(queue)) {
        return queue->items[queue->front++];
    }
    return -1; // 返回-1表示错误
}

// 创建栈
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// 销毁栈
void destroyStack(Stack* stack) {
    free(stack->items);
    free(stack);
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// 入栈操作
void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    }
}

// 出栈操作
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // 返回-1表示错误
}

// 逆置队列
void reverseQueue(Queue* queue, Stack* stack) {
    while (!isQueueEmpty(queue)) {
        int item = dequeue(queue);
        push(stack, item);
    }
    while (!isEmpty(stack)) {
        int item = pop(stack);
        enqueue(queue, item);
    }
}

int main() {
    int n;
    scanf("%d", &n); // 读取队列的元素个数

    Queue* queue = createQueue(n);
    Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        enqueue(queue, item);
    }

    reverseQueue(queue, stack);

    // 输出逆置后的队列
    for (int i = 0; i < n; i++) {
        int item = dequeue(queue);
        printf("%d ", item);
    }
    printf("\n");

    destroyQueue(queue);
    destroyStack(stack);

    return 0