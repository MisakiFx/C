#include  <stdio.h> 
int main() 
{ 
	int i,j; 
	for(i=0;i < 10; i++) 
	{ 
		j=i*10+8; 
		if (j % 4 == 0) 
		printf("%8d",j); 
	} 
} 
