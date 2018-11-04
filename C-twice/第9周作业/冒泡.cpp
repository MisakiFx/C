#include <stdio.h>
/**********FOUND**********/
void sort(int *x,int n)
{
  int i,j,t;
  for(i=0;i<n-1;i++)
    /**********FOUND**********/
    for(j=0;j<n-i-1;j++)
    /**********FOUND**********/
    if(x[j]>x[j+1])
    {
      t=x[j];
      x[j]=x[j+1];
      x[j+1]=t;
    }
}

int main()
{
  int i,n,a[100];
  printf("please input the length of the array:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  /**********FOUND**********/
  sort(a,n);
  printf("output the sorted array:\n");
  for(i=0;i<=n-1;i++)
    printf("%5d",a[i]);
   printf("\n");
}

