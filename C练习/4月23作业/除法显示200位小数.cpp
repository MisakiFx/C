#include <stdio.h>
int main()
{
	int a, b, i = 0;
	scanf("%d/%d",&a,&b);
	printf("0.");
	while(a % b != 0 && i < 200)
	{
		printf("%d", a * 10 / b );
		a = a * 10 % b;
		i++;
	}
}
