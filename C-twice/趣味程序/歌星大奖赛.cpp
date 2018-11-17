#include <stdio.h>
int main()
{
/*在歌星大奖赛中，有 10个评委为参赛的选手打分，分数为1到 100 分。
选手最后得分为去掉一个最高分和一个最低分后其余 8 个分数的平均值。请编写一个程序实现。 
*/
	//更为简单快捷的程序设计
	int integer,i,max,min,sum;
	max = -32768;
	min = 32767;
	for(i = 1;i <= 10; i++)
	{
		printf("请输入成绩：");
		scanf("%d",&integer);//再循环中赋值 
		sum += integer;
		if(integer > max) max = integer;
		if(integer < min) min = integer;//每赋一个值就比较一次找到最大最小值 
	}
	printf("最高分：%d\n最低分：%d\n",max,min);
	printf("最终分数：%d",(sum - max - min) / 8); 
	//时间复杂度为线性阶 
 } 
