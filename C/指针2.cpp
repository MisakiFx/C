#include <stdio.h>
int main()
{
	int num1=1024;
	int num2=2048;
	int *ptr1,*ptr2;
	ptr1=&num1;
	ptr2=&num2;
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",num1,ptr1);
	printf("num2��ֵ��%d\tnum2��ַ��%p\n",num2,ptr2);
	//������1��ֵ��������2
	//num2=num1;*ptr2=*ptr1;���仰�ȼ�
	//ֱ�Ӳ���ָ��
	ptr2=ptr1; 
	printf("���¸�ֵ��\n"); 
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",num1,ptr1);
	printf("num2��ֵ��%d\tnum2��ַ��%p\n",num2,ptr2);
	//��ptr1����ptr2����ʱptr2Ҳָ��num1������ʵ����num2��ֵû�б�
	printf("\n");
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",num1,ptr1);
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",*ptr2,ptr2);//Ҳ������ô��ʾ��
	*ptr2=111111;
	//��ʱptr2ָ�����num1�����Ա����ĵ�Ҳ��num1��
	printf("���¸�ֵ��\n"); 
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",num1,ptr1);
	printf("num1��ֵ��%d\tnum1��ַ��%p\n",*ptr2,ptr2);
	//��ʱnum1=*ptr1=*ptr2��ptr1��ptr2��ָ��num1
	//ָ�벻��ʱ����ָ����Ϊ��
	ptr1=NULL; 
	 
	 
	 
	 
}
