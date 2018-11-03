#include <math.h>   
#include <conio.h>   
#include <stdio.h>   
int main()   
{ 
	int x,y,t,i;     
	printf("Please enter two numbers:");     
	scanf("%d,%d",&x,&y);     
	if(x < y) 
	/************found************/     
	{
		t = x; 
		x = y ; 
		y = t;
	}     
	t = x % y;     
	while( t )     
	{ 
		x = y;        
		y=t;        
		t = x % y;     
	}   
	/************found************/    
	printf("max is : %d\n",y); 
}
