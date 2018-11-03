#include <conio.h>   
#include <stdio.h>   
int main()   
{ 
	int a[10]={1,4,2,7,3,12,5,34,5,9},i,max,pos;       
	max = a[0];     
	pos = 0;     
	for (i=1; i<10; i++)   
	/************found************/       
	if (max < a[i])       
	{  
		/************found************/            
		max = a[i];    
		pos =i;       
	}      
	printf("The max is: %d ,pos is: %d\n", max , pos);   
}
