#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count;
int BFSM(char T[20],char P[20])
{
    int m,n,j,i;
    n=strlen(T);
    m=strlen(P);
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m&&P[j]==T[i+j])
        {
            j=j+1;
            count++;
        }
        count++;
        if(j==m)
            return i+1;
    }
    return -1;
}
int main()
{
    char T[20],P[20];
    int flag;
    printf("\n enter text:\n");
    scanf("%s",&T);
    printf("\n enter pattern:\n");
    scanf("%s",&P);
    flag=BFSM(T,P);
    if(flag==1)
    {
       printf("\n pattern is not found:");
       printf("number of comperition =%d",count);
    }
    else
        printf("\n pattern is found:");
    printf("number of comperition =%d",count);
}
