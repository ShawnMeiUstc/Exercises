/*
 * 重建二叉树
 *
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
 * 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
 * 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
 * 二叉树并输出它的后序遍历序列。
 *
 * 思路：前序序列中第一个值就是根节点的值，遍历中序序列找到根节点位置，则根节点
 * 左侧为左子树（3个元素），右侧为右子树（4个元素），左、右子树的中序序列确定；
 * 在前序序列中，根节点之后前3个元素为左子树元素，后4个为右子树元素，子树的前序序列确定；
 * 这样子树的前序、中序序列都确定了，问题同初始问题就一样了，可以分别对左右子树递归地
 * 构建。
 */

#include <iostream>

using namespace std;

struct tree_node
{
	int data;
	tree_node* lc;
	tree_node* rc;
};

class solution
{
public:
	tree_node* reconstruct_tree(int* pre, int* in, int len)
	{
		if (pre == nullptr || in == nullptr || len <= 0)
			return nullptr;
		tree_node* root = new tree_node;
		root->data = pre[0];
		root->lc = root->rc = nullptr;
		int i = 0;
		for (; i != len; ++i)
		{
			if (pre[0] == in[i])
				break;
		}

		int r_tree_pre[100], r_tree_in[100], l_tree_pre[100], l_tree_in[100], r_len = len - i -1, l_len = i;
		for (int j = i + 1; j != len; ++j)
		{
			r_tree_pre[j-i-1] = pre[j];
			r_tree_in[j-i-1] = in[j];
		}
		for (int j = 0; j != i; ++j)
		{
			l_tree_pre[j] = pre[j + 1];
			l_tree_in[j] = in[j];
		}

		root->lc = reconstruct_tree(l_tree_pre, l_tree_in, l_len);
		root->rc = reconstruct_tree(r_tree_pre, r_tree_in, r_len);
		return root;
	}

	void trav_post(tree_node* root)
	{
		if (!root)
			return;
		if (root->lc)
			trav_post(root->lc);
		if (root->rc)
			trav_post(root->rc);
		cout << root->data << " ";
	}
};

int main()
{
	int arr1[] = { 1, 2, 4, 7, 3, 5, 6, 8 }, arr2[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	solution a; 
	tree_node* root = a.reconstruct_tree(arr1, arr2, 8);
	a.trav_post(root);
	system("pause");
}