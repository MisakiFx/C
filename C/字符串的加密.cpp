#include <stdio.h>
#include <string.h>
#define KEY 5//ƫ����/��Կ 
//�ַ����ļ��������
//���ܷ�ʽ�����ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��������(5)
//���磺xuetan9�У���һ���ַ���x���ַ����е�λ����0����ô��Ӧ������Ϊ'm'+0+5 
//���ܲ����ǰѼ����㷨��'+'ȫ���ĳ�'-' 
/**
*���ܴ�����ַ���
*����1��Ҫ���ܵ��ַ���
*����ֵ�����ؼ��ܺ���ַ��� 
**/
char * encrypt(char []);
char * dencrypt(char []);
int main()
{
	char password[50]="123456";
	encrypt(password);
	printf("���ܺ�������ǣ�%s\n",password);
	dencrypt(password);
	printf("���ܺ�������ǣ�%s\n",password);
}
char * encrypt(char password[])
{
	int i;
	int count=strlen(password);
	for(i=0;i<count;i++)
	{
		password[i]=password[i]+i+KEY;
	}
	//�ַ���ĩβ��'\0'�費��Ҫ�滻��- - ����Ҫ
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
	//�ַ���ĩβ��'\0'�費��Ҫ�滻��- - ����Ҫ
	return password; 
}
