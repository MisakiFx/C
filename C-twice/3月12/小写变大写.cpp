#include <stdio.h>
#include <ctype.h>
int main()
{
	char c, m;
	printf("������һ��Сд��ĸ:");
	scanf("%c",&c); 
	if(islower(c))
	{
		m = c - 32;//m = toupper(c)
		printf("%c",m);
	}
	else
	{
		printf("������ǷǷ��ַ�");
	}
} 
