#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//typedef int SLDatatype;
//typedef struct SList {
//	SLDatatype* arr;
//	int capacity;
//	int size;
//}SL;
//void SLPushFront(SL* ps, SLDatatype x)
//{
//	assert(ps);
//	SLCheckCapacity(ps);
//	for (int i = ps->size; i > 0; i--)
//	{
//		ps->arr[i] = ps->arr[i - 1];
//	}
//	ps->arr[0] = x;
//	ps->size++;
//}
//void Delete_num(SL* L1,SL* L2) {
//	for (int i = 0; i < L1->size; i++) {
//		if (L1->arr[i] % 2 == 0) {
//			SLPushFront(L2,L1->arr[i]);
//		}
//	}
//}

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct Student {
    int no;                 // 学号  
    char name[50];         // 姓名  
    int classno;           // 班级号  
    float score;           // 成绩  
    struct Student* pno;   // 学号指针  
    struct Student* pclass; // 班级号指针  
    struct Student* pscore; // 成绩指针  
} Student;

Student* head = NULL; // 头指针  

// 添加学生记录  
void add_student(int no, const char* name, int classno, float score) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    new_student->no = no;
    strcpy(new_student->name, name);
    new_student->classno = classno;
    new_student->score = score;
    new_student->pno = NULL;
    new_student->pclass = NULL;
    new_student->pscore = NULL;

    new_student->pno = head;
    head = new_student; // 插入到链表头部  
}

// 输出全部学生记录  
void display_students() {
    Student* current = head;
    if (!current) {
        printf("没有学生记录。\n");
        return;
    }
    while (current) {
        printf("学号: %d, 姓名: %s, 班级号: %d, 成绩: %.2f\n", current->no, current->name, current->classno, current->score);
        current = current->pno;
    }
}

// 按学号排序  
void sort_by_no() {
    // 这里是插入排序  
    if (!head) return;

    Student* sorted = NULL;
    Student* current = head;

    while (current) {
        Student* next = current->pno;
        if (!sorted || sorted->no >= current->no) {
            current->pno = sorted;
            sorted = current;
        }
        else {
            Student* temp = sorted;
            while (temp->pno && temp->pno->no < current->no)
                temp = temp->pno;
            current->pno = temp->pno;
            temp->pno = current;
        }
        current = next;
    }
    head = sorted;
}

// 按班级号排序  
void sort_by_classno() {
    // 处理方法同上  
    if (!head) return;

    Student* sorted = NULL;
    Student* current = head;

    while (current) {
        Student* next = current->pno;
        if (!sorted || sorted->classno >= current->classno) {
            current->pclass = sorted;
            sorted = current;
        }
        else {
            Student* temp = sorted;
            while (temp->pclass && temp->pclass->classno < current->classno)
                temp = temp->pclass;
            current->pclass = temp->pclass;
            temp->pclass = current;
        }
        current = next;
    }
    head = sorted;
}

// 按成绩排序  
void sort_by_score() {
    // 处理方法同上  
    if (!head) return;

    Student* sorted = NULL;
    Student* current = head;

    while (current) {
        Student* next = current->pno;
        if (!sorted || sorted->score <= current->score) {
            current->pscore = sorted;
            sorted = current;
        }
        else {
            Student* temp = sorted;
            while (temp->pscore && temp->pscore->score > current->score)
                temp = temp->pscore;
            current->pscore = temp->pscore;
            temp->pscore = current;
        }
        current = next;
    }
    head = sorted;
}

// 清空所有记录  
void clear_all() {
    Student* current = head;
    while (current) {
        Student* next = current->pno;
        free(current);
        current = next;
    }
    head = NULL;
    printf("已清空所有记录。\n");
}

// 主程序  
int main() {
    int choice;
    while (1) {
        printf("\n1. 添加学生记录\n");
        printf("2. 输出全部学生记录\n");
        printf("3. 按学号排序\n");
        printf("4. 按班级号排序\n");
        printf("5. 按成绩排序\n");
        printf("6. 清空所有记录\n");
        printf("7. 退出程序\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int no, classno;
            char name[50];
            float score;
            printf("输入学号: ");
            scanf("%d", &no);
            printf("输入姓名: ");
            scanf("%s", name);
            printf("输入班级号: ");
            scanf("%d", &classno);
            printf("输入成绩: ");
            scanf("%f", &score);
            add_student(no, name, classno, score);
        }
        else if (choice == 2) {
            display_students();
        }
        else if (choice == 3) {
            sort_by_no();
            printf("已按学号排序。\n");
        }
        else if (choice == 4) {
            sort_by_classno();
            printf("已按班级号排序。\n");
        }
        else if (choice == 5) {
            sort_by_score();
            printf("已按成绩排序。\n");
        }
        else if (choice == 6) {
            clear_all();
        }
        else if (choice == 7) {
            clear_all();
            printf("退出程序\n");
            break;
        }
        else {
            printf("无效选择，请重试。\n");
        }
    }
    return 0;
}
