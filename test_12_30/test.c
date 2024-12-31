#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (!newNode) {
//        printf("Memory allocation failed\n");
//        exit(1);
//    }
//    newNode->data = data;
//    newNode->next = NULL;
//    return newNode;
//}
//
//void BinInsertSort(Node** headRef) {
//    Node* sorted = NULL;
//    Node* current = *headRef;
//    while (current != NULL) {
//        Node* next = current->next;
//        sortedInsert(&sorted, current);
//        current = next;
//    }
//    *headRef = sorted;
//}
//
//void sortedInsert(Node** headRef, Node* newNode) {
//    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
//        newNode->next = *headRef;
//        *headRef = newNode;
//    }
//    else {
//        Node* current = *headRef;
//        while (current->next != NULL && current->next->data < newNode->data) {
//            current = current->next;
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//    }
//}
//
//void printList(Node* node) {
//    while (node != NULL) {
//        printf("%d ", node->data);
//        node = node->next;
//    }
//    printf("\n");
//}
//
//void freeList(Node* head) {
//    Node* temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//Node* arrayToLinkedList(int arr[], int n) {
//    if (n <= 0) return NULL;
//    Node* head = createNode(arr[0]);
//    Node* tail = head;
//    for (int i = 1; i < n; i++) {
//        Node* newNode = createNode(arr[i]);
//        tail->next = newNode;
//        tail = newNode;
//    }
//    return head;
//}
//
//void Swap(int* p1, int* p2) {
//    int tmp = *p1;
//    *p1 = *p2;
//    *p2 = tmp;
//}
//
//void insertSort(int* a, int n) {
//    for (int i = 0; i < n - 1; i++) {
//        int end = i;
//        int tmp = a[end + 1];
//        while (end >= 0) {
//            if (tmp < a[end]) {
//                a[end + 1] = a[end];
//                --end;
//            }
//            else {
//                break;
//            }
//        }
//        a[end + 1] = tmp;
//    }
//}
//
//void ShellSort(int* a, int n) {
//    int gap = n;
//    while (gap > 1) {
//        gap = gap / 3 + 1;
//        for (size_t i = 0; i < n - gap; ++i) {
//            int end = i;
//            int tmp = a[end + gap];
//            while (end >= 0) {
//                if (tmp < a[end]) {
//                    a[end + gap] = a[end];
//                    end -= gap;
//                }
//                else {
//                    break;
//                }
//            }
//            a[end + gap] = tmp;
//        }
//    }
//}
//
//void AdjustDown(int* a, int n, int parent) {
//    int child = parent * 2 + 1;
//    while (child < n) {
//        if (child + 1 < n && a[child + 1] > a[child]) {
//            ++child;
//        }
//
//        if (a[child] > a[parent]) {
//            Swap(&a[child], &a[parent]);
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else {
//            break;
//        }
//    }
//}
//
//void HeapSort(int* a, int n) {
//    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
//        AdjustDown(a, n, i);
//    }
//    int end = n - 1;
//    while (end > 0) {
//        Swap(&a[0], &a[end]);
//        AdjustDown(a, end, 0);
//        --end;
//    }
//}
//
//void BubbleSort(int* a, int n) {
//    for (int j = 0; j < n; j++) {
//        int flag = 0;
//        for (int i = 1; i < n - j; i++) {
//            if (a[i - 1] > a[i]) {
//                Swap(&a[i - 1], &a[i]);
//                flag = 1;
//            }
//        }
//
//        if (flag == 0) {
//            break;
//        }
//    }
//}
//
//void SelectSort(int* a, int n) {
//    int begin = 0, end = n - 1;
//    while (begin < end) {
//        int mini = begin, maxi = begin;
//        for (int i = begin + 1; i <= end; ++i) {
//            if (a[i] > a[maxi]) {
//                maxi = i;
//            }
//
//            if (a[i] < a[mini]) {
//                mini = i;
//            }
//        }
//        Swap(&a[begin], &a[mini]);
//        if (begin == maxi) {
//            maxi = mini;
//        }
//
//        Swap(&a[end], &a[maxi]);
//        ++begin;
//        --end;
//    }
//}
//
//void _MergeSort(int* a, int* tmp, int begin, int end) {
//    if (begin >= end)
//        return;
//    int mid = (begin + end) / 2;
//    _MergeSort(a, tmp, begin, mid);
//    _MergeSort(a, tmp, mid + 1, end);
//    int begin1 = begin, end1 = mid;
//    int begin2 = mid + 1, end2 = end;
//    int i = begin;
//    while (begin1 <= end1 && begin2 <= end2) {
//        if (a[begin1] <= a[begin2]) {
//            tmp[i++] = a[begin1++];
//        }
//        else {
//            tmp[i++] = a[begin2++];
//        }
//    }
//
//    while (begin1 <= end1) {
//        tmp[i++] = a[begin1++];
//    }
//
//    while (begin2 <= end2) {
//        tmp[i++] = a[begin2++];
//    }
//
//    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
//}
//
//void MergeSort(int* a, int n) {
//    int* tmp = (int*)malloc(sizeof(int) * n);
//    if (tmp == NULL) {
//        perror("malloc fail");
//        return;
//    }
//    _MergeSort(a, tmp, 0, n - 1);
//    free(tmp);
//    tmp = NULL;
//}
//
//int GetMidi(int* a, int left, int right) {
//    int midi = (left + right) / 2;
//    if (a[left] < a[midi]) {
//        if (a[midi] < a[right]) {
//            return midi;
//        }
//        else if (a[left] < a[right]) {
//            return right;
//        }
//        else {
//            return left;
//        }
//    }
//    else {
//        if (a[midi] > a[right]) {
//            return midi;
//        }
//        else if (a[left] < a[right]) {
//            return left;
//        }
//        else {
//            return right;
//        }
//    }
//}
//
//int PartSort1(int* a, int left, int right) {
//    int midi = GetMidi(a, left, right);
//    Swap(&a[left], &a[midi]);
//
//    int keyi = left;
//    int begin = left, end = right;
//    while (begin < end) {
//        while (begin < end && a[end] >= a[keyi]) {
//            --end;
//        }
//        while (begin < end && a[begin] <= a[keyi]) {
//            ++begin;
//        }
//
//        Swap(&a[begin], &a[end]);
//    }
//
//    Swap(&a[keyi], &a[begin]);
//    return begin;
//}
//
//void QuickSort(int* a, int left, int right) {
//    if (left >= right)
//        return;
//
//    int keyi = PartSort1(a, left, right);
//    QuickSort(a, left, keyi - 1);
//    QuickSort(a, keyi + 1, right);
//}
//
//void Print(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void CopyArray(int* src, int* dest, int n) {
//    for (int i = 0; i < n; i++) {
//        dest[i] = src[i];
//    }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    int arr[n];
//    int Arr[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    CopyArray(arr, Arr, n);
//    insertSort(Arr, n);
//    printf("InsertSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    Node* head = arrayToLinkedList(Arr, n);
//    BinInsertSort(&head);
//    printf("BinInsertSort: ");
//    printList(head);
//    freeList(head);
//    CopyArray(arr, Arr, n);
//    ShellSort(Arr, n);
//    printf("ShellSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    SelectSort(Arr, n);
//    printf("SelectSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    HeapSort(Arr, n);
//    printf("HeapSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    BubbleSort(Arr, n);
//    printf("BubbleSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    QuickSort(Arr, 0, n - 1);
//    printf("QuickSort: ");
//    Print(Arr, n);
//    CopyArray(arr, Arr, n);
//    MergeSort(Arr, n);
//    printf("MergeSort: ");
//    Print(Arr, n);
//    return 0;
//}
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (!newNode) {
//        printf("Memory allocation failed\n");
//        exit(1);
//    }
//    newNode->data = data;
//    newNode->next = NULL;
//    return newNode;
//}
//
//void BinInsertSort(Node** headRef, int* compareCount, int* moveCount) {
//    Node* sorted = NULL;
//    Node* current = *headRef;
//    while (current != NULL) {
//        Node* next = current->next;
//        (*compareCount)++;
//        sortedInsert(&sorted, current, compareCount, moveCount);
//        current = next;
//    }
//    *headRef = sorted;
//}
//
//void sortedInsert(Node** headRef, Node* newNode, int* compareCount, int* moveCount) {
//    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
//        newNode->next = *headRef;
//        *headRef = newNode;
//        (*moveCount)++;
//    }
//    else {
//        Node* current = *headRef;
//        while (current->next != NULL && current->next->data < newNode->data) {
//            current = current->next;
//            (*compareCount)++;
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//        (*moveCount)++;
//    }
//}
//
//void printList(Node* node) {
//    while (node != NULL) {
//        printf("%d ", node->data);
//        node = node->next;
//    }
//    printf("\n");
//}
//
//void freeList(Node* head) {
//    Node* temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//Node* arrayToLinkedList(int arr[], int n) {
//    if (n <= 0) return NULL;
//    Node* head = createNode(arr[0]);
//    Node* tail = head;
//    for (int i = 1; i < n; i++) {
//        Node* newNode = createNode(arr[i]);
//        tail->next = newNode;
//        tail = newNode;
//    }
//    return head;
//}
//
//void Swap(int* p1, int* p2, int* moveCount) {
//    int tmp = *p1;
//    *p1 = *p2;
//    *p2 = tmp;
//    (*moveCount) += 3; 
//}
//
//void insertSort(int* a, int n, int* compareCount, int* moveCount) {
//    for (int i = 1; i < n; i++) {
//        int key = a[i];
//        int j = i - 1;
//        (*moveCount)++;
//        while (j >= 0 && a[j] > key) {
//            a[j + 1] = a[j];
//            j--;
//            (*compareCount)++;
//            (*moveCount)++;
//        }
//        if (j >= 0) {
//            (*compareCount)++;
//        }
//        a[j + 1] = key;
//        (*moveCount)++;
//    }
//}
//
//void ShellSort(int* a, int n, int* compareCount, int* moveCount) {
//    int gap = n / 2;
//    while (gap > 0) {
//        for (int i = gap; i < n; i++) {
//            int temp = a[i];
//            int j = i;
//            (*moveCount)++;
//            while (j >= gap && a[j - gap] > temp) {
//                a[j] = a[j - gap];
//                j -= gap;
//                (*compareCount)++;
//                (*moveCount)++;
//            }
//            if (j >= gap) {
//                (*compareCount)++;
//            }
//            a[j] = temp;
//            (*moveCount)++;
//        }
//        gap /= 2;
//    }
//}
//
//void AdjustDown(int* a, int n, int parent, int* compareCount, int* moveCount) {
//    int child = parent * 2 + 1;
//    while (child < n) {
//        if (child + 1 < n && a[child + 1] > a[child]) {
//            child++;
//            (*compareCount)++;
//        }
//
//        if (a[child] > a[parent]) {
//            Swap(&a[child], &a[parent], moveCount);
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else {
//            break;
//        }
//        (*compareCount)++;
//    }
//}
//
//void HeapSort(int* a, int n, int* compareCount, int* moveCount) {
//    for (int i = (n - 2) / 2; i >= 0; i--) {
//        AdjustDown(a, n, i, compareCount, moveCount);
//    }
//    for (int i = n - 1; i > 0; i--) {
//        Swap(&a[0], &a[i], moveCount);
//        AdjustDown(a, i, 0, compareCount, moveCount);
//    }
//}
//
//void BubbleSort(int* a, int n, int* compareCount, int* moveCount) {
//    for (int i = 0; i < n - 1; i++) {
//        int flag = 0;
//        for (int j = 0; j < n - i - 1; j++) {
//            (*compareCount)++;
//            if (a[j] > a[j + 1]) {
//                Swap(&a[j], &a[j + 1], moveCount);
//                flag = 1;
//            }
//        }
//        if (!flag) {
//            break;
//        }
//    }
//}
//
//void SelectSort(int* a, int n, int* compareCount, int* moveCount) {
//    for (int i = 0; i < n - 1; i++) {
//        int minIndex = i;
//        for (int j = i + 1; j < n; j++) {
//            (*compareCount)++;
//            if (a[j] < a[minIndex]) {
//                minIndex = j;
//            }
//        }
//        if (minIndex != i) {
//            Swap(&a[i], &a[minIndex], moveCount);
//        }
//    }
//}
//
//void _MergeSort(int* a, int* tmp, int begin, int end, int* compareCount, int* moveCount) {
//    if (begin >= end)
//        return;
//    int mid = (begin + end) / 2;
//    _MergeSort(a, tmp, begin, mid, compareCount, moveCount);
//    _MergeSort(a, tmp, mid + 1, end, compareCount, moveCount);
//    int begin1 = begin, end1 = mid;
//    int begin2 = mid + 1, end2 = end;
//    int i = begin;
//    while (begin1 <= end1 && begin2 <= end2) {
//        (*compareCount)++;
//        if (a[begin1] <= a[begin2]) {
//            tmp[i++] = a[begin1++];
//            (*moveCount)++;
//        }
//        else {
//            tmp[i++] = a[begin2++];
//            (*moveCount)++;
//        }
//    }
//
//    while (begin1 <= end1) {
//        tmp[i++] = a[begin1++];
//        (*moveCount)++;
//    }
//
//    while (begin2 <= end2) {
//        tmp[i++] = a[begin2++];
//        (*moveCount)++;
//    }
//
//    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
//    (*moveCount) += (end - begin + 1);
//}
//
//void MergeSort(int* a, int n, int* compareCount, int* moveCount) {
//    int* tmp = (int*)malloc(sizeof(int) * n);
//    if (tmp == NULL) {
//        perror("malloc fail");
//        return;
//    }
//    _MergeSort(a, tmp, 0, n - 1, compareCount, moveCount);
//    free(tmp);
//    tmp = NULL;
//}
//
//int GetMidi(int* a, int left, int right, int* compareCount) {
//    int midi = (left + right) / 2;
//    if (a[left] < a[midi]) {
//        if (a[midi] < a[right]) {
//            return midi;
//        }
//        else if (a[left] < a[right]) {
//            return right;
//        }
//        else {
//            return left;
//        }
//    }
//    else {
//        if (a[midi] > a[right]) {
//            return midi;
//        }
//        else if (a[left] < a[right]) {
//            return left;
//        }
//        else {
//            return right;
//        }
//    }
//    (*compareCount) += 3;
//    return 0;
//}
//
//int PartSort1(int* a, int left, int right, int* compareCount, int* moveCount) {
//    int midi = GetMidi(a, left, right, compareCount);
//    Swap(&a[left], &a[midi], moveCount);
//    int keyi = left;
//    int begin = left, end = right;
//    while (begin < end) {
//        while (begin < end && a[end] >= a[keyi]) {
//            --end;
//            (*compareCount)++;
//        }
//        while (begin < end && a[begin] <= a[keyi]) {
//            ++begin;
//            (*compareCount)++;
//        }
//
//        Swap(&a[begin], &a[end], moveCount);
//    }
//
//    Swap(&a[keyi], &a[begin], moveCount);
//    return begin;
//}
//
//void QuickSort(int* a, int left, int right, int* compareCount, int* moveCount) {
//    if (left >= right)
//        return;
//
//    int keyi = PartSort1(a, left, right, compareCount, moveCount);
//    QuickSort(a, left, keyi - 1, compareCount, moveCount);
//    QuickSort(a, keyi + 1, right, compareCount, moveCount);
//}
//
//void Print(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void CopyArray(int* src, int* dest, int n) {
//    for (int i = 0; i < n; i++) {
//        dest[i] = src[i];
//    }
//}
//
//typedef struct AlgorithmResult {
//    char name[50];
//    int compareCount;
//    int moveCount;
//} AlgorithmResult;
//
//int compareByCompareCount(const void* a, const void* b) {
//    return ((AlgorithmResult*)a)->compareCount - ((AlgorithmResult*)b)->compareCount;
//}
//
//int compareByMoveCount(const void* a, const void* b) {
//    return ((AlgorithmResult*)a)->moveCount - ((AlgorithmResult*)b)->moveCount;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    int arr[n];
//    int Arr[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    AlgorithmResult results[] = {
//        {"InsertSort", 0, 0},
//        {"BInsertSort", 0, 0},
//        {"ShellSort", 0, 0},
//        {"SelectSort", 0, 0},
//        {"HeapSort", 0, 0},
//        {"BubbleSort", 0, 0},
//        {"QuickSort", 0, 0},
//        {"MergeSort", 0, 0}
//    };
//    CopyArray(arr, Arr, n);
//    insertSort(Arr, n, &results[0].compareCount, &results[0].moveCount);
//    CopyArray(arr, Arr, n);
//    Node* head = arrayToLinkedList(Arr, n);
//    BinInsertSort(&head, &results[1].compareCount, &results[1].moveCount);
//    freeList(head);
//    CopyArray(arr, Arr, n);
//    ShellSort(Arr, n, &results[2].compareCount, &results[2].moveCount);
//    CopyArray(arr, Arr, n);
//    SelectSort(Arr, n, &results[3].compareCount, &results[3].moveCount);
//    CopyArray(arr, Arr, n);
//    HeapSort(Arr, n, &results[4].compareCount, &results[4].moveCount);
//    CopyArray(arr, Arr, n);
//    BubbleSort(Arr, n, &results[5].compareCount, &results[5].moveCount);
//    CopyArray(arr, Arr, n);
//    QuickSort(Arr, 0, n - 1, &results[6].compareCount, &results[6].moveCount);
//    CopyArray(arr, Arr, n);
//    MergeSort(Arr, n, &results[7].compareCount, &results[7].moveCount);
//    qsort(results, 8, sizeof(AlgorithmResult), compareByCompareCount);
//    printf("the number of comparing(<)：");
//    for (int i = 0; i < 8; i++) {
//        printf("%s ", results[i].name);
//    }
//    printf("\n");
//    qsort(results, 8, sizeof(AlgorithmResult), compareByMoveCount);
//    printf("the number of moving(<)：");
//    for (int i = 0; i < 8; i++) {
//        printf("%s ", results[i].name);
//    }
//    printf("\n");
//    return 0;
//}
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//TreeNode* createNode(int value) {
//    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//    if (newNode == NULL) {
//        printf("内存分配失败\n");
//        exit(1);
//    }
//    newNode->data = value;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//void insertNode(TreeNode** root, int value) {
//    if (*root == NULL) {
//        *root = createNode(value);
//        return;
//    }
//    if (value < (*root)->data) {
//        insertNode(&((*root)->left), value);
//    }
//    else {
//        insertNode(&((*root)->right), value);
//    }
//}
//
//void inorderTraversal(TreeNode* root) {
//    if (root != NULL) {
//        inorderTraversal(root->left);
//        printf("%d ", root->data);
//        inorderTraversal(root->right);
//    }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n < 0) {
//        printf("error\n");
//        return 1;
//    }
//    TreeNode* root = NULL;
//    int value;
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &value);
//        insertNode(&root, value);
//    }
//    inorderTraversal(root);
//    return 0;
//}
//#define TABLE_SIZE 11
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
#define INITIAL_CAPACITY 10
typedef struct {
    int* data;
    int size;
    int capacity;
} SL;

SL* initSL() {
    SL* sl = (SL*)malloc(sizeof(SL));
    if (sl == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    sl->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (sl->data == NULL) {
        printf("内存分配失败\n");
        free(sl);
        exit(1);
    }
    sl->size = 0;
    sl->capacity = INITIAL_CAPACITY;
    return sl;
}

void addElement(SL* sl, int value) {
    if (sl->size >= sl->capacity) {
        sl->capacity *= 2;
        sl->data = (int*)realloc(sl->data, sl->capacity * sizeof(int));
        if (sl->data == NULL) {
            printf("内存重新分配失败\n");
            exit(1);
        }
    }
    sl->data[sl->size] = value;
    sl->size++;
}

void freeSL(SL* sl) {
    free(sl->data);
    free(sl);
}

int binarySearch(SL* sl, int item) {
    int left = 0;
    int right = sl->size - 1;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sl->data[mid] >= item) {
            result = mid + 1; 
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    SL* sl = initSL();
    int value;
    while (scanf("%d", &value) == 1) {
        addElement(sl, value);
    }
    while (getchar() != '\n');
    if (sl->size == 0) {
        printf("0\n");
        freeSL(sl);
        return 0;
    }
    int item;
    scanf("%d", &item);
    int position = binarySearch(sl, item);
    printf("%d\n", position);
    freeSL(sl);
    return 0;
}




































