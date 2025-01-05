#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define MAX_VERTICES 100
//typedef struct {
//    int numVertices;
//    bool adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
//} GraphAM;
//typedef struct Node {
//    int vertex;
//    struct Node* next;
//} Node;
//typedef struct {
//    int numVertices;
//    Node* adjacencyList[MAX_VERTICES];
//} GraphAL;
//void CreateGraphAM(GraphAM* graph, int numVertices, int numEdges) {
//    graph->numVertices = numVertices;
//    for (int i = 0; i < numVertices; i++) {
//        for (int j = 0; j < numVertices; j++) {
//            graph->adjacencyMatrix[i][j] = false;
//        }
//    }
//}
//void DestroyGraphAM(GraphAM* graph) {
//    graph->numVertices = 0;
//}
//int LocateVertexAM(GraphAM graph, int vertex) {
//    return vertex >= 1 && vertex <= graph.numVertices ? vertex - 1 : -1;
//}
//int GetVertexValueAM(GraphAM graph, int vertex) {
//    return vertex;
//}
//int FirstAdjacentVertexAM(GraphAM graph, int vertex) {
//    int index = LocateVertexAM(graph, vertex);
//    if (index == -1) return -1;
//    for (int i = 0; i < graph.numVertices; i++) {
//        if (graph.adjacencyMatrix[index][i]) return i + 1;
//    }
//    return -1;
//}
//void InsertVertexAM(GraphAM* graph, int vertex) {
//    if (graph->numVertices >= MAX_VERTICES) return;
//    graph->numVertices++;
//}
//void InsertEdgeAM(GraphAM* graph, int srcVertex, int destVertex) {
//    int srcIndex = LocateVertexAM(*graph, srcVertex);
//    int destIndex = LocateVertexAM(*graph, destVertex);
//    if (srcIndex != -1 && destIndex != -1) {
//        graph->adjacencyMatrix[srcIndex][destIndex] = true;
//    }
//}
//void DeleteVertexAM(GraphAM* graph, int vertex) {
//    int index = LocateVertexAM(*graph, vertex);
//    if (index == -1) return;
//    for (int i = 0; i < graph->numVertices; i++) {
//        graph->adjacencyMatrix[index][i] = false;
//        graph->adjacencyMatrix[i][index] = false;
//    }
//    for (int i = index; i < graph->numVertices - 1; i++) {
//        for (int j = 0; j < graph->numVertices; j++) {
//            graph->adjacencyMatrix[i][j] = graph->adjacencyMatrix[i + 1][j];
//            graph->adjacencyMatrix[j][i] = graph->adjacencyMatrix[j][i + 1];
//        }
//    }
//    graph->numVertices--;
//}
//void DeleteEdgeAM(GraphAM* graph, int srcVertex, int destVertex) {
//    int srcIndex = LocateVertexAM(*graph, srcVertex);
//    int destIndex = LocateVertexAM(*graph, destVertex);
//    if (srcIndex != -1 && destIndex != -1) {
//        graph->adjacencyMatrix[srcIndex][destIndex] = false;
//    }
//}
//void DFSUtilAM(GraphAM graph, int vertex, bool visited[], void (*Visit)(int)) {
//    int index = LocateVertexAM(graph, vertex);
//    if (index == -1) return;
//    visited[index] = true;
//    Visit(vertex);
//    for (int i = 0; i < graph.numVertices; i++) {
//        if (graph.adjacencyMatrix[index][i] && !visited[i]) {
//            DFSUtilAM(graph, i + 1, visited, Visit);
//        }
//    }
//}
//void DFSTraverseAM(GraphAM graph, void (*Visit)(int)) {
//    bool visited[graph.numVertices];
//    for (int i = 0; i < graph.numVertices; i++) visited[i] = false;
//    for (int i = 0; i < graph.numVertices; i++) {
//        if (!visited[i]) {
//            DFSUtilAM(graph, i + 1, visited, Visit);
//        }
//    }
//}
//void BFSUtilAM(GraphAM graph, int startVertex, bool visited[], void (*Visit)(int)) {
//    int queue[graph.numVertices], front = 0, rear = 0;
//    visited[startVertex - 1] = true;
//    queue[rear++] = startVertex;
//    while (front < rear) {
//        startVertex = queue[front++];
//        Visit(startVertex);
//        for (int adjacent = 1; adjacent <= graph.numVertices; adjacent++) {
//            if (graph.adjacencyMatrix[startVertex - 1][adjacent - 1] && !visited[adjacent - 1]) {
//                visited[adjacent - 1] = true;
//                queue[rear++] = adjacent;
//            }
//        }
//    }
//}
//void BFSTraverseAM(GraphAM graph, void (*Visit)(int)) {
//    bool visited[graph.numVertices];
//    for (int i = 0; i < graph.numVertices; i++) visited[i] = false;
//    for (int i = 1; i <= graph.numVertices; i++) {
//        if (!visited[i - 1]) {
//            BFSUtilAM(graph, i, visited, Visit);
//        }
//    }
//}
//int FindDegreeAM(GraphAM graph, int vertex) {
//    int degree = 0;
//    int index = LocateVertexAM(graph, vertex);
//    if (index == -1) return -1;
//    for (int i = 0; i < graph.numVertices; i++) {
//        if (graph.adjacencyMatrix[index][i]) degree++;
//    }
//    return degree;
//}
//Node* createNode(int vertex) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertex = vertex;
//    newNode->next = NULL;
//    return newNode;
//}
//void CreateGraphAL(GraphAL* graph, int numVertices, int numEdges) {
//    graph->numVertices = numVertices;
//    for (int i = 0; i < numVertices; ++i) {
//        graph->adjacencyList[i] = NULL;
//    }
//}
//void DestroyGraphAL(GraphAL* graph) {
//    for (int i = 0; i < graph->numVertices; ++i) {
//        Node* current = graph->adjacencyList[i];
//        while (current) {
//            Node* temp = current;
//            current = current->next;
//            free(temp);
//        }
//        graph->adjacencyList[i] = NULL;
//    }
//    graph->numVertices = 0;
//}
//int LocateVertexAL(GraphAL graph, int vertex) {
//    return vertex >= 1 && vertex <= graph.numVertices ? vertex - 1 : -1;
//}
//int GetVertexValueAL(GraphAL graph, int vertex) {
//    return vertex;
//}
//int FirstAdjacentVertexAL(GraphAL graph, int vertex) {
//    int index = LocateVertexAL(graph, vertex);
//    if (index == -1 || graph.adjacencyList[index] == NULL) return -1;
//    return graph.adjacencyList[index]->vertex;
//}
//void InsertVertexAL(GraphAL* graph, int vertex) {
//    if (graph->numVertices >= MAX_VERTICES) return;
//    graph->numVertices++;
//    graph->adjacencyList[vertex - 1] = NULL;
//}
//void InsertEdgeAL(GraphAL* graph, int srcVertex, int destVertex) {
//    int srcIndex = LocateVertexAL(*graph, srcVertex);
//    int destIndex = LocateVertexAL(*graph, destVertex);
//    if (srcIndex != -1 && destIndex != -1) {
//        Node* newNode = createNode(destVertex);
//        newNode->next = graph->adjacencyList[srcIndex];
//        graph->adjacencyList[srcIndex] = newNode;
//    }
//}
//void DeleteVertexAL(GraphAL* graph, int vertex) {
//    int index = LocateVertexAL(*graph, vertex);
//    if (index == -1) return;
//    Node* current = graph->adjacencyList[index];
//    while (current) {
//        Node* temp = current;
//        current = current->next;
//        free(temp);
//    }
//    graph->adjacencyList[index] = NULL;
//    for (int i = index; i < graph->numVertices - 1; i++) {
//        graph->adjacencyList[i] = graph->adjacencyList[i + 1];
//    }
//    graph->numVertices--;
//}
//void DeleteEdgeAL(GraphAL* graph, int srcVertex, int destVertex) {
//    int srcIndex = LocateVertexAL(*graph, srcVertex);
//    if (srcIndex == -1) return;
//    Node* current = graph->adjacencyList[srcIndex];
//    Node* prev = NULL;
//    while (current && current->vertex != destVertex) {
//        prev = current;
//        current = current->next;
//    }
//    if (current == NULL) return;
//    if (prev == NULL) {
//        graph->adjacencyList[srcIndex] = current->next;
//    }
//    else {
//        prev->next = current->next;
//    }
//    free(current);
//}
//void DFSUtilAL(GraphAL graph, int vertex, bool visited[], void (*Visit)(int)) {
//    int index = LocateVertexAL(graph, vertex);
//    if (index == -1) return;
//    visited[index] = true;
//    Visit(vertex);
//    Node* current = graph.adjacencyList[index];
//    while (current) {
//        if (!visited[current->vertex - 1]) {
//            DFSUtilAL(graph, current->vertex, visited, Visit);
//        }
//        current = current->next;
//    }
//}
//void DFSTraverseAL(GraphAL graph, void (*Visit)(int)) {
//    bool visited[graph.numVertices];
//    for (int i = 0; i < graph.numVertices; i++) visited[i] = false;
//    for (int i = 0; i < graph.numVertices; i++) {
//        if (!visited[i]) {
//            DFSUtilAL(graph, i + 1, visited, Visit);
//        }
//    }
//}
//void BFSUtilAL(GraphAL graph, int startVertex, bool visited[], void (*Visit)(int)) {
//    int queue[graph.numVertices], front = 0, rear = 0;
//    visited[startVertex - 1] = true;
//    queue[rear++] = startVertex;
//    while (front < rear) {
//        startVertex = queue[front++];
//        Visit(startVertex);
//        Node* current = graph.adjacencyList[startVertex - 1];
//        while (current) {
//            if (!visited[current->vertex - 1]) {
//                visited[current->vertex - 1] = true;
//                queue[rear++] = current->vertex;
//            }
//            current = current->next;
//        }
//    }
//}
//
//void BFSTraverseAL(GraphAL graph, void (*Visit)(int)) {
//    bool visited[graph.numVertices];
//    for (int i = 0; i < graph.numVertices; i++) visited[i] = false;
//    for (int i = 1; i <= graph.numVertices; i++) {
//        if (!visited[i - 1]) {
//            BFSUtilAL(graph, i, visited, Visit);
//        }
//    }
//}
//int FindDegreeAL(GraphAL graph, int vertex) {
//    int degree = 0;
//    int index = LocateVertexAL(graph, vertex);
//    if (index == -1) return -1;
//    Node* current = graph.adjacencyList[index];
//    while (current) {
//        degree++;
//        current = current->next;
//    }
//    return degree;
//}
//int FindInDegreeAL(GraphAL graph, int vertex) {
//    int inDegree = 0;
//    int index = LocateVertexAL(graph, vertex);
//    if (index == -1) return -1;
//    for (int i = 0; i < graph.numVertices; i++) {
//        Node* current = graph.adjacencyList[i];
//        while (current) {
//            if (current->vertex == vertex) {
//                inDegree++;
//            }
//            current = current->next;
//        }
//    }
//    return inDegree;
//}
//void VisitPrint(int vertex) {
//    printf("%d ", vertex);
//}
//int main() {
//    int graphType, numVertices, numEdges;
//    scanf("%d %d %d", &graphType, &numVertices, &numEdges);
//    GraphAM graphAM;
//    GraphAL graphAL;
//    if (graphType == 3 || graphType == 4) { // UDG or UDN
//        CreateGraphAM(&graphAM, numVertices, numEdges);
//        CreateGraphAL(&graphAL, numVertices, numEdges);
//        printf("UDG has been created successfully.\n");
//    }
//    else if (graphType == 1 || graphType == 2) { // DG or DN
//        CreateGraphAM(&graphAM, numVertices, numEdges);
//        CreateGraphAL(&graphAL, numVertices, numEdges);
//        printf("DG has been created successfully.\n");
//    }
//
//    int vertices[numVertices];
//    for (int i = 0; i < numVertices; i++) {
//        scanf("%d", &vertices[i]);
//    }
//    for (int i = 0; i < numEdges; i++) {
//        int srcVertex, destVertex;
//        scanf("%d %d", &srcVertex, &destVertex);
//        InsertEdgeAM(&graphAM, srcVertex, destVertex);
//        InsertEdgeAL(&graphAL, srcVertex, destVertex);
//        if (graphType == 3 || graphType == 4) { // UDG or UDN
//            InsertEdgeAM(&graphAM, destVertex, srcVertex);
//            InsertEdgeAL(&graphAL, destVertex, srcVertex);
//        }
//    }
//    printf("DFS traverse: ");
//    DFSTraverseAM(graphAM, VisitPrint);
//    printf("\n");
//    printf("BFS traverse: ");
//    BFSTraverseAM(graphAM, VisitPrint);
//    printf("\n");
//    printf("The degree of each vertex: ");
//    for (int i = 1; i <= numVertices; i++) {
//        printf("%d: %d", i, FindDegreeAM(graphAM, i));
//        if (i < numVertices) printf(", ");
//    }
//    printf("\n");
//    DestroyGraphAM(&graphAM);
//    DestroyGraphAL(&graphAL);
//    return 0;
//}
#define TABLE_SIZE 11
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//Node* createNode(int value) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL) {
//        printf("内存分配失败\n");
//        exit(1);
//    }
//    newNode->data = value;
//    newNode->next = NULL;
//    return newNode;
//}
//
//int hashFun(int key) {
//    return key % TABLE_SIZE;
//}
//
//void insertHash(Node* hashTable[], int value) {
//    int index = hashFun(value);
//    Node* newNode = createNode(value);
//    if (hashTable[index] == NULL) {
//        hashTable[index] = newNode;
//    }
//    else {
//        Node* temp = hashTable[index];
//        while (temp->next != NULL) {
//            temp = temp->next;
//        }
//        temp->next = newNode;
//    }
//}
//
//void printHash(Node* hashTable[]) {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        Node* temp = hashTable[i];
//        while (temp != NULL) {
//            printf("%d ", temp->data);
//            temp = temp->next;
//        }
//    }
//    printf("\n");
//}
//
//int main() {
//    int* values = (int*)malloc(sizeof(int));
//    if (values == NULL) {
//        printf("内存分配失败\n");
//        exit(1);
//    }
//    int n = 0;
//    int capacity = 1;
//    int value;
//    while (scanf("%d", &value) == 1) {
//        if (n >= capacity) {
//            capacity *= 2;
//            values = (int*)realloc(values, capacity * sizeof(int));
//            if (values == NULL) {
//                printf("内存重新分配失败\n");
//                exit(1);
//            }
//        }
//        values[n++] = value;
//    }
//
//    Node* hashTable[TABLE_SIZE];
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        hashTable[i] = NULL;
//    }
//
//    for (int i = 0; i < n; i++) {
//        insertHash(hashTable, values[i]);
//    }
//    printHash(hashTable);
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        Node* temp = hashTable[i];
//        while (temp != NULL) {
//            Node* toDelete = temp;
//            temp = temp->next;
//            free(toDelete);
//        }
//    }
//    free(values);
//    return 0;
//}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void BinInsertSort(Node** headRef) {
    Node* sorted = NULL;
    Node* current = *headRef;
    while (current != NULL) {
        Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

void sortedInsert(Node** headRef, Node* newNode) {
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        Node* current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* arrayToLinkedList(int arr[], int n) {
    if (n <= 0) return NULL;
    Node* head = createNode(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = createNode(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void Swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void insertSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0) {
            if (tmp < a[end]) {
                a[end + 1] = a[end];
                --end;
            }
            else {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int* a, int n) {
    int gap = n;
    while (gap > 1) {
        gap = gap / 3 + 1;
        for (size_t i = 0; i < n - gap; ++i) {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0) {
                if (tmp < a[end]) {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void AdjustDown(int* a, int n, int parent) {
    int child = parent * 2 + 1;
    while (child < n) {
        if (child + 1 < n && a[child + 1] > a[child]) {
            ++child;
        }

        if (a[child] > a[parent]) {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else {
            break;
        }
    }
}

void HeapSort(int* a, int n) {
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0) {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

void BubbleSort(int* a, int n) {
    for (int j = 0; j < n; j++) {
        int flag = 0;
        for (int i = 1; i < n - j; i++) {
            if (a[i - 1] > a[i]) {
                Swap(&a[i - 1], &a[i]);
                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

void SelectSort(int* a, int n) {
    int begin = 0, end = n - 1;
    while (begin < end) {
        int mini = begin, maxi = begin;
        for (int i = begin + 1; i <= end; ++i) {
            if (a[i] > a[maxi]) {
                maxi = i;
            }

            if (a[i] < a[mini]) {
                mini = i;
            }
        }
        Swap(&a[begin], &a[mini]);
        if (begin == maxi) {
            maxi = mini;
        }

        Swap(&a[end], &a[maxi]);
        ++begin;
        --end;
    }
}

void _MergeSort(int* a, int* tmp, int begin, int end) {
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int i = begin;
    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] <= a[begin2]) {
            tmp[i++] = a[begin1++];
        }
        else {
            tmp[i++] = a[begin2++];
        }
    }

    while (begin1 <= end1) {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2) {
        tmp[i++] = a[begin2++];
    }

    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n) {
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL) {
        perror("malloc fail");
        return;
    }
    _MergeSort(a, tmp, 0, n - 1);
    free(tmp);
    tmp = NULL;
}

int GetMidi(int* a, int left, int right) {
    int midi = (left + right) / 2;
    if (a[left] < a[midi]) {
        if (a[midi] < a[right]) {
            return midi;
        }
        else if (a[left] < a[right]) {
            return right;
        }
        else {
            return left;
        }
    }
    else {
        if (a[midi] > a[right]) {
            return midi;
        }
        else if (a[left] < a[right]) {
            return left;
        }
        else {
            return right;
        }
    }
}

int PartSort1(int* a, int left, int right) {
    int midi = GetMidi(a, left, right);
    Swap(&a[left], &a[midi]);

    int keyi = left;
    int begin = left, end = right;
    while (begin < end) {
        while (begin < end && a[end] >= a[keyi]) {
            --end;
        }
        while (begin < end && a[begin] <= a[keyi]) {
            ++begin;
        }

        Swap(&a[begin], &a[end]);
    }

    Swap(&a[keyi], &a[begin]);
    return begin;
}

void QuickSort(int* a, int left, int right) {
    if (left >= right)
        return;

    int keyi = PartSort1(a, left, right);
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}

void Print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void CopyArray(int* src, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int Arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    CopyArray(arr, Arr, n);
    insertSort(Arr, n);
    printf("InsertSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    Node* head = arrayToLinkedList(Arr, n);
    BinInsertSort(&head);
    printf("BinInsertSort: ");
    printList(head);
    freeList(head);
    CopyArray(arr, Arr, n);
    ShellSort(Arr, n);
    printf("ShellSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    SelectSort(Arr, n);
    printf("SelectSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    HeapSort(Arr, n);
    printf("HeapSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    BubbleSort(Arr, n);
    printf("BubbleSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    QuickSort(Arr, 0, n - 1);
    printf("QuickSort: ");
    Print(Arr, n);
    CopyArray(arr, Arr, n);
    MergeSort(Arr, n);
    printf("MergeSort: ");
    Print(Arr, n);
    return 0;
}


