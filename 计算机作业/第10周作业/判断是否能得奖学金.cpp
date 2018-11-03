#include <stdio.h>   
int main()   
{      
	int score,sum=0;     
	int i,n=0;     
	for(i=1;i<=5;i++)     
	{ 
		scanf("%d",&score);       
		sum+=score;   
		/************found************/       
		if(score>=88) 
		n++;     
	}   
	/************found************/     
	if(sum>=450 || n==5 )       
	printf("The student is very  good!\n");     
	else        
	printf("The student is not very good!\n");   
}
