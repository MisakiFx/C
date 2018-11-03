#include <stdio.h>
#include <string.h>
#define USER_NAME "Misaki"
#define PASSWORD "Misaki"
#define N 3
char * MyFgets(char [],int);
int login(char[],char[]);//验证传入的用户名和密码是否正确
int login(char userName[],char password[])//验证传入的用户名和密码是否正确
{
	//参数1：需要验证的用户名
	//参数2：需要验证的密码
	//返回：如果合法，返回1，否则，返回2
	int result=0;
	if(strcmp(userName,USER_NAME)==0&&strcmp(password,PASSWORD)==0)//别忘了要==0 (谁在前在后没关系)
	{
		result=1;//验证合法 
	}
	return result; 
 } 
int main()
{
	//常用字符串处理函数，在<string.h>头文件中
	char word1[50]="Misaki";
	char word2[]={'M','i','s','a','k','i','\0'};
	char word3[]="你好，见崎鸣！";//一个中文字符有两个字节
	char userName[50];
	char password[50]; 
	int count=0;
	//strlen函数，量取字符串长度，不算'\0' 
	printf("word1的长度是：%d\n",strlen(word1)); 
	printf("word2的长度是：%d\n",strlen(word2)); 
	printf("word3的长度是：%d\n",strlen(word3)); 
	printf("*******************************************\n"); 
	//字符串复制，由于数组名都有常量特性，数组名不能随意更改（word1=word2是不行的）
	//数组的复制原理，每个元素逐个进行复制，或者使用strcpy函数
	strcpy(word1,word3);//让word1里的内容等于word3,将word3里的元素包括'\0'完整的复制到word1中 （word1=word3） 
	puts(word1);
	printf("%s\n2",word3);
	printf("********************************************\n"); 
	//字符串的比较，两个字符串从首字母开始，按照ASCII码的顺序逐个比较
	//如果相等返回0，字符串1>字符串2，返回正数，否则返回负数
	//验证用户名和密码
	do
	{
		printf("请输入用户名：");
		scanf("%s",userName);
		printf("请输入密码：");
		scanf("%s",password);
		if(login(userName,password)==1)
		{
			printf("登陆成功！\n");
			break;
		} 
		else
		{
			printf("用户名或密码输入错误，请重新输入！\n");
			count++;
			printf("还有%d次机会！\n",N-count);
		}
		if(count==3)
		{
			printf("登录失败，你滚吧！");
		}
	}while(login(userName,password)==0&&count<N);
	printf("************************************************\n");
	//字符串连接：strcat(str1,str2);
	//要保证拼接后，1号字符串空间足够
	strcat(word1,word2); //将word1与word2拼接起来
	printf("word1:%s\tword2:%s\t",word1,word2); //将word2中的字符串拼接到word1后面 （2拼到1后面） 
	 
}
