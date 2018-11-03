#include  <stdio.h> 
int main() 
{ 
	int m,n,k,i=0; 
	for(m=100;m<=1000;m++) 
	{ 
		k = 0; 
		n=m; 
		do 
		{ 
		k=k+n%10; 
		n=n/10; 
		}while(n);
		if(k%15==0) 
		{ 
			printf("%5d",m);
			i++; 
			if(i%10==0) 
			printf("\n"); 
		} 
	 } 
 } 
