#include <stdio.h>
#include <math.h>
 int main()
 {
	double a, b, c, d;
	double x1, x2;
	printf("�����뷽����a,b,c��ֵ��");
	scanf("%lf%lf%lf",&a,&b,&c);
	d = b * b - 4 * a * c;
	if(d < 0)
	{
		printf("�����޽⣡\n");
		return 1;
	}
	else if(d == 0)
	{
		x1 = (-b) / (2 * a);
		printf("������Ψһ�⣺%.2lf\n",x1);
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("���̽�Ϊ��x1 = %.2lf\tx2 = %.2lf\n",x1,x2);
	} 
 }
