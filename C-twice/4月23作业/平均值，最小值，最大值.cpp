#include <stdio.h>  
int main()
{   
	int i; 
	/**********FOUND**********/ 
	float a[10],min,max,avg;   
	printf("input 10 score:");   
	for(i=0;i<=9;i++)  
	{     
		printf("input a score of student:");     
		/**********FOUND**********/      
		scanf("%f",&a[i]);   
	}    
	max=min=avg=a[0];   
	for(i=1;i<=9;i++) 
	{    
		/**********FOUND**********/    
		if(min>a[i])         
		min=a[i];     
		if(max<a[i])       
		max=a[i];     
		avg=avg+a[i];   
	}   
	avg=avg/10;   
	printf("max:%f\nmin:%f\navg:%f\n",max,min,avg); 
}
