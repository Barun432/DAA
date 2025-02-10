#include<bits/stdc++.h>
using namespace std;
static bool comp(int a, int b){
    return a>b; //dec.order..
}
int slove(vector<int>&profit ,vector<int>&deadline , int n){
    sort(profit.begin(),profit.end(),comp);
    bool gantchat[n]={0};
    int day=0; int pro=0;
    for(int i=0;i<n;i++){
        for(int j=min(n,deadline[i]-1);j>=0;j--){
            if(gantchat[j]==false){
                day+=1;
                pro+=profit[i];
                gantchat[j]=true;
                break;
            }
        }
    }
    return pro;
}

int main(){
    vector<int>profit;
    vector<int>deadline;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        profit.push_back(x);
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        deadline.push_back(y);
    }
 
    cout<<slove(profit,deadline,n);
}