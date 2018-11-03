#include <stdio.h>
void Mean1()
{
	printf("%c\n",'A');
}
void Mean2()
{
	printf("%c\n",'a' - 32);
}
void Mean3()
{
	printf("%c\n",65);
}
void Mean4()
{
	printf("%c",'\101');
}
int main()
{
	Mean1();
	Mean2();
	Mean3();
	Mean4();
} 
