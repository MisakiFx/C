#include  <stdio.h> 
main() 
{ 
	int i,n,sum; 
	sum=0; 
	n = 0;
	for(i=1; i <= 300; i++)
	{  
		if(i % 7 == 0 || i % 17 == 0) 
		{
			if(i%2==0) 
			{ 
				sum=sum+i; 
				n++; 
				printf("%6d",i); 
				if(n % 5 == 0) 
				printf("\n"); 
			} 
		}
	}
	printf("\ntotal=%d",sum); 
} 
