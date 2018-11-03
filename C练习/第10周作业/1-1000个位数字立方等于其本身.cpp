#include <stdio.h>   
int main()   
{       
	int i,g;       
	for(i=1;i<1000;i++)            
	{  
		/************found************/           
		g=i % 10;    
		/************found************/             
		if(g * g * g == i)                   
		printf("%4d",i);       
	}       
	printf("\n"); 
}
