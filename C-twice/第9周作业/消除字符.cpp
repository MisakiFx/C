#include <stdio.h>
void fun(char s[],char c)
{
	/**********Program**********/
	int i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == c)
		{
			int j = i;
			while(s[j] != '\0')
			{
				s[j] = s[j + 1];
				j++;
			}
			continue;
		}
		i++;
	}
	s[i] = '\0'; 
	/********** End **********/
}
int main()
{
	static char str[]="turbo c and borland c++";
	char c='a';
	fun(str,c);
	printf("str=%s\n",str);
}

