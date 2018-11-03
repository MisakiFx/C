#include <conio.h>   
#include <stdio.h>   
int max;   
int maxarr(int arr[ ])   
{    
	int pos,i;   
	/************found************/         
	max = arr[0];     
	pos = 0;     
	for ( i=1; i<10; i++)       
	if (max < arr[i])       
	{  
	max = arr[i];  
	pos = i;       
	}   
	/************found************/     
	return pos;   
}    
int main()  
{      
	int a[10]={34,4,2,7,3,12,5,8,5,9};      
	printf("The max is: %d ,pos is: %d\n", max , maxarr(a));  
}
