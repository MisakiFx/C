#include <conio.h> 
#include <stdio.h> 
int fun(int k) 
{   
	int m=0,  mc=0;   
	while (k >= 2 && mc < 10)    
	{     
		if (k%13 == 0 || k % 17 == 0)     
		{        
			m=m+k;        
			mc++;      
		}     
		k--;   
	}   
	return m; 
} 
int main() 
{    
	printf("%d\n", fun (500)); 
} 
