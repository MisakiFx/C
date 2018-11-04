#include <stdio.h>
long sum(int n)
{
/**********Program**********/
long sum = 0, j = 1;
for(int i = 1; i <= n; i++)
{
	sum += j;
	j = j * 10 + (i + 1);
}
/**********  End  **********/
        return sum;
}

    
int main()
{
        int n;
        printf("Input n: ");
        scanf("%d",  &n);        
        printf("sum=%ld\n",sum(n));
}

