#include <stdio.h>
#define N 10 
int main() 
{ 
	int a[]={0,1,2,3,4,5,6,7,8,9},k; 
	int low=0,high=N-1,mid,find=0; 
	printf("�����������ҵ�ֵ��\n"); 
	scanf("%d",&k); 
	while (low<=high) 
	{ 
		/***********SPACE***********/ 
		mid=(low + high) / 2; 
		if(a[mid]==k) 
		{ 
			printf("�ҵ�λ��Ϊ��%d\n",mid+1);
			find=1; 
		} 
		if(a[mid] < k)
		/***********SPACE***********/ 
		low = mid + 1; 
		else 
		/***********SPACE***********/ 
		high = mid - 1; 
	} 
	if(!find) 
	printf("%d δ�ҵ�\n",k); 
}
