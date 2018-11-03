#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fun(char *ss)
{
    /**********Program**********/
	int i = 0;
	while(ss[i] != '\0')
	{
		if(ss[i] >= 'a' && ss[i] <= 'z' && i % 2 != 0)
		{
			ss[i] = ss[i] - 32;
		}
		i++;
	}
    /**********  End  **********/
}
int main()
{

    char tt[81];
    system("CLS");
    printf("\nPlease enter an string within 80 characters:\n");
    gets(tt);
    printf("\n\nAfter changing, the string\n  %s",tt);
    fun(tt);
    printf("\nbecomes\n %s\n",tt);

}

