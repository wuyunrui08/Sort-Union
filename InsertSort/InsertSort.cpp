#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

double InsertSort(vector<int>& ans);
void Display(vector<int>& ans);

int main()
{
	const int Number = 10000;
	vector<int>array;//数组array
	//随机取Number个数字
	for (int i = 0; i < Number; i++)
	{
		srand(time(nullptr)+i);
		array.push_back(rand() % Number);
	}
	//cout << "排序前的情况:" << endl;
	
	//Display(array);//显示排序前的情况
	
	cout << "排序所用时间：" << InsertSort(array) << "ms" << endl;
	
	//cout << endl << "排序后的情况" << endl;
	//Display(array);

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
	cout << endl;
}
