#include <math.h>   
#include <conio.h>   
#include <stdio.h>   
int prinum( int a[])   
{ 
	int count,i,j,k;     
	count = 0;     
	for ( i=0; i<10; i++)     
	{       
		k=a[i]-1;       
		for ( j=2; j<=k; j++)  
		if (a[i] % j == 0)    
		break;       
		if(j >= k+1)         
		count++;        
	}  
	/************found************/        
	return count;   
}   
int main()   
{ 
	int a[10]={2,3,5,7,8,9,10,11,12,13},n;     
	/************found************/     
	n = prinum(a);      
	printf("prime number(s) is(are): %d\n", n );   
} 
