#include <stdio.h>
#include <math.h>
double calcCircle(double);//����Բ�������
int validate(double);//��֤����������Ƿ�������
double calcRectangle(double,double);//��������������
double calcTangle(double,double); 
int main()
{
	//����Բ�����Σ������������ʹ�ò�ͬ�ķ�����
	//��Ϊ���������������ͨ�õĹ��ܣ����գ���ӡ����ͨ�õĹ��ܶ����Խ�����дΪ������ε��� 
	double r;//�뾶 
	double width,height;//��͸�
	double bottom,high;//�����ε׺͸� 
	double s;//ͼ�����
	int choice;//ѡ�� 
	printf("��ϵͳ֧�ּ�������ͼ�ε��������ѡ��\n");
	printf("1.Բ\n");
	printf("2.����\n");
	printf("3.������\n");
	printf("��ѡ��");
	do{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("������Բ�뾶��");
				do{		//��Ҫ���û���������ݽ��зǸ��ж� 
					scanf("%lf",&r);
					if(!validate(r))
					{
						printf("�㶺���أ���ô���䣺"); 
					}
				}while(!validate(r));
				s=calcCircle(r); //����Բ������㺯��
				printf("Բ�����Ϊ��%.2lf",s); 
				break;
			case 2:
				printf("��������εĳ��Ϳ�");
				do{
				scanf("%lf%lf",&width,&height);
				if(!validate(width) || !validate(height))
				{
					printf("�������أ���ô���䣺");
				}
				}while(!validate(width) || !validate(height));
				s=calcRectangle(width,height);
				printf("���ε�����ǣ�%.2lf",s);
				break;
			case 3:
				printf("�����������εĵ׺͸ߣ�");
				do{
					scanf("%lf%lf",&bottom,&high);
					if(!validate(bottom) || !validate(high))
					{
						printf("�������أ����䣺");
					}
				}while(!validate(bottom)|| !validate(high));
				s=calcTangle(bottom,high);
				printf("�����ε�����ǣ�%lf",s); 
				break;
			default:
				printf("��ϵͳĿǰֻ֧������ͼ�ε�������㣬������ѡ��");
		 } 
	}while(choice!=1&&choice!=2&&choice!=3);
 } 
double calcCircle(double r)
{
	double s=3.14*pow(r,2);
	return s;//������� 	
}
int validate(double num)
{
	return num>0;//���num����0����һ����0ֵ��ʾΪ�� 
}
double calcRectangle(double width,double height)
{
	return width*height;
}
double calcTangle(double bottom,double high)
{
	return (bottom*high)/2;
}
