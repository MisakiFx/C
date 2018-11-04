#include <stdio.h>
#include <stdlib.h> 
int main()
{
	//动态分配内存，malloc函数
	//动态分配内存：编译时没有内存，程序运行后，再分配内存
	//演示动态分配内存
	int *nums;
	int *nums2;
	int i;
	nums=(int*)malloc(sizeof(int)*5);//为前面的指针动态分配了5个整形个字节的动态空间（按照指针操作），括号里的数字单位是字节 
	//也可以表示为：nums=(int*)malloc(20);五个整型的字节数=4*5=20  
	//等价于：int nums[5];（按照数组操作） 
	for (i=0;i<5;i++)
	{
		printf("请输入第%d个元素：",i+1);
		scanf("%d",nums+i);//等价于：scanf("%d",&*(nums+i));
	}
	printf("数组元素为：\n");
	for (i=0;i<5;i++)
	{
		printf("%d \t",*(nums+i));
	}
	free(nums);//释放动态分配的内存（配套的，记得释放，必须释放，防止成为野指针）
	nums = NULL;//回收指针，防止成为野指针，良好指针习惯
	return 0;
	//realloc重新分配内存空间，成功则返回分配后的内存空间，失败则反回空指针
	nums2=calloc(5,sizeof(int));
	
	 
}
