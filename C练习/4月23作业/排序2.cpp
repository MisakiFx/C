#include <stdio.h>
#define N 10
int main()
{
	int a[N] = {7,8,9,54,25,65,84,66,88,10}, t, num, low = 0, high = 9, mid, find = 0;
	//ð��������ѭ����������Ԫ�ظ���-1,��ѭ��ÿһ��ΪԪ�ظ�����ÿ��ѭ���������С������ǰ���н��� 
	for(int i = 0; i < N - 1; i++) 
	{
		for(int j = 0; j < N - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	//���ַ����ң�������õ�������м�һ������ʼ�Ƚϣ�һ������С��Χ������м����Ȳ�����С������������ĺ�벿�֣�����ǰ�벿�� 
	printf("������Ҫ���ҵ�����",&num);
	scanf("%d",&num);
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(a[mid] == num)
		{
			printf("�ҵ���,�±���%d\n",mid);
			find = 1;
		}
		if(a[mid] < num)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	if(find == 0)
	{
		printf("δ�ҵ���");
	 } 
}
