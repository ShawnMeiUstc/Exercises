/*
 * 单链表的一些基本操作
 * 注意head是指向指针的指针
 * |||||||||||||||||||||||
 * 从尾到头打印链表
 *
 * 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。（不改变
 * 链表的结构）
 *
 * 思路：在不改变链表结构的前提下，链表的遍历是顺序的，而输出是逆序的，自然想到
 * 用栈结构来存储顺序遍历的值。还有种方法是递归，原理与使用栈相同，但是当链表过长
 * 可能会导致栈溢出。
 */

#include<iostream> 
#include<stack>

using namespace std;

struct node
{
	node* next;
	int data;
};

class solution
{
public:
	void add_to_tail(node** head, int value)
	{
		if (!head)
			return;
		node* new_node = new node;
		new_node->data = value;
		new_node->next = nullptr;

		if (!*head)
		{
			*head = new_node;
			new_node = nullptr;
		}
		else
		{
			node* cur_node = *head;
			while (cur_node->next)
			{
				cur_node = cur_node->next;
			}
			cur_node->next = new_node;
			new_node = nullptr;
		}
	}

	void add_to_head(node** head, int value)
	{
		if (!head)
			return;
		node* new_node = new node;
		new_node->data = value;
		new_node->next = nullptr;

		if (!*head)
		{
			*head = new_node;
			new_node = nullptr;
		}
		else
		{
			new_node->next = *head;
			*head = new_node;
			new_node = nullptr;
		}

	}

	void delete_node(node** head, int value) //如不是头结点，遍历到待删除节点的前驱节点
	{
		if (!head || !*head)
			return;

		node* to_be_deleted = nullptr;
		if ((*head)->data == value)
		{
			to_be_deleted = *head;
			*head = (*head)->next;
		}
		else
		{
			node* cur_node = *head;
			while (cur_node->next && cur_node->next->data != value)
			{
				cur_node = cur_node->next;
			}

			if (cur_node->next && cur_node->next->data == value)
			{
				to_be_deleted = cur_node->next;
				cur_node->next = cur_node->next->next;
			}
		}

		if (to_be_deleted)
		{
			delete to_be_deleted;
			to_be_deleted = nullptr;
		}

	}

	node* create_list(istream& in)
	{
		int value = 0;
		if (!(in >> value))
			return nullptr;
		node*head_node = new node;
		head_node->data = value;
		head_node->next = nullptr;
		node** head = &head_node;

		while (in >> value)
		{
			add_to_tail(head, value);
		}
		return *head;
	}

	void print_list(node** head)
	{
		if (!head || !*head)
			return;
		node* cur_node = *head;
		while (cur_node)
		{
			cout << cur_node->data << " ";
			cur_node = cur_node->next;
		}
		cout << endl;
	}

	void print_list_from_tail(node** head)
	{
		if (!head || !*head)
			return;
		node* cur_node = *head;
		stack<int> s;
		while (cur_node)
		{
			s.push(cur_node->data);
			cur_node = cur_node->next;
		}

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
	
};

int main()
{
	solution a;
	node* head_node = a.create_list(cin);
	node** head = &head_node;
	a.delete_node(head, 55); 
	a.print_list(head);
	a.print_list_from_tail(head);
	system("pause");
}