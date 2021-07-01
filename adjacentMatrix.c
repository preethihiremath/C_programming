#include<stdio.h>
#include<stdlib.h>
int m,n;
void create_adjacent(int adj[][n+1],int arr[][2])
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            adj[i][j]=0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}
void print_adjacent(int adj[][n+1])
{
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter n(no. of vertices) : ");
    scanf("%d",&n);
    printf("Enter m(no. of edges) : ");
    scanf("%d",&m);
    int arr[m][2];
    for(int i=0;i<m;i++)
    {
        printf("Enter edge %d : ",i+1);
        for(int j=0;j<2;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int adj[n+1][n+1];
    create_adjacent(adj,arr);
    print_adjacent(adj);
    return 0;
}