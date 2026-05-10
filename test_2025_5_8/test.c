#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_N 50

typedef struct {
    int x, y, m;
} Island;

double graph[MAX_N][MAX_N];
Island islands[MAX_N];
int n;

void calculate_average_time() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &islands[i].x, &islands[i].y, &islands[i].m);
    }

    // 构建邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            }
            else {
                int dx = islands[i].x - islands[j].x;
                int dy = islands[i].y - islands[j].y;
                graph[i][j] = sqrt(dx * dx + dy * dy);
            }
        }
    }

    // Prim算法实现
    double dist[MAX_N];       // 存储到MST的最小距离
    int parent[MAX_N];        // 存储父节点
    int visited[MAX_N] = { 0 }; // 访问标记
    int order[MAX_N];         // 节点加入顺序
    int order_size = 0;

    // 初始化距离数组
    for (int i = 0; i < n; i++) {
        dist[i] = DBL_MAX;
        parent[i] = -1;
    }
    dist[0] = 0.0;  // 主岛初始距离为0

    // 构建MST
    for (int i = 0; i < n; i++) {
        // 寻找未访问的最小距离节点
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (u == -1) break;  // 所有节点已访问

        visited[u] = 1;
        order[order_size++] = u;  // 记录加入顺序

        // 更新邻接节点的最小距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // 计算每个节点的接入时间
    double ti[MAX_N] = { 0.0 };
    for (int i = 1; i < order_size; i++) { // 主岛不需要计算
        int u = order[i];
        ti[u] = (ti[parent[u]] > dist[u]) ? ti[parent[u]] : dist[u];
    }

    // 计算加权平均值
    double total_time = 0.0;
    int total_people = 0;
    for (int i = 0; i < n; i++) {
        total_time += ti[i] * islands[i].m;
        total_people += islands[i].m;
    }
    printf("%.2f\n", total_time / total_people);
}

int main() {
    calculate_average_time();
    return 0;
}
