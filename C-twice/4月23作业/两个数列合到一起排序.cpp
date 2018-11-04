#include <stdio.h> 
#define M 5 
#define N 6  
int main() 
{     
	int A[M] = {1, 3, 5, 6, 8}, B[N] = {1, 2, 5, 7, 8, 9}, C[M + N];     
	int i = 0, j = 0, k = 0;
	while(i <= M && j <= N)
	{
		if(A[i] < B[j])
		{
			C[k] = A[i];
			k++;
			i++;
		}
		else
		{
			C[k] = B[j];
			k++;
			j++;
		}
		if(i <= M && j > N)
		{
			for(; k < M + N; k++)
			{
				C[k] = A[i];
				i++;
			}
		}
		if(j <= N && i > M)
		{
			for(; k < M + N; k++)
			{
				C[k] = B[j];
				j++;
			}
		}
	}       
	printf("合并后的序列为：");    
	for (k = 0; k < M + N; k++)         
	printf("%3d", C[k]);    
	return 0; 
}
