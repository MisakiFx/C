#include <stdio.h>
/*A、B、C、D、E 五人在某天夜里合伙去捕鱼，到第二天凌晨时都疲惫不堪，
于是各自找地方 睡觉。日上三杆，A 第一个醒来，他将鱼分为五份，把多余的一条鱼扔掉，拿走自己的一份。B 第
二个醒来，也将鱼分为五份，把多余的一条鱼扔掉，拿走自己的一份。 C、D、E 依次醒来，
也按同 样的方法拿鱼。问他们合伙至少捕了多少条鱼? */
int main()
{
	int x, n, i, flag = 1;
	for(n = 6; flag; n++)
	{
		for(x = n, i = 1 ; i <= 5; i++)
		{
			if((x - 1) % 5 == 0)
			{
				x = (x - 1) / 5 * 4;
			}
			else 
			{
				flag = 0;
				break;
			} 
		}
		if(flag) break;
		else flag = 1;
	}
	printf("鱼有%d只",n);
}
