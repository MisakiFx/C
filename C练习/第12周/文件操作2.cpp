#include <stdio.h>
int main()
{
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	int count = 0;
	int nums[100];
	if((fp1 = fopen("D:\\Studyfile\\�������ҵ\\��12��\\1.txt","r")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return 1;
	} 
	for(int i = 0; i < 100; i++)
	{
		fscanf(fp1,"%d",&nums[i]);
	}
	fclose(fp1);
	for(int i = 0; i < 100; i++)
	{
		printf("%d\t",nums[i]);
	}
	printf("\n");
	for(int i = 0 ; i < 99; i++)
	{
		int min = i;
		for(int j = i;j < 100; j++)
		{
			if(nums[j] < nums[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int t = nums[i];
			nums[i] = nums[min];
			nums[min] = t;
		}
	}
	if((fp2 = fopen("D:\\Studyfile\\�������ҵ\\��12��\\2.txt","w")) == NULL)
	{
		printf("�ļ�2��ʧ�ܣ�");
		return 2;
	}
	for(int i = 0; i < 100; i++)
	{
		fprintf(fp2,"%d\t",nums[i]);
		count++;
		if(count % 10 == 0)
		{
			fprintf(fp2,"%c",'\n');	
		}
	}
	fclose(fp2);
}
