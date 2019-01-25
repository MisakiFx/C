#include <stdio.h>
//模仿qsort()实现一个可以自订的bubble()
int int_cmp(const void* p1, const void* p2)
{
    return (*(int*)p1 > *(int*)p2);
}
void _swap(void* p1, void* p2, int size)//用于交换的函数，按字节大小进行交换
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        char tmp = *((char *)p1 + i);
        *((char *)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}
void bubble(void* base, int count, int size, int (*cmp)(const void*, const void*))//bubble()函数
{
    int i = 0;
    int j = 0;
    for(i = 0;i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
            {
                _swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
            }
        }
    }
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 22, 103, 0, 45, 2};
    int i = 0;
    bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}