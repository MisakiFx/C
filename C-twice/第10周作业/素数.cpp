#include <stdio.h>  
#include <math.h>   
int main()   
{     
	int m,j,n=0,k;     
	for(m=200;m<=300;m++)     
	{       
		k=sqrt(m);       
		for(j=2;j<=k;j++)  
		/************found************/         
		if(m%j==0) break;       
		if(j<=k)   
		{ 
			if(n%8==0) 
			printf("\n");   
			/************found************/         
			printf("%d,",m);         
			n++;       
		}     
	}   
}
