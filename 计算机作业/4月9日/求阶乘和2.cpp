#include <stdio.h> 
double fun(int n) 
{
	double s=0.0,fac=1.0; 
	int i; 
	for(i=1; i<=n; i++) 
	{ 
		fac=fac * i; 
		s=s + fac; 
	}
	return s;
}
int main() 
{
	double fun(int n); 
	double s; 
	int t;
	scanf("%d",&t); 
	s=fun(t); 
	printf("s=%f\n",s);
}
