 #include  <stdio.h> 
double fun(int m) 
{ 
	int i;
	double sum = 0;
	for(i = 5; i <= m + 5; i++)
	{
		sum += 1.0 / i; 
	}
	return sum;
} 
int main() 
{ 
	int n; 
	printf("Enter n: "); 
	scanf("%d", &n); 
	printf("\nThe result is %1f\n", fun(n)); 
} 
