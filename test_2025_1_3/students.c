#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//int main() {
//    int student_id, age;
//    char name[50];
//    float scores[6];
//    int total_points = 0;
//    int credits[6] = { 4, 3, 4, 3, 3, 3 };
//    scanf("%d %s %d", &student_id, name, &age);
//    for (int i = 0; i < 6; i++) {
//        scanf("%f", &scores[i]);
//        if (scores[i] < 60) {
//            total_points += 0;
//        }
//        else {
//            total_points += credits[i];
//        }
//    }
//    printf("\n%d %s %d\n", student_id, name, age);
//    printf("%d\n", total_points);
//
//    return 0;
//}
//
//typedef struct {
//    char name[11];
//    char phone[11];
//} User;
//
//int cmp(const void* a, const void* b) {
//    return strcmp(((User*)a)->name, ((User*)b)->name);
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n > 50) {
//        return 1;
//    }
//    User users[50];
//    for (int i = 0; i < n; i++) {
//        scanf("%s %s", users[i].name, users[i].phone);
//        users[i].name[10] = '\0';
//        users[i].phone[10] = '\0';
//    }
//    qsort(users, n, sizeof(User), cmp);
//    for (int i = 0; i < n; i++) {
//        printf("%12.10s%12.10s\n", users[i].name, users[i].phone);
//    }
//    return 0;
//}
//
//struct Date {
//    int year;
//    int month;
//    int day;
//};
//
//int isLeapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//
//int daysInMonth(int month, int year) {
//    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    if (month == 2 && isLeapYear(year)) {
//        return 29;
//    }
//    return days[month - 1];
//}
//
//int daysSinceEpoch(struct Date date) {
//    int days = 0;
//    for (int y = 1; y < date.year; y++) {
//        days += isLeapYear(y) ? 366 : 365;
//    }
//    for (int m = 1; m < date.month; m++) {
//        days += daysInMonth(m, date.year);
//    }
//    days += date.day;
//    return days;
//}
//
//int differenceInDays(struct Date date1, struct Date date2) {
//    return daysSinceEpoch(date2) - daysSinceEpoch(date1);
//}
//
//int main() {
//    struct Date date1, date2;
//    scanf("%d %d %d", &date1.year, &date1.month, &date1.day);
//    scanf("%d %d %d", &date2.year, &date2.month, &date2.day);
//    int diff = differenceInDays(date1, date2);
//    printf("%d\n", diff);
//    return 0;
//}
//#define MAX_CHAR 256
//typedef struct {
//    char ch;
//    int count;
//    int order;
//} CharInfo;
//
//int cmp(const void* a, const void* b) {
//    CharInfo* ca = (CharInfo*)a;
//    CharInfo* cb = (CharInfo*)b;
//    if (ca->count == cb->count) {
//        return ca->order - cb->order;
//    }
//    return cb->count - ca->count;
//}
//
//int main() {
//    char input[1000];
//    fgets(input, sizeof(input), stdin);
//    int length = strlen(input);
//    if (length > 0 && input[length - 1] == '\n') {
//        input[length - 1] = '\0';
//    }
//    CharInfo chars[MAX_CHAR] = { 0 };
//    for (int i = 0; i < MAX_CHAR; i++) {
//        chars[i].ch = i;
//        chars[i].order = -1;
//    }
//    int order = 0;
//    for (int i = 0; i < length; i++) {
//        unsigned char ch = input[i];
//        if (chars[ch].order == -1) {
//            chars[ch].order = order++;
//        }
//        chars[ch].count++;
//    }
//    qsort(chars, MAX_CHAR, sizeof(CharInfo), cmp);
//    int count = 0;
//    for (int i = 0; i < MAX_CHAR; i++) {
//        if (chars[i].count > 0) {
//            if (count % 4 == 0 && count > 0) {
//                printf("\n");
//            }
//            if (chars[i].ch == ' ') {
//                printf(" -%d", chars[i].count);
//            }
//            else {
//                printf("%c-%d", chars[i].ch, chars[i].count);
//            }
//            if (++count % 4 != 0) {
//                printf(" ");
//            }
//        }
//    }
//    if (count % 4 != 0) {
//        printf("\n");
//    }
//    return 0;
//}
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LEN 6

typedef struct {
    int id;
    char name[NAME_LEN + 1];
    int age;
} Student;

int cmpByName(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int cmpByAgeAndName(const void* a, const void* b) {
    Student* sa = (Student*)a;
    Student* sb = (Student*)b;
    if (sa->age == sb->age) {
        return strcmp(sa->name, sb->name);
    }
    return sa->age - sb->age;
}

void print(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d %6s %3d\n", students[i].id, students[i].name, students[i].age);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n > MAX_STUDENTS) {
        return 1;
    }
    Student students[MAX_STUDENTS];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
        students[i].name[NAME_LEN] = '\0';
    }
    qsort(students, n, sizeof(Student), cmpByName);
    print(students, n);
    printf("\n");
    qsort(students, n, sizeof(Student), cmpByAgeAndName);
    print(students, n);
    return 0;
}





















