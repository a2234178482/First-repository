//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>  
//#include <stdio.h>
//typedef struct Node {
//	float coefficient; // 系数 int exponent; // 指数 struct Node* next; // 指向下一个节点的指针} Node;  
//};
//typedef struct {
//		Node* head; // 链表头指针} Polynomial;  
//
//		// 创建一个新节点Node* createNode(float coefficient, int exponent) {  
//		Node* newNode = (Node*)malloc(sizeof(Node));
//		newNode->coefficient = coefficient;
//		newNode->exponent = exponent;
//		newNode->next = NULL;
//		return newNode;
//	}
//
//	// 初始化一个多项式void initPolynomial(Polynomial* poly) {  
//	poly->head = NULL;
//}
//
//// 添加一个项到多项式中void addTerm(Polynomial* poly, float coefficient, int exponent) {  
//Node* newNode = createNode(coefficient, exponent);
//if (poly->head == NULL || poly->head->exponent < exponent) {
//	newNode->next = poly->head;
//	poly->head = newNode;
//	return;
//}
//
//Node* current = poly->head;
//while (current->next != NULL && current->next->exponent > exponent) {
//	current = current->next;
//}
//
//// 如果指数相同，则合并 if (current->exponent == exponent) {  
//current->coefficient += coefficient;
//free(newNode); //释放多余的节点 } else {  
//newNode->next = current->next;
//current->next = newNode;
// }
//}
//
//// 输出多项式void printPolynomial(Polynomial* poly) {  
//Node* current = poly->head;
//while (current != NULL) {
//	printf("%.1f %d ", current->coefficient, current->exponent);
//	current = current->next;
//}
//printf("\n");
//}
//
//// 将两个多项式相加void addPolynomials(Polynomial* A, Polynomial* B) {  
//Node* current = B->head;
//while (current != NULL) {
//	addTerm(A, current->coefficient, current->exponent);
//	current = current->next;
//}
//}
//
//// 获取特定索引的项int getTerm(Polynomial* poly, int index, float* coefficient, int* exponent) {  
//Node* current = poly->head;
//int count = 0;
//while (current != NULL && count < index) {
//	current = current->next;
//	count++;
//}
//if (current != NULL) {
//	*coefficient = current->coefficient;
//	*exponent = current->exponent;
//	return1; // 成功 }  
//	return0; //失败}  
//
//	int main() {
//		Polynomial A, B;
//		initPolynomial(&A);
//		initPolynomial(&B);
//
//		// 输入多项式A float coeff;  
//		int exp;
//		while (scanf("%f %d", &coeff, &exp) == 2) {
//			addTerm(&A, coeff, exp);
//			if (getchar() == '\n') break; // 输入结束 }  
//
//			// 输入多项式B while (scanf("%f %d", &coeff, &exp) ==2) {  
//			addTerm(&B, coeff, exp);
//			if (getchar() == '\n') break; // 输入结束 }  
//
//			// 相加多项式A和B addPolynomials(&A, &B);  
//
//			// 输出相加后的多项式 printPolynomial(&A);  
//
//			// 获取用户要输出的项（索引，从0开始）  
//			int index;
//			scanf("%d", &index);
//			float result_coeff;
//			int result_exp;
//			if (getTerm(&A, index, &result_coeff, &result_exp)) {
//				printf("%.1f %d\n", result_coeff, result_exp);
//			}
//			else {
//				printf("输入的索引超出范围\n");
//			}
//
//			return0;
//		}


//#define MAX_WINDOWS10#define MAX_CLICKS10typedef struct {  
//int x1, y1, x2, y2; // 窗口的坐标} Window;  
//
//int main() {
//	int N, M; // 窗口数量和点击次数 Window windows[MAX_WINDOWS];  
//	//读取N和M scanf("%d %d", &N, &M);  
//	//读取N个窗口的位置 for (int i =0; i < N; i++) {  
//	scanf("%d %d %d %d", &windows[i].x1, &windows[i].y1, &windows[i].x2, &windows[i].y2);
//}
//
////读取M次点击 for (int j =0; j < M; j++) {  
//int clickX, clickY;
//scanf("%d %d", &clickX, &clickY);
//int selectedWindow = -1; // 标记被选择的窗口 // 从上到下的顺序检查窗口 for (int i = N -1; i >=0; i--) {  
//if (clickX >= windows[i].x1 && clickX <= windows[i].x2 && clickY >= windows[i].y1 && clickY <= windows[i].y2) {
//	// 找到了一个窗口 selectedWindow = i;  
//	break; // 找到顶层窗口，停止检查 }  
//}
//
//// 如果一个窗口被选中 if (selectedWindow != -1) {  
//printf("%d\n", selectedWindow + 1); // 输出窗口编号（1-based）  
//// 将选中的窗口移动到顶部 Window temp = windows[selectedWindow];  
//for (int k = selectedWindow; k < N - 1; k++) {
//	windows[k] = windows[k + 1]; // 移动窗口 }  
//	windows[N - 1] = temp; // 将选中的窗口放到最上层 } else {  
//	printf("IGNORED\n"); // 没有选中任何窗口 }  
//}
//
//return0;
//}
//#include <stdlib.h>  
//
//#define MAX_LENGTH100typedef struct {  
//int data[MAX_LENGTH];
//int top;
//} Stack;
//
//// 初始化堆栈void initStack(Stack* stack) {  
//stack->top = -1;
//}
//
//// 判断堆栈是否为空int isEmpty(Stack* stack) {  
//return stack->top == -1;
//}
//
//// 入栈操作void push(Stack* stack, int value) {  
//stack->data[++stack->top] = value;
//}
//
//// 出栈操作int pop(Stack* stack) {  
//if (!isEmpty(stack)) {
//	return stack->data[stack->top--];
//}
//return -1; // 不会返回到这个地方}  
//
//int main() {
//	int n;
//	int input[MAX_LENGTH];
//	int output[MAX_LENGTH];
//
//	//读取输入序列的长度 scanf("%d", &n);  
//
//	//读取输入序列 for (int i =0; i < n; i++) {  
//	scanf("%d", &input[i]);
//}
//
////读取输出序列 for (int i =0; i < n; i++) {  
//scanf("%d", &output[i]);
// }
//
// Stack stack;
// initStack(&stack);
//
// int inputIndex = 0;
// int outputIndex = 0;
// int popCount = 0;
//
// // 模拟堆栈操作 while (outputIndex < n) {  
// // 入栈操作 while (inputIndex < n && (isEmpty(&stack) || stack.data[stack.top] != output[outputIndex])) {  
// push(&stack, input[inputIndex++]);
// popCount++; // 每次入栈++出栈 }  
//
// // 检查栈顶元素 if (!isEmpty(&stack) && stack.data[stack.top] == output[outputIndex]) {  
// pop(&stack); // 出栈 outputIndex++;  
// }
// else {
//	 break; // 如果出栈元素不匹配，停止 }  
// }
//
// // 判断是否完全匹配 if (outputIndex == n) {  
// printf("%d\n", popCount);
// }
// else {
//	 printf("0\n");
// }
//
// return0;
//}