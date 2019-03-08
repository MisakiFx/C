#include <stdio.h>
#include "test.h"
#include "test.h"
//#define SIZE 10
//#undef SIZE//清除原来的宏定义
//#define SIZE 5
/* 续行符 \  */
//#define CHECK(fp) if (fp == NULL) \
//{ \
//  printf("fopen failed! %s:%d\n", __FILE__, __LINE__); \
//  return 1; \
//}
//#define ADD(x, y) ((x) + (y))
//#define MUL(x, y) ((x) * (y))
//#define SIZE 10;
//宏是在文本替换
//#define uint unsigned int //不推荐这么写
//typedef unsigned int uint;//用这个更好
//小结：（本质是文本替换）
//1、定义常量
//2、定义类型
//3、定义某一段代码，使之类似于一个函数
//以下情况只有宏能搞定，函数搞不定（仅限于C语言，C++强烈不推荐使用宏）
//a）打印日志的时候，需要带上文件和行号
//b）宏没有参数类型检查，所以同一个宏可以引用到不同类型的参数
//c）宏是直接展开代码，相比于函数调用开销更小
//#define PRINT(FORMAT, VALUE) \
//  printf("the value = " #FORMAT " is format\n", VALUE);
//宏的参数 # 能把参数变成一个字符串，然后这个字符串就可以再代码中进行文本拼接
//#define ADD_TO_NUM(num , value) \
//  sum##num += value;//## 拼接可以拼接变量，这里变成了sum(num) => sum1
int main()
{
#ifdef SIZE//如果SIZE被宏定义就编译以下代码
  printf("haha\n");
#endif
#if 0 //条件为真就编译，为假就不编译
  printf("hehe\n");
#endif
  //int a = SIZE;//int a = 10;;
  //int b[SIZE] = { 0 };//int b[SIZE;] = { 0 };
  //int a = ADD(10, 20) * 10 + 20;
  //rintf("a = %d\n", a);//纯文本替换这里就会出错
  //int a = MUL(10, 10 + 10);//也会出错
  //printf("a = %d\n", a);
  //FILE* fp = fopen("./test.txt", "r");
  //CHECK(fp);
  //printf("Misaki\n");
  //PRINT("%d", 10);
  //int sum1 = 10;
  //ADD_TO_NUM(1, 10);
  //printf("%d\n", sum1);
}
