#include <stdio.h>
//�ṹ���ָ�루�ṹָ�������
//����ָ������е�ֵ����ָ��Ľṹ�������׵�ַ
//struct �ṹ����*�ṹָ�������
struct Martial//���� 
{
	int id;//���ɵı�� 
	char name[50];//���ɵ��˳� 
	int count;//��ǰ���ɵ�������
	int type;//���ɵ����͡���1���ɣ�2������3а��	
};
struct Player
{
	int id;//��ҵı��
	char name[50];//��ҵ�����
	char pass[50];//��ҵĵ�¼����
	char sex;//��ҵ��Ա�
	struct Martial martial;//�����������	
}; 
int main()
{
	struct Player player1={1,"Misaki","123456",'m',{1,"loi��ʤ",500,3}};
	struct Player *ptr_player1=&player1;
	printf("%s\t%s\n",player1.name,player1.martial.name);
	printf("%s\t%s\n",(*ptr_player1).name,(*ptr_player1).martial.name);//ʹ��ָ�������ʣ�������Ҫ��ָ���������������ȷ���ָ��ȡָ���Ӧ��ֵ��
	printf("%s\t%s\n",ptr_player1->name,ptr_player1->martial.name);//������ָ��ֱ�������ʣ�->��ǰ����ָ�������ָ����ָ�����ݵ����������0 
} 
