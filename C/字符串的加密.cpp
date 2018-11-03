#include <stdio.h>
#include <string.h>
#define KEY 5//偏移量/密钥 
//字符串的加密与解密
//加密方式：将字符串中每个字符加上他在字符串中的位置和一个便宜量(5)
//例如：xuetan9中，第一个字符串x在字符串中的位置是0，那么对应的密文为'm'+0+5 
//解密不过是把加密算法中'+'全部改成'-' 
/**
*加密传入的字符串
*参数1：要加密的字符串
*返回值：返回加密后的字符串 
**/
char * encrypt(char []);
char * dencrypt(char []);
int main()
{
	char password[50]="123456";
	encrypt(password);
	printf("加密后的数组是：%s\n",password);
	dencrypt(password);
	printf("解密后的数组是：%s\n",password);
}
char * encrypt(char password[])
{
	int i;
	int count=strlen(password);
	for(i=0;i<count;i++)
	{
		password[i]=password[i]+i+KEY;
	}
	//字符串末尾有'\0'需不需要替换？- - 不需要
	return password; 
}
char * dencrypt(char password[])
{
	int i;
	int count=strlen(password);
	for(i=0;i<count;i++)
	{
		password[i]=password[i]-i-KEY;
	}
	//字符串末尾有'\0'需不需要替换？- - 不需要
	return password; 
}
