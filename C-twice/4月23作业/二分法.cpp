#include <stdio.h> 
int fun(int a[],int n,int key) 
{   
	int low,high,mid;   
	low=0;   
	high=n-1;   
	while(mid <= high)   
	{     
		mid=(low+high)/2;   
		if(key<a[mid])      
		high = mid - 1;   
		else if(key>a[mid])    
		low = mid + 1;  
		else       
		return mid - 1;   
	}   
	return -1; 
}  
int main() 
{   
	int a[10]={1,2,3,4,5,6,7,8,9,10};   
	int b,c;   
	b=4;   
	c=fun(a,10,b);   
	if(c==1)       
	printf("not found");   
	else       
	printf("position %d\n",c); 
}
