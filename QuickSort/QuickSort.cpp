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
