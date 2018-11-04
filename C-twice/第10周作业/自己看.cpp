#include <stdio.h>   
float  fun( float q )   
{       
	int n;       
	float  s;       
	n = 2;       
	s = 2.0;   
	/************found************/       
	while (s <= q)          
	{           
		s=s+(float)(n+1)/n;   
		/************found************/           
		n++;          
	}         
	return s;   
}   
int main()   
{       
	printf("%f\n", fun(50));   
}
