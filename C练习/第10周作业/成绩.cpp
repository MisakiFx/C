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
		case 9:printf("����!\n");
		break;       
		case 8:printf("����!\n");
		break;       
		case 7:printf("�е�!\n");
		break;       
		case 6:printf("����!\n");
		break;   
		/*************found**************/       
		default:
		printf("������!\n");     
	} 
}
