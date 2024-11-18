#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[256];
    int numbers[100];
    int count = 0;
    int num = 0;
    int sign = 1;
    int is_number = 0;
    fgets(input, sizeof(input), stdin);
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
            is_number = 1;
        }
        else if (input[i] == '-' && (i == 0 || !isdigit(input[i - 1]))) {
            sign = -1;
            is_number = 0; 
        }
        else if (is_number) {
            numbers[count++] = num * sign;
            num = 0;
            sign = 1; 
            is_number = 0;
        }
    }
    if (is_number) {
        numbers[count++] = num * sign;
    }
    for (int i = 0; i < count; ++i) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
//int main() {
//    char input[1000], output[2000] = ""; 
//    int i, j = 0, n;
//    scanf("%[^\n]", input); 
//    getchar();
//    for (i = 0; input[i] != '#' && i < strlen(input); i++) {
//        if (isdigit(input[i])) { 
//            n = input[i] - '0'; 
//            if (n <= 0 || input[i + 1] == '#') { 
//                output[j++] = input[i];
//                if (input[i + 1] != '#') output[j++] = '_';
//            }
//            else { 
//                for (int k = 0; k <= n; k++) {
//                    output[j++] = input[i + 1];
//                }
//                output[j++] = '_';
//                i++; 
//            }
//        }
//        else { 
//            output[j++] = input[i];
//            if (input[i + 1] != '#' && input[i + 1] != '\0') output[j++] = '_';
//        }
//    }
//    if (i < strlen(input) && input[i] != '#') {
//        output[j++] = input[i]; 
//    }
//    printf("%s\n", output);
//    return 0;
//} 