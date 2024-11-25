#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//
//    int c[a][b];
//    for (int d = 0; d < a; d++) {
//        for (int e = 0; e < b; e++) {
//            scanf("%d", &c[d][e]);
//        }
//    }
//
//    int f = 0;
//
//    for (int g = 0; g < a; g++) {
//        int h = INT_MAX;
//        int i = -1;
//
//        for (int j = 0; j < b; j++) {
//            if (c[g][j] < h) {
//                h = c[g][j];
//                i = j;
//            }
//        }
//
//        int k = INT_MIN;
//        for (int l = 0; l < a; l++) {
//            if (c[l][i] > k) {
//                k = c[l][i];
//            }
//        }
//
//        if (h == k) {
//            printf("%4d", h);
//            f = 1;
//        }
//    }
//
//    if (!f) {
//        printf("no");
//    }
//
//    return 0;
//}

//typedef struct {
//    int row;
//    int col;
//    int value;
//} Tri;
//
//void sum(Tri A[], int m, Tri B[], int n, Tri C[], int* size) {
//    int i = 0, j = 0, k = 0;
//
//    while (i < m && j < n) {
//        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
//            C[k++] = A[i++];
//        }
//        else if (A[i].row > B[j].row || (A[i].row == B[j].row && A[i].col > B[j].col)) {
//            C[k++] = B[j++];
//        }
//        else {
//            int val = A[i].value + B[j].value;
//            if (val != 0) {
//                C[k].row = A[i].row;
//                C[k].col = A[i].col;
//                C[k++].value = val;
//            }
//            i++;
//            j++;
//        }
//    }
//
//    while (i < m) {
//        C[k++] = A[i++];
//    }
//
//    while (j < n) {
//        C[k++] = B[j++];
//    }
//
//    *size = k;
//}
//
//int main() {
//    int m, n;
//    scanf("%d %d", &m, &n);
//
//    Tri* A = (Tri*)malloc(m * sizeof(Tri));
//    Tri* B = (Tri*)malloc(n * sizeof(Tri));
//    Tri* C = (Tri*)malloc((m + n) * sizeof(Tri));
//
//    for (int i = 0; i < m; i++) {
//        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
//    }
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
//    }
//
//    int resultSize;
//    sum(A, m, B, n, C, &resultSize);
//
//    if (resultSize == 0) {
//        printf("-1 -1 -1\n");
//    }
//    else {
//        for (int i = 0; i < resultSize; i++) {
//            printf("%d %d %d\n", C[i].row, C[i].col, C[i].value);
//        }
//    }
//
//    free(A);
//    free(B);
//    free(C);
//
//    return 0;
//}
//ÂÖ×ªÊý×é 
void reverse(int* a, int left, int right) {
    while (left < right) {
        int tmp = 0;
        tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}


int missingNumber(int* nums, int numsSize) {
    int x = 0;
    int y = numsSize;
    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];
    }
    for (int j = 0; j <= y; j++) {
        x ^= j;
    }
    return x;
}
int kthToLast(struct ListNode* head, int k) {
    struct ListNode* fast = head; ;
    struct ListNode* tail = head;;
    while (k--) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        tail = tail->next;
    }
    return tail->val;
}