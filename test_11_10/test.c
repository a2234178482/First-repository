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
void STDestroy(ST* pst) {
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = pst->capacity = 0;
}


//int main() {
//    ST s;
//    STInit(&s);
//
//    char ch;
//    bool seek = false;
//    int count = 0;
//
//    while ((ch = getchar()) != '@') {
//        if (ch == '&') {
//            if (seek) {
//                printf("no\n");
//                return 0;
//            }
//            seek = true;
//        }
//        else {
//            if (!seek) {
//                STPush(&s, ch);
//            }
//            else {
//                if (STEmpty(&s) || STTop(&s) != ch) {
//                    printf("no\n");
//                    return 0;
//                }
//                STPop(&s);
//            }
//            count++;
//        }
//    }
//    if (seek && STEmpty(&s)) {
//        printf("%d\n", count / 2);
//    }
//    else {
//        printf("no\n");
//    }
//    return 0;
//}

//double legendre(int n, double x) {
//    if (n == 0) {
//        return 1.0;
//    }
//    else if (n == 1) {
//        return x;
//    }
//    else {
//        
//        return((2 * n - 1) * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x))/n;
//    }
//}
//
//int main() {
//    int n = 0;
//    double x = 0.0;
//    scanf("%d %lf", &n, &x);
//    printf("%.2f",legendre(n, x));
//    return 0;
//}
//int reverseInteger(int n) {
//    int reversed = 0;
//    int sign = (n >= 0) ? 1 : -1;  
//    n = abs(n); 
//
//    while (n != 0) {
//        int digit = n % 10;
//        reversed = reversed * 10 + digit;
//        n /= 10;
//    }
//
//    return reversed * sign; 
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    int reversed = reverseInteger(n);
//    printf("%d\n", reversed);
//    return 0;
//}
//int count(ST* pst, ST* pq) {
//    int outCount = 0;
//    int inputIndex = 0;
//    int outputIndex = 0;
//    while (outputIndex < pq->top) {
//        if (!STEmpty(pst) && STTop(pst) == pq->a[outputIndex]) {
//            STPop(pst);
//            outputIndex++;
//            outCount++;
//        }
//        else {
//            if (inputIndex < pst->top) {
//                STPush(pst, pst->a[inputIndex]);
//                inputIndex++;
//            }
//            else {
//                return 0;
//            }
//        }
//    }
//    return outCount;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    ST input;
//    STInit(&input);
//    for (int i = 0; i < n; i++) {
//        int num;
//        scanf("%d", &num);
//        STPush(&input, num);
//    }
//    ST output;
//    STInit(&output);
//    for (int i = 0; i < n; i++) {
//        int num;
//        scanf("%d", &num);
//        STPush(&output, num);
//    }
//    int result = count(&input, &output);
//    printf("%d\n", result);
//    return 0;
//}
int isvalid(const char* s) {
    ST st;
    STInit(&st);
    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            STPush(&st, *s);
        }
        else if (*s == ')' || *s == ']' || *s == '}') {
            if (STEmpty(&st)) {
                STDestroy(&st);
                return 0;
            }
            char top = STTop(&st);
            STPop(&st);
            if ((*s == ')' && top != '(') ||
                (*s == ']' && top != '[') ||
                (*s == '}' && top != '{')) {
                STDestroy(&st);
                return 0;
            }
        }
        ++s;
    }
    int result = STEmpty(&st);
    STDestroy(&st);
    return result;
}

int main() {
    char a[100];
    if (fgets(a, 100, stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    a[strcspn(a, "\n")] = 0;  
    int ret = isvalid(a);
    printf("%d\n", ret);
    return 0;
}