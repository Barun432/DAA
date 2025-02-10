#include<stdio.h>
int partion(int arr[],int start , int end){
 int pos=start; 
 for(int i=start;i<=end;i++){
     if(arr[i]<=arr[end]){
     int temp=arr[pos];
     arr[pos]=arr[i];
     arr[i]=temp;
     pos++;
     }

 }     
 return pos-1;

}
void quicksort(int arr[],int start, int end){
    if(start>=end){
        return;
    }
     int r= (rand()%(end-start)+start);
     int temp= arr[start];
     arr[start]=arr[r];
     arr[r]=temp;
      int loc = partion(arr,start,end);
                quicksort(arr,start,loc-1);
                quicksort(arr,loc+1,end);
}
int main(){
int n;
     printf("Ente the size::");
      scanf("%d",&n);
       int arr[100];
      printf("Enter the Array Element::");
      for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
      }
         quicksort (arr,0,n-1);
         printf("\n");
        // after sorted array
         printf("AFTER SORTED ARRAY::  ");
         for(int i=0;i<n;i++){
            printf("%d  ",arr[i]);
         }
      }