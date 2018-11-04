#include <conio.h>
#include <stdio.h> 
void fun (long s, long *t)
{
  long sl=10;
  s /= 10;
  /***********SPACE***********/
  *t = s % 10;
  while(s>0)
  { 
    /***********SPACE***********/
    s = s / 100;
    /***********SPACE***********/
    *t = s%10*sl + *t;
    /***********SPACE***********/
    sl = sl * 10;
  }
}

int main()
{ 
  long s, t;
  printf("\nPlease enter s:"); 
  scanf("%ld", &s);
  fun(s, &t);
  printf("The result is: %ld\n", t);
}


