#include <stdio.h>
//��ʽ������ʵ��
//ʵ�ʲ�����ʵ�ʴ�����Щ��ֵ���뺯��
//ʵ��pow����
double pow(double,int); //����Ĳ�������ʽ���� 
int main()
{
	double x;
	int y; 
	printf("���������֣�������������㣺");
	scanf("%lf%lf",&x,&y);
	double result=pow(x,y); //����Ĳ�����ʵ�ʲ�����ʵ�ξ��ǵ���     
	printf("%.2lf��%.2lf�η�=%.2lf",x,y,result);
}
double pow(double a,int b)//����Ĳ���Ҳ����ʽ����
{
	int i;
	double result=1;
	for(i=0;i<b;i++)
	{
		result*=a;
	}
	return result;
}
