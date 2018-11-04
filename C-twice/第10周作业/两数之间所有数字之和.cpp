#include <stdio.h> 
#include <conio.h>   
int main()   
{      
	int n,m;      
	int sum;  
	/************found************/      
	sum = 0;             
	printf("\nInput n,m\n");      
	scanf("%d,%d",&n,&m);      
	while( n<=m )      
	{  
		/************found************/          
		sum += n;             
		n++;      
	}      
	printf("sum=%d \n",sum);   
} 
