#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int strrindex(char* s, char* t) {
    int index = -1;
    char* pos = s;
    while ((pos = strstr(pos, t)) != NULL) {
        index = pos - s;
        pos++;
    }
    return index;
}

int main() {
    char s[1000], t[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';
    int ret = strrindex(s, t);
    printf("%d\n", ret);
    return 0;
}
