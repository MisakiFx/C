#include  <stdio.h> 
void fun(long x) 
{ 
	long ge,shi,qian,wan; 
	wan=x/10000; 
	/***********SPACE***********/ qian=x / 1000 % 10; 
	/***********SPACE***********/ shi=x / 10 % 10; 
	ge=x%10; 
	/***********SPACE***********/ if (ge == wan && shi == qian) 
	printf("this number is a huiwen\n"); 
	else 
	printf("this number is not a huiwen\n"); 
} 
int main() 
{ 
	fun(12321); 
} 
