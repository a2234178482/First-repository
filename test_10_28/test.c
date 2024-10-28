#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//typedef int STDataType;
//typedef struct Stack {
//    STDataType* a;
//    int top;
//    int capacity;
//} ST;
//void STInit(ST* pst) {
//    assert(pst);
//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;
//}
//bool STEmpty(ST* pst) {
//    assert(pst);
//    return pst->top == 0;
//}
//bool STFull(ST* pst) {
//    return pst->top == pst->capacity;
//}
//void STPush(ST* pst, STDataType x) {
//    assert(pst);
//    if (STFull(pst)) {
//        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
//        if (tmp == NULL) {
//            perror("realloc fail");
//            exit(EXIT_FAILURE);
//        }
//        pst->a = tmp;
//        pst->capacity = newcapacity;
//    }
//    pst->a[pst->top++] = x;
//}
//int STPop(ST* pst) {
//    assert(pst);
//    assert(!STEmpty(pst));
//    return pst->a[--pst->top];
//}
//void STDestroy(ST* pst) {
//    assert(pst);
//    free(pst->a);
//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;
//}
//int evaluateRPN(const char* tokens) {
//    ST stack;
//    STInit(&stack);
//    char* token = strtok((char*)tokens, " ");
//    while (token != NULL) {
//        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
//            STPush(&stack, atoi(token));
//        }
//        else {
//            int val2 = STPop(&stack);
//            int val1 = STPop(&stack);
//            switch (token[0]) {
//            case '+':
//                STPush(&stack, val1 + val2);
//                break;
//            case '-':
//                STPush(&stack, val1 - val2);
//                break;
//            case '*':
//                STPush(&stack, val1 * val2);
//                break;
//            case '/':
//                if (val2 == 0) {
//                    printf("Error: Division by zero\n");
//                    exit(EXIT_FAILURE);
//                }
//                STPush(&stack, val1 / val2);
//                break;
//            default:
//                printf("Error: Unknown operator '%c'\n", token[0]);
//                exit(EXIT_FAILURE);
//            }
//        }
//        token = strtok(NULL, " ");
//    }
//
//    int result = STPop(&stack);
//    STDestroy(&stack);
//    return result;
//}
//
//int main() {
//    char arr[256];
//    fgets(arr, sizeof(arr), stdin);
//    int result = evaluateRPN(arr);
//    printf("%d\n", result);
//    return 0;
//}