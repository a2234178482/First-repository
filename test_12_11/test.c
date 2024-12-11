#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void max_min(float* arr, int n, float* max_val, float* min_val) {
    *max_val = arr[0];
    *min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    float max_val, min_val;
    max_min(arr, n, &max_val, &min_val);
    printf("%.2f\n", max_val);
    printf("%.2f\n", min_val);
    return 0;
}
