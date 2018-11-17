#include <stdio.h>
/**假设银行一年整存零取的月息为 0.63% 。
现在某人手中有一笔钱，他打算在今后的五年 中每年的年底取出 1000 元，到第五年时刚好取完，请算出他存钱时应存入多少。 */
int main()
{
	double money;
	for(int i = 1; i <= 5; i++)
	{
		money = (money + 1000) / (1 + 12 * 0.0063);
	}
	printf("应存入：%lf",money);
}
