#include <stdio.h>  
/************found************/   
double fun(int n)      
{       
	int i,j;      
	double sum=0.0, t; 
	for(i=1;i<=n;i++)      
	{          
		t=0.0;     
		for(j=1;j<=i;j++)  
		/************found************/              
		t += j;             
		sum+= 1.0/t;         
	}      
	return sum;   
}   
int main()   
{      
	int  n;   
	double  s;      
	printf("\nInput n:  ");      
	scanf("%d",&n);      
	s=fun(n);      
	printf("\n\ns=%f\n\n",s); 
} 
