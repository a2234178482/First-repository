#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//bool search(int** juzhen, int* colsize, int target) {
//	if (juzhen == 0 || colsize[0] == 0) {
//		return false;
//	}
//	int rows = juzhen;
//	int cols = colsize[0];
//	int row = 0;
//	int col = -1;
//	while (row < rows && col >= 0) {
//		int current = juzhen[row][col];
//		if (current == target) {
//			return true;
//		}
//		else if (current > target) {
//			col--;
//		}
//		else {
//			row++;
//		}
//
//	}
//	return false;
//}
//
//int main() {
//	int matrixData[4][4] = {  
//		{ 1, 3, 5, 7 },
//		{ 10,11,16,20 },
//		{ 23,30,34,60 },
//		{ 60,61,62,63 }
//	};
//	int* matrix[4];
//	for (int i = 0; i < 4; i++) {
//		matrix[i] = matrixData[i];
//	}
//	int matrixSize = 4; 
//	int matrixColSize[4] = {4,4,4,4};  
//	int target =3;  
//	if (searchMatrix(matrix, matrixSize, matrixColSize, target)) {
//		printf("找到了 %d\n", target);
//	}
//	else {
//		printf("没有找到 %d\n", target);
//	}
//	target = 13;
//	if (searchMatrix(matrix, matrixSize, matrixColSize, target)) {
//		printf("找到了 %d\n", target);
//	}
//	else {
//		printf("没有找到 %d\n", target);
//	}
//	return 0;
//}


//int main() {
//	char* suspects[] = {"A", "B", "C", "D"};  
//	int i;
//
//	for (i =0; i <4; i++) {  
//	int is_suspect =1; 
//	int true_count =0;
//	for (int j =0; j <4; j++) {  
//	if (j == i) {  
//	is_suspect = 1; 
//	continue;
//	}  
//	 if (j ==0) { 
//		 if (is_suspect ==0) { 
//		 true_count++;  
//}
// }
// else if (j == 1) {
//	if (is_suspect ==0) { 
//	 if (i == 2) {
//		 true_count++; 
//	 }  
//	 }
//	 else {
//		 true_count++; }  
//	 }
// else if (j == 2) {  
//		 if (is_suspect ==0) {   
//	 if (i == 3) {
//		 true_count++;  }  
//	 }
//	 else {
//		 true_count++;  }  
//	 }
// else if (j == 3) {  if (is_suspect ==0) {   
//	 if (i == 2) {
//		 true_count++; }  
//	 }
//	 else {
//		 true_count++;  }  
//	 }
// }
//
// if (true_count ==3) {  
// printf("凶手是：%s\n", suspects[i]);
// return0;  }  
// }
//
// printf("未能找到凶手\n");
// return0;
//}


void printPascalsTriangle(int rows) {
	int triangle[rows][rows];
	for (int i =0; i < rows; i++) {  
	for (int j = 0; j <= i; j++) {
		 if (j ==0 || j == i) {  
		triangle[i][j] = 1;
	}
 else {
	  triangle[i][j] = triangle[i -1][j -1] + triangle[i -1][j];  
}
}
}

	for (int i =0; i < rows; i++) {  
	for (int j =0; j < rows - i -1; j++) {  
	printf(" ");
}
	 for (int j =0; j <= i; j++) {  
	 printf("%d ", triangle[i][j]);
}
	 printf("\n");  }  
}

int main() {
	int rows;
	printf("请输入杨辉三角的行数: ");
	scanf("%d", &rows);
	printPascalsTriangle(rows);
	return 0;
}