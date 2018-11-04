#include <conio.h> 
#include <stdio.h> 
int main()   
{     
	int a[10]={10,4,2,7,3,12,5,34,5,9},i;     
	double aver,s;     
	s = 0;   
	/************found************/     
	for (i=0; i<10; i++)   
	/************found************/     
	s = s + a[i];     
	aver =  s / i;     
	printf("The aver is: %.2f\n", aver); 
}
