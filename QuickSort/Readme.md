
# 快速排序算法

---

下面我们来学习快速排序算法。

快速排序是从冒泡排序演变而来的算法，但是比冒泡排序效率高很多。快速排序之所以快速，因为其同归并排序一样用了**分治法**的思想，同冒泡法一样，快速排序也是属于交换排序的一种，通过元素之间的比较和交换顺序来达到排序的目的。而对于冒泡法不同的是，他采用了分治法，从而在每一轮的挑选基准中，把大的丢到比基准大的一边，而小的丢到另一边。从而把数组拆分成了两个部分。如果是极端的情况，那么快速排序可能退化成冒泡排序，也就是基准选择不对的情况，那么其复杂度从O(nlogn)退化到O(n ^2^ ),削减了效率。


快速排序大体上看，主要是分为三个步骤

- 分解
- 解决
- 合并

> - 分解: 一个数组假设为ans[p..r],那么被分为ans[p...q-1],ans[q+1...r],而中间的ans[q],使得ans[p...q-1]中的每一个元素都小于或者等于ans[q],ans[q+1...r]中的每一个元素都大于或者等于ans[q]。
> - 解决： 然后通过函数递归调用来解决问题，也就是对数组ans[p...q-1]和ans[q+1...r]进行排序
> - 合并： 数组都是在原来的基础上进行排序，所以合并操作在解决的时候已经算是一种合并了。故不需要合并操作
 
以上便是基本的介绍快速排序的基本思想和解决方法

---

来看一个动态的图示演例

![dynamic](./Photos/photo.gif)


---

### 代码

```c++

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

double QuickSort(vector<int>& ans, int p, int r);
int Parrtition(vector<int>& ans, int p, int r);
void Swap(int& a, int& b);
void Display(vector<int>& ans);

int main()
{
	int number;
	cout << "请输入个数" << endl;
	cin >> number;
	vector<int>array;//数组array
	//随机取Number个数字
	for (int i = 0; i < number; i++)
	{
		srand(time(nullptr)+i);
		array.push_back(rand() % 1000);
	}
	cout << "排序前的情况:" << endl;
	
	Display(array);//显示排序前的情况
	
	cout << "排序所用时间：" << QuickSort(array,0,array.size()-1)<<"ms"<<endl;
	
	cout << endl << "排序后的情况" << endl;
	Display(array);

	return 0;
}

double QuickSort(vector<int>& ans, int p, int r)
{
	clock_t start, end;
	start = clock();
	if (p < r)
	{
		int q;
		q = Parrtition(ans, p, r);
		QuickSort(ans, p, q - 1);
		QuickSort(ans, q + 1, r);
	}
	end = clock();
	return (double)(end - start);
}

int Parrtition(vector<int>& ans, int p, int r)
{
	int x = ans[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (ans[j] <= x)
		{
			i++;
			Swap(ans[i], ans[j]);
		}
		
	}
	Swap(ans[i + 1], ans[r]);
	return i + 1;
}

void Swap(int &a, int &b)
{
	int t;
	t = a, a = b, b = t;
}

void Display(vector<int>& ans)
{
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl << endl;
}

```

----

参考《算法导论》

---

