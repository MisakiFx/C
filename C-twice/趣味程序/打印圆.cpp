#include <stdio.h>
#include <math.h>
int main()
{
	//����Բ�ķ���R*R=X*X+Y*Y 
	double y;
	int x, m;
	for(y = 10; y >= -10; y--)
	{
		m = 2.0 * sqrt(100 - y * y);//2.0������Ļ�ݿ�� 
		for(x = 1; x < 25 - m; x++)//�뾶-x�������ǰ��Ҫ��Ŀո� 
		{
			printf(" ");
		}
		printf("*");
		for(; x < 25 + m; x++)//�뾶+x��������м�Ҫ��Ŀո� 
		{
			printf(" ");
		}
		printf("*\n");
	}
} 
