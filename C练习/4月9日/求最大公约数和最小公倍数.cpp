#include <stdio.h> 
int main() 
{ 
	int m,n,r,p,gcd,lcm; 
	scanf("%d%d",&m,&n); 
	p=m*n; 
	r=m%n; 
	while(r != 0) 
	{ 
		m=n;
		n=r; 
		r = m % n; 
	} 
	gcd=n; 
	lcm=p/gcd; 
	printf("gcd=%d,lcm=%d\n",gcd,lcm); 
}
