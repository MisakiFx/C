#include <stdio.h> 
#define N 3   
int fun(int  t[][N], int n)   
{       
	int  i, sum;  
	/************found************/      
	sum = 0;     
	for(i=0; i<n; i++)  
	/************found************/           
	sum+=t[i][i];           
	for(i=0; i<n; i++)           
	sum+= t[i][n-i-1] ;          
	return sum;   
}   
int main()   
{       
	int  t[][N]={1,2,3,4,5,6,7,8,9},i,j;       
	for(i=0; i<N; i++)       
	{           
		for(j=0; j<N; j++)               
		printf("%4d",t[i][j]);           
		printf("\n");      
	}       
	printf("The result is:  %d\n",fun(t,N));      
}
