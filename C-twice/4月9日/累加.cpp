#include<stdio.h> 
int sum(int n) 
{ 
	int i,sum = 0; 
	for(i=1;i<=n;i++) 
	sum += i; 
	return(sum); 
} 
int main() 
{ 
	int sum(int n); 
	int a,b; 
	scanf("%d",&a); 
	b=sum(a); 
	printf("%d\n",b); 
}
