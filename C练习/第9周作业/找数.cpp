#include  <stdio.h>

#define   M   3
#define   N   4
void fun(int  (*a)[N])
{ 
        int  i=0,j,find=0,rmax,c,k;
        while( (i<M) && (!find))
        {  
                rmax=a[i][0];  
                c=0;
                for(j=1; j<N; j++)
                        if(rmax<a[i][j]) 
                        {
                                rmax=a[i][j]; 
/***********SPACE***********/
                                c= j ;
                        }
                        find=1; k=0;
                while(k<M && find)
                {
                        if (k!=i && a[k][c]<=rmax) 
/***********SPACE***********/
                                find=0;
                        k++;
                }
                if(find) 
                        printf("find: a[%d][%d]=%d\n",i,c,a[i][c]);
/***********SPACE***********/
                i++ ;
        }
        if(!find) 
                printf("not found!\n");
}
int main()
{ 
        int  x[M][N],i,j;
        printf("Enter number for array:\n");
        for(i=0; i<M; i++)
                for(j=0; j<N; j++) 
                        scanf("%d",&x[i][j]);
        printf("The array:\n");
        for(i=0; i<M; i++)
        {  
                for(j=0; j<N; j++) 
                        printf("%3d",x[i][j]);
                printf("\n\n");
        }
        fun(x);
}

