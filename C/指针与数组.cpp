#include <stdio.h>
int main()
{
	int i;
	//�������������ڴ�ռ䣬�����������ڴ�ռ���׵�ַ
	double score[]={98,87,65,43,76};
	//double *ptr_score=&score[0]��&score[0]�ȼ۴�ʱҲ��score�ȼ� 
	printf("������׵�ַΪ��%p\t�������Ԫ�صĵ�ַΪ��%p\n",score,&score[0]); 
	//************************************************************
	//************************************************************
	//ָ����Բ�������
	double *ptr_score;
	ptr_score=score;
	printf("����Ϊ��\n");
	
	for(i=0;i<5;i++)
	{
		printf("%.0lf\t",*ptr_score++);//++�ں������Ȳ�����������������+1 
		//һ������ΪT��ָ����ƶ�����sizeof(T)Ϊ�ƶ���λ
		//���磬doubleָ��һ���ƶ�8��byte
	}
	printf("\n");
	ptr_score=score;
	for(i=0;i<5;i++)
	{
		//����������һ��ָ�룬���Դ�ӡ����Ҳ����������ӡ 
		printf("%.0lf\t",ptr_score[i]);
		//��scoreָ�����ptr_score��ptr_score[]Ҳ������Ϊ����ʹ�� 
	}
	printf("\n");
	ptr_score=score;
	for(i=0;i<5;i++)
	{
		//������������ӡ 
		printf("%.0lf\t",*(ptr_score+i));
		//�Ƽ�����ָ���ӡ��ʽ��ָ�뱾���������仯 
	}
	printf("\n");
	//********************************************************
	//ָ���������ӻ��ĳ������ֵ
	ptr_score+=2;
	printf("%.0lf\n",*ptr_score); 
	ptr_score++;
	printf("%.0lf\n",*ptr_score); 
	ptr_score-=3;
	printf("%.0lf\n",*ptr_score); 
	
}
