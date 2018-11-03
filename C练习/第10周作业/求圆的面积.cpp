#include <stdio.h>   
/************found************/   
double fun ( float r)    
{    
	return 3.14159 * r*r/2.0 ;    
}   
int main()   
{    
	float  x;    
	printf ( "Enter  x:  ");   
	/************found************/    
	scanf ( "%f", &x);    
	printf (" s = %f\n ", fun ( x ) );    
} 
