#include <stdio.h>
int main()
{
	double a, b, c;
	printf("���������������߳��ȣ�");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a && b - a < c && c - a < b && c - b < a)
	{
		if(a == b && a != c|| a == c && a != b|| b == c && b != a)
		{
			printf("����");
		}
		if(a == b && a == c)
		{
			printf("�ȱ�");
		}
		if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		{
			printf("ֱ��");
		}
	}
	else
	{
		printf("����");
	}
	printf("������\n");
}
