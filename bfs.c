#include <stdio.h>
#include <stdlib.h>
void bfs(int A[10][10],int n,int visited[10],int source)
{
    int q[10],rear=-1,front=0,d,i;
    visited[source]=1;
    q[++rear]=source;
    while(front<=rear)
    {
        d=q[front++];
        for(i=1;i<=n;i++)
        {
            if(A[d][i]==1&&visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n,A[10][10],i,j,visited[10],count=0;
    printf("read number of node:");
    scanf("%d",&n);
    printf(" read adjacent matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&A[i][j]);
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            bfs(A,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("\n graph connected, %d component",count);
    else
        printf("\n graph not connected, %d component",count);
    return 0;
}
