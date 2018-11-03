#include <stdio.h>
void fun(int *a,int *b)
{
/**********Program**********/
	int t;
	t = *a;
	*a = *b;
	*b = t;
/********** End **********/
}
int main()
{
int a,b;
printf("Enter a,b:");
scanf("%d%d",&a,&b);
fun(&a,&b);
printf("a=%d b=%d\n",a,b);
}

