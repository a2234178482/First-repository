#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode(int val):val(val),lchild(nullptr),rchild(nullptr){}
};
void PreOreder(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->val;
	PreOreder(root->lchild);
	PreOreder(root->rchild);
}
void inOreder(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	inOreder(root->lchild);
	cout << root->val;
	inOreder(root->rchild);
}
void PostOrder(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val;
}
void PreOreder(TreeNode* root)
{
	if (root != nullptr)
	{
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* head = st.top();
			st.pop();
			cout << head->val << endl;
			if (head->rchild != nullptr)
			{
				st.push(head->rchild);
			}
			if(head->lchild != nullptr)
			{
				st.push(head->lchild);
			}
		}
	}
}
void inOreder(TreeNode* root)
{
	if (root != nullptr)
	{
		stack<TreeNode*> stk;
		while (root != nullptr || !stk.empty())
		{
			if (root != nullptr)
			{
				stk.push(root);
				root = root->lchild;
			}
			else
			{
				TreeNode* tmp = stk.top();
				stk.pop();
				cout << tmp->val;
				root = root->rchild;
			}
		}
	}
}
void PostOredertwostack(TreeNode* root)
{
	if (root != nullptr)
	{
		stack<TreeNode*> st;
		stack<TreeNode*> collect;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* tmp = st.top();
			st.pop();
			collect.push(tmp);
			if (tmp->lchild)
			{
				st.push(tmp->lchild);
			}
			if (tmp->rchild)
			{
				st.push(tmp->rchild);
			}
		}
		while (collect.empty())
		{
			TreeNode* ret = collect.top();
			collect.pop();
			cout << ret->val;
		}
	}
}
void PostOrederonestack(TreeNode* root)
{
	if (root != nullptr) {
		stack<TreeNode*> st;
		TreeNode* lastprint = nullptr;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			if (cur->lchild != nullptr && lastprint != cur->lchild
				&& lastprint != cur->rchild)
			{
				st.push(cur->lchild);
			}
			else if (cur->rchild != nullptr && lastprint != cur->rchild)
			{
				st.push(cur->rchild);
			}
			else
			{
				cout << cur->val;
				lastprint = cur;
				st.pop();
			}
		}
	}
}