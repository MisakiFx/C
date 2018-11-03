#include <stdio.h>
int main()
{
	int choice,result;
	printf("请输入1-5之间的数字：");
	while((result=scanf("%d",&choice))!=1||choice<1||choice>5)//当用户输入的值不合法时重新输入
    {
        if(result!=1)//如果用户输入的不是数字类型
        {
            scanf("%*s");//用来处理非整数的输入，*表示输入项在读入后不赋值给对应的变量，取消将字符赋值给choice
            fflush(stdin);//连用，固定形式 
        }
        printf("必须输入1-5之间的整数：");
    }
 } 
