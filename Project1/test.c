#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_PROCESSES 5
#define TIME_QUANTUM 1

// 进程状态枚举
typedef enum {
    READY,      // 就绪
    FINISHED    // 结束
} ProcessState;

// 进程控制块结构体
typedef struct PCB {
    char name[10];          // 进程名
    struct PCB* next;       // 指向下一个PCB的指针
    int required_time;      // 要求运行时间
    int elapsed_time;       // 已运行时间
    int priority;           // 优先数(越小优先级越高)
    ProcessState state;     // 进程状态
} PCB;

// 全局变量
PCB* ready_queue = NULL;    // 就绪队列头指针
int process_count = 0;      // 进程计数器

// 函数声明
void init_processes();
void add_to_ready_queue(PCB* process);
PCB* get_highest_priority_process();
void run_process(PCB* process);
void print_queue();
void free_processes();

int main() {
    printf("=== 多级反馈队列调度算法模拟 ===\n\n");

    // 初始化进程
    init_processes();

    // 打印初始状态
    printf("初始进程状态:\n");
    print_queue();
    printf("\n");

    // 调度循环
    while (ready_queue != NULL) {
        PCB* current = get_highest_priority_process();
        printf("选中运行的进程: %s\n", current->name);
        run_process(current);
        print_queue();
        printf("\n");
    }

    printf("所有进程已执行完毕!\n");
    free_processes();
    return 0;
}

// 初始化进程
void init_processes() {
    char name[10];
    int required_time, priority;

    for (int i = 0; i < MAX_PROCESSES; i++) {
        PCB* process = (PCB*)malloc(sizeof(PCB));
        if (process == NULL) {
            printf("内存分配失败!\n");
            exit(1);
        }

        // 修改了这里，使用更安全的snprintf代替sprintf_s
        snprintf(name, sizeof(name), "P%d", i + 1);
        // 修改了这里，使用strncpy代替strcpy_s
        strncpy(process->name, name, sizeof(process->name) - 1);
        process->name[sizeof(process->name) - 1] = '\0'; // 确保字符串终止

        printf("请输入进程 %s 的要求运行时间和优先数(用空格分隔): ", name);
        scanf_s("%d %d", &required_time, &priority);

        process->required_time = required_time;
        process->elapsed_time = 0;
        process->priority = priority;
        process->state = READY;
        process->next = NULL;

        add_to_ready_queue(process);
        process_count++;
    }
}

// 将进程添加到就绪队列(按优先级排序)
void add_to_ready_queue(PCB* process) {
    if (ready_queue == NULL) {
        ready_queue = process;
        return;
    }

    PCB* current = ready_queue;
    PCB* prev = NULL;

    // 找到插入位置(按优先级从小到大)
    while (current != NULL && current->priority <= process->priority) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // 插入到队列头部
        process->next = ready_queue;
        ready_queue = process;
    }
    else {
        // 插入到中间或尾部
        prev->next = process;
        process->next = current;
    }
}

// 从就绪队列中获取优先级最高的进程
PCB* get_highest_priority_process() {
    if (ready_queue == NULL) {
        return NULL;
    }

    PCB* highest = ready_queue;
    ready_queue = ready_queue->next;
    highest->next = NULL;
    return highest;
}

// 运行进程(模拟)
void run_process(PCB* process) {
    // 模拟运行一个时间片
    process->elapsed_time += TIME_QUANTUM;
    process->required_time -= TIME_QUANTUM;
    process->priority += 1;  // 每次运行后优先级降低

    if (process->required_time <= 0) {
        // 进程执行完毕
        process->state = FINISHED;
        printf("进程 %s 执行完毕!\n", process->name);
        free(process);
        process_count--;
    }
    else {
        // 重新加入就绪队列
        process->state = READY;
        add_to_ready_queue(process);
    }
}

// 打印当前队列状态
void print_queue() {
    printf("进程名\t要求时间\t已运行时间\t优先数\t状态\n");
    printf("------------------------------------------------\n");

    PCB* current = ready_queue;
    while (current != NULL) {
        printf("%s\t%d\t\t%d\t\t%d\t%s\n",
            current->name,
            current->required_time,
            current->elapsed_time,
            current->priority,
            current->state == READY ? "R" : "E");
        current = current->next;
    }
}

// 释放所有进程内存
void free_processes() {
    while (ready_queue != NULL) {
        PCB* temp = ready_queue;
        ready_queue = ready_queue->next;
        free(temp);
    }
}