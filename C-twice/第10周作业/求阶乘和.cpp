#include <stdio.h>    
int fun(int n)   
{       
	int  i;       
	int s;       
	s=1;            
	for (i=1; i<=n; i++)  
	/************found************/           
	s = s * i;           
	return s;   
}   
int main()   
{       
	int s;       
	int  k,n;       
	scanf("%d",&n);       
	s=0;            
	for (k=0; k<=n; k++)  
	/************found************/           
	s = s + fun(k);           
	printf("%d\n", s);   
} 
