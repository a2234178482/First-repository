#define _CRT_SECURE_NO_WARNINGS 1

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
typedef int BTDataType;

BTNode* NodeCreate(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n)
	{
		return NULL;
	}
	if (a[*pi] == '#' || a[*pi] == '\0')
	{
		return NULL;
	}
	BTNode* newnode = NodeCreate(a[*pi]);
	(*pi)++;
	newnode->_left = BinaryTreeCreate(a, n, pi);
	(*pi)++;
	newnode->_right = BinaryTreeCreate(a, n, pi);
	return newnode;
}
// 二叉链
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* NodeCreate(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n)
	{
		return NULL;
	}
	if (a[*pi] == '#' || a[*pi] == '\0')
	{
		return NULL;
	}
	BTNode* newnode = NodeCreate(a[*pi]);
	(*pi)++;
	newnode->_left = BinaryTreeCreate(a, n, pi);
	(*pi)++;
	newnode->_right = BinaryTreeCreate(a, n, pi);
	return newnode;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
	free(root);
	root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		if (root == NULL)
		{
			return 0;
		}
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left != NULL)
	{
		return left;
	}
	else
	{
		return BinaryTreeFind(root->_right, x);
	}
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(struct BinaryTreeNode* root)
{
	Qe q;
	QueueInit(&q);
	if (root == NULL)
	{
		return;
	}
	Queuepush(&q, root);
	int Ksize = 1;
	while (!QueueEmpty(&q))
	{


		while (Ksize)
		{
			struct BinaryTreeNode* data = QueueFront(&q);
			QueuePop(&q);
			if (data->_left)
			{
				Queuepush(&q, data->_left);

			}
			if (data->_right)
			{
				Queuepush(&q, data->_right);

			}
			printf("%c ", data->_data);
			Ksize--;

		}
		printf("\n");
		Ksize = QueueSize(&q);
	}
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(struct BinaryTreeNode* root)
{
	Qe q;
	QueueInit(&q);
	if (root == NULL)
	{
		return;
	}
	Queuepush(&q, root);
	while (!QueueEmpty(&q))
	{
		struct BinaryTreeNode* data = QueueFront(&q);
		QueuePop(&q);
		if (data == NULL)
		{
			break;
		}
		Queuepush(&q, data->_left);
		Queuepush(&q, data->_right);
	}
	while (!QueueEmpty(&q))
	{
		QueuePop(&q);
		if (QueueFront(&q) != NULL)
		{
			QueueDestroy(&q);
			return false;
		}

	}
	QueueDestroy(&q);
	return true;

}