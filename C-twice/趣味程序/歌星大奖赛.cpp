#include <stdio.h>
int main()
{
/*�ڸ��Ǵ����У��� 10����ίΪ������ѡ�ִ�֣�����Ϊ1�� 100 �֡�
ѡ�����÷�Ϊȥ��һ����߷ֺ�һ����ͷֺ����� 8 ��������ƽ��ֵ�����дһ������ʵ�֡� 
*/
	//��Ϊ�򵥿�ݵĳ������
	int integer,i,max,min,sum;
	max = -32768;
	min = 32767;
	for(i = 1;i <= 10; i++)
	{
		printf("������ɼ���");
		scanf("%d",&integer);//��ѭ���и�ֵ 
		sum += integer;
		if(integer > max) max = integer;
		if(integer < min) min = integer;//ÿ��һ��ֵ�ͱȽ�һ���ҵ������Сֵ 
	}
	printf("��߷֣�%d\n��ͷ֣�%d\n",max,min);
	printf("���շ�����%d",(sum - max - min) / 8); 
	//ʱ�临�Ӷ�Ϊ���Խ� 
 } 
