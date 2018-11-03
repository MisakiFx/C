#include <stdlib.h>
#include<stdio.h>
void sort(int a[],int n)
{
  /**********Program**********/ 
  int min, t;
  for(int i = 0; i < n - 1; i++)
  {
  	min = i;
  	for(int j = i + 1; j < n; j++)
  	{
  		if(a[j] < a[min])
  		{
  			min = j;
		}
	}
	t = a[i];
	a[i] = a[min];
	a[min] = t;
  }
  /**********  End  **********/
}

int main()
{
  int a[13],i;
  for(i=0;i<13;i++)
    scanf("%d",&a[i]);
  for(i=0;i<13;i++)
    printf("%3d",a[i]);
  printf("\n-------------------\n");
  sort(a,13);
  for(i=0;i<13;i++)
    printf("%3d",a[i]);
}
