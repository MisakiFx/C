#include <stdio.h>
#include <math.h>
#define WIGHT 62//����ͼ���ܿ��Ϊ62 
#define WIGHT2 62
int main()
{
	double y;//���Һ�����y��
	int x, m;//���Һ�����x���ÿһ�е�ĺ�����
	for(y = 1; y >= -1; y -= 0.1)//���ѭ�������� 
	{
		m = acos(y) * 10;//����������ĺ������m,10��������������ԽСԽ�� 
		for(x = 1; x < m; x++)
		{
			printf(" "); 
		}
		printf("*");//�ҵ���ӡ�Ǻŵ�λ�ô�ӡ 
		for(;x < WIGHT - m; x++)//���öԳƽ��д�ӡ 
		{
			printf(" ");
		}
		printf("*\n"); 
	} 
	for(y = 1; y >= 0; y -= 0.1)
	{
		m = asin(y) * 20;
		for(x = 1; x < m; x++)
		{
			printf(" ");
		}
		printf("*");
		for(; x < WIGHT2 - m; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
	for(y = 0; y <= 1; y += 0.1)
	{
		m = asin(y) * 20;
		for(x = 1; x < WIGHT2+m+2; x++)
		{
			printf(" ");
		}
		printf("*");
		for(; x < 2 * WIGHT2 - m; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}
