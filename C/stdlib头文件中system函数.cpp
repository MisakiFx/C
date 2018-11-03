#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	颜色属性由两个16进制数字制定，第一个为背景色，第二个为前景色。
	每个数字都可以为下列值之一：
	黑色 = 0		蓝色 = 1		绿色 = 2		湖蓝色 = 3
	红色 = 4		紫色 = 5		黄色 = 6		白色 = 7
	灰色 = 8		淡蓝色=9		淡绿色=A		淡红色=C
	淡紫色=D		淡黄色=E		亮白色=F
	*/
	//设置背景色为灰色，文字颜色为淡黄色
	printf("这是一行很普通的文字！\n");
	system("color F5");//system函数可以运行DOS命令 （CMD命令）
	system("pause");//暂停 "请按任意键继续" 
	printf("这是一行很普通的文字！\n");	 
	system("cls");//清屏命令，可以做动画效果
	system("shutdown /r /t 180");//自动关机命令，180秒后自动关机
	system("shutdown /a");//取消自动关机 
	//system函数在<stdlib.h>头文件中 
	return 0; 
}
