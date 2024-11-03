#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//int is_prime(int x) {
//	if (x < 2) {
//		return 0;
//	}
//	for (int i = 2; i < sqrt(x); i++) {
//		if (x % i == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	if (is_prime(n)) {
//		printf("prime");
//	}
//	else {
//		printf("not prime");
//	}
//} 
//void Print(int x) {
//	for (int i = 1; i <= x; i++) {
//		printf("%d", i);
//		printf("\n");
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}
//int count_num(int x, int y) {
//	int count = 0;
//	while (x) {
//		int tmp = x % 10;
//		if (tmp == y) {
//			count++;
//		}
//		x = x / 10;
//	}
//	return count;
//}
//int main() {
//	int x;
//	int y;
//	scanf("%d %d", &x, &y);
//	int ret = count_num(x, y);
//	printf("%d", ret);
//	return 0;
//}
//int reverse(int n) {
//    int reversed = 0;
//    int x = (n < 0) ? -1 : 1; 
//    n = abs(n);
//    while (n > 0) {
//        int digit = n % 10; 
//        reversed = reversed * 10 + digit;
//        n =n/ 10; 
//    }
//    return reversed * x;
//}
//int main() {
//    int n;
//    scanf("%d", &n); 
//    int result = reverse(n); 
//    printf("%d", result); 
//    return 0;
//}
//int candy(int day, int x) {
//	if (day == 1) {
//		return x;
//	}
//	int num = (x + 1) * 2;
//	return candy(day - 1, num);
//}
//int main() {
//	int day = 5;
//	int x = 1;
//	int ret = candy(day, x);
//	printf("%d", ret);
//}
//int f(int n) {
//	if (n == 2 || n == 1) {
//		return 1;
//	}
//	else {
//		return f(n-2) + f(n - 1);
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	int ret = f(n);
//	printf("%d", ret);
//}
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // 假设最大字符串长度为1000

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// 元素入栈
void push(Stack* s, char x) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = x;
    }
}

// 元素出栈
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// 获取栈顶元素
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int main() {
    Stack s;
    initStack(&s);

    char ch;
    bool isMatching = true;
    int count = 0; // 计算有效字符的数量

    while ((ch = getchar()) != '@') {
        if (ch == '&') {
            if (isEmpty(&s)) { // 如果'&'之前没有字符，不符合条件
                isMatching = false;
                break;
            }
            // 开始匹配序列2
            while ((ch = getchar()) != '@') {
                if (peek(&s) == ch) {
                    pop(&s);
                }
                else {
                    isMatching = false;
                    break;
                }
                count++;
            }
            break;
        }
        else {
            push(&s, ch);
            count++;
        }
    }

    if (isMatching && isEmpty(&s)) {
        printf("%d\n", count - 1); // 减去一个'&'符号
    }
    else {
        printf("no\n");
    }

    return 0;
}