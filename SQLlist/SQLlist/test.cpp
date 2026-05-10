#define CRT_SECURE_NO_WARNINGS 1
#include <iostream>
typedef int Eldatype;
typedef struct SQLlist
{
	Eldatype* nums;
	int size, length;
}Sqlist;

void Initlist(Sqlist& list)
{
	list.nums = NULL;
	list.size = 0;
	list.length = 0;
}
void Increasecapacity(Sqlist& list,int n)
{
	Eldatype* jiude = list.nums;
	list.nums = (Eldatype*)malloc((n + list.length) * sizeof(Eldatype));
	for (int i = 0; i < list.length; i++)
	{
		list.nums[i] = jiude[i];
	}
	list.size = n + list.size;
}
void IncreaseElem(Sqlist& list, int n, int e)
{
	//在第n个元素后面插入值等于e
	for (int i = list.size; i > n; i--)
	{
		list.nums[i] = list.nums[i -1];
	}
	list.nums[n] = e;
	list.length++;
}
void Delete(Sqlist& list, int n)
{
	//删除第n个元素
	list.nums[n] = 0;
	for (int i = list.size-1; i > n; i--)
	{
		list.nums[i] = list.nums[i - 1];
	}
	list.length--;
}
int Check(Sqlist& list, int e)
{
	//查找元素值等于e的下表
	for (int i = 0; i < list.size; i++)
	{
		if (list.nums[i] = e)
			return i;
	}
}