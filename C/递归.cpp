#include <stdio.h>
int num=0;
int factorial(int num);//����׳˺��� 
void test(int num)
{
	printf("%d",num++);
	test(num);//�Լ������Լ�����ѭ�� 
 } 
int main()
{
	//�����Լ������Լ��Ĺ��̽еݹ�
	//test(num);//ѭ��������˳����� 
	int result=factorial(5);
	printf("%d",result);
}
int factorial(int num)
{
	if(num == 1)
	{
		return 1;
	}
	else
	{
		num=num*factorial(num-1);
		return num;
	}
}
