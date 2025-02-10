#include<stdio.h>
int flag=0;
int bubble(int arr[], int n){
      for(int i=0;i<n-1;i++){
           flag=0;
           for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
               flag=1;

            }
           }
           if(flag==0){
               break;
           }
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
        bubble(arr,n);
         printf("\n");
        // after sorted array
         printf("AFTER SORTED ARRAY");
         for(int i=0;i<n;i++){
            printf("%d",arr[i]);
         }
      }
      
