#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
//1.链表成环问题
bool hascycle(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

//顺序表经典算法
//1.移除元素

//思路1 创建新的数组，遍历原数组，将不为val的元素放到新数组中
//思路2 快慢指针 
int remove_elem(int* nums, int numsize, int val)
{
	//先创建两个变量
	int src, dst;
	src = dst = 0;
	while (src < numsize)
	{
		if (nums[src] == val)
		{
			src++;
		}
		else
		{
			//赋值，两指针++
			nums[dst] = nums[src];
			dst++;
			src++;
		}
	}
	//此时dst的值刚好就是数组的新长度  
	return dst;
}

//有序线性表的合并
void merge(int* nums1, int num1size, int m, int* nums2, int nums2size, int n)
{
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = m + n - 1;
	while (l1 < 0 && l2 < 0)
	{
		if (nums1[l1] < nums2[l2])
		{
			nums1[l3--] = nums2[l2--];
		}else{
			nums1[l3--] = nums1[l1--];
		}
	} 
	while(l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}

}

//移除链表元素
typedef struct ListNode ListNode;
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* remove_elem(struct ListNode* head, int val)
{
	ListNode* newhead, * newtail;
	newhead = newtail = NULL;
	ListNode* pcur = head;
	while (pcur)
	{
		if (newhead == NULL)
		{
			newhead = newtail = pcur;
		}
		else {
			newtail->next = pcur;
			newtail = newtail->next;
		}
		pcur = pcur->next;
	}
	if(newtail)
		newtail->next = NULL;
	return newhead;
}

//反转链表
typedef struct ListNode ListNode;
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}

	ListNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//链表的中间节点
typedef struct ListNode ListNode;
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next; 
	}
	return slow;
}