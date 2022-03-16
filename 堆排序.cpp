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
void reStore(int* t, int f, int e)              //fΪ���ڵ��±꣬eΪ����±�
{
	int j = f;                            //ָ�������±�1
	int k = 0;
	while (j <= floor(e / 2))
	{
		if (2 * j +1<= e && t[2 * j] < t[2 * j + 1])            //2*j<e˵��j���ڽڵ��������ӽڵ㣬�ҽڵ������ڵ�
		{
			k = 2 * j + 1;                              //ָ���ҽڵ㣨�ϴ�ڵ㣩
		}
		else
		{
			k = 2 * j;                        //ָ����߽ڵ㣨�ϴ�ڵ㣩
		}
		if (t[k] > t[j])               //�ϴ��ӽڵ�С��j���ڽڵ�
		{
			swap(t[k], t[j]);              //����ʹ�ϴ�ڵ㴦�ڸ��ڵ�
			j = k;
		}
		else
		{
			return;                      //��ֹѭ��
		}
	}
	return;
}
void heapSort(int *R,int m,int n)
{
	int num = n - m + 1;                      //�������
	int* t = new int[num + 1];                 //�±��1��ʼ
	for (int i = m; i <= n; i++)                //��������
	{
		t[i - m + 1] = R[i];
		
	}
	int k = 0;
	for (int i = floor(num / 2); i >= 1; i--)          //��ʼ����,numΪ����±�
	{
		reStore(t, i, num);
	}
	show(t, 1, num);                      //�����ʼ���ѽ��
	for (int i = num; i >= 2; i--)
	{
		swap(t[i], t[1]);                //�������ڵ㣨���㣩��ʹ���Ԫ�ؾ�λ
		reStore(t, 1, i - 1);
	}
	for (int i = m; i <= n; i++)                //����������Ľ����������R
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