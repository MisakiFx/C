#include <stdio.h> 
int fun(int n) 
{ 
	int i; 
	int j; 
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			j = 0;
			break;
		}
	}
	if(i == n)
	{
		j = 1;
	} 
	return j; 
}       
int main() 
{ 
	int m,flag;   
	printf("input an integer:");   
	scanf("%d",&m);   
	flag=fun(m);   
	if(flag)     
	printf("%d is a prime.\n",m);   
	else     
	printf("%d is not a prime.\n",m); 
}
