#include <stdio.h>
int count=0;//���ⲿ����ȫ�ֱ��� ��ȫ�ֱ��������ǲ�����ֵ��ϵͳ�Զ�Ҳ�����Ĭ��ֵ 
//ȫ�ֱ������������ǵ�ǰԴ�ļ� 
void changeNum()
{
	count++;
 } 
int main()
{
	changeNum();
	changeNum();
	printf("%d",count);
} 
