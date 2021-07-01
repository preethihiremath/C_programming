#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}
 int partition(int arr[], int left, int right)
{
   int pivot = left;
   int l= left+1;
   int r= right;
   while(l<=r)
   {
       while(arr[l]<=arr[pivot])
       {
           l++;
       }
       while(arr[r]>arr[pivot])
       {
           r--;
       }
       if(l<r)
       {
           swap(&arr[l],&arr[r]);
       }
   }
   swap(&arr[r],&arr[pivot]);
   return r;
}
 
void quick_sort(int a[],int l,int r)
{
   int j;
   if(l<r)
 
   {
       j=partition(a,l,r);
       quick_sort(a,l,j-1);
       quick_sort(a,j+1,r);
   }
}
 
void delay(int s)
{
   int ms = 1000 *s;
   clock_t start;
   start = clock();
   while (clock() < start + ms);
}
 
int main(){
  int i, n, array[2000];
   clock_t stime, etime;
   printf("Enter no of elements:");
   scanf("%d",&n);
   printf("Enter array elements:\n");
  
   for(int i=0;i<n;i++)
   { 
   array[i]=rand();
   }
   printf("\nArray before Sorting is :");
   for(int i=0;i<n;i++){
       printf("%d ",array[i]);
   }
   stime=clock(); 
   delay(3000);
   quick_sort(array,0,n-1);
   etime=clock();
 
   printf("\n\nSorted array is :");
   for(int i=0;i<n;i++){
       printf("%d ",array[i]);
   }
 printf("\nStart time: %lf\tEnd time: %lf",(float)stime,(float)etime);
 printf("\nTotal time to sort %d elements=%f\n", n , difftime(etime,stime)/CLOCKS_PER_SEC);   
  return 0;
}
