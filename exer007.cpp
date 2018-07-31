/*
 * 二叉树基本操作(没有父节点指针)
 */

#include <iostream>
#include <stack>
#include <queue>

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
	tree_node* create_btree(istream& in) // 生成一颗二叉树，对每个新节点，从二叉树根节点开始，左孩子为空，就插入为左孩子；
	{                                    // 右孩子为空，就插入为右孩子；
		int value;                       // 都不为空，随机转入一侧，并以孩子节点为根节点重复这般操作。
		if (!(in >> value))
			return nullptr;
		tree_node* root = new tree_node;
		root->lc = root->rc = nullptr;
		root->data = value;
		while (in >> value)
		{
			tree_node* temp_root = root;
			tree_node* new_node = new tree_node;
			new_node->data = value;
			new_node->lc = new_node->rc = nullptr;

			while (true)
			{
				if (!temp_root->lc)
				{
					temp_root->lc = new_node;
					new_node = nullptr;
					break;
				}
				else if (!temp_root->rc)
				{
					temp_root->rc = new_node;
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

	int node_size(tree_node* root)  //求节点数
	{
		if (!root)
			return 0;

		int count = 1; //自身
		if (root->lc)
			count += node_size(root->lc);
		if (root->rc)
			count += node_size(root->rc);
		return count;
	}

	void trav_pre_recur(tree_node* root) //前序遍历递归
	{
		if (!root)
			return;
		cout << root->data << " ";
		trav_pre_recur(root->lc);
		trav_pre_recur(root->rc);
	}

	void trav_in_recur(tree_node* root) //中序遍历递归
	{
		if (!root)
			return;
		trav_in_recur(root->lc);
		cout << root->data << " ";
		trav_in_recur(root->rc);
	}

	void trav_post_recur(tree_node* root)//后序遍历递归
	{
		if (!root)
			return;
		trav_post_recur(root->lc);
		trav_post_recur(root->rc);
		cout << root->data << " ";
	}

	void trav_pre_iter(tree_node* root)//前序遍历迭代
	{
		if (!root)
			return;
		stack<tree_node*> s;
		while (root || !s.empty())
		{
			if (root)
			{
				cout << root->data << " ";
				s.push(root);
				root = root->lc;
			}
			else
			{
				root = s.top();
				s.pop();
				root = root->rc;
			}
		}
	}

	void trav_in_iter(tree_node* root) //中序遍历迭代
	{
		if (!root)
			return;
		stack<tree_node*> s;
		while (root || !s.empty())
		{
			if (root)
			{
				s.push(root);
				root = root->lc;
			}
			else
			{
				root = s.top();
				cout << root->data << " ";
				s.pop();
				root = root->rc;
			}
		}
	}

	void trav_post_iter(tree_node* root) //后序遍历迭代
	{
		if (!root)
			return;
		stack<tree_node*> s;
		tree_node* cur = root, *pre_visit = nullptr; //当前节点，上次被访问节点
		while (cur)         //沿左子树跑到最左
		{
			s.push(cur);
			cur = cur->lc;
		}

		while (!s.empty())
		{
			cur = s.top();
			s.pop();
			if (cur->rc == nullptr || cur->rc == pre_visit) // 三种情况：1.cur节点是左侧最低节点（无右孩子）	                                           
			{                                               //           2.cur节点有右孩子，但是已被访问
				cout << cur->data << " ";
				pre_visit = cur;
			}
			else                                            //           3.cur节点有右孩子但未被访问
			{
				s.push(cur);                                // 此时cur节点作为根节点重新入栈
				cur = cur->rc;                              // 转向cur的右子树（cur是最左节点，左子树已遍历）
				while (cur)                                 // 新的根节点，沿左子树跑到最左，故事重复了
				{
					s.push(cur);
					cur = cur->lc;
				}
			}

		}
	}

	void trav_level(tree_node* root)  //层次遍历
	{
		if (!root)
			return;
		queue<tree_node*> q;
		q.push(root);
		while (!q.empty())
		{
			root = q.front();
			q.pop();
			cout << root->data << " ";
			if (root->lc)
				q.push(root->lc);
			if (root->rc)
				q.push(root->rc);
		}
	}
};

int main()
{
	solution a;
	tree_node* root = a.create_btree(cin);
	cout << a.node_size(root) << endl;
	a.trav_pre_recur(root);
	cout << endl;
	a.trav_in_recur(root);
	cout << endl;
	a.trav_post_recur(root);
	cout << endl;
	a.trav_pre_iter(root);
	cout << endl;
	a.trav_in_iter(root);
	cout << endl;
	a.trav_post_iter(root);
	cout << endl;
	a.trav_level(root);
	cout << endl;
	system("pause");
}