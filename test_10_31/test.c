#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main() {

    int year, month;

    while (scanf("%d %d", &year, &month) != EOF)

    {

        switch (month)

        {

        case 2:

            if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)

                printf("29\n");

            else

                printf("28\n");

            break;

        case 4:

        case 6:

        case 9:

        case 11: printf("30\n"); break;

        default: printf("31\n"); break;

        }

    }

    return 0;
}

void findSingleNumbers(int* nums, int numsSize, int* result) {
    int xorResult = 0;

    // Step 1: 获取两个只出现一次的数字的异或值  
    for (int i = 0; i < numsSize; i++) {
        xorResult ^= nums[i];
    }

    // Step 2: 找到 xorResult 中的一个非零位  
    int diffBit = xorResult & -xorResult; // 获取最右边的1  

    // Step 3: 根据 diffBit 将数字分为两组并进行异或  
    result[0] = 0;
    result[1] = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & diffBit) {
            result[0] ^= nums[i]; // 第一组  
        }
        else {
            result[1] ^= nums[i]; // 第二组  
        }
    }
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result[2];

    findSingleNumbers(nums, numsSize, result);

    printf("The two numbers that appear only once are: %d and %d\n", result[0], result[1]);

    return 0;
}

// 比较函数，用于排序整数  
int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 比较函数，用于排序浮点数  
int compareFloat(const void* a, const void* b) {
    if (*(float*)a < *(float*)b) return -1;
    if (*(float*)a > *(float*)b) return 1;
    return 0;
}

// 比较函数，用于排序字符串  
int compareString(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    // 整数数组  
    int intArray[] = { 5, 3, 8, 1, 2 };
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    // 对整数数组进行排序  
    qsort(intArray, intSize, sizeof(int), compareInt);
    printf("Sorted integer array: ");
    for (size_t i = 0; i < intSize; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // 浮点数数组  
    float floatArray[] = { 5.5, 2.2, 3.3, 1.1, 4.4 };
    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    // 对浮点数数组进行排序  
    qsort(floatArray, floatSize, sizeof(float), compareFloat);
    printf("Sorted float array: ");
    for (size_t i = 0; i < floatSize; i++) {
        printf("%.1f ", floatArray[i]);
    }
    printf("\n");

    // 字符串数组  
    const char* stringArray[] = { "banana", "apple", "orange", "grape" };
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    // 对字符串数组进行排序  
    qsort(stringArray, stringSize, sizeof(char*), compareString);
    printf("Sorted string array: ");
    for (size_t i = 0; i < stringSize; i++) {
        printf("%s ", stringArray[i]);
    }
    printf("\n");

    return 0;
}