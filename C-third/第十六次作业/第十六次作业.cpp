#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
模拟实现strcpy()
**/
int Strcpy(char* a, char* b)
{
    if(a == NULL || b == NULL)
    {
        return -1;
    }
    int i;
    for(i = 0; i < strlen(b); i++)
    {
        a[i] = b[i];
    }
    a[i] = '\0';
    return 1;
}
/*
模拟实现strcat()
**/
int Strcat(char* str1, char* str2)
{
    if(str1 == NULL || str2 == NULL)
    {
        return -1;
    }
    int a = strlen(str1);
    int b = strlen(str2) + 1;
    for(int i = 0; i < b; i++)
    {
        str1[a] = str2[i];
        a++;
    }
    return 1;
}
int main()
{
    char a[1024] = "abc";
    char b[] = "abcdef";
    //Strcpy(a, b); 
    Strcat(a, b);
    printf("%s\n", a);
}