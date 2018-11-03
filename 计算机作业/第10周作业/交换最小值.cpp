#include <conio.h>   
#include <stdio.h>   
#define  N   20   
int main()   
{     
	int a[N]={7,10,12,0,3,6,9,11,5,8}, n=10, i, k,m,min,t;     
	for ( i = 0; i<n; i++) 
	printf("%d  ",a[i]);      
	printf("\n");     
	min= a[0]; 
	m=0;     
	for ( k = 0; k < n; k++ )  
	/************found************/               
	if (a[k]<min )       
	{          
		min = a[k];  
		m = k;       
	}   
	/************found************/     
	t = a[0]; 
	a[0]=a[m]; 
	a[m] = t;     
	for ( i=0; i<n; i++ ) 
	printf("%d  ",a[i]); 
	printf("\n"); 
}
