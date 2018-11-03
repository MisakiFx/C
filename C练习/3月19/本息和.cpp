#include <stdio.h>
#define INTEREST 0.025
#define TAX 0.2
int main()
{
	double deposit = 1000;
	double interest = 1000 * INTEREST * 1 * (1 - TAX);
	printf("%.2lf",deposit + interest);
} 
