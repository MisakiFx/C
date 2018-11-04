#include <stdio.h>   
long sum(int a,int n) 
{
	int i;
	long j = 0, h = 1, sum = 0; 
 	for(i = 1; i <= n; i++)
 	{
 		j = j + h * a;
 		sum += j;
 		h = h * 10;
	}
	return sum;
} 
 
 
int main() 
{         
	int a , n;         
	printf("Input a,n: ");         
	scanf("%d,%d", &a, &n);                 
	printf("sum=%ld\n",sum(a,n)); 
}
