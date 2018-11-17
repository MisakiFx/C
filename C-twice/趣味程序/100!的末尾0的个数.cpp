#include <stdio.h>
/*100!的末尾有多少个0*/
/*一个数中有多少个因子5它的阶乘末尾就有多少个0*/
int main()
{
	int a, count = 0;
	for(a = 5; a <= 100; a += 5)
	{
		count++;
		if((a % 25) == 0) count++;
	}
	printf("末尾0的个数为：%d",count);
}
