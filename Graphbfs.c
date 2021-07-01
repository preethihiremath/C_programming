#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100  

int n;    
int adj[MAX][MAX];          
int visited[MAX];             
void create_graph();
void BFS();
 
int queue[MAX], front = -1,rear = -1;

int isEmpty_queue()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}
 
void push_queue(int vertex)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = vertex ;
   }
}
 

 
int pop_queue()
{
   int delete_item;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }
   
   delete_item = queue[front];
   front = front+1;
   return delete_item;
}
 
void create_graph()
{
   int count,max_edge,origin,dest;
 
   printf("Enter no of vertices: ");
   scanf("%d",&n);
   max_edge = n*(n-1); 
 
   for(count=1; count<=max_edge; count++)
   {
      printf("Enter edge %d or -1 -1 to quit: ",count);
      scanf("%d%d",&origin,&dest);
 
      if((origin == -1) && (dest == -1))
         break;
 
     
      else
      {
         adj[origin][dest] = 1;
      }
   }
}
 
void BFS()
{
    int v,i;
   for(v=0; v<n; v++)
      visited[v] = 0;
   
   printf("Enter Start Vertex for BFS: \n");
   scanf("%d", &v);
   push_queue(v);
   while(!isEmpty_queue())
   {
       
      v = pop_queue( );
       if(visited[v])
           continue;
           
      printf("%d ",v);
      visited[v] = 1;
      
      for(i=0; i<n; i++)
      {
         if(adj[v][i] == 1 && visited[i] == 0)
         {
            push_queue(i);
         }
      }
   }
   printf("\n");
}
int main()
{
   create_graph();
   BFS();
   return 0;
}