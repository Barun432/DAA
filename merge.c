#include<stdio.h>
void merge(int arr[], int start, int mid, int end){
     int left=start;
      int right=mid+1;
      int index=0;
      int n1= end-start+1;
      int temp[n1];
      while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            index++,left++;
        }
        else{
            temp[index]=arr[right];
            index++,right++;
        }
      }
      while(left<=mid){
        temp[index]=arr[left];
        index++,left++;
      }
      while(right<=end){
       temp[index]=arr[end];
       index++,right++;
      }
      index=0;
      while(start<=end){
      arr[start]=temp[index];
        index++,start++;
      }
}
 void mergesort(int arr[], int start , int end){
    if(start==end){
        return;
    }
     int mid= start+(end-start)/2;
     mergesort(arr,start,mid);
     mergesort(arr,mid+1,end);
      merge(arr, start,mid,end);
 }
  int main(){
     int n;
     printf("Enter the size::");
     scanf("%d",&n);
      int arr[100];
     printf("Enter the Array Element");
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
     mergesort(arr,0,n-1);
     printf("ARRAY SORTED ELEMENT::");
      for(int i=0;i<n;i++){
        printf("%d",arr[i]);
     }
  }