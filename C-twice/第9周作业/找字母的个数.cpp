#include <stdio.h>
int fun(char s[])
{
	/**********Program**********/
	int i = 0, k = 0;
	while(s[i] != '\0')
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		k++;
		i++;
	}
	return k; 
	/********** End **********/
}
int main()
{
char str[]="Best wishes for you!";
int k;
k=fun(str);
printf("k=%d\n",k);
}

