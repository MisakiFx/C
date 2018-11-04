#include <stdio.h>//输入字符和行数，有惊喜哦。。 
void Star(char c,int m)
{
	int t;
	for(t=1;t<=m;t++)
	{
		printf("%c",c);
	}
}
void Space(int n)
{
	int i;
	for(i=1;i<=n;i++) 
	{
		printf("%c",' ');
	}
}
int main()
{
	int m,n,a=1,q,p=1;
	char c;
	scanf("%c %d",&c,&n);
	Space(n-1);
	printf("%c\n",c);
	q=n-2;
	while(p<n-1)
	{
		Space(q);
		printf("%c",c);
		Space(a);
		printf("%c\n",c);
		a+=2; 
		q--;
		p++;
	}
	Star(c,2*n-1);
	
 } 
