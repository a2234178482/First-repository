#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//
//int count(char* str, char ch) {
//    int count = 0;
//    while (*str != '\0') {
//        if (*str == ch) {
//            count++;
//        }
//        str++;
//    }
//    return count;
//}
//
//int main() {
//    char str[100];
//    char ch;
//    fgets(str, sizeof(str), stdin);
//    scanf("%c", &ch);
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] == '\n') {
//            str[i] = '\0';
//            break;
//        }
//    }
//    int result = count(str, ch);
//    printf("%d\n",result);
//    return 0;
//}
//void stringNx(char a[]) {
//    int length = strlen(a);
//    for (int i = 0; i < length / 2; i++) {
//        char temp = a[i];
//        a[i] = a[length - i - 1];
//        a[length - i - 1] = temp;
//    }
//}
//int main() {
//    char str[100];
//    fgets(str, sizeof(str), stdin);
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] == '\n') {
//            str[i] = '\0';
//            break;
//        }
//    }
//    stringNx(str);
//    printf("%s\n", str);
//    return 0;
//}
void capitalizeWords(char str[]) {
    int i = 0;
    int Word = 1; 
    while (str[i] != '\0') {
        if (isspace(str[i])) {
            Word = 1;
        }
        else if (Word) {
            str[i] = toupper(str[i]);
            Word = 0; 
        }
        i++;
    }
}

int main() {
    char ch[100];
    fgets(ch, sizeof(ch), stdin);
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == '\n') {
            ch[i] = '\0';
            break;
        }
    }
    capitalizeWords(ch);
    printf("%s\n", ch);
    return 0;
}



