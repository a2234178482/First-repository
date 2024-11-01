#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>  

typedef struct Patient {
    int caseNumber; // 病例号  
    struct Patient* next; // 下一位病人的指针  
} Patient;

typedef struct Queue {
    Patient* front; // 队头指针  
    Patient* rear; // 队尾指针  
} Queue;

// 功能函数声明  
Queue* createQueue();
void enqueue(Queue* q, int caseNumber);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void freeQueue(Queue* q);
void processRemainingPatients(Queue* q);

int main() {
    Queue* queue = createQueue();
    int choice;

    do {
        printf("1:病人排队 2:看医生 3:查看排队 4：不再排队，余下依次就诊 5:下班\n请选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int caseNumber;
            printf(">>输入病例号：");
            scanf("%d", &caseNumber);
            enqueue(queue, caseNumber);
            break;
        }
        case 2: {
            int caseNumber = dequeue(queue);
            if (caseNumber != -1) {
                printf(">>患者(%d)看医生\n", caseNumber);
            }
            break;
        }
        case 3: {
            printf(">> 排队患者：");
            displayQueue(queue);
            break;
        }
        case 4: {
            printf(">>以下患者将依次就诊：");
            processRemainingPatients(queue);
            break;
        }
        case 5: {
            printf("下班，感谢使用。\n");
            freeQueue(queue);
            exit(0);
        }
        default:
            printf("无效的选择，请重试。\n");
        }
    } while (1);

    return 0;
}

// 创建队列  
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// 插入病人到队列  
void enqueue(Queue* q, int caseNumber) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->caseNumber = caseNumber;
    newPatient->next = NULL;

    if (q->rear == NULL) { // 如果队列为空  
        q->front = newPatient;
        q->rear = newPatient;
    }
    else {
        q->rear->next = newPatient;
        q->rear = newPatient;
    }
}

// 从队列出队  
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf(">>目前没有排队患者。\n");
        return -1; // 最前面没有病人  
    }
    Patient* temp = q->front;
    int caseNumber = temp->caseNumber;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // 如果队列为空，更新队尾  
    }
    free(temp);
    return caseNumber;
}

// 查看当前排队病人  
void displayQueue(Queue* q) {
    Patient* current = q->front;
    if (current == NULL) {
        printf("没有患者排队。\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->caseNumber);
        current = current->next;
    }
    printf("\n");
}

// 处理余下的患者  
void processRemainingPatients(Queue* q) {
    while (q->front != NULL) {
        int caseNumber = dequeue(q);
        if (caseNumber != -1) {
            printf("%d ", caseNumber);
        }
    }
    printf("\n");
}

// 释放队列  
void freeQueue(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}

#include <stdio.h>  
#include <stdlib.h>  

#define MAX_SIZE 100 // 定义队列和栈的最大大小  

// 定义队列的结构  
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 定义栈的结构  
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 初始化队列  
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// 入队操作  
void enqueue(Queue* q, int value) {
    if (q->rear < MAX_SIZE) {
        q->data[q->rear++] = value;
    }
    else {
        printf("Queue is full!\n");
    }
}

// 出队操作  
int dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->data[q->front++];
    }
    else {
        printf("Queue is empty!\n");
        return -1; // 代表队列空  
    }
}

// 检查队列是否为空  
int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// 初始化栈  
void initStack(Stack* s) {
    s->top = -1;
}

// 入栈操作  
void push(Stack* s, int value) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = value;
    }
    else {
        printf("Stack is full!\n");
    }
}

// 出栈操作  
int pop(Stack* s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    else {
        printf("Stack is empty!\n");
        return -1; // 代表栈空  
    }
}

// 检查栈是否为空  
int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// 逆转队列  
void reverseQueue(Queue* q) {
    Stack s;
    initStack(&s);

    // 将队列的元素推入栈中  
    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    // 从栈中取出元素并放回队列  
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int n, value;
    // 输入队列元素个数  
    scanf("%d", &n);

    // 输入队列的元素  
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    // 逆转队列  
    reverseQueue(&q);

    // 输出逆转后的队列  
    while (!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}