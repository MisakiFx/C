#include <stdio.h>
#include <string.h>
//��װfgets,���������ַ������ַ����飬���յ��ַ����� 
void GetString(char [],int);
int GetStrLength(char []);

int main()
{
	int count;
	char names[50];
	printf("���������ƣ�");
	GetString(names,10);
	printf("Name:");
	puts(names);
	count=GetStrLength(names);
	printf("��%d���ַ�\n",count);
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
	//ʹ��fgets���������ַ�����ʹ��\0�滻�ַ���������һλ\n
	fgets(str,count,stdin);
	//���������Ԫ��|n
	char * find=strchr(str,'\n');//����'\n'�ַ�����������ָ�� 
	if(find)
	{
		*find='\0';//����ָ�뽫�ҵ���Ԫ���޸�Ϊ\0 
	} 
} 
