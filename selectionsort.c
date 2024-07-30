#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int count;
void selectionsort(int A[SIZE],int n)
{
    int i,j,temp,min;
    for(i=0;i<=n-2;i++)
    {
       min=i;
       for(j=i+1;j<=n-1;j++)
       {
           if(A[j]<A[min])
            min=j;
       }
       temp=A[i];
       A[i]=A[min];
       A[min]=temp;
    }
}
int main()
{
    int i,A[SIZE],n;
    printf("\n enter the size of array:\n");
    scanf("%d",&n);
    printf("\n enter the array element:\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    selectionsort(A,n);
    printf("\n sorted element are:");
    for(i=0;i<=n;i++)
        printf("%d\t",A[i]);
    printf("count=%d",count);
    return 0;
}
