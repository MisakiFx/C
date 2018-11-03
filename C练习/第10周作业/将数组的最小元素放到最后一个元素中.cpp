#include <stdio.h> 
#define M 11     
int main()   
{ 
	int a[M],i;     
	for(i=0;i<M-1;i++)       
	scanf("%d",&a[i]);      
	a[M-1]=a[0];   
	/************found************/    
	for(i=1; i < M - 1;i++)   
	/************found************/       
	if(a[i] < a[M - 1])            
	a[M-1]=a[i];    
	printf("Max is %d\n",a[M-1]);   
}
