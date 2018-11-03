#include <stdio.h>   
#include <conio.h>   
#include <stdlib.h>   
#include <math.h>   
int main()   
{     
	int score,t;     
	printf("Please enter a score:");     
	do       
	{
	scanf("%d",&score);
	}while(score<0||score>100);     
	t=score/10;   
	/*************found**************/     
	switch(t)     
	{       
		case 10:       
		case 9:printf("优秀!\n");
		break;       
		case 8:printf("良好!\n");
		break;       
		case 7:printf("中等!\n");
		break;       
		case 6:printf("及格!\n");
		break;   
		/*************found**************/       
		default:
		printf("不及格!\n");     
	} 
}
