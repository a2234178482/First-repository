#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//将该链表中数据域值最大的那个点移到链表的最后面

//思路：写一函数，循环构建节点，在写一个函数，创建新链表，然后遍历链表中所有元素，找出最大的值，移动至链表末尾
//typedef int DataType;
//
//typedef struct node{
//	DataType data;
//	struct node* link;
//}node;
//void SLTPrint(node* phead)
//{
//	node* pcur = phead;
//	while (pcur)
//	{
//		printf("%d ", pcur->data);
//		pcur = pcur->link;
//	}
//}
//node* SLTBuyNode(DataType x)
//{
//	node* newnode = (node*)malloc(sizeof(node));
//	if (newnode == NULL)
//	{
//		perror("malloc fail!");
//		exit(1);
//	}
//	newnode->data = x;
//	newnode->link = NULL;
//	return newnode;
//}
//void SLTistDesTroy(node** pphead)
//{
//	assert(pphead && *pphead);
//	node* pcur = *pphead;
//	while (pcur)
//	{
//		node* link = pcur->link;
//		free(pcur);
//		pcur = link;
//	}
//	*pphead = NULL;
//}
//void SLTMove(node** head)
//{
//	if (*head== NULL || (*head)->link == NULL)
//	{
//		return;
//	}
//	node* max_value = *head;
//	node* pre_max = NULL;
//	node* cur = *head;
//	node* pre = NULL;
//	while (cur != NULL)
//	{
//		if (cur->data >= max_value->data)
//		{
//			max_value = cur;
//			pre_max = pre;
//		}
//		pre = cur;
//		cur = cur->link;
//	}
//	if (max_value != pre)
//	{
//		if (max_value == *head)
//		{
//			*head = max_value->link;
//		}
//		else
//		{
//			pre_max->link = max_value->link;
//			pre->link = max_value;
//		}
//		max_value->link = NULL;
//	}
//}
//int main()
//{
//	node* head = NULL;
//	node* tail = NULL;
//	int number;
//	while (scanf("%d", &number) != EOF) {
//		node* newNode = SLTBuyNode(number);
//		if (head == NULL) {
//			head = newNode;
//			tail = newNode;
//		}
//		else {
//			tail->link = newNode;
//			tail = newNode;
//		}
//
//	}
//	SLTMove(&head);
//	SLTPrint(head);
//	SLTistDesTroy(&head);
//}

//
//int main()
//{
//	//int a = 1;
//	//int b = 2;
//
//	//int c = (a > b, a = b + 10, a, b = a + 1);//逗号表达式
//
//	//printf("%d\n", c);
//
//	//if (a = b + 1, c = a / 2, d > 0)
//	//{
//	//	//...
//	//}
//	
//	//伪代码
//	while (a = get_val(), count_val(a), a > 0)
//	{
//		//业务处理
//		//...
//
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 0 };
//	arr[5] = 6;//[] -  下标引用操作符
//	//[] 是操作符，它的操作数是：arr, 5
//	//3 + 5;
//	//
//
//	return 0;
//}

//void test()
//{
//	printf("hehe\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
////函数在调用的时候，函数名后边的括号就是函数调用操作符
////() - 操作数是：函数名，参数
////函数调用操作符，最少有1个操作数 - 函数名
////
//int main()
//{
//	int c = Add(2, 3);
//	test();
//	printf("hehe");
//	printf("%d", 100);
//
//	return 0;
//}
//

//声明一个学生类型
//学生：名字，性别，年龄，学号
//     名字 - 字符串 - 字符数组中
//     性别 - 字符串 - 字符数组
//     年龄 - 整数
//     学号 - 字符串 - 字符数组

//struct Student
//{
//	//成员
//	char name[20];
//	char sex[12];
//	int age;
//	char id[16];
//} s5,s6,s7;//s5,s6,s7都是结构体变量（全局）
//
//
////全局变量
//struct Student s4;
//
//int main()
//{
//	//局部变量
//	struct Student s1;
//	struct Student s2;
//	struct Student s3;
//
//	return 0;
//}

//
//struct Point
//{
//	int x;
//	int y;
//}p3 = { 0,0 }, p4 = {4, 1};
//
//struct Point p2 = {6, 8};
//
//struct Student
//{
//	//成员
//	char name[20];
//	char sex[12];
//	int age;
//	char id[16];
//};
//
//struct Node
//{
//	int data;
//	struct Point p;
//	struct Node* next;
//};
//
//int main()
//{
//	struct Point p1 = {4, 5};
//	struct Student s1 = { "张三", "男", 18, "2024080101" };
//	struct Student s2 = {.age=20, .id="2024090203", .name="lisi", .sex="nv"};
//
//	struct Node n1 = { 200, {20, 30} , NULL};
//
//	scanf("%d", &(s1.age));//直接访问成员 .
//	printf("%s %s %d %s\n", s1.name, s1.sex, s1.age, s1.id);
//	//结构体变量.结构体成员
//	return 0;
//}

//截断
//char倒是是signed char?还是unsiged char？标准是没有规定的，取决于你使用的编译器
//在当前使用VS上，char就是signed char
////
//int main()
//{
//	char a = 5;
//	//5
//	//00000000000000000000000000000101
//	//00000101 - a
//	//
//	char b = 125;
//	//00000000000000000000000001111101
//	//01111101 - b
//	//
//	char c = a + b;
//	//00000000000000000000000000000101 - a
//	//00000000000000000000000001111101 - b
//	//00000000000000000000000010000010
//	//10000010 - c
//	//a和b都是char类型，长度是小于int类型的长度的
//	//在计算的时候，默认就会发生整型提升
//	//
//	printf("%d\n", c);//?
//	//11111111111111111111111110000010 - 补码
//	//10000000000000000000000001111101
//	//10000000000000000000000001111110 --> -126
//	//%d - 按照有符号整数的形式打印
//	//
//	return 0;
//}


#include <stdio.h>

//int fun()
//{
//    static int count = 1;
//    return ++count;
//}
//int main()
//{
//    int answer;
//    answer = fun() - fun() * fun();
//    printf("%d\n", answer);//输出多少？
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("%d\n", ret);
//    printf("%d\n", i);
//    return 0;
//}
//
//


//
//int main()
//{
//	int a = 25;//变量创建的本质是啥呢？是在内存中开辟一块空间
//	//&a;//& - 取地址操作符
//	//%p -- 是专门用来打印地址的 -- 其实是以16进制的形式进行打印的
//	//
//	printf("%p\n", &a);
//	printf("%x\n", &a);
//
//	return 0;
//}

int main()
{
	int a = 20;
	printf("%p\n", &a);
	int* p = &a; //地址 --指针
	//p是指针变量 --存放指针（地址）的变量
	//指针变量是用来存放地址的
	return 0;
}

int main()
{
	char ch = 'w';
	char* pc = &ch;
	return 0;
}

int main()
{
	int a = 20;
	int* p = &a;
	*p = 20;

}

int main()
{
	int a = 20;
	int* p = &a;
	//*p = 100 解引用操作，（间接访问操作）*p等价于a
	//* ---解引用操作符
	a = 100;
	printf("%d\n", a);
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	printf("%zd\n", sizeof(pa));
	printf("%zd\n", sizeof(int*));
	printf("%p\n", pa);
	return 0;
}

int main()
{
	char ch = 'w';
	char* pc = &ch;
	printf("%zd\n", sizeof(pc));
	printf("%zd\n", sizeof(char*));
	printf("%p\n",pc);
	return 0;
}

int main()
{
	int a = 0x11223344;
	char* pa = &a;
	*pa = 0;
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	char* pc = (char*)&a;
	printf("pa   = %p\n", pa);
	printf("pa+1 = %p\n", pa + 1);
	printf("pc   = %p\n", pc);
	printf("pc+1 = %p\n", pc + 1);
	return 0;
}

int main()
{
	int* pi;
	char* pc;
	double* pd;
	void* pv;
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	char* pc = &a;
	void* pv = &a;
	double d = 3.14;
	void* pv = &d;
	*pv; --error
	pv + 1  --error
	return 0;
}

int main()
{
	const int n = 10;
	//const修饰了n之后，n就不能被修改了，但是n还是变量
	//n是常变量
	n = 10;
	printf("%d\n", n);
	return 0;
}

int main()
{
	int arr[10] = { 0 };
	const int n = 10;//cpp中const修饰的n就是常量
	int arr[n] = { 0 };
	return 0;
}

int main()
{
	const int n = 10;
	// n = 0; --error
	int* p = &n;
	*p = 20;
	printf("%d\n", n);
	return 0;
}

//const修饰指针变量有两种情况
//1.const放在*左边，限制的是*p，意思是不能通过p来改变p指向的对象的内容，但是p本身是可变的
//2.const放在*右边，限制的是p，意思是不能修改p本身的值，但是p指向的内容是可变的

int main()
{
	const int n = 10;
	int m = 100;
	const int* const p = &p;
	//*p = 20; --ok
	//p = &m; -- error
	printf("%d", n);
	return 0;
}

int main()
{
	const int n = 10;
	int m = 100;
	const int* const p = &p;
	//*p = 20; --error
	//p = &m;  --ok
	printf("%d", n);
	return 0;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[0];
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[0];
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p+i));
	}
	return 0;
}


//指针-指针的前提是两个指针指向的是同一块空间
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);//指针-指针
//	printf("%d\n", &arr[0] - &arr[9]);//指针-指针
//	//指针-指针的绝对值是指针和指针之间的元素个数
//	char ch[6] = {0};
//	printf("%d\n", &arr[9] - &ch[4]);//err
//	return 0;
//}
//

//strlen --求字符串长度的库函数
#include <string.h>

int my_strlen(char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}

int my_strlen(char* p)
{
	char* p1 = p;
	while (*p != '\0')
	{
		p++;
	}
	return p - p1;
}

int main()
{
    int arr[10] = { 0 };
    int* p = &arr[0];
    int i = 0;
    for (i = 0; i <= 11; i++)
    {
        //当指针指向的范围超出数组arr的范围时，p就是野指针
        *(p++) = i;
    }
    return 0;
}

