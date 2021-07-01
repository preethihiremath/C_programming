#include<stdlib.h>
#include<stdio.h>
#define MAX 25
int front=-1,rear=-1,V;
int queue[MAX];
int visited[MAX];
void enqueue(int i)
{   
    if(rear<=V-1)
    {
        if(front==-1)
        {
            front++;
        }
        rear++;
        queue[rear]=i;
    }
}
int isEmpty()
{
    if(rear==-1)
    {
        return 1;
    }
    return 0;
}
int dequeue()
{
    int x;
    if(!isEmpty())
   {    
       x = queue[front];
       front++;
       if(front>rear)
       {
           front=-1;
           rear=-1;
       }
       return x;
   }
   return -1;
}
struct node
{
    int vertex;
    struct node *next;
};
struct Graph
{                           
    int n;                                                                      //no. of vertices
    struct node** adjlists;                        
};
struct node* createnode(int v)                                                  //memory allocation for each node
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}
struct Graph* creategraph(int n)                                                 //memory allocation for a new graph
{
    struct Graph* newgraph= malloc(sizeof(struct Graph));
    newgraph->n = n;
    newgraph->adjlists = malloc(n*(sizeof(struct node)));
    for(int i=0;i<n;i++)
    {
        newgraph->adjlists[i] = NULL;
    }
    return newgraph;
}
void add_edge(struct Graph* graph, int src, int dest)
{
    struct node* newnode=createnode(dest);
    newnode->next = graph->adjlists[src];
    graph->adjlists[src] = newnode;
}
void print( struct Graph* graph)
{
    for(int i=1;i<=graph->n;i++)
    {
        struct node* temp = graph->adjlists[i];
        printf("adjacency list of vertex %d : ",i);
        while(temp!=NULL)
        {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("X\n");
    }
}
void BFS(struct Graph* graph,int i)
{
    visited[i] = 1;
    enqueue(i);
    printf("visited :");
    while(!isEmpty())
    {
        int x = dequeue();
        printf(" %d->",x);
        struct node* temp= graph->adjlists[x];
        while(temp!=NULL)
        {
            int connected = temp->vertex;
            if(visited[connected]==0)
            {
                visited[connected]=1;
                enqueue(connected);
            }
            temp=temp->next;
        }
    }
}
int main()
{
    int x,t;
    printf("Enter number of vertices in the graph : ");
    scanf("%d",&V);
    struct Graph* graph = creategraph(V);
    printf("Enter number of edges : ");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        int a,b;
        printf("Enter edge %d : ",i+1);
        scanf("%d %d",&a,&b);
        add_edge(graph,a,b);
    }
    for(int i=0;i<x;i++)
    {
        visited[i]=0;
    }
    printf("Enter initial vertex : ");
    scanf("%d",&t);
    BFS(graph,t);
    printf("X");
     printf("\n");
    return 0;

}