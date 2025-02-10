#include<stdio.h>
#include<stdlib.h>
 int heapify(int arr[], int n , int index){
     int left = (2*index);
     int right = 2*index +1;
     int largest = index;
   if(left<=n && arr[left]> arr[largest]){
        largest=left;
   }
    if(right<=n && arr[right]> arr[largest]){
        largest= right;
    }
     if(largest!=index){
        int temp = arr[largest];
        arr[largest]= arr[index];
        arr[index]=temp;
        index=largest; // becoz largest update.
        heapify(arr,n,index);
     }
 }
     void buildheap(int arr[] ,int n ) {
        for(int index=n/2; index>0;index--){
        heapify(arr,n,index);
   }
     }
     void heapsort(int arr[], int n){
        while(n!=1){
            int temp = arr[1];
            arr[1]= arr[n];
            arr[n]=temp;
            n--;
            heapify(arr,n,1);
        }
     }
 int main(){

     int n= 6;
      int arr[n];
     printf("Enter Array Element");
      for(int i=0;i<=n;i++){
      scanf( "%d", &arr[i]);
      }
      buildheap(arr,n);
      printf("Build Heap Array::");
      for(int i=1;i<=n;i++){
       printf("%d \t",arr[i]);
      }
       printf("\n");
      heapsort(arr,n);
     printf(" Heap  Sort Array::");
      for(int i=1;i<=n;i++){

      printf("%d \t", arr[i]);
      }
  printf("\n");     
 }    
 