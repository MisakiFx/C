#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ϵͳ 
struct Account 
{
	char *bankName;
	char *userName;
	double limit;
	double billAmount;
};
double GetRepayment(Account);//����Ӳ���struct������ 
double GetRepayment1(double,double); 
double GetRepayment2(const Account*);//����ڶ����������ʱ���const��ֹ�ṹ���ڵ�ֵ���޸�

int main()
{
	//�ṹ��Ϊ�������������ַ�ʽ
	//1.���ݽṹ�ĳ�Ա��������ͨ��ʽ���д��ݣ� 
	//2.���ݽṹ
	//3.���ݽṹ�ĵ�ַ
	struct Account zsAcc;
	zsAcc.bankName=(char*)malloc(50);
	zsAcc.userName=(char*)malloc(50);
	zsAcc.bankName="��������";
	zsAcc.userName="Misaki";
	zsAcc.limit=50000;
	zsAcc.billAmount=35000;
	double result=GetRepayment(zsAcc);//�ṹ������崫��
	double result1=GetRepayment1(zsAcc.limit,zsAcc.billAmount);//�ṹ��ĳ�Ա��������
	double result2=GetRepayment2(&zsAcc);//�Խṹ��ָ�뷽ʽ���д��� 
	printf("%.2lf\n",result);
	printf("%.2lf\n",result1);
	printf("%.2lf",result2);
	return 0;		
}
double GetRepayment(struct Account account)
{
	return account.limit-account.billAmount;
}
double GetRepayment1(double m1,double m2)
{
	return m1-m2;
}
double GetRepayment2(const struct Account *account)//����ڶ����������ʱ���const��ֹ�ṹ���ڵ�ֵ���޸� 
{
	return account->limit-account->billAmount;
}
