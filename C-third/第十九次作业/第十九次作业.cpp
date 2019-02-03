#include <stdio.h>
#include <assert.h>
//strncpy()
char* Strncpy(char* destination, const char* source, size_t num)
{
    assert(destination != NULL);
    assert(source != NULL);
    size_t i = 0;
    while(i < num && source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    if(i == num)
    {
        return destination;
    }
    if(source[i] == '\0')
    {
        for(; i < num; i++)
        {
            destination[i] = '\0';
        }
        return destination;
    }
}
//strncat()
char* Strncat(char* destination, const char* source, size_t num)
{
    assert(destination != NULL);
    assert(source != NULL);
    size_t i = 0;
    while(destination[i] != '\0')
    {
        i++;
    }
    size_t j = 0;
    while(j < num && source[j] != '\0')
    {
        destination[i] = source[j];
        j++;
        i++;
    }
    destination[i] = '\0';
    return destination;
}
//strncmp()
int Strncmp(const char* str1, const char* str2, size_t num)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    size_t i = 0;
    while(str1[i] == str2[i] && i < num && str1[i] != '\0' && str2[i] != '\0')
    {
        i++;
    }
    if(i == num)
    {
        return 0;
    }
    if(str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    }
    if(str1[i] > str2[i])
    {
        return 1;
    }
    if(str1[i] < str2[i])
    {
        return -1;
    }
}
int main()
{
    char str1[10] = "151";
    char str2[10] = "132abc";
    int i = Strncmp(str1, str2, 3);
    printf("%d\n", i);
}