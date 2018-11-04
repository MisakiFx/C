#include <math.h>  
#include <conio.h>   
#include <stdio.h>  
int  main()   
{ 
	int a[12]={2,3,5,7,8,9,10,11,12,13,15,17},i,j,k,s;   
	/************found************/     
	s = 0;     
	for ( i=0; i<12; i++)     
	{       
		k=sqrt(a[i]);       
		for ( j=2;j <= k; j++)  
		if (a[i] % j == 0)           
		break;       
		if( j<=k )   
		/************found************/    
		s=s+a[i];       
		}    
	printf("Sum is: %d\n",s); 
}
