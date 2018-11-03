/*
用来存放计算函数调用次数的函数实现及原型
*/
int whileCount;//外部变量在不同文件中使用时还要重新定义
void counter(int);//计算当前的函数执行了多少次
void counter(int i)
{
    static int subTotal=0;
    subTotal++;
    printf("counter函数被调用了%d次\n",subTotal);
    printf("while循环的当前轮数是第%d轮\n",whileCount);
    return 0;
}
