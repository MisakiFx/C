#include <stdio.h>
void changeNum()
{
	//�ֲ�����
	//���������������Զ����� 
	int num1=5,num2=8;
	num1=55;
	num2=88;
}
int main()
{
	 int num1=5;
	 int num2=8;
	 changeNum();//���ú���
	 printf("num1=%d\tnum2=%d\n",num1,num2);//��ʱ��num1��num2����������ģ���changeNum�еľֲ�������ȫ����һ���ռ� 
	 return 0; 
 } 
