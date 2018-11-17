#include <stdio.h>
/*已知鸡和兔的总数量为n，总腿数为m。输入n和m，
依次输出鸡的数目和兔的数目。
如 果无解，则输出No answer*/
/*两种做法：1、连立方程式
2、利用循环一个一个试*/
int main()
{
	int a, b, n ,m;
	scanf("%d%d",&n, &m);
	a = (4 * n - m) / 2;
	b = n - a;
	if(m % 2 ==1 || a < 0 || b < 0)
	{
		printf("No answer\n");
	}
	else 
	{
		printf("%d %d",a, b);
	 } 
}
