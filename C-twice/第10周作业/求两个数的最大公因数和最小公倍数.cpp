#include <math.h>   
#include <conio.h>  
#include <stdio.h>   
int main()   
{ 
	int x,y,t,max,min,i,n1,n2;     
	printf("Please enter two numbers:");     
	scanf("%d,%d",&x,&y);     
	if(x > y)      
	{
		t = x; x = y; y = t;
	}     
	n1=x; 
	n2=y;     
	t = n2 % n1;   
	/************found************/     
	while(t)     
	{       
		n2 = n1 ;       
		n1 = t ;       
		t = n2 % n1;     
	}   
	/************found************/     
	max = n1;     
	min = x * y / max ; 
	printf("max is : %d\n",max);    
	printf("min is : %d\n",min); 
} 
