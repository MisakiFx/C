#include <stdio.h> 
#define N 20 
void fun(int a[], int n) 
{ 
	int i, j, t, p; 
	for (j = 0 ;j < n-1;j++) 
	{ 
		p = j; 
		for (i = j;i < n; i++) 
		if(a[i] < a[p]) 
		p = i; 
		t = a[p]; 
		a[p] = a[j]; 
		a[j] = t; 
	} 
} 
int main() 
{ 
	int a[N]={9,6,8,3,-1},i, m = 5; 
	printf("����ǰ������:"); 
	for(i = 0;i < m;i++) 
	printf("%d ",a[i]); 
	printf("\n"); 
	fun(a,m); 
	printf("����������:"); 
	for(i = 0;i < m;i++) 
	printf("%d ",a[i]); 
	printf("\n"); 
}
