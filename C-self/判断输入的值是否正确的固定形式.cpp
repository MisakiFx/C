#include <stdio.h>
int main()
{
	int choice,result;
	printf("������1-5֮������֣�");
	while((result=scanf("%d",&choice))!=1||choice<1||choice>5)//���û������ֵ���Ϸ�ʱ��������
    {
        if(result!=1)//����û�����Ĳ�����������
        {
            scanf("%*s");//������������������룬*��ʾ�������ڶ���󲻸�ֵ����Ӧ�ı�����ȡ�����ַ���ֵ��choice
            fflush(stdin);//���ã��̶���ʽ 
        }
        printf("��������1-5֮���������");
    }
 } 
