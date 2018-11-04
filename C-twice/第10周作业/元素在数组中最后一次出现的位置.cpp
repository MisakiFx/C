#include <stdio.h>   
int main()  
{ 
	int a[10]={1,5,2,5,6,8,7,4,3,0};     
	int  i,k,n,f=0;     
	scanf("%d",&n);      
	for(i=0;i<10;i++)   
	/************found************/       
	if(a[i] == n)        
	{ 
		f=1;   
		/************found************/            
		k = i;         
	}     
	if(f)         
	printf("%d  is  No. %d\n", n,k);      
	else         
	printf(" %d not found !\n",n);  
} 
