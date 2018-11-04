#include <stdio.h> 
#include <math.h> 
void sushu(int m) 
{ 
	int k; 
	int i; 
	k = m;
	for(i=2;i<=k;i++)
	if(k % i == 0) break;
	if(i>=k)
	printf("%4d",m); 
} 
int main() 
{ 
	int m; 
	for (m=101;m<=200;m++) 
	sushu(m);
}
