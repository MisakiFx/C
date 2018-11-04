#include <stdio.h>
#include <stdlib.h>
    //计算某个函数被调用了多少次
    //int whileCount=0;全局变量，用来计算while循环进行的轮数（在别的文件中调用这个变量行不通）
    //全局变量的作用域是当前源文件
extern int whileCount;//引用外部变量，作用域是整个程序，用来计算while循环的轮数（定义外部变量不能赋值，只用声明变量）
int main()
{
    /*
	1.auto -- 自动变量 -- 只能用于作用块的变量，一个快结束，变量自动销毁（默认存储类型）
	auto int num1=0
	2.register -- 寄存器存储 -- 只作用于块作用域的变量，请求速度快，对于循环次数较多的循环控制变量及循环体内反复使用的变量均可定义为寄存器变量（空间有限）
	register int num2=0;
	3.static -- 静态存储 -- 载入程序时创建对象，程序结束时对象消失（定义后占用内存变多，少定义）（常量）
	static int num3=0;
	4.extern -- 外部变量 -- 说明符表示声明的变量定义在别处。作用域是整个程序，生存期贯穿程序的开始和结束
	extern int num4=0;
	*/
	int value;//自动变量 -- 执行循环的次数
	register int i;//交给寄存器寄存
	printf("请输入循环执行的次数（按0退出）：");
	//scanf赋值会有返回值，类型相同返回真（给几个数字赋值返回几），类型不同返回假（0）
	while(scanf("%d",&value)==1&&value>0)//用户输入的值是个整型数字并且value大于1时进入循环
    {
        whileCount++;//轮数++
        for(i=value;i>0;i--)
        {
            //1.循环执行了多少次
            //2.counter被调用了多少次
            counter(i);//每次循环调用counter
        }
        printf("请输入循环执行的次数（按0退出）：");
    }
    return 0;
}
