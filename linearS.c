// linear search is a technique where we can search  one by one. where its time complexity: TC=0(n).if element found then return true otherwise false.and also if array go out of bound.

// 
// function call
// #include<stdio.h>
// int search(int arr[], int n, int target){
//     int  found=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             found=i;
//             return found;
//         }
//     }
//     return -1;
// }
//  int main(){
//      int n;
//       printf("Enter the size::");
//       scanf("%d",&n);
//        int arr[100];
//        printf("Enter the Array Elment ::");
//        for(int i=0;i<n;i++){
//          scanf("%d",&arr[i]);
//        }
//        int target;
//        printf("Enter the target::");
//        scanf("%d",&target);
//        int result= search(arr,n,target);
//        if(result==-1){
//         printf("not");
//        }
//        else{
//         printf("found at index %d",result);
//        }
//  }
 // linear search is a technique where we can search  one by one. where its time complexity: TC=0(n).if element found then return true otherwise false.and also if array go out of bound.

// 
// recursive call
#include<stdio.h>
int search(int arr[], int n, int i,int target){
    if(i>=n)
    return -1;
if(arr[i]==target)
  return i;

return search(arr,n,i+1,target);
}
 int main(){
     int n;
      printf("Enter the size::");
      scanf("%d",&n);
       int arr[100];
       printf("Enter the Array Elment ::");
       for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
       }
       int target;
       printf("Enter the target::");
       scanf("%d",&target);

       int result= search(arr,n,0,target);

       if(result==-1){
  printf("not found");
       }
       else{
  printf("found at index %d",result);
       }
 }