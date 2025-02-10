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