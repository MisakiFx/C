#include <stdio.h> 
long fun (long num) 
{ 
	/**********FOUND**********/ 
	long k = 1; 
	do 
	{ 
		k*=num%10; 
		/**********FOUND**********/ 
		num/=10; 
	}while (num); 
	return k; 
} 
main() 
{ 
	long n; 
	printf("\nPlease enter a number:"); 
	/**********FOUND**********/ 
	scanf("%ld",&n); 
	/**********FOUND**********/ 
	printf("\n%ld\n",fun(n)); 
}
