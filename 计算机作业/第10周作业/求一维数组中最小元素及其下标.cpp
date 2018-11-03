#include <conio.h>   
#include <stdio.h>   
int main()   
{ 
int a[10]={1,4,2,7,3,12,5,34,5,9},i,min,pos;      
/************found************/     
min = a[0];     
pos = 0;     
for (i=1; i<10; i++)       
if (min > a[i])       
{  
min = a[i];   
/************found************/  
pos = i;       
}      
printf("The min is: %d ,pos is: %d\n", min , pos); 
}
