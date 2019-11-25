
<h2 id="back"></h2>

# 冒泡排序

- #### [思想](#method)
- #### [代码](#code)


---

<h2 id="method"></h2>

### 思想

冒泡排序也是属于选择排序的一种，每一次“冒泡”，都会找到最大的一个或者最小的一个，从而将其归位。换句话说，每一轮的比较，都会把最大的或者最小的那个，从他原本的位置经过逐一比较之后，放到最后或者最前的位置，从而实现了排序。

比较复杂度是O(n^2^),不是一种较好的办法，但是比较容易实现。

[back](#back)

---

借鉴《算法导论》

---

<h2 id="code"></h2>

### 代码

```c++

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

double BubbleSort(vector<int>& ans);
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
	
	cout << "排序所用时间：" << BubbleSort(array)<<"ms"<<endl;
	
	cout << endl << "排序后的情况" << endl;
	Display(array);

	return 0;
}

double BubbleSort(vector<int>& ans)
{
	clock_t start, end;
	start = clock();
	int temp;
	for (int i = 0; i < ans.size()-2; i++)//比较次数，数组长度
	{
		for (int j = ans.size()-1; j > i + 1; j--)
		{
			if (ans[j] < ans[j - 1])//如果发现小的，那么交换，把最小的放到最前面的位置
			{
				temp = ans[j];
				ans[j] = ans[j - 1];
				ans[j - 1] = temp;
			}
		}
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
