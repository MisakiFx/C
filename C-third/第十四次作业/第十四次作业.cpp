#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* rotate(char* str, int k)
{
    int len = strlen(str);
    char* str1 = (char*)malloc(sizeof(char) * (len + 1));
    str1[len] = '\0';
    for(int i = k; i < len; i++)
    {
        str1[i - k] = str[i];
    }
    for(int i = len - k, j = 0; i < len; i++)
    {
        str1[i] = str[j++];
    }
    return str1;
    //printf("%s的第%d个字母的反转为%s\n",str,k,str1);    
}
int isRotate(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2) return 0;
    for(int i = 0; i < len1; i++)
    {
        char* t = rotate(str1, i);
        if(strcmp(t, str2) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char* A = "ABCD";
    char* a1 = rotate(A, 1);
    char* a2 = rotate(A, 2);
    printf("%s向左旋转一个字符为%s\n", A, a1);
    printf("%s想做旋转两个字符为%s\n", A, a2);
    printf("%s是否为%s旋转后的结果：%d", A, a2, isRotate(A, a2));
}