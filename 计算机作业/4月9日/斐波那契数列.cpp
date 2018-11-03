#include  <stdio.h> 
void fun() 
{ 
	int i; 
	float f1=1,f2=1,f3; 
	/**********FOUND**********/ 
	printf("%8.0f%8.0f",f1,f2); 
	/**********FOUND**********/ 
	for(i=1;i<=18;i++) 
	{ 
		f3=f1+f2; 
		/**********FOUND**********/ 
		f1=f2; 
		/**********FOUND**********/ 
		f2=f3; 
		printf("%8.0f",f3); 
	} 
	printf("\n"); 
} 
int main() 
{ 
	fun(); 
} 
