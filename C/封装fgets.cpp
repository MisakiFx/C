#include <stdio.h>
#include <string.h>
//封装fgets,用来接收字符串的字符数组，接收的字符总数 
void GetString(char [],int);
int GetStrLength(char []);

int main()
{
	int count;
	char names[50];
	printf("请输入名称：");
	GetString(names,10);
	printf("Name:");
	puts(names);
	count=GetStrLength(names);
	printf("有%d个字符\n",count);
} 
int GetStrLength(char str[])
{
	int count=0;
	while(str[count]!='\0')
	{
		count++;
	}
	return count;
}
void GetString(char str[],int count)
{
	//使用fgets函数接收字符串，使用\0替换字符数组的最后一位\n
	fgets(str,count,stdin);
	//查找里面的元素|n
	char * find=strchr(str,'\n');//查找'\n'字符，并返回其指针 
	if(find)
	{
		*find='\0';//根据指针将找到的元素修改为\0 
	} 
} 
