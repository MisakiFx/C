#include <stdio.h>
#include <string.h>
#define USER_NAME "Misaki"
#define PASSWORD "Misaki"
#define N 3
char * MyFgets(char [],int);
int login(char[],char[]);//��֤������û����������Ƿ���ȷ
int login(char userName[],char password[])//��֤������û����������Ƿ���ȷ
{
	//����1����Ҫ��֤���û���
	//����2����Ҫ��֤������
	//���أ�����Ϸ�������1�����򣬷���2
	int result=0;
	if(strcmp(userName,USER_NAME)==0&&strcmp(password,PASSWORD)==0)//������Ҫ==0 (˭��ǰ�ں�û��ϵ)
	{
		result=1;//��֤�Ϸ� 
	}
	return result; 
 } 
int main()
{
	//�����ַ�������������<string.h>ͷ�ļ���
	char word1[50]="Misaki";
	char word2[]={'M','i','s','a','k','i','\0'};
	char word3[]="��ã���������";//һ�������ַ��������ֽ�
	char userName[50];
	char password[50]; 
	int count=0;
	//strlen��������ȡ�ַ������ȣ�����'\0' 
	printf("word1�ĳ����ǣ�%d\n",strlen(word1)); 
	printf("word2�ĳ����ǣ�%d\n",strlen(word2)); 
	printf("word3�ĳ����ǣ�%d\n",strlen(word3)); 
	printf("*******************************************\n"); 
	//�ַ������ƣ��������������г������ԣ�����������������ģ�word1=word2�ǲ��еģ�
	//����ĸ���ԭ��ÿ��Ԫ��������и��ƣ�����ʹ��strcpy����
	strcpy(word1,word3);//��word1������ݵ���word3,��word3���Ԫ�ذ���'\0'�����ĸ��Ƶ�word1�� ��word1=word3�� 
	puts(word1);
	printf("%s\n2",word3);
	printf("********************************************\n"); 
	//�ַ����ıȽϣ������ַ���������ĸ��ʼ������ASCII���˳������Ƚ�
	//�����ȷ���0���ַ���1>�ַ���2���������������򷵻ظ���
	//��֤�û���������
	do
	{
		printf("�������û�����");
		scanf("%s",userName);
		printf("���������룺");
		scanf("%s",password);
		if(login(userName,password)==1)
		{
			printf("��½�ɹ���\n");
			break;
		} 
		else
		{
			printf("�û�������������������������룡\n");
			count++;
			printf("����%d�λ��ᣡ\n",N-count);
		}
		if(count==3)
		{
			printf("��¼ʧ�ܣ�����ɣ�");
		}
	}while(login(userName,password)==0&&count<N);
	printf("************************************************\n");
	//�ַ������ӣ�strcat(str1,str2);
	//Ҫ��֤ƴ�Ӻ�1���ַ����ռ��㹻
	strcat(word1,word2); //��word1��word2ƴ������
	printf("word1:%s\tword2:%s\t",word1,word2); //��word2�е��ַ���ƴ�ӵ�word1���� ��2ƴ��1���棩 
	 
}
