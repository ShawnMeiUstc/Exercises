/*
 * 二叉树的下一个结点
 * 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
 * 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
 *
 * 思路：情况1：如果该结点有右子树，则右子树中最左子节点为所求；
 *      情况2：如果无右子树，且是其父结点的左子节点，则父结点为所求；
 *      情况3：如果无右子树，且是其父结点的右子节点，则需向上遍历，找到某一节点，
 *             它是其父结点的左子节点，则父结点为所求。（所给节点是所求节点的左子树的最右元素）
 */

#include <iostream>

using namespace std;

struct tree_node
{
	int data;
	tree_node* lc;
	tree_node* rc;
	tree_node* parent;
};

class solution
{
public:
	tree_node* find_next_node(tree_node* some_node)
	{
		if (!some_node)
			return nullptr;

		if (some_node->rc)
		{
			some_node = some_node->rc;
			while (some_node->lc)
			{
				some_node = some_node->lc;
			}
			return some_node;
		}
		else if (some_node->parent && some_node->parent->lc == some_node)
		{
			return some_node->parent;
		}
		else if (some_node->parent && some_node->parent->rc == some_node)
		{
			some_node = some_node->parent;
			while (some_node->parent && some_node->parent->lc != some_node)
				some_node = some_node->parent;
			if (some_node->parent)
				return some_node->parent;
		}
		else
		{
			return nullptr;
		}

		return nullptr;
	}


	//测试用
	tree_node* create_btree(istream& in) // 生成一颗二叉树，对每个新节点，从二叉树根节点开始，左孩子为空，就插入为左孩子；
	{                                    // 右孩子为空，就插入为右孩子；
		int value;                       // 都不为空，随机转入一侧，并以孩子节点为根节点重复这般操作。
		if (!(in >> value))
			return nullptr;
		tree_node* root = new tree_node;
		root->lc = root->rc = root->parent = nullptr;
		root->data = value;
		while (in >> value)
		{
			tree_node* temp_root = root;
			tree_node* new_node = new tree_node;
			new_node->data = value;
			new_node->lc = new_node->rc = new_node->parent = nullptr;

			while (true)
			{
				if (!temp_root->lc)
				{
					temp_root->lc = new_node;
					new_node->parent = temp_root;
					new_node = nullptr;
					break;
				}
				else if (!temp_root->rc)
				{
					temp_root->rc = new_node;
					new_node->parent = temp_root;
					new_node = nullptr;
					break;
				}
				else
				{
					if (rand() % 2)
						temp_root = temp_root->lc;
					else
						temp_root = temp_root->rc;
				}
			}
		}
		return root;
	}

	void trav_in_recur(tree_node* root) //中序遍历递归
	{
		if (!root)
			return;
		trav_in_recur(root->lc);
		cout << root->data << " ";
		trav_in_recur(root->rc);
	}
};

int main()
{
	solution a;
	tree_node* root = a.create_btree(cin);
	tree_node* some_node = root->lc->rc;
	if (some_node)
		cout << some_node->data << endl;
	a.trav_in_recur(root);
	cout << endl;
	tree_node* find = a.find_next_node(some_node);
	if (find)
		cout << find->data << endl;
	system("pause");
}