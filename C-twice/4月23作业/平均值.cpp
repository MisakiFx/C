#include <stdio.h> 
int fun(double x[],int n) 
{ 
	int j,c=0; 
	/**********FOUND**********/ 
	float xa=0; 
	/**********FOUND**********/ 
	for(j=0;j<=n;j++) 
	xa+=x[j]; 
	xa=xa/n; 
	printf("ave=%f\n",xa); 
	/**********FOUND**********/ 
	for(j=0;j<n;j++) 
	if(x[j]<=xa) 
	c++; 
	/**********FOUND**********/ 
	return c; 
} 
int main() 
{ 
	double x[]={23.5,45.67,12.1,6.4,58.9,98.4}; 
	printf("%d\n",fun(x,6)); 
}
