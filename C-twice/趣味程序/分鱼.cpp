#include <stdio.h>
/*�ס��ҡ�����λ�����������㣬�����洬����21ֻ���
������ʱ�����Ƿ�����7��װ�� ���㣬����7��ֻװ�˰���㣬����7�����ǿյġ�
��������û�гӣ�ֻ��ͨ��Ŀ����Ϊ7�����������������ȵģ�7����������������ȵġ�
�ڲ����㵹������ǰ���£���������Ϳ�ƽ��Ϊ����? */
int main()
{
	int i, k, j, m, flag = 1, count = 0,n; 
	int mean[3][3];
	for(i = 0; i <= 3; i++)
	{
		mean[0][0] = i;
		for(j = 0; j <= 7 - i && j <= 3; j++)
		{
			mean[1][0] = j;
			if(mean[2][0] = (7 - j - mean[0][0]) > 3) continue;
			if(mean[2][0] < mean[1][0]) break;
			for(k = 1; k <= 7; k++)
			{
				mean[0][1] = k;
				for(m = 1; m <= 7 - k; m++)
				{
					mean[1][1] = m;
					mean[2][1] = 7 - mean[0][1] - mean[1][1];
					for(n = 0, flag = 1; flag && n < 3; n++)
					{
						if(mean[n][0] + mean[n][1] < 7 && mean[n][0] * 2 + mean[n][1] == 7)
						{
							mean[n][2] = 7 - mean[n][0] - mean[n][1];
						}
						else
						{
							flag = 0;
						}
					}
					if(flag)
					{
						printf("��%d��������\n��\t��\t��\n",++count);
						for(n = 0; n < 3; n++)
						{
							printf("%d\t%d\t%d\n",mean[n][0],mean[n][1],mean[n][2]);
						}
					}
				}
			}
		}
	}
} 
