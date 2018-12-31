#include <stdio.h>
#include <string.h>
char* rotate(char* str, int k)
{
    int len = strlen(str);
    char str1[len + 1] = {0};
    str1[len] = '\0';
    for(int i = k; i < len; i++)
    {
        str1[i - k] = str[i];
    }
    for(int i = len - k, j = 0; i < len; i++)
    {
        str1[i] = str[j++];
    }
    printf("%s的第%d个字母的反转为%s\n",str,k,str1);    
}
int main()
{
    char* A = "ABCD";
    rotate(A, 1);
    rotate(A, 2);
}