#include <stdio.h>
#define N 10
/**********FOUND**********/
int fun(int *a,int *b,int n)
{
  int *c,max=*a;
  for(c=a+1;c<a+n;c++)
    if(*c>max)
    {
      max=*c;
      /**********FOUND**********/
      *b=c-a;
    }
  return max;
}

int main()
{
  int a[N],i,max,p=0;
  printf("please enter 10 integers:\n");
  for(i=0;i<N;i++)
    /**********FOUND**********/
    scanf("%d",&a[i]);
  /**********FOUND**********/
  max=fun(a,&p,N);
  printf("max=%d,position=%d",max,p);
}

