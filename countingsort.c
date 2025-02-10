#include <stdio.h>
#include <stdlib.h>
void countingSort(int arr[], int n, int max) {
    int count[max + 1], a[n];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        a[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    //copy element..
    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }
} 
 int main(){
 int n= 6;
 int max=0;
      int arr[n];
     printf("Enter Array Element");
      for(int i=0;i<n;i++){
      scanf( "%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
      }
      countingSort(arr,n,max);

    printf("Sorted array: ");

      for (int i = 0; i<n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");

 }