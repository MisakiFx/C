#include <stdio.h>
/*100!��ĩβ�ж��ٸ�0*/
/*һ�������ж��ٸ�����5���Ľ׳�ĩβ���ж��ٸ�0*/
int main()
{
	int a, count = 0;
	for(a = 5; a <= 100; a += 5)
	{
		count++;
		if((a % 25) == 0) count++;
	}
	printf("ĩβ0�ĸ���Ϊ��%d",count);
}
