#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int BTDatetype;
typedef struct BTree {
    BTDatetype val;
    struct BTree* lchild;
    struct BTree* rchild;
} BTree;

//BTree* createNode(BTDatetype data) {
//    BTree* newNode = (BTree*)malloc(sizeof(BTree));
//    if (!newNode) {
//        printf("Memory allocation failed\n");
//        exit(1);
//    }
//    newNode->val = data;
//    newNode->lchild = NULL;
//    newNode->rchild = NULL;
//    return newNode;
//}
//
//BTree* buildBTree(BTDatetype preorder[], int* index, int n) {
//    if (*index >= n || preorder[*index] == '#') {
//        (*index)++;
//        return NULL;
//    }
//    BTree* root = createNode(preorder[*index]);
//    (*index)++;
//    root->lchild = buildBTree(preorder, index, n);
//    root->rchild = buildBTree(preorder, index, n);
//    return root;
//}
//
//int isEmpty(BTree* root) {
//    return root == NULL;
//}
//
//void preorderR(BTree* root) {
//    if (root != NULL) {
//        printf("%c", root->val);
//        preorderR(root->lchild);
//        preorderR(root->rchild);
//    }
//}
//
//void inorderR(BTree* root) {
//    if (root != NULL) {
//        inorderR(root->lchild);
//        printf("%c", root->val);
//        inorderR(root->rchild);
//    }
//}
//
//void postorderR(BTree* root) {
//    if (root != NULL) {
//        postorderR(root->lchild);
//        postorderR(root->rchild);
//        printf("%c", root->val);
//    }
//}
//
//void preorderNonR(BTree* root) {
//    if (isEmpty(root)) 
//        return;
//    BTree* stack[100];
//    int top = -1;
//    stack[++top] = root;
//    while (top >= 0) {
//        BTree* current = stack[top--];
//        printf("%c", current->val);
//        if (current->rchild) 
//            stack[++top] = current->rchild;
//        if (current->lchild) 
//            stack[++top] = current->lchild;
//    }
//}
//
//void inorderNonR(BTree* root) {
//    if (isEmpty(root)) return;
//    BTree* stack[100];
//    int top = -1;
//    BTree* current = root;
//    while (current != NULL || top >= 0) {
//        while (current != NULL) {
//            stack[++top] = current;
//            current = current->lchild;
//        }
//        current = stack[top--];
//        printf("%c", current->val);
//        current = current->rchild;
//    }
//}
//
//int countNodes(BTree* root) {
//    if (root == NULL) return 0;
//    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
//}
//
//int countLeaves(BTree* root) {
//    if (root == NULL) 
//        return 0;
//    if (root->lchild == NULL && root->rchild == NULL) 
//        return 1;
//    return countLeaves(root->lchild) + countLeaves(root->rchild);
//}
//
//int Depth(BTree* root) {
//    if (root == NULL) 
//        return 0;
//    int leftDepth = Depth(root->lchild);
//    int rightDepth = Depth(root->rchild);
//    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
//}
//
//void printLeaves(BTree* root) {
//    if (root == NULL) 
//        return;
//    if (root->lchild == NULL && root->rchild == NULL) 
//        printf("%c ", root->val);
//    printLeaves(root->lchild);
//    printLeaves(root->rchild);
//}

//int main() {
//    BTDatetype preorder[99];
//    char a;
//    int count = 0;
//    while (scanf("%c", &a) != EOF && a != '\n') {
//        if (a == '#') {
//            preorder[count] = '#';
//        }
//        else {
//            preorder[count] = a;
//        }
//        count++;
//    }
//    int index = 0;
//    BTree* root = buildBTree(preorder, &index, count);
//    printf("preorder(recursive): ");
//    preorderR(root);
//    printf("\n");
//    printf("inorder(recursive): ");
//    inorderR(root);
//    printf("\n");
//    printf("postorder(recursive): ");
//    postorderR(root);
//    printf("\n");
//    printf("preorder(non-recursive): ");
//    preorderNonR(root);
//    printf("\n");
//    printf("inorder(non-recursive): ");
//    inorderNonR(root);
//    printf("\n");
//    printf("the number of nodes: %d\n", countNodes(root));
//    printf("leaf nodes: ");
//    printLeaves(root);
//    printf("\n");
//    printf("the number of leaf nodes: %d\n", countLeaves(root));
//    printf("the depth of the binary tree: %d\n", Depth(root));
//    return 0;
//}
typedef struct MinHeapNode {
    BTDatetype freq;
    BTDatetype originalVal;
    BTree* left, * right;
} MinHeapNode;
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;
MinHeapNode* newMinHeapNode(BTDatetype freq, BTDatetype originalVal) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->freq = freq;
    minHeapNode->originalVal = originalVal;
    minHeapNode->left = minHeapNode->right = NULL;
    return minHeapNode;
}
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
BTree* buildHuffmanTree(int freq[], int size) {
    MinHeapNode* left, * right, * top;
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        MinHeapNode* node = newMinHeapNode(freq[i], freq[i]);
        BTree* tree_node = (BTree*)malloc(sizeof(BTree));
        tree_node->val = freq[i];
        tree_node->lchild = tree_node->rchild = NULL;
        node->left = tree_node;
        minHeap->array[i] = node;
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newMinHeapNode(left->freq + right->freq, 0);
        BTree* tree_top = (BTree*)malloc(sizeof(BTree));
        tree_top->val = 0;
        tree_top->lchild = left->left;
        tree_top->rchild = right->left;
        top->left = tree_top;
        insertMinHeap(minHeap, top);
    }
    return minHeap->array[0]->left;
}
void calculateWPL(BTree* root, int depth, int* wpl) {
    if (root == NULL) return;
    if (root->lchild == NULL && root->rchild == NULL)
        *wpl += root->val * depth;
    calculateWPL(root->lchild, depth + 1, wpl);
    calculateWPL(root->rchild, depth + 1, wpl);
}
int main() {
    int n;
    scanf("%d", &n);
    int freq[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }
    BTree* root = buildHuffmanTree(freq, n);
    int wpl = 0;
    calculateWPL(root, 0, &wpl);
    printf("%d\n", wpl);
    return 0;
}





