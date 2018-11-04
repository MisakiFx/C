#include <stdio.h>
void fun(int a[], int n)
{
	int i,t;
	/***********SPACE***********/
	for (i=0; i<n / 2; i++)
	{
		t=a[i];
		/***********SPACE***********/
		a[i] = a[n - 1 - i];
		/***********SPACE***********/
		a[n - 1 - i] = t;
	}
}
int main()
{
	int b[9]={1,2,3,4,5,6,7,8,9}, i;
	printf("\nThe original data :\n");
	for (i=0; i<9; i++)
	printf("%4d ", b[i]);
	printf("\n");
	fun(b, 9);
	printf("\nThe data after invert :\n");
	for (i=0; i<9; i++)
	printf("%4d ", b[i]);
	printf("\n");
}

