#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  

// 函数用于交换两个元素  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 调整堆，使其满足堆的性质  
void heapify(int arr[], int n, int i) {
    int largest = i; // 初始化最大元素为根  
    int left = 2 * i + 1; // 左子节点  
    int right = 2 * i + 2; // 右子节点  

    // 如果左子节点比根节点大，更新最大元素为左子节点  
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点比当前最大元素大，更新最大元素为右子节点  
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大元素不是根，则交换并继续调整  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数  
void heapSort(int arr[], int n) {
    // 建堆，从最后一个非叶子节点开始调整堆  
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 一个一个抽取元素，从堆中移除最大的元素  
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // 将当前最大元素移动到数组末尾  
        heapify(arr, i, 0); // 再次调整堆  
    }
}

// 打印数组  
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数  
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);
    return 0;
}

#include <stdio.h>  
#include <stdlib.h>  

// 辅助函数，用于交换两个元素  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 快速选择算法：找到第 k 小的元素  
int partition(int arr[], int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]); // 将枢轴值移到数组的最后  
    int store_index = left;

    for (int i = left; i < right; i++) {
        if (arr[i] > pivot_value) { // 寻找大于枢轴的元素  
            swap(&arr[store_index], &arr[i]);
            store_index++;
        }
    }
    // 将枢轴值放回到正确的位置  
    swap(&arr[store_index], &arr[right]);
    return store_index; // 返回枢轴位置  
}

// 快速选择算法的实现  
void quickSelect(int arr[], int left, int right, int k) {
    if (left == right) {
        return; // 如果只有一个元素  
    }

    int pivot_index = left + (right - left) / 2; // 选择中间的元素作为枢轴  
    pivot_index = partition(arr, left, right, pivot_index);

    // 递归进行选择  
    if (k == pivot_index) {
        return;
    }
    else if (k < pivot_index) {
        quickSelect(arr, left, pivot_index - 1, k);
    }
    else {
        quickSelect(arr, pivot_index + 1, right, k);
    }
}

// 求解问题的主函数  
void findTopK(int arr[], int n, int k) {
    quickSelect(arr, 0, n - 1, k - 1); // k-1 因为数组是从 0 开始索引  
    printf("前 %d 个最大元素是: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数  
int main() {
    int arr[] = { 3, 1, 5, 12, 2, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // 要找的前 k 大元素数量  

    findTopK(arr, n, k);
    return 0;
}

