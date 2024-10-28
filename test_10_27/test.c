#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>  
#include <assert.h>  
#include <string.h>
//typedef struct ListNode {
//    int val;
//    struct ListNode* next;
//} ListNode;
//
//ListNode* SLBuyNode(SLdatatype x) {
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    if (newnode == NULL) {
//        perror("malloc fail!");
//        exit(1);
//    }
//    newnode->val = x;
//    newnode->next = NULL;
//    return newnode;
//}
//
//void Print(ListNode* phead) {
//    ListNode* pcur = phead;
//    while (pcur != NULL) {
//        printf("%d ", pcur->val);
//        pcur = pcur->next;
//    }
//}
//
//ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//    ListNode* newhead = NULL;
//    ListNode* newtail = NULL;
//    ListNode* l1 = list1;
//    ListNode* l2 = list2;
//    while (l1 != NULL && l2 != NULL) {
//        ListNode* nextNode = NULL;
//        if (l1->val < l2->val) {
//            nextNode = l1;
//            l1 = l1->next;
//        }
//        else {
//            nextNode = l2;
//            l2 = l2->next;
//        }
//
//        if (newhead == NULL) {
//            newhead = newtail = nextNode;
//        }
//        else {
//            newtail->next = nextNode;
//            newtail = newtail->next;
//        }
//    }
//
//    if (l1 != NULL) {
//        newtail->next = l1;
//    }
//    if (l2 != NULL) {
//        newtail->next = l2;
//    }
//    return newhead;
//}

//void SLTErase(ListNode* phead) {
//    ListNode* pcur = phead;
//    while (pcur != NULL) {
//        ListNode* nextNode = pcur->next;
//        while (nextNode != NULL && nextNode->val == pcur->val) {
//            ListNode* duplicate = nextNode;
//            nextNode = nextNode->next;
//            free(duplicate);
//        }
//        pcur->next = nextNode;
//        pcur = nextNode;
//    }
//}
//
//int main() {
//    ListNode* phead = NULL;
//    ListNode* pphead = NULL;
//    int val, value;
//    while (scanf("%d", &val) == 1) {
//        ListNode* newNode = SLBuyNode(val);
//        if (phead == NULL) {
//            phead = newNode;
//        }
//        else {
//            ListNode* temp = phead;
//            while (temp->next != NULL) {
//                temp = temp->next;
//            }
//            temp->next = newNode;
//        }
//    }
//    while (scanf("%d", &value) == 1) {
//        ListNode* newnode = SLBuyNode(value);
//        if (pphead == NULL) {
//            pphead = newnode;
//        }
//        else {
//            ListNode* temp = pphead;
//            while (temp->next != NULL) {
//                temp = temp->next;
//            }
//            temp->next = newnode;
//        }
//    }
//    ListNode* l1 = merge_two_lists(phead, pphead);
//    SLTErase(l1);
//    Print(l1);
//    ListNode* current = l1;
//    while (current != NULL) {
//        ListNode* next = current->next;
//        free(current);
//        current = next;
//    }

//typedef double SLdatatype; // 更改为double以便支持浮点数
//typedef struct Node {
//    SLdatatype x; // 系数
//    SLdatatype y; // 指数
//} Node;
//
//typedef struct SLNode {
//    Node data;
//    struct SLNode* next;
//} SLNode;
//
//SLNode* SLcreatNode(SLdatatype x, SLdatatype y) {
//    SLNode* newnode = malloc(sizeof(SLNode));
//    if (!newnode) {
//        perror("malloc fail!");
//        exit(1);
//    }
//    newnode->data.x = x;
//    newnode->data.y = y;
//    newnode->next = NULL;
//    return newnode;
//}
//
//void insertSorted(SLNode** pphead, SLdatatype x, SLdatatype y) {
//    SLNode* newNode = SLcreatNode(x, y);
//    SLNode* prev = NULL, * current = *pphead;
//
//    while (current != NULL && current->data.y > y) {
//        prev = current;
//        current = current->next;
//    }
//
//    if (prev == NULL) {
//        newNode->next = *pphead;
//        *pphead = newNode;
//    }
//    else {
//        prev->next = newNode;
//        newNode->next = current;
//    }
//}
//
//void Print_SL(SLNode* phead) {
//    SLNode* pcur = phead;
//    int count = 1;
//    while (pcur != NULL) {
//        printf("%.1f %.0f\n", pcur->data.x, pcur->data.y);
//        pcur = pcur->next;
//        count++;
//    }
//}
//
//void freeList(SLNode* phead) {
//    SLNode* temp;
//    while (phead != NULL) {
//        temp = phead;
//        phead = phead->next;
//        free(temp);
//    }
//}
//
//SLNode* merge_two_SL(SLNode* list1, SLNode* list2) {
//    if (list1 == NULL) return list2;
//    if (list2 == NULL) return list1;
//    SLNode* l1 = list1;
//    SLNode* l2 = list2;
//    SLNode head;
//    SLNode* tail = &head;
//    head.next = NULL;
//    while (l1 && l2) {
//        if (l1->data.y > l2->data.y) {
//            tail->next = l1;
//            tail = l1;
//            l1 = l1->next;
//        }
//        else if (l1->data.y < l2->data.y) {
//            tail->next = l2;
//            tail = l2;
//            l2 = l2->next;
//        }
//        else {
//            l1->data.x += l2->data.x;
//            if (l1->data.x != 0) {
//                tail->next = l1;
//                tail = l1;
//            }
//            SLNode* temp = l2->next;
//            free(l2);
//            l2 = temp;
//            l1 = l1->next;
//        }
//    }
//    if (l1) tail->next = l1;
//    if (l2) tail->next = l2;
//    return head.next;
//}
//
//void find(SLNode* head, int index) {
//    int count = 1;
//    while (head && count < index) {
//        if (count == index) {
//            printf("%.1f %.0f", head->data.x, head->data.y);
//            return;
//        }
//        count++;
//        head = head->next;
//    }
//    if (!head) {
//        printf("Index out of bounds.");
//    }
//}
//
//int main() {
//    SLNode* poly1 = NULL;
//    SLNode* poly2 = NULL;
//    SLNode* mergedPoly = NULL;
//    SLdatatype x, y;
//    int index;
//    char input[256];
//    fgets(input, sizeof(input), stdin);
//    sscanf(input, "%lf %lf", &x, &y);
//    while (!feof(stdin) && sscanf(input, "%lf %lf", &x, &y) == 2) {
//        insertSorted(&poly1, x, y);
//        fgets(input, sizeof(input), stdin);
//    }
//    fgets(input, sizeof(input), stdin);
//    sscanf(input, "%lf %lf", &x, &y);
//    while (!feof(stdin) && sscanf(input, "%lf %lf", &x, &y) == 2) {
//        insertSorted(&poly2, x, y);
//        fgets(input, sizeof(input), stdin);
//    }
//    scanf("%d", &index);
//    mergedPoly = merge_two_SL(poly1, poly2);
//    find(mergedPoly, index);
//    freeList(poly1);
//    freeList(poly2);
//    freeList(mergedPoly);
//    return 0;
//}
typedef struct student {
    char no[10];     
    char name[20];   
    int classno;     
    int score;       
} Student;
typedef struct Node {
    struct Node* next;       
    Student* student;       
} Node;
Node* head_no = NULL;       
Node* head_class = NULL;   
Node* head_score = NULL;   
Node* createNode(Student* student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->student = student;
    return newNode;
}
void addStudent(const char* no, const char* name, int classno, int score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->no, no);
    strcpy(newStudent->name, name);
    newStudent->classno = classno;
    newStudent->score = score;
    Node* newNodeNo = createNode(newStudent);
    if (head_no == NULL || strcmp(newStudent->no, head_no->student->no) < 0) {
        newNodeNo->next = head_no;
        head_no = newNodeNo;
    }
    else {
        Node* prev = head_no;
        while (prev->next != NULL && strcmp(prev->next->student->no, newStudent->no) < 0) {
            prev = prev->next;
        }
        newNodeNo->next = prev->next;
        prev->next = newNodeNo;
    }

    Node* newNodeClass = createNode(newStudent);
    if (head_class == NULL || newStudent->classno < head_class->student->classno) {
        newNodeClass->next = head_class;
        head_class = newNodeClass;
    }
    else {
        Node* prev = head_class;
        while (prev->next != NULL && prev->next->student->classno < newStudent->classno) {
            prev = prev->next;
        }
        newNodeClass->next = prev->next;
        prev->next = newNodeClass;
    }
    Node* newNodeScore = createNode(newStudent);
    if (head_score == NULL || newStudent->score > head_score->student->score) {
        newNodeScore->next = head_score;
        head_score = newNodeScore;
    }
    else {
        Node* prev = head_score;
        while (prev->next != NULL && prev->next->student->score > newStudent->score) {
            prev = prev->next;
        }
        newNodeScore->next = prev->next;
        prev->next = newNodeScore;
    }
}
void printStudents( Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%s,%s,%d,%d\n", cur->student->no, cur->student->name, cur->student->classno, cur->student->score);
        cur = cur->next;
    }
}
void clearStudents() {
    Node* cur, * tmp;
    cur = head_no;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp->student);
        free(tmp);
    }
    head_no = head_class = head_score = NULL;
}
int main() {
    int choice;
    char no[10], name[20];
    int classno, score;
    while(1) {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%s %s %d %d", no, name, &classno, &score);
            addStudent(no, name, classno, score);
            break;
        case 2:
            printStudents(head_no);
            break;
        case 3:
            break;
        case 4:
            printStudents(head_no);
            break;
        case 5:
            break;
        case 6:
            printStudents( head_class);
            break;
        case 7:
            break;
        case 8:
            printStudents(head_score);
            break;
        case 9:
            clearStudents();
            break;
        case 10:
            return 0;
        default:
            break;
        }
    }
    return 0;
}