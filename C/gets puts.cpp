#include <stdio.h>
#include <string.h> 
int GetStrLength(char []);//输入一个字符串，返回传入字符串的长度 
int main()
{
	char names1[50];
	char names2[50]="Misaki";
	int len=GetStrLength(names2);
	printf("%d\n",len);
	printf("请输入名称：");
	gets(names1);//相当于scanf("%s\n",names1);
	//gets函数不对接收字符串的buffer进行边界检测，会造成越界，从而产生bug 
	puts(names1);//相当于printf("%s\n",names1); 
	//可以使用fgets代替gets进行边界检测
	fgets(names1,10,stdin);//最多可以读入10-1个字符，还有一个空字符 
	printf("数组names1中的内容：\n");
	printf("%s",names1);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"); 
	for(int i=0;i<50;i++)
	{
		printf("%d\n",names1[i]);
	}
	//fgets会默认给最后一个元素设置为\n  
}
int GetStrLength(char str[])//输入一个字符串，返回传入字符串的长度 
{
	int count =0;//字符个数
	while(str[count]!='\0')//当字符串中不为空字符，继续循环 
	{
		count++;
	}
	return count; 
}
