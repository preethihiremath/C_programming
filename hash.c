#include<stdio.h>
#include <stdlib.h>

#define size 7

int arr[size];


void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }

    if(arr[key] == -1)
    {    
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        for(int i=0; i<size; i++)
        {
        key = (key+i) % size;
        
        if(arr[key] == -1)
        {
              arr[key] = value;
              printf("%d neew inserted at arr[%d]\n", value,key);
              break;
        }
       }
       
    }
    else
    {
    printf("Unable to insert %d\n",value);
    printf("hash table is full\n");
    }
}

void delete(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void display()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    int choice, value;
    init();

     while(1)
     {
         
		printf("Implementation of Hash Table in C with Linear Probing \n\n");
		printf("MENU-: \n1.Inserting item in the Hashtable" 
                              "\n2. Deleting item from the Hashtable" 
                              "\n3.Searching an item in  Hashtable"
                              "\n4.Display Hashtable"
                              "\n5.exit"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice) 
                {
 
		case 1:
 
		      printf("Inserting element in Hashtable\n");
		      printf("Enter value-:\t");
		      scanf("%d", &value);
		      insert(value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hashtable \n Enter the value to delete-:");
		      scanf("%d", &value);
		      delete(value);
 
		      break;
 
		case 3:
 
		     printf("Searching in Hashtable \n Enter the value to search-:");
		      scanf("%d", &value);
		      search(value);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
         case 5: exit(1);
 
		default:
 
		       printf("Wrong Input\n");
 
		}
     }
   

    return 0;
}