/*
 * 用两个栈实现队列
 * 
 * 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
 * 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
 *
 * 思路：结点总是插入stack1，当stack2非空的时候，删除的元素总是stack2的顶部结点；
 * 当stack2为空，就将stack1元素相继弹出，然后按序压入stack2,再弹出stack2顶部结点
 */

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void) {}
	~CQueue(void) {}

	// 在队列末尾添加一个结点
	void appendTail(const T& node);

	// 删除队列的头结点
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (stack1.size())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	if (stack2.empty())
		throw new exception("queue is empty!");
	T temp = stack2.top();
	stack2.pop();
	return temp;
}

int main()
{
	CQueue<int> q;
	int i = 1;
	while (i != 10)
	{
		q.appendTail(i*i);
		++i;
	}
	cout << q.deleteHead() << endl;
	system("pause");
}