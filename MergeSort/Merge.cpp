#include<iostream>
#include<cstdlib>
#include<vector>
#include<time.h>
using namespace std;

void Split(vector<int>& pos, vector<int>& temp, const int start, const int end);
void Merge(vector<int>& pos, vector<int>& temp, const int left, const int mid, const int right);
double MergeSort(vector<int>& pos, const int start, const int end);
void Display1(vector<int>& pos);
void Display2(vector<int>& pos);

int main()
{
	int n;
	cout << "请输入排序的数的个数" << endl;
	cin >> n;

	vector<int>pos(n, 0);//申请n个数

	cout << "请输入需要排序的数" << endl;
	for (int i = 0; i < n; i++)
	{
		srand(time(nullptr) + i);
		pos[i] = rand() % 100;//初始化数据
	}
	Display1(pos);//显示排序前的数组

	cout<<"花费时间:"<<MergeSort(pos, 0, pos.size() - 1)<<"ms"<<endl;//从第几个数开始，0个到最后一个数进行归并排序
	Display2(pos);//显示排序后的数组

	pos.clear();
	return 0;
}

//拆分
void Split(vector<int>& pos, vector<int>& temp, const int start, const int end)
{
	if (start < end)//条件，不能分割为止
	{
		int mid;//中间数定位
		mid = (start + end) / 2;
		Split(pos, temp, start, mid);//左边拆分
		Split(pos, temp, mid + 1, end);//右边拆分
		Merge(pos, temp, start, mid, end);//归并
	}
}

//合并
void Merge(vector<int>& pos, vector<int>& temp, const int left, const int mid, const int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = 0;
	/*
		i 表示第一个数组，从左到中间的数
		j 表示第二个数组，从中间到右边的数
		k 表示临时数组中的下表
	*/
	while (i <= mid && j <= right)//两个数组判比
	{
		if (pos[i] <= pos[j])//如果左边的大于右边的
		{
			temp[k] = pos[i];//左边的放进临时数组中
			k++; i++;//继续跟下一个比较
		}
		else
		{
			temp[k] = pos[j];//如果右边的大于左边
			k++; j++;//同样放入临时数组中，继续跟下一个比较
		}
	}
	//当一方数组中有剩余的时候，把他放进临时数组中，然后等待归并
	while (i <= mid)
	{
		temp[k] = pos[i];
		k++; i++;
	}
	while (j <= right)
	{
		temp[k] = pos[j];
		k++; j++;
	}
	//把临时数组中的内容复制到实际数组中
	for (int i = 0; i < k; i++)
		pos[left + i] = temp[i];
}

//排序算法
double MergeSort(vector<int>& pos, const int start, const int end)
{
	vector<int>temp(pos.size(), 0);//创建临时数组
	clock_t startTime, endTime;
	startTime = clock();
	Split(pos, temp, start, end);
	endTime = clock();
	temp.clear();
	return (double)(endTime - startTime);
}

void Display1(vector<int>& pos)
{
	cout << "排序前的数组如下" << endl;
	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i] << " ";
	}
	cout << endl;
}

void Display2(vector<int>& pos)
{
	cout << "排序后的数组如下" << endl;
	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i] << " ";
	}
	cout << endl;
}
