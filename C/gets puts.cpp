#include <stdio.h>
#include <string.h> 
int GetStrLength(char []);//����һ���ַ��������ش����ַ����ĳ��� 
int main()
{
	char names1[50];
	char names2[50]="Misaki";
	int len=GetStrLength(names2);
	printf("%d\n",len);
	printf("���������ƣ�");
	gets(names1);//�൱��scanf("%s\n",names1);
	//gets�������Խ����ַ�����buffer���б߽��⣬�����Խ�磬�Ӷ�����bug 
	puts(names1);//�൱��printf("%s\n",names1); 
	//����ʹ��fgets����gets���б߽���
	fgets(names1,10,stdin);//�����Զ���10-1���ַ�������һ�����ַ� 
	printf("����names1�е����ݣ�\n");
	printf("%s",names1);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"); 
	for(int i=0;i<50;i++)
	{
		printf("%d\n",names1[i]);
	}
	//fgets��Ĭ�ϸ����һ��Ԫ������Ϊ\n  
}
int GetStrLength(char str[])//����һ���ַ��������ش����ַ����ĳ��� 
{
	int count =0;//�ַ�����
	while(str[count]!='\0')//���ַ����в�Ϊ���ַ�������ѭ�� 
	{
		count++;
	}
	return count; 
}
