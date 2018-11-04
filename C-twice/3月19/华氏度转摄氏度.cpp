#include <stdio.h>
int main()
{
	double f;//华氏度
	double c;//摄氏度 
	printf("请输入华氏度：");
	scanf("%lf",&f);
	c = (f - 32) / 1.8;
	printf("摄氏度为:%.2lf",c); 
 } 
