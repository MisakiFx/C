#include <stdio.h>
//两数交换
void Swap(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main()
{
    //两数交换
    //int a = 1;
    //int b = 2;
    //Swap(&a, &b);
    //printf("a = %d, b = %d\n", a, b); 
    //键盘输入三个数，输出其中最小
    //int a = 0, b = 0, c = 0;
    //scanf("%d%d%d", &a, &b, &c);
    //if(a <= b && a <= c)
    //{
    //    printf("%d\n", a);
    //}
    //else if(b <= a && b <= c)
    //{
    //    printf("%d\n", b);
    //}
    //else if(c <= a && c <= b)
    //{
    //    printf("%d\n", c);
    //}
    //判断闰年
    //int year = 0;
    //scanf("%d", &year);
    //if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    //{
    //    printf("闰年\n");
    //}
    //else
    //{
    //    printf("不是闰年\n");
    //}
    //猜数
    int num = 0;
    scanf("%d", &num);
    if(num > 50)
    {
        printf("请输入<50的数\n");
    }
    else
    {
        printf("请输入>50的数\n");
    }
    
}