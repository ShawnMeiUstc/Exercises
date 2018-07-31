// 二进制中1的个数
//
// 题目1：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
//
// 题目2：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数为奇数还是偶数。
//
// 题目1的思路1：注意移位运算中逻辑右移和算术右移的区别，所以不要对输入数进行右移
// 操作，应该对标志数1进行左移再异或。
// 题目1的思路2：一个整数减去1，再和原来的数做位与运算，会把这个整数二进制表示的最右一位
// 1变为0。
//
// 题目2的思路：统计出1的个数再判断奇偶性；也可以通过移位与异或判断；

#include <iostream>
using namespace std;

class solution
{
public:
	int one_in_binary_num_1(int num)
	{
		unsigned int flag = 1;
		int count = 0;
		while (flag)
		{
			if (flag & num)
				++count;
			flag <<= 1;
		}
		return count;
	}

	int one_in_binary_num_2(int num)
	{
		int count = 0;
		while (num)
		{
			++count;
			num &= (num - 1);
		}
		return count;
	}

	//  第一次异或的结果，第i个位置上是1代表原数中第i位和第i + 1位有一个为1，
	//	也就是奇数个1。也就是说，某个位为1，代表从它开始向左连续两位中1的个数是奇数（异或的本质）。
	//	第二次异或，注意是两位两位的比较了，所有x是和x >> 2做异或运算，比如，若结果第6位为1，
	//	那么代表上一次的结果的第6位和第8位有奇数个1，也就是原数中第6, 7, 8, 9位中有奇数个1。
	//	同样，到第五次运算结束后，过第0位为1代表0到31位共奇数个1。
	//	整个过程就是不断的压缩信息，先用1位代表从本位开始向左的2位中1的奇偶，然后向左的4位，向左的8位。。。。
	bool odd_even_one(int num)   // true为奇数个，false为偶数个
	{
		num ^= (num >> 1);
		num ^= (num >> 2);
		num ^= (num >> 4);
		num ^= (num >> 8);
		num ^= (num >> 16);
		return num & 1;
	}
};

int main()
{
	int i = 1245, j = -1246, k = 0;
	solution a;
	cout << a.one_in_binary_num_1(i) << " " << a.one_in_binary_num_2(i) << endl
		<< a.one_in_binary_num_1(j) << " " << a.one_in_binary_num_2(j) << endl
		<< a.one_in_binary_num_1(k) << " " << a.one_in_binary_num_2(k) << endl
		<< boolalpha
		<< a.odd_even_one(i) << " " << a.odd_even_one(j) << " " << a.odd_even_one(k) << endl;
	cin.get();
}