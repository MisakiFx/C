#include <conio.h>   
#include <stdio.h>   
int main()   
{     
	int a[3][3]={4,4,34,37,3,12,5,6,5},i,j,max,min;     
	max = min = a[0][0];     
	for ( i=0; i<3; i++)   
	/************found************/      
	for ( j=0; j<3; j++)      
	{ 
		if ( max < a[i][j] )          
		max = a[i][j];   
		/************found************/        
		if (min > a[i][j])           
		min = a[i][j];       
	}      
	printf("The max is: %d\n", max);      
	printf("The min is: %d\n", min);   
}
