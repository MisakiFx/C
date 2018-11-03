#include <stdio.h>
int fun(int n) 
{ 
	int sum = (1 + n) * n / 2;
	return sum;
} 
int main() 
{ 
	int m; 
	printf("Enter m: "); 
	scanf("%d", &m); 
	printf("\nThe result is %d\n", fun(m)); 
} 
