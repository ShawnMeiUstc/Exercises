/*
 * 用两个队列实现栈
 *
 * 题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数stack_push
 * 和stack_pop，分别完成在栈顶加入元素和弹出元素。
 *
 * 思路：结点总是插入queue1,当queue1只有一个元素，弹出它；当queue1多于一个元素，
 * 依次取出其队首元素存入queue2，直至剩最后一个元素，弹出；若queue1为空，转到queue2，
 * 进行类似操作
 */

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class CStack
{
public:
	CStack(void) {}
	~CStack(void) {}
	void stack_push(const T& ndoe);
	T stack_pop();
private:
	queue<T> queue1, queue2;
};

template<typename T>
void CStack<T>::stack_push(const T & node)
{
	queue1.push(node);
}

template<typename T>
T CStack<T>::stack_pop()
{
	while (queue1.size() > 1)
	{
		queue2.push(queue1.front());
		queue1.pop();
	}
	if (queue1.size() == 1)
	{
		T temp = queue1.front();
		queue1.pop();
			return temp;
	}

	if (queue2.empty())
		throw new exception("stack is empty!");
	else
	{
		while (queue2.size() > 1)
		{
			queue1.push(queue2.front());
			queue2.pop();
		}

		T temp = queue2.front();
		queue2.pop();
		return temp;
	}
}


int main()
{
	CStack<int> s;
	s.stack_push(1);
	s.stack_push(2);
	s.stack_push(3);
	cout << s.stack_pop() << " ";
	cout << s.stack_pop() << " ";
	cout << s.stack_pop() << " ";
	cout << s.stack_pop() << " ";
	system("pause");
}