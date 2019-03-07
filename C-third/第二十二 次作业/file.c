#include <stdio.h>
#include <errno.h>
int main()
{
  //1、打开文件
  //fp => 句柄 句柄就是遥控器
  FILE* fp = fopen("./test.txt", "a");//第一个参数文件路径，第二个参数打开法方式
  //w打开方式打开文件会将原来文件中的内容全部清空
  //每个程序一打开就会默认打开三个文件：标准输入，标准输出，标准错误
  if(fp == NULL)
  {
    perror("fopen");
    //printf("%s\n", strerror(errno));//打印错误码
    //进程的退出码，echo $?的 方式能获取上个进程的退出码
    return 1;
    //结果出错，返回非0
    //进程退出码
  }
  ////2、读文件
  ////buffer => 缓冲区:提高读取效率，同城情况下是一块内存
  //char buf1[1024] = { 0 }; 
  //size_t n = fread(buf1, 1, 100, fp);//1 * 4 = 读取的字节数
  ////1为一个元素几个字节，读取100个元素，返回成功读取的元素个数
  //printf("%s\n", buf1);
  //printf("%ld\n", n);
  ////3、写文件
  //char buf2[1024] = "aaaa";
  //size_t n2 = fwrite(buf2, 1, 4, fp);
  ////参数与fread相同，同样返回成功写入的元素个数
  //printf("n2 = %lu\n", n2);
  //if(n2 == 0) 
  //{
  //  perror("fwrite");
  //}
  //5、追加写
  //在文件后追加内容
  //char buf[1024] = "hehe";
  //fwrite(buf, 1, 4, fp);
  //6、fprintf()
  //fprintf(fp, "a = %d\n", 100);
  //fprintf(stdout, "stdout : a = %d\n", 100);
  //fprintf(stderr, "stderr : a = %d\n", 100);
  //printf:标准输出中格式化数据
  //fprintf:文件中格式化数据
  //sprintf:内存中格式化数据
  char str[1024] = { 0 };
  sprintf(str, "a = %d\n", 100);//可以完成数字转字符串
  int n = 0;
  sscanf(str, "%d", &n);//字符串转数字
  //也可以以借助标准库函数：atoi/itoa
  //7、文件的随机读写
  //4、关闭文件
  fclose(fp);//文件不使用的时候，就需要及时关闭掉
  //文件不及时关闭的话，句柄泄露/资源泄露/文件描述符泄漏
  //可能导致后续的文件就无法打开了（一个进程可以打开的文件是有上限的）
  return 0;
}
