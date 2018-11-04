#include<stdio.h> 
void f(int n) 
{ 
int i,j,k; 
i=n/100; 
/***********SPACE***********/ j=n / 10 % 10; 
k=n%10; 
/***********SPACE***********/ if((i * i * i + j * j * j + k * k * k) == n)
{ 
printf("%5d\n",n); 
} 
} 
int main() 
{ 
void f(int n); 
int i; 
for(i=100;i<1000;i++) 
f(i); 
} 
