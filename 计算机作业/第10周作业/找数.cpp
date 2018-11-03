#include <stdio.h>   
#include <conio.h>  
#include <stdlib.h>   
#include <math.h>
int main()
{
    int i;
	/************found************/     
	int n = 0;     
	for(i=100;i<=200;i++)     
	{      
	/************found************/       
		if(i%3!=0&&i%7!=0)
		{
			if(n%8==0) printf("\n");
			printf("%6d",i);
			n++;
		}
	}
	printf("\nNumbers are: %d\n",n);
}
