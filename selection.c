#include<stdio.h>
 int Selection( int arr[], int n){
     for(int i=0;i<n-1;i++){
         int min= i;
         for(int j=i+1;j<n; j++){
            if(arr[min]>arr[j]){
                min=j;
            }
         }
         int temp=arr[min];
         arr[min]=arr[i];
         arr[i]=temp;
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
         Selection (arr,n);
         printf("\n");
        // after sorted array
         printf("AFTER SORTED ARRAY::  ");
         for(int i=0;i<n;i++){
            printf("%d  ",arr[i]);
         }
      }