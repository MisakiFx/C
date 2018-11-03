#include <stdio.h>
#include<conio.h>
#include<stdio.h>
#define M 20
void fun(int bb[],int *n,int y)
{
  /**********Program**********/
  for(int i = 0; i < *n; i++)
  {
  	if(bb[i] == y)
  	{
  		for(int j = i; j < *n; j++)
		{
			bb[j] = bb[j + 1];	  	
		}
		(*n)--;	
		i--;
	}
   } 
  /**********  End  **********/
}
int main()
{
  int aa[M],n,y,k;
  printf("\nPlease enter n:");scanf("%d",&n);
  printf("\nEnter %d positive number:\n",n);
  for(k=0;k<n;k++) scanf("%d",&aa[k]);
  printf("The original data is:\n");
  for(k=0;k<n;k++) printf("%5d",aa[k]);
  printf("\nEnter a number to deletede:");scanf("%d",&y);
  fun(aa,&n,y);
  printf("The data after deleted %d:\n",y);
  for(k=0;k<n;k++) printf("%4d",aa[k]);
  printf("\n");
}

