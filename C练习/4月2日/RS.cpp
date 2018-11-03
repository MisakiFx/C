#include <stdio.h>
int main()
{
	int a;
	char* r[5] = {"unreadable","barely readable, occasional words distinguishable",
	"readable with considerable difficulty","readable with practically no difficulty","perfectly readable"};
	char* s[9] = {"Faint signals, barely perceptible","Very weak signals","Weak signals","Fair signals",
	"Fairly good signals","Good signals","Moderately strong signals","Strong signals","Extremely strong signals"};
	scanf("%d",&a);
	printf("%s, %s.",s[a % 10 - 1],r[a / 10 - 1]);
}
