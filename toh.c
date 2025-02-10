#include<stdio.h>
    void TOH(int n, char a, char b, char c){
        if(n==0){
            return;
        }
        TOH(n-1,a,c,b);
        printf("MOVE DISK %d FRROM  ROd%c to %c ",n ,a, c);
        printf("\n");
        TOH(n-1,a,b,c);
    }
    int main(){
    int n;
     printf("Enter the size::");
     scanf("%d",&n);
     TOH(n,'A','B','C');
}