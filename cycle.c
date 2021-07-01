#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check2(int n, int GRAPH[n][n], int VISITED[n],int whereAmI,int  whereWasI){
    int FLAG = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == whereWasI)
            continue;
        
        if(GRAPH[whereAmI][i]!=0 && GRAPH[whereAmI][i]!=-1){
            if(VISITED[i]==1)
                return 1;
            VISITED[i] = 1;
            FLAG = check2(n, GRAPH, VISITED, i, whereAmI);
            if (FLAG == 1)
                return 1;            
        }
    }    
    return 0;
}

int checkCycle(int n, int GRAPH[n][n]){
    int VISITED[n];

    for (int i = 0; i < n; i++)
    {
        VISITED[i] = 0;
    }
    int whereAmI = 0;
    int whereWasI = -1;
    
    VISITED[whereAmI] = 1;
    return check2(n,GRAPH, VISITED, whereAmI, whereWasI);
}

int main(){
    int n;
    printf("Enter the number of Vertices: ");
    scanf("%d",&n);
    int GRAPH[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                GRAPH[i][j] = 0;
            }else if (i<j) 
            {
                printf("Enter the distance between Node %d to %d(Enter '-1' for no edge) ",i+1,j+1);
                scanf("%d",&GRAPH[i][j]);
                GRAPH[j][i] = GRAPH[i][j];
            }
        }        
    }

    printf("\nThe Adjency Matrix is: ");
    printf("[");
    for(int i = 0; i < n; i++)
    {
        printf("\n[");
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", GRAPH[i][j]);
        }
        printf("]");
    }
    printf("\n]");  
    if(checkCycle(n, GRAPH) ){
        printf("\nGRAPH HAS CYCLES:\n");
    }else
    {
        printf("\nGRAPH HAS NO CYCLES:\n");
    }
    
}