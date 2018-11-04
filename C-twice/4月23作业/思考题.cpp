#include <stdio.h>
#include <stdlib.h>
int fun(int *,int);
void fun1(int *, int);
void fun2(int *, int);
void fun3(int *, int);
void fun4(int *, int);
void fun5(int *, int);
int* ArrayInit(int n)
{
	int t; 
	int (*a)[n] = (int(*)[n])malloc(sizeof(int[n]) * n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[i][j] = i * n + j + 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i < j)
			{
				t = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = t;
			}
		}
	}
	return (int*)a;
}
int main()
{
	int n = 2, flag = 1;
	do
	{
		if(n <= 1 || n > 6 || flag == 0)
		{
			printf("�����������������룡\n");
			fflush(stdin);
			flag = 1;
		}
		else 
		printf("������һ������1С�ڵ���6�������������������飺");
		if(scanf("%d",&n) != 1)
		{
			flag = 0;
		}
	}while(n <= 1 || n > 6 || flag == 0); 
	int* a = ArrayInit(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d\t",a[i*n+j]);
		}
		printf("\n");
	 } 
	while(fun(a,n))
	{
		printf("\n\n");
	}	
}
void fun5(int *a, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i <= j)
			{
				sum += a[i * n + j];
			}
		}
	}
	printf("�����Ǻ�Ϊ��%d\n",sum);
}
void fun4(int *a, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				sum += a[i * n + j];
			}
		}
	}
	printf("���Խ��ߺ�Ϊ��%d\n",sum);
}
void fun3(int *a, int n)
{
	int max = 0, min = 62535, sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			sum += a[j * n + i];
			if(a[i * n + j] > max)
			{
				max = a[j * n + i];
			}
			if(a[i * n + j] < min)
			{
				min = a[j * n + i];
			}
		}
		printf("��%d�У�\n",i + 1);
		printf("��Ϊ��%d,���ֵΪ��%d,��СֵΪ��%d\n",sum,max,min);
		sum = 0;
		max = 0;
		min = 62535;
	}
}
void fun2(int *a, int n)
{
	int max = 0, min = 62535, sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			sum += a[i * n + j];
			if(a[i * n + j] > max)
			{
				max = a[i * n + j];
			}
			if(a[i * n + j] < min)
			{
				min = a[i * n + j];
			}
		}
		printf("��%d�У�\n",i + 1);
		printf("��Ϊ��%d,���ֵΪ��%d,��СֵΪ��%d\n",sum,max,min);
		sum = 0;
		max = 0;
		min = 62535;
	}
}
void fun1(int *a,int n)
{
	int max = 0;
	int min  = 62535;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			sum += a[i * n + j];
			if(a[i * n + j] > max)
			{
				max = a[i * n + j];
			}
			if(a[i * n + j] < min)
			{
				min = a[i * n + j];
			}
		}
	}
	printf("��Ϊ��%d,���ֵΪ��%d,��СֵΪ��%d\n",sum,max,min);
}
int fun(int* a, int n)
{
	int choose;
	printf("1�������е����ֵ����Сֵ������Ԫ�صĺͣ�\n");
	printf("2��������ÿ���е����ֵ����Сֵ���ͣ�\n");
	printf("3��������ÿ���е����ֵ����Сֵ���ͣ�\n");
	printf("4�����������Խ���Ԫ�صĺͣ�\n");
	printf("5�������������ǵĺͣ�\n");
	printf("0���˳�\n");
	printf("������1~5ѡ��");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			fun1(a, n);
			break;
		case 2:
			fun2(a, n);
			break;
		case 3:
			fun3(a, n); 
			break;
		case 4:
			fun4(a, n);
			break;
		case 5:
			fun5(a, n);
			break;
	}
	return choose;
}
