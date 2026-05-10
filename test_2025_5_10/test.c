#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    // 创建第一个子进程
    child1 = fork();
    if (child1 == 0) {
        // 子进程1
        printf("这是子进程1，我的PID是%d\n", getpid());
        return 0;
    }

    // 创建第二个子进程
    child2 = fork();
    if (child2 == 0) {
        // 子进程2
        printf("这是子进程2，我的PID是%d\n", getpid());
        return 0;
    }

    // 父进程
    printf("这是父进程，我的PID是%d，我的两个子进程是%d和%d\n", getpid(), child1, child2);

    // 等待子进程结束
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    return 0;
}