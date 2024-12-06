#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>  

//#define MAXN 20  
//bool is_prime(int num) {
//    if (num < 2) return false;
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//void generate(bool primes[]) {
//    for (int i = 0; i < 38; i++) {
//        primes[i] = is_prime(i);
//    }
//}
//void print(int* arr, int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//bool is_valid(int* arr, int n, bool* primes) {
//    for (int i = 0; i < n; i++) {
//        if (!primes[arr[i] + arr[(i + 1) % n]]) {
//            return false;
//        }
//    }
//    return true;
//}
//void permute(int* arr, int* output, bool* used, int depth, int n, bool* primes) {
//    if (depth == n - 1) {
//        output[0] = 1;  
//        for (int i = 1; i < n; i++) {
//            output[i] = arr[i - 1]; 
//        }
//        if (is_valid(output, n, primes)) {
//            print(output, n);
//        }
//        return;
//    }
//
//    for (int i = 2; i <= n; i++) {    
//        if (!used[i]) {
//            used[i] = true;
//            arr[depth] = i;
//            permute(arr, output, used, depth + 1, n, primes);
//            used[i] = false;
//        }
//    }
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n < 2 || n % 2 != 0 || n > MAXN) {
//        return 1;
//    }
//    bool primes[38];
//    generate(primes);
//    int arr[MAXN], output[MAXN];
//    bool used[MAXN + 1] = { false };
//    permute(arr, output, used, 0, n, primes);
//    return 0;
//}
//int main() {
//    int N;
//    scanf("%d", &N);
//    int bottles[N], visited[N];
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &bottles[i]);
//        bottles[i]--;
//        visited[i] = 0;   
//    }
//    int count = 0;
//    for (int i = 0; i < N; i++) {
//        if (!visited[i]) {
//            int cycle_size = 0;
//            int j = i;
//            while (!visited[j]) {
//                visited[j] = 1;  
//                j = bottles[j]; 
//                cycle_size++;
//            }
//            if (cycle_size > 0) {
//                count += (cycle_size - 1);
//            }
//        }
//    }
//    printf("%d", count);
//    return 0;
//}
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int a[n][m];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            a[i][j] = 0;
//        }
//    }
//    int T;
//    scanf("%d", &T);
//    for (int op = 0; op < T; op++) {
//        int ope;
//        scanf("%d", &ope);
//        if (ope == 0) {
//            int x, y, k;
//            scanf("%d %d %d", &x, &y, &k);
//            a[x][y] = k;
//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < m; j++) {
//                    printf("%d ", a[i][j]);
//                }
//                printf("\n");
//            }
//        }
//        else if (ope == 1) {
//            int row, L, R;
//            scanf("%d %d %d", &row, &L, &R);
//            int sum = 0;
//            for (int j = L; j <= R; j++) {
//                sum += a[row][j];
//            }
//            printf("%d\n", sum);
//        }
//    }
//    return 0;
//}
#include <stdio.h>  

#define MAX_SIZE 9  

int main() {
    int N;
    int M;
    int matrixN[MAX_SIZE][MAX_SIZE];
    int matrixM[MAX_SIZE][MAX_SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrixN[i][j]);
        }
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrixM[i][j]);
        }
    }
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            int match = 1;
            for (int mi = 0; mi < M; mi++) {
                for (int mj = 0; mj < M; mj++) {
                    if (matrixN[i + mi][j + mj] != matrixM[mi][mj]) {
                        match = 0;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                printf("%d,%d\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}