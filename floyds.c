#include<stdio.h>

#define INFINITY 999

#define MAX 10

struct EDGE

{

    int x, y, wt;

} e[MAX];

int parent[MAX];

int cost[MAX][MAX];

int t[MAX][2];

int nedges;

int eno;

void sort_edges()

{

    int i,j;

    struct EDGE temp;

    for(i=1; i < nedges; i++)

        for(j=1; j < nedges-i; j++)

            if(e[j].wt > e[j+1].wt)

            {

                temp = e[j];

                e[j] = e[j+1];

                e[j+1] = temp;

            }

}

int get_parent(int v)

{

    while(parent[v])

        v = parent[v];

    return v;

}

void join(int i, int j)

{

    parent[j] = i;

}

void kruskal(int n)

{

    int i,j,k,sum=0;

    int eno = 1;

    struct EDGE nextedge;

    for(k=1; k < n; )

    {

        nextedge = e[eno++];

        i = get_parent( nextedge.x );

        j = get_parent( nextedge.y );

        if(i != j)

        {

            join(nextedge.x, j); //e. parent[j] = nextedge.x;

            t[k][1] = nextedge.x;

            t[k][2] = nextedge.y;

            sum = sum + nextedge.wt;

            k++;

        }

    }

    printf("\nCost of the spanning tree is: %d\n",sum);

    printf("\nThe edges of the spanning tree are:\n");

    for(i=1; i<n; i++)

        printf("%d -> %d\n",t[i][1],t[i][2]);

}

int main()

{

    int i,j;

    int n;

    printf("\nEnter the no.of vertices: ");

    scanf("%d",&n);

    for(i=1; i<=n; i++)

        parent[i] = 0;

    eno = 1;

    printf("\nEnter the cost adjacency matrix: 0 = self loop & 999 = no edge\n");

    for(i=1; i<=n; i++)

    {

        for(j=1; j<=n; j++)
        {

            scanf("%d",&cost[i][j]);

            if(i == j || cost[i][j] == INFINITY)

                continue;

            e[eno].x = i;

            e[eno].y = j;

            e[eno].wt = cost[i][j];

            eno++;

            nedges++;

        }

    }

    sort_edges();

    kruskal(n);

    return 0;

}
