#include <stdlib.h>
#include  <conio.h>
#include  <stdio.h>
#include  <math.h>
/***********FOUND***********/
double fun(int n)  
{
        double sum, s0, s1, s2, s; int k;
        sum=1.0;
        if (n<=2) 
                sum=0.0;
        s0=0.0; s1=0.0; s2=1.0;
        for (k=4;k<=n;k++)
        { 
                s=s0+s1+s2;
                sum+=sqrt(s);
                s0=s1;s1=s2;s2=s;
        }
/***********FOUND***********/
        return sum;
}
int main()
{
        int n;
        system("CLS");
        printf("Input  N=");
        scanf("%d",&n);
        printf("%f\n",fun(n));
}

