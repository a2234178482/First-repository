#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//typedef struct {
//    int x;
//    int y1, y2;
//    int t; 
//} E;
//
//typedef struct {
//    int x1, y1;
//    int x2, y2;
//} R;
//
//int cmp(const void* a, const void* b) {
//    return ((E*)a)->x - ((E*)b)->x;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    E e[2 * n];
//    for (int i = 0; i < n; i++) {
//        R r;
//        scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
//        e[2 * i] = (E){ r.x1, r.y1, r.y2, 1 };
//        e[2 * i + 1] = (E){ r.x2, r.y1, r.y2, -1 };
//    }
//    qsort(e, 2 * n, sizeof(E), cmp);
//    int a[10001] = { 0 };
//    long long area = 0;
//    int cx = e[0].x;
//    for (int i = 0; i < 2 * n; i++) {
//        int dx = e[i].x - cx;
//        if (dx > 0) {
//            int h = 0;
//            for (int j = 0; j <= 10000; j++) {
//                if (a[j]) {
//                    h++;
//                }
//            }
//            area += (long long)dx * h;
//        }
//        if (e[i].t == 1) {
//            for (int j = e[i].y1; j < e[i].y2; j++) {
//                a[j]++;
//            }
//        }
//        else {
//            for (int j = e[i].y1; j < e[i].y2; j++) {
//                a[j]--;
//            }
//        }
//        cx = e[i].x;
//    }
//    printf("%lld\n", area);
//    return 0;
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    int pos[n];
//    int idx[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &pos[i]);
//        idx[pos[i] - 1] = i;
//    }
//    int vis[n];
//    int swaps = 0;
//    for (int i = 0; i < n; i++) {
//        if (!vis[i]) {
//            int sz = 0;
//            int j = i;
//            while (!vis[j]) {
//                vis[j] = 1;
//                j = idx[j];
//                sz++;
//            }
//            if (sz > 1) {
//                swaps += (sz - 1);
//            }
//        }
//    }
//    printf("%d\n", swaps);
//    return 0;
//}
#define MAX_SIZE 100

typedef struct {
    int number;
    int count;
} Pair;

int compare(const void* a, const void* b) {
    return ((Pair*)a)->number - ((Pair*)b)->number;
}

int main() {
    int n;
    scanf("%d", &n);

    int numbers[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    Pair pairs[MAX_SIZE] = { 0 };
    int pair_count = 0;

    // Count occurrences of each number
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < pair_count; j++) {
            if (pairs[j].number == numbers[i]) {
                pairs[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            pairs[pair_count].number = numbers[i];
            pairs[pair_count].count = 1;
            pair_count++;
        }
    }

    // Sort pairs by number to handle multiple max counts correctly
    qsort(pairs, pair_count, sizeof(Pair), compare);

    // Find the maximum count
    int max_count = 0;
    for (int i = 0; i < pair_count; i++) {
        if (pairs[i].count > max_count) {
            max_count = pairs[i].count;
        }
    }

    // Print all numbers with the maximum count
    for (int i = 0; i < pair_count; i++) {
        if (pairs[i].count == max_count) {
            printf("%d %d\n", pairs[i].number, pairs[i].count);
        }
    }

    return 0;
}

#define MAX_SIZE 20

// 比较函数用于qsort，按降序排列
int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int numbers[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // 提取唯一元素
    int unique_numbers[MAX_SIZE];
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) {
            if (numbers[i] == unique_numbers[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_numbers[unique_count++] = numbers[i];
        }
    }

    // 对唯一元素进行降序排序
    qsort(unique_numbers, unique_count, sizeof(int), compare_desc);

    // 创建编号映射
    int rank_map[MAX_SIZE][2]; // [number, rank]
    for (int i = 0; i < unique_count; i++) {
        rank_map[i][0] = unique_numbers[i];
        rank_map[i][1] = i + 1;
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < unique_count; j++) {
            if (numbers[i] == rank_map[j][0]) {
                printf("%d ", rank_map[j][1]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
