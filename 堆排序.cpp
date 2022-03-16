#include <iostream>
#include <stdio.h>
using namespace std;

void show(int* a, int m,int n)
{
	for (int i = m; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void reStore(int* t, int f, int e)              //f为根节点下标，e为最大下标
{
	int j = f;                            //指向树根下标1
	int k = 0;
	while (j <= floor(e / 2))
	{
		if (2 * j +1<= e && t[2 * j] < t[2 * j + 1])            //2*j<e说明j所在节点有两个子节点，右节点大于左节点
		{
			k = 2 * j + 1;                              //指向右节点（较大节点）
		}
		else
		{
			k = 2 * j;                        //指向左边节点（较大节点）
		}
		if (t[k] > t[j])               //较大子节点小于j所在节点
		{
			swap(t[k], t[j]);              //交换使较大节点处于父节点
			j = k;
		}
		else
		{
			return;                      //终止循环
		}
	}
	return;
}
void heapSort(int *R,int m,int n)
{
	int num = n - m + 1;                      //数组个数
	int* t = new int[num + 1];                 //下标从1开始
	for (int i = m; i <= n; i++)                //复制数组
	{
		t[i - m + 1] = R[i];
		
	}
	int k = 0;
	for (int i = floor(num / 2); i >= 1; i--)          //初始建堆,num为最大下标
	{
		reStore(t, i, num);
	}
	show(t, 1, num);                      //输出初始建堆结果
	for (int i = num; i >= 2; i--)
	{
		swap(t[i], t[1]);                //交换根节点（最大点），使最大元素就位
		reStore(t, 1, i - 1);
	}
	for (int i = m; i <= n; i++)                //将辅助数组的结果赋给数组R
	{
		R[i] = t[i - m + 1];
	}
	delete[]t;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	heapSort(a,0, n-1);
	show(a, 0,n-1);
	delete[]a;
	return 0;
}