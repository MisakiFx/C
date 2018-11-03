#include<stdio.h> 
long int fun(int n) 
{   
	long int sum = 0;
	int j = 1, i;
	for(i = 1; i <= n; i++)
	{
		j = j * i;
		sum += j;
	}
	return sum;
 
} 
int main() 
{   
	int n;   
	long int result;   
	scanf("%d",&n); 
	result=fun(n);   
	printf("%ld\n",result); 
} 
