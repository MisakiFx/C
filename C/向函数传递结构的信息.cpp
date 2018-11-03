#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//银行系统 
struct Account 
{
	char *bankName;
	char *userName;
	double limit;
	double billAmount;
};
double GetRepayment(Account);//这里加不加struct都可以 
double GetRepayment1(double,double); 
double GetRepayment2(const Account*);//最好在定义和声明的时候加const防止结构体内的值被修改

int main()
{
	//结构作为函数参数的三种方式
	//1.传递结构的成员（按照普通方式进行传递） 
	//2.传递结构
	//3.传递结构的地址
	struct Account zsAcc;
	zsAcc.bankName=(char*)malloc(50);
	zsAcc.userName=(char*)malloc(50);
	zsAcc.bankName="招商银行";
	zsAcc.userName="Misaki";
	zsAcc.limit=50000;
	zsAcc.billAmount=35000;
	double result=GetRepayment(zsAcc);//结构体的整体传递
	double result1=GetRepayment1(zsAcc.limit,zsAcc.billAmount);//结构体的成员单独传递
	double result2=GetRepayment2(&zsAcc);//以结构的指针方式进行传递 
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
double GetRepayment2(const struct Account *account)//最好在定义和声明的时候加const防止结构体内的值被修改 
{
	return account->limit-account->billAmount;
}
