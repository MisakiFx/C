#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
//�Զ��庯������Ҫ�أ�����ֵ���͡��������������б�
//ʹ�ú����������ͼ�ε�������㹫ʽ����ӡ������
//Բ������

//�������������Ҫ����ֵô��
//��������ʲô��
//��Ҫ�������������ô��

//����Բ��������޷���ֵ�� 
void calcCircle();//����ԭ�� 
void calcCircle()//����ʵ��
{
	double radius,s;//�뾶����� 
	printf("������Բ�뾶��");
	scanf("%lf",&radius);
	s = 3.14*pow(radius,2);//Բ���
	printf("�뾶Ϊ%.2lf��Բ�����Ϊ��%.2lf\n",radius,s); 
 }
 
 //�������������޷���ֵ�� 
void calcRectangle();//����ԭ��
void calcRectangle()
{
	double width,height,s;//��͸ߺ����
	printf("��������εĿ�͸ߣ�");
	scanf("%lf%lf",&width,&height);
	if(width<0||height<0)
	{
		printf("��͸߲���С��0������");
		return;//��return������ֹ����������ֵ��������0������return 0�� 
	}
	s=width*height;
	printf("���ε�����ǣ�%.2lf",s); 
 } 
 
int main()
{
	calcCircle();//���ü���Բ����ĺ���
	calcRectangle();//���ü�����εĺ��� 
 } 
