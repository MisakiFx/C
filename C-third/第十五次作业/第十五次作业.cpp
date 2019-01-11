#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
查找不重复的数字`
**/
int FindNum(int* a, int* b, int* arr, int len)
{
    int num = 0;
    int isFind = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(j == i) continue;
            if(arr[j] == arr[i])
            {
                isFind = 1;
                break;
            }
        }
        if(isFind == 0)
        {
            if(num == 0)
            {
                num++;
                *a = arr[i];
            }
            if(num == 1)
            {
                *b = arr[i];
            }
        }
        isFind = 0;
    }
    return 1;
}
/*
喝汽水
**/
int DrinkJuice(int money)
{
    int sum = 0; 
    sum += money;
    while(money > 1)
    {
        if(money % 2 != 0)
        {
            money = money / 2;
            sum += money;
            money++;
        }
        else
        {
            money = money / 2;
            sum += money;
        }
    }
    return sum;
}
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
    int b = sizeof(str2);
    for(int i = 0; i < b; i++)
    {
        str1[a] = str2[i];
        a++;
    }
    return 1;
}
int main()
{
    //int arr[] = {2, 1, 2, 3, 5, 4, 4, 5};
    //int a = 0, b = 0;
    //FindNum(&a, &b, arr, sizeof(arr) / sizeof(arr[0]));
    //printf("不重复的数字为：%d\t%d\n", a, b);
    //int num = DrinkJuice(20);
    //printf("能喝%d瓶\n",num);
    //char a[] = "abcd";
    //char b[5];
    //Strcpy(b, a);
    //printf("%s\n",b);
    char str1[10] = "abc";
    char str2[] = "def";
    printf("%s\n",str1);
}