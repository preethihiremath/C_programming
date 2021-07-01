#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int temp;  
  
void heapify(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  {
    largest = left;  
}

if (right < size && arr[right] > arr[largest])  {
    largest = right; 
}
 
  
if (largest != i)  
    {  
        temp = arr[i];  
        arr[i]= arr[largest];   
        arr[largest] = temp;  
        heapify(arr, size, largest);  
    }  
}  
  
void heapSort(int arr[], int size)  
{  
int i;  
for (i = size / 2 - 1; i >= 0; i--)  {
heapify(arr, size, i);  
for (i=size-1; i>=0; i--)  
    {  
        temp = arr[0];  
        arr[0]= arr[i];   
        arr[i] = temp;  
        heapify(arr, i, 0);  
    } 
}
 
}  
  
void main()  
{ 
    clock_t stime, etime; 
    int i, n; 
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    int array[n]; 
    int size = sizeof(array)/sizeof(array[0]); 

    printf("Enter the elements\n");  
    for(int i=0;i<n;i++)
    { 
        array[i]=rand();
    }
    printf("\nArray before Sorting is :");
   for(int i=0;i<n;i++){
       printf("%d ",array[i]);
   }

    stime=clock();		
    heapSort(array, size);  
    etime=clock();
    
    printf("\n\nSorted array is :");
   for(int i=0;i<n;i++){
                 printf("%d ",array[i]);
         }
    printf("\n\nStart time: %lf\tEnd time: %lf",(float)stime,(float)etime);
    printf("\nTotal time to sort %d elements=%f\n", n , difftime(etime,stime)/CLOCKS_PER_SEC);   	 
}