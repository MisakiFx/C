#include "stdio.h"   
#include "math.h"   
#include "stdlib.h"  
int  main()   
{  
   int s;    
   int i;   
   /***********begin***********/
   s = 0;   
	for(i = 1; i <= 1000; i++)
	{
		if(i % 5 != 0 && i % 7 != 0)
		{
			s += i;
		}
	}
  /************end************/     
  printf("s=%d\n",s);   
} 
