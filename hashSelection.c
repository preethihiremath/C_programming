#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct node
{
    int data;
    struct node *next;
};

struct node *head[SIZE]={NULL},*c;

void insert()
{
    int i,key;
    printf("\nEnter a value to insert into hash table\n");
    scanf("%d",&key);
    i=key%SIZE;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next = NULL;
    if(head[i] == NULL)
        head[i] = newnode;
    else
    {
        c=head[i];
        while(c->next != NULL)
        {
           c=c->next;
        }
        c->next=newnode;
    }
}

void display()
{
    int i;
    for(i=0;i<SIZE;i++)
          {
           printf("\nHash[%d]: ",i);
               if(head[i] == NULL)
               {
               printf("Empty hash table");
               
               }
               else
               {
                              for(c=head[i];c!=NULL;c=c->next)
                              printf("%d->",c->data);
               }
          }
         
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                 exit(0);
                                           
        }
    }
}