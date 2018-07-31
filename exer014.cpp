/*
 * 排序算法总结
 */

#include <iostream>

using namespace std;

class solution
{
public:                                           // 最好      最坏      平均       空间       稳定

	// 原始起泡排序
	void bubble_sort_origin(int* arr, int n)      //  O(n)      O(n^2)    O(n^2)     O(1)       yes
	{
		if (!arr || n <= 1)
			return;
		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
		}
	}
	// 改进起泡排序
	//借助整数m尽快地收缩待排序区间：既可提前退出，更可减少每趟（及所有）扫描交换中元素比较操作
	//对尾部有序（或接近有序）的输入，算法收敛的速度大大提高
	void bubble_sort_advance(int* arr, int n)
	{
		if (!arr || n <= 1)
			return;

		for (int m = 1; n > 1; n = m)           //最后的赋值语句修改待排范围为[0,m)
		{
			for (int i = m = 1; i != n; ++i)
			{
				if (arr[i - 1] > arr[i])
				{
					swap(arr[i - 1], arr[i]);
					m = i;                     // 记录最后一次发生交换的位置
				}                              // 这之后的元素都有序
			}
		}
	}

	// 选择排序                                     // 最好      最坏      平均       空间       稳定
	void select_sort(int* arr, int n)               // O(n^2)    O(n^2)    O(n^2)     O(1)        no
	{
		if (!arr || n <= 1)
			return;

		for (int i = 0; i != n; ++i)
		{
			int min_index = i;
			for (int j = i + 1; j != n; ++j)
			{
				if (arr[min_index] > arr[j])
					min_index = j;
			}
			swap(arr[i], arr[min_index]);
		}

	}

	// 插入排序
	void insert_sort(int* arr, int n)            // 最好      最坏      平均       空间       稳定
	{
		if (!arr || n <= 1)                      // O(n)      O(n^2)    O(n^2)     O(1)        yes
			return;

		int temp, i, j;
		for (i = 1; i != n; ++i)
		{
			temp = arr[i];
			for (j = i; j != 0 && arr[j - 1] > temp; --j)
			{
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}
	}

	// 希尔排序                                                   // 最好      最坏      平均       空间       稳定
	// 以下初始增量简单设定为n/2，之后依次递减为当前增量的一半    // O(n^1.3)  O(n^2)    O(n^2)     O(1)        no
	void shell_sort(int* arr, int n) 
	{
		if (!arr || n <= 1)
			return;

		int i, j, temp, increment;
		for (increment = n >> 1; increment > 0; increment >>= 1)
		{
			// 底层采用输入敏感的插入排序
			for (i = increment; i < n; i += increment) // 不能是i != n，因为可能会加一个增量后超过n
			{
				temp = arr[i];
				for (j = i; j >= increment && arr[j - increment] > temp; j -= increment)
				{
					arr[j] = arr[j - increment];
				}
				arr[j] = temp;
			}
		}
	}

	//归并排序                                              // 最好      最坏      平均       空间       稳定
	void merge_sort(int* arr, int n)                        // O(nlgn)  O(nlgn)    O(nlgn)    O(n)        yes
	{
		if (!arr || n <= 1)
			return;
		int fi = 0, la = n;
		int mid = (fi + la) >> 1;
		int len_left = mid - fi, len_right = la - mid;
		int* arr_left = arr, *arr_right = &arr[mid];
		merge_sort(arr_left, len_left);
		merge_sort(arr_right, len_right);
		merge(arr, fi, mid, la);
	}

	void merge(int* arr, int fi, int mid, int la) //归并函数
	{
		//划分数组a，b，c
		int* pa = &arr[fi];
		int len_b = mid - fi;
		int* pb = new int[len_b];       //复制数组前半区
		for (int i = 0; i != len_b; ++i)
		{
			pb[i] = arr[i];
		}
		int* pc = &arr[mid];
		int len_c = la - mid;

		int i = 0, j = 0;
		while (i != len_b && j != len_c)
		{
			if (pb[i] < pc[j])
			{
				pa[fi++] = pb[i++];
			}
			else
			{
				pa[fi++] = pc[j++];
			}
		}

		if (j == len_c)   // 如果数组c先复制完，处理b，反之b先复制完，c不用处理
		{
			while (i != len_b)
				pa[fi++] = pb[i++];
		}

		delete[] pb;
		pb = nullptr;
	}

	// 快速排序                                    // 最好      最坏      平均       空间                   稳定
	void quick_sort(int* arr, int n)               // O(nlgn)  O(n^2)    O(nlgn)    O(lgn)（来自递归栈）     no
	{
		if (!arr || n <= 1)
			return;

		int fi = 0, la = n;
		int mid = create_pivot(arr, fi, la - 1);
		int len_left = mid - fi, len_right = la - mid - 1; //左右子数组不包含mid这一点
		int* arr_left = arr, *arr_right = &arr[mid + 1];
		quick_sort(arr_left, len_left);
		quick_sort(arr_right, len_right);
	}

	int create_pivot(int* arr, int fi, int la)         // 轴点构造函数
	{
		swap(arr[fi], arr[rand() % (la - fi + 1)]);    // 随机选取一点作为起始轴点
		int pivot = arr[fi];
		while (fi < la)
		{
			while (fi < la && pivot <= arr[la])
				--la;
			arr[fi] = arr[la];

			while (fi < la && pivot >= arr[fi])
				++fi;
			arr[la] = arr[fi];
		}
		arr[fi] = pivot;
		return fi;
	}

	// 堆排序                                   // 最好      最坏      平均       空间       稳定
                                                // O(nlgn)  O(nlgn)    O(nlgn)    O(1)        no
	void heap_sort(int* arr, int n)
	{
		if (!arr || n <= 1)
			return;
		heapfy(arr, n);
		while (n > 1)                   // 元素个数n不低于2个
		{
			swap(arr[0], arr[n - 1]);   // 摘除堆顶元素，最后一个元素成为堆顶
			--n;
			percolate_down(arr, 0, n);  // 新堆顶元素下滤，恢复堆序性
		}
	}

	void heapfy(int* arr, int n) // 从最后一个内部节点开始的建堆算法
	{
		for (int i = parent(n - 1)/*最后一个（下标最大）内部节点*/; 0 <= i && i < n; --i)
		{
			percolate_down(arr, i, n);
		}
	}

	int percolate_down(int* arr, int i, int n)   //对下标为i的节点的下滤过程
	{
		if (i < 0 || i >= n)
			exit(1);
		int j = 0;
		while (i != (j = proper_parent(arr, i, n)))
		{
			swap(arr[i], arr[j]);
			i = j;
		}
		return i;
	}

	int rc(int);
	int lc(int);
	int parent(int);
	int proper_parent(int* arr, int i, int n);

	// 计数排序(桶排序)                                // 最好      最坏      平均       空间       稳定
	void counting_sort(int* arr, int n)                // O(n+k)    O(n+k)    O(n+k)     O(k)       yes
	{
		if (!arr || n <= 1)
			return;

		int min = arr[0], max = arr[0];
		for (int i = 0; i != n; ++i)
		{
			if (arr[i] < min)
				min = arr[i];
			if (max < arr[i])
				max = arr[i];
		}

		int len = max - min + 1;
		if (len <= 1)
			return;
		int* bucket = new int[len] {0}; //函数内部的数组不会默认初始化，手动解决
		
		for (int i = 0; i != n; ++i)
		{
			++bucket[arr[i] - min];
		}

		int j = 0;
		for (int i = 0; i != len; ++i)
		{
			while (bucket[i]--)
			{
				arr[j++] = i + min;
			}
		}

		delete[] bucket;
		bucket = nullptr;
	}

	// 基数排序                             //   最好         最坏         平均         空间        稳定
	void radix_sort(int* arr, int n)        // O(d(n+k))    O(d(n+k))    O(d(n+k))     O(rk+n)       yes
	{
		if (!arr || n <= 1)
			return;

		int min = arr[0], max = arr[0];
		for (int i = 0; i != n; ++i)
		{
			if (arr[i] < min)
				min = arr[i];
			if (max < arr[i])
				max = arr[i];
		}
		if (max == min)
			return;

		int* bucket = new int[10]{ 0 };
		int* temp = new int[n] {0};
		int exp = 1;
		while (max / exp)
		{
			int i = 0;
			for (;i != n; ++i)        //count
			{
				++bucket[(arr[i] / exp) % 10];
			}

			for (i = 1; i != 10; ++i)  //accumulate
			{
				bucket[i] += bucket[i - 1];
			}

			for (i = n-1; i >= 0; --i)   //从后向前遍历保持稳定性
			{
				temp[bucket[(arr[i] / exp) % 10] - 1] = arr[i];
				--bucket[(arr[i] / exp) % 10];
			}

			for (i = 0; i != n; ++i)  
			{
				arr[i] = temp[i];
			}

			for (i = 0; i != 10; ++i) //bucket数组置0
			{
				bucket[i] = 0;
			}

			exp *= 10;
		}
		delete[] bucket;
		bucket = nullptr;
		delete[] temp;
		temp = nullptr;
	}

	
};

inline
int solution::lc(int i)
{
	return 1 + (i << 1);
}
inline
int solution::rc(int i)
{
	return (1 + i) << 1;
}
inline
int solution::parent(int i)
{
	return (i - 1) >> 1;
}
inline
int solution::proper_parent(int* arr, int i, int n) // 下标为i的节点与其两个孩子（如果存在）
{                                                   // 取合适的父结点
	if (i < 0 || i >= n)
		exit(1);

	if (lc(i) < n && lc(i) >= 0)
	{
		if (rc(i) < n && rc(i) >= 0)
		{
			return arr[i] < arr[lc(i)] ?
				(arr[lc(i)] < arr[rc(i)] ? rc(i) : lc(i)) :
				(arr[i] < arr[rc(i)] ? rc(i) : i);
		}
		else
		{
			return arr[i] < arr[lc(i)] ? lc(i) : i;
		}
	}
	else
	{
		if (rc(i) < n && rc(i) >= 0)
		{
			return arr[i] < arr[rc(i)] ? rc(i) : i;
		}
	}
	return i;
}



int main()
{
	int arr[] = { 2,5,7,3,4,9,2,100 };
	solution a;
	char c;
	cin >> c;
	switch (c)
	{
	case 'b':
		a.bubble_sort_origin(arr, 8);
		break;
	case 'B':
		a.bubble_sort_advance(arr, 8);
		break;
	case 'i':
		a.insert_sort(arr, 8);
		break;
	case 's':
		a.select_sort(arr, 8);
		break;
	case 'S':
		a.shell_sort(arr, 8);
		break;
	case 'm':
		a.merge_sort(arr, 8);
		break;
	case 'q':
		a.quick_sort(arr, 8);
		break;
	case 'h':
		a.heap_sort(arr, 8);
		break;
	case 'c':
		a.counting_sort(arr, 8);
		break;
	case 'r':
		a.radix_sort(arr, 8);
		break;
	default:
		break;
	}

	for (int i = 0; i != 8; ++i)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
}