#include <stdio.h>
//Ƕ�׽ṹ
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
	//���Player
	//����������������ɣ����壬��Ӫ��
	struct Player player={1,"Misaki","123456",'m',{1,"loli��ʤ",500,1}}; 
	printf("%s\t%s\n",player.name,player.martial.name);
}
