#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//int  xuanzhuan_char(char *a, char* b) {
//	int sz1 = strlen(a);
//	int sz2 = strlen(b);
//	if (sz1 != sz2) {
//		return 0;
//	}
//	char* concat = (char*)malloc((2 * sz1 + 1) * sizeof(char));
//	strcpy(concat, a);
//	strcat(concat, a);
//	int result = strstr(concat, b) != NULL;
//	free(concat);
//	return result;
//}
//
//int main() {
//	char a[] = "abcde";
//	char b[] = "badsd";
//	int ret = xuanzhuan_char(a, b);
//	printf("%d", ret);
//	return 0;
//}

int find_number(int arr[4][4], int r, int c, int target) {
	int row = 0;
	int col = c - 1;
	while (row < r && col>0) {
		if (arr[row][col] == target) {
			return 1;
		}
		else if (arr[row][col] > target) {
			col--;
		}
		else {
			row++;
		}
	}
	return 0;
}