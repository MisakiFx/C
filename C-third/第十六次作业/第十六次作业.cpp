#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
/*
模拟实现strcpy()
**/
int Strcpy(char* a, char* b)
{
    if(a == NULL || b == NULL)
    {
        return -1;
    }
    size_t i;
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
    size_t a = strlen(str1);
    size_t = strlen(str2) + 1;
    for(int i = 0; i < b; i++)
    {
        str1[a] = str2[i];
        a++;
    }
    return 1;
}
/*
模拟实现strstr()
*/
const char* Strstr(const char* str1, const char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    if(*str1 == '\0' || *str2 == '\0')
    {
        return NULL;
    }
    const char* black_ptr = str1;
    while(*black_ptr != '\0')
    {
        const char* red_ptr = black_ptr;
        const char* sub_ptr = str2;
        while(*red_ptr != '\0' && *sub_ptr != '\0' && (*red_ptr == *sub_ptr))
        {
            ++red_ptr;
            ++sub_ptr;
        }
        if(*sub_ptr == '\0')
        {
            //找到了
            return black_ptr;    
        }
        ++black_ptr;
    }
    //没找到
    return NULL;
}
/*
模拟实现strchr()
*/
const char* Strchr(const char* str1, int character)
{
    assert(str1 != NULL);
    const char* p = str1;
    while(*p != '\0' && *p != character)
    {
        p++; 
    }
    if(*p == '\0')
    {
        return NULL;
    }
    return p;
}
/*
模拟实现strcmp()
*/
int Strcmp(const char* str1, const char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 < *str2)
        {
            return -1;
        }
        else if(*str1 > *str2)
        {
            return 1;
        }
        else 
        {
            ++str1;
            ++str2;
        }
    }
    if(*str1 == '\0' && *str2 != '\0')
    {
        return -1;
    }
    if(*str1 != '\0' && *str2 == '\0')
    {
        return 1;
    }
    if(*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
}
/*
模拟实现memcpy()
*/
void* Memcpy(void* dest, const void* src, size_t num)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* pdest = (char*)dest;
    char* psrc = (char*)src;
    for(size_t i = 0; i < num; i++)
    {
        pdest[i] = psrc[i];
    }
    return dest;
}
/*
模拟实现memmove()
*/
void* Memmove(void* dest, const void* src, size_t num)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* pdest = (char*)dest;
    char* psrc = (char*)src;
    if(pdest > psrc && pdest < psrc + num)
    {
        for(int64_t i = num - 1; i >= 0; i--)
        {
            pdest[i] = psrc[i];
        }
    }
    else
    {
        Memcpy(dest, src, num);
    }
    return dest;
}
int main()
{
    char a[1024] = {0};
    char b[] = "123abcdef";
    //Strcpy(a, b); 
    //Strcat(a, b);
    //const char* p = Strstr(b, a);
    //const char* p = Strchr(a, 'd');
    //printf("%p\n", p);
    //if(p != NULL)
    //printf("%d\n", p - a + 1);
    //else printf("NULL!");
    Memmove(b + 1, b, 10);
    printf("%s\n", b);
}