#include<bits/stdc++.h>
using namespace std;
int fractional(vector<int>&profit ,vector<int>&itemW, int n, int capcity,int index,vector<vector<int>>&dp){
    if(index>=n || capcity<=0){return 0;}
    if(dp[capcity][index]!=-1){return dp[capcity][index];}
    int include=0;
    if(itemW[index]<=capcity){
        include = profit[index] + fractional(profit ,itemW,n,capcity-itemW[index],index+1,dp);
    }
    int exclude = 0 + fractional(profit,itemW,n,capcity,index+1,dp);
    dp[capcity][index] = max(include,exclude);
    return dp[capcity][index];
}
 int main(){
    vector<int> profit;
    vector<int> itemW;
    int n;
    cin>>n;
    int capcity;
    cin>>capcity;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        profit.push_back(x);
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        itemW.push_back(y);
    }
    int index=0;
    vector<vector<int>>dp(capcity+1,vector<int>(n+1,-1));
    cout<<fractional(profit,itemW,n,capcity,index,dp)<<endl;

    return 0;
 }