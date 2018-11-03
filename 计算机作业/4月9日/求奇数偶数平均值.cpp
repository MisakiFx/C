#include <stdio.h> 
int main() 
{ 
	int x,i=0,j=0; 
	float s1=0,s2=0,av1,av2; 
	scanf("%d",&x); 
	while(x != 0) 
	{ 
		if(x%2==0) 
		{ 
			s1=s1+x; 
			i++; 
		} 
		else
		{ 
			s2=s2+x; 
			j++; 
		} 
		scanf("%d",&x); 
	} 
	if(i!=0) 
	av1=s1/i; 
	else 
	av1=0; 
	if(j!=0) 
	av2 = s2 / j ; 
	else 
	av2=0; 
	printf("oushujunzhi:%7.2f,jishujunzhi:%7.2f\n",av1,av2); 
} 
