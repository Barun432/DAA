#include<stdio.h>
int insertion(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    } 
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
        insertion(arr,n);
         printf("\n");
        // after sorted array
         printf("AFTER SORTED ARRAY::  ");
         for(int i=0;i<n;i++){
            printf("%d  ",arr[i]);
         }
      }