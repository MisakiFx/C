#include <stdio.h>
#include <stdlib.h> 
int main()
{
	//��̬�����ڴ棬malloc����
	//��̬�����ڴ棺����ʱû���ڴ棬�������к��ٷ����ڴ�
	//��ʾ��̬�����ڴ�
	int *nums;
	int *nums2;
	int i;
	nums=(int*)malloc(sizeof(int)*5);//Ϊǰ���ָ�붯̬������5�����θ��ֽڵĶ�̬�ռ䣨����ָ�������������������ֵ�λ���ֽ� 
	//Ҳ���Ա�ʾΪ��nums=(int*)malloc(20);������͵��ֽ���=4*5=20  
	//�ȼ��ڣ�int nums[5];��������������� 
	for (i=0;i<5;i++)
	{
		printf("�������%d��Ԫ�أ�",i+1);
		scanf("%d",nums+i);//�ȼ��ڣ�scanf("%d",&*(nums+i));
	}
	printf("����Ԫ��Ϊ��\n");
	for (i=0;i<5;i++)
	{
		printf("%d \t",*(nums+i));
	}
	free(nums);//�ͷŶ�̬������ڴ棨���׵ģ��ǵ��ͷţ������ͷţ���ֹ��ΪҰָ�룩
	nums = NULL;//����ָ�룬��ֹ��ΪҰָ�룬����ָ��ϰ��
	return 0;
	//realloc���·����ڴ�ռ䣬�ɹ��򷵻ط������ڴ�ռ䣬ʧ���򷴻ؿ�ָ��
	nums2=calloc(5,sizeof(int));
	
	 
}
