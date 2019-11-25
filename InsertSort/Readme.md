
<h2 id="back"></h2>

# 直接插入排序

- ### 目录
- #### [简述](#introduction)
- #### [步骤](#step)
- #### [代码](#code)



---

<h2 id="introduction"></h2>

[back](#back)

### 简述

直接插入排序是一种简单的排序，基本操作就是，从一堆数中选择一个数，然后插入到排好序的列表中（本列表）。这种方法也称归位。直接插入排序，每一次选择数字，都是一种归位。

举个例子，就好比如，你在打扑克，然后你抽到了一堆扑克牌，你要对它进行排序，你会很直接地，从一边或者中间选择一张扑克牌，然后根据数值大小，进行插入排序。选出的牌，你会很自然的插入到比它小的前面。不一会，你的手中的扑克牌就完成了排序。

<h2 id="step"></h2>

### 算法的步骤

以下是《数据结构C语言版》的算法步骤：

1. 设待排序的记录存放在数组r[1..n]中，r[1]是一个有序序列。
2. 循环n-1c次，每次使用顺序查找法，查找r[i] (i=2,...n)在已排好序的序列r[1...i-1]中的插入位置，然后将r[i]插入表长为i-1的有序序列r[1...i-1]，直到r[n]插入表长为n-1的有序序列r[1...n-1],最后得到一个表长为n的有序序列。

我的理解：

按要求选出一个最大或者最小的值，然后放到最前面，再从剩下的几个选出最大或者最小的，重复刚刚的操作，一直到整个数组有序

### 特性

直接插入法的平均时间复杂度是O（n^2^）,其空间复杂度是S（1）。

主要特点是：
>- 是稳定的
>- 算法比较简便，而且容易书写
>- 适用于链表的结构
>- 对基本有序的情况的话，更为适合使用。但是，如果基数非常大，那么复杂度比较高，不应该使用


<h2 id="code"></h2>

[back](#back)

### 代码实现

#### main.cpp

```c++

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

double InsertSort(vector<int>& ans);
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
	
	cout << "排序所用时间：" << InsertSort(array)<<"ms"<<endl;
	
	cout << endl << "排序后的情况" << endl;
	Display(array);

	return 0;
}

double InsertSort(vector<int>& ans)
{
	clock_t start, end;
	start = clock();
	int key;
	for (int i = 1,j; i < ans.size(); i++)
	{
		key = ans[i];//从前面取数
		j = i - 1;//从前一个开始取数
		while (j >= 0 && ans[j] < key)//然后每一次都与后面的进行比较
		{
			ans[j + 1] = ans[j];//每一次都进行一次移位
			j = j - 1;
		}
		ans[j + 1] = key;//最后找到该值，然后就放入，算数值归位
	}

	end = clock();
	return (double)(end - start);
}

void Display(vector<int>& ans)
{
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl << endl;
}

```

[back](#back)

---

借鉴《算法导论》







