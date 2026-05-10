#define CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class ListReverse
{
	struct Listnode
	{
		struct Listnode* next;
		int val;
		Listnode(int v) :val(v), next(nullptr) {};
		Listnode(int v, Listnode* n) :val(v), next(n) {};
	};
	struct Doublelist
	{
		struct Doublelist* prev;
		struct Doublelist* next;
		int value;
		Doublelist(int v) : value(v), prev(nullptr), next(nullptr) {};
	};
	static Listnode* listReverse(Listnode* listnode)
	{
		Listnode* prev = nullptr;
		Listnode* next = nullptr;
		while (listnode != nullptr)
		{
			next = listnode->next;
			listnode->next = prev;
			prev = listnode;
			listnode = next;
		}
		return prev;
	}
	static Doublelist* doublelistReverse(Doublelist* head)
	{
		Doublelist* prev = nullptr;
		Doublelist* next = nullptr;
		while (head != nullptr)
		{
			next = head->next;
			head->next = prev;
			head->prev = next;
			prev = head;
			head = next;
		}
		return prev;
	}
	static Listnode* addtwoList(Listnode* h1, Listnode* h2)
	{
		Listnode* dump = new Listnode(0);
		Listnode* cur = dump;
		int carry = 0;
		while (h1 || h2)
		{
			int val1 = h1 ? h1->val : 0;
			int val2 = h2 ? h2->val : 0;
			int sum = val1 + val2;
			int digit = sum % 10;
			carry = sum / 10;
			cur->next = new Listnode(digit);
			cur = cur->next;
			if (h1) { h1 = h1->next; }
			if (h2) { h2 = h2->next; }
		}
		if (carry > 0)
		{
			cur->next = new Listnode(carry);
		}
		Listnode* result = dump->next;
		free(dump);
		return result;
	}
};