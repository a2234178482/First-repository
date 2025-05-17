#include "BinarySearchTree.h"
//int main()
//{
//	key::BSTree<int> t;
//	int a[] = { 8,3,1,10,1,6,4,7,14,13 };
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.InOrder();
//	for (auto e : a)
//	{
//		t.Erase(e);
//		t.InOrder();
//	}
//}
int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉" };
	key_value::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		auto ret = countTree.find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
	key_value::BSTree<string, int> copy = countTree;
	copy.InOrder();
	return 0;
}