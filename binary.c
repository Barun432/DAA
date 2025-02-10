// #include<stdio.h>
// int  main(){
//      int n;
//      int found=-1;
//      int index=-1;
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
//         int s=0;
//         int e=n-1;
     
          
//         while(s<=e){
//             int mid=s+(e-s)/2;
//             if(arr[mid]==target){
//             found=1;
//             index=mid;
            
//                  break;
//             }  
//              else if(arr[mid]>target)
//                 e=mid-1;
//                else
//                s=mid+1;
//         }
        
//         if(found!=0){
//   printf("index found at %d",index);
//         }
//         else{
//             printf("not");
//         }
     
// }
//   function call......................................
// #include<stdio.h>
// int binary(int arr[],int start,int end, int target){
//      while(start<=end){
//          int mid=start+(end-start)/2;
//                   if(arr[mid]== target){
//                     return mid;
//                   }
//                   else if( arr[mid]> target)
//                   end=mid-1;
//                   else
//                   start=mid+1;
//                   }
//                   return -1;
//      }
//       int main(){
//          int n;
//           printf("Enter the size");
//            scanf("%d",&n);
//             int arr[100];
//              printf("Enter the Array Element");
//               for(int i=0;i<n;i++){
//                  scanf("%d",&arr[i]);
//               }
              
//                int target;
//                 printf(" Enter the target::");
//                  scanf("%d",&target);
//                int ans= binary(arr,0,n-1, target);
//                if(ans==-1){
//               printf("not");

//                }
//                else{
//                 printf("TARGET FOUND AT INDEX %d",ans);
//                } 
//                }

// recurison......................
#include<stdio.h>
 int binary(int arr[], int start, int end, int target){
    if(start>end){
        return -1;
    }
     while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    
    else if(arr[mid]>target) 
    return binary(arr,start,mid-1,target);
    else
    return binary(arr, mid+1,end,target);
     }
     return -1;
 }
  int main(){
    int n;
     printf("Enter the size::");
     scanf("%d",&n);
     int arr[100];
     printf("Enter the Array Element::");
      for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
      }
      int target;
       printf("Enter the target::");
       scanf("%d",&target);
       int result=binary(arr,0,n-1,target);
       if(result!=-1){
        printf("TARGET FOUND AT INDEX::%d", result);
       }
       else{
        printf("TARGET NOT FOUND ");
       }
  }

                    
