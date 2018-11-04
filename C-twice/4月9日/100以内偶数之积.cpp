#include <stdio.h> 
double fun(int m) 
{  
	double sum = 1;
	for(int i = 2; i <= m; i += 2)
	{
		sum *= i;
	}
	return sum;
} 
int main() 
{ 
	printf("ji=%f\n",fun(100)); 
}
