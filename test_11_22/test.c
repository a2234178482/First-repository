#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//typedef char STDataType;
//typedef struct Stack {
//    STDataType* a;
//    int top;
//    int capacity;
//} ST;
//
//void STInit(ST* pst) {
//    assert(pst);
//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;
//}
//
//void STPush(ST* pst, STDataType x) {
//    assert(pst);
//    if (pst->top == pst->capacity) {
//        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
//        if (tmp == NULL) {
//            perror("realloc fail");
//            return;
//        }
//        pst->a = tmp;
//        pst->capacity = newcapacity;
//    }
//    pst->a[pst->top] = x;
//    pst->top++;
//}
//
//void STPop(ST* pst) {
//    assert(pst);
//    assert(pst->top > 0);
//    pst->top--;
//}
//
//STDataType STTop(ST* pst) {
//    assert(pst);
//    assert(pst->top > 0);
//    return pst->a[pst->top - 1];
//}
//
//bool STEmpty(ST* pst) {
//    assert(pst);
//    return pst->top == 0;
//}
//void STDestroy(ST* pst) {
//    assert(pst);
//    free(pst->a);
//    pst->a = NULL;
//    pst->top = pst->capacity = 0;
//}
//
//
//int isvalid(const char* s) {
//    ST st;
//    STInit(&st);
//    while (*s) {
//        if (*s == '(' || *s == '[' || *s == '{') {
//            STPush(&st, *s);
//        }
//        else if (*s == ')' || *s == ']' || *s == '}') {
//            if (STEmpty(&st)) {
//                STDestroy(&st);
//                return 0;
//            }
//            char top = STTop(&st);
//            STPop(&st);
//            if ((*s == ')' && top != '(') ||
//                (*s == ']' && top != '[') ||
//                (*s == '}' && top != '{')) {
//                STDestroy(&st);
//                return 0;
//            }
//        }
//        ++s;
//    }
//    int result = STEmpty(&st);
//    STDestroy(&st);
//    return result;
//}
//
//int main() {
//    char a[100];
//    if (fgets(a, 100, stdin) == NULL) {
//        printf("Error reading input\n");
//        return 1;
//    }
//    a[strcspn(a, "\n")] = 0;
//    int ret = isvalid(a);
//    printf("%d\n", ret);
//    return 0;
//}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// 创建N个随机数，写到文件中
void CreateNDate()
{
    // 造数据
    int n = 10000000;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if (fin == NULL)
    {
        perror("fopen error");
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        int x = rand() + i;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// 返回实际读到的数据个数，没有数据了，返回0
int ReadNDataSortToFile(FILE* fout, int n, const char* file1)
{
    int x = 0;
    int* a = (int*)malloc(sizeof(int) * n);
    if (a == NULL)
    {
        perror("malloc error");
        return 0;
    }

    // 想读取n个数据，如果遇到文件结束，应该读到j个
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (fscanf(fout, "%d", &x) == EOF)
            break;

        a[j++] = x;
    }

    if (j == 0)
    {
        free(a);
        return 0;
    }

    // 排序
    qsort(a, j, sizeof(int), compare);

    FILE* fin = fopen(file1, "w");
    if (fin == NULL)
    {
        free(a);
        perror("fopen error");
        return 0;
    }

    // 写回file1文件
    for (int i = 0; i < j; i++)
    {
        fprintf(fin, "%d\n", a[i]);
    }

    free(a);
    fclose(fin);

    return j;
}

void MergeFile(const char* file1, const char* file2, const char* mfile)
{
    FILE* fout1 = fopen(file1, "r");
    if (fout1 == NULL)
    {
        perror("fopen error");
        return;
    }

    FILE* fout2 = fopen(file2, "r");
    if (fout2 == NULL)
    {
        perror("fopen error");
        return;
    }

    FILE* mfin = fopen(mfile, "w");
    if (mfin == NULL)
    {
        perror("fopen error");
        return;
    }

    // 归并逻辑
    int x1 = 0;
    int x2 = 0;
    int ret1 = fscanf(fout1, "%d", &x1);
    int ret2 = fscanf(fout2, "%d", &x2);
    while (ret1 != EOF && ret2 != EOF)
    {
        if (x1 < x2)
        {
            fprintf(mfin, "%d\n", x1);
            ret1 = fscanf(fout1, "%d", &x1);
        }
        else
        {
            fprintf(mfin, "%d\n", x2);
            ret2 = fscanf(fout2, "%d", &x2);
        }
    }

    while (ret1 != EOF)
    {
        fprintf(mfin, "%d\n", x1);
        ret1 = fscanf(fout1, "%d", &x1);
    }

    while (ret2 != EOF)
    {
        fprintf(mfin, "%d\n", x2);
        ret2 = fscanf(fout2, "%d", &x2);
    }

    fclose(fout1);
    fclose(fout2);
    fclose(mfin);
}

int main()
{
    CreateNDate();

    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";
    const char* mfile = "mfile.txt";

    FILE* fout = fopen("data.txt", "r");
    if (fout == NULL)
    {
        perror("fopen error");
        return;
    }

    int m = 1000000;
    ReadNDataSortToFile(fout, m, file1);
    ReadNDataSortToFile(fout, m, file2);

    while (1)
    {
        MergeFile(file1, file2, mfile);

        // 删除file1和file2
        remove(file1);
        remove(file2);

        // 重命名mfile为file1
        rename(mfile, file1);

        // 当再去读取数据，一个都读不到，说明已经没有数据了
        // 已经归并完成，归并结果在file1
        int n = 0;
        if ((n = ReadNDataSortToFile(fout, m, file2)) == 0)
            break;

        /*if (n < 100)
        {
            int x = 0;
        }*/
    }

    return 0;
}