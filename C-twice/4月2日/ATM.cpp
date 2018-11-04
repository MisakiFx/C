#include <stdio.h>
#include <string.h>
#define PASSWORD "123456"
double money = 100;
int Use()
{
	int choice;
	double money2;
	char id[20];
	printf("请输入操作选项：\n");
	printf("1：查询余额\n");
	printf("2：取款\n");
	printf("3：存款\n");
	printf("4：转账\n");
	printf("5：打印退单\n");
	printf("6：退卡\n"); 
	if(scanf("%d",&choice) != 1)
	{
		printf("操作失败\n");
		return 1;
	}
	switch(choice)
	{
		case 1:
			printf("%.2lf\n",money);
			break;
		case 2:
			printf("请输入取款金额:");
			scanf("%lf",&money2);
			if(money - money2 < 0)
			{
				printf("余额不足！\n");
				break;
			}
			else
			{
				money -= money2;
				printf("取款成功！\n");
			}
			break;
		case 3:
			printf("请输入存款金额:");
			scanf("%lf",&money2);
			money += money2;
			printf("存款成功！\n");
			break;
		case 4:
			printf("请输入转账方账号：");
			scanf("%s",id);
			printf("请输入转账金额：");
			scanf("%lf",&money2);
			if(money - money2 < 0)
			{
				printf("余额不足！\n");
				break;
			}
			printf("转账成功！\n"); 
			break;
		case 5:
			printf("打印清单成功！\n");
			break;
		case 6:
			break;
		default:
			break;
	} 
	return choice;
}
int main()
{
	char pass[7];
	printf("请输入密码:");
	scanf("%s",pass);
	if(strcmp(pass,PASSWORD) != 0)
	{
		printf("输入错误");
		return 1; 
	}
	while(Use() != 6)
	{
		
	}
	printf("操作完成！");
}
