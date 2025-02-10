#include<bits/stdc++.h>
using namespace std;
int fractional(vector<int>profit,vector<int>itemW,int capcity ,int n){
    vector<float>valuRatio;
    for(int i=0;i<n;i++){
      float ratio = (profit[i]*1.0)/itemW[i];
      valuRatio.push_back(ratio);
    }
    priority_queue<pair<float,pair<int,int>>> maxi;
    for(int i=0;i<n;i++){
    maxi.push({valuRatio[i],{profit[i],itemW[i]}});
    }
    int totalans=0;
    while(!maxi.empty() && capcity!=0){
    auto front = maxi.top();
    float ratio = front.first;
    int gain= front.second.first;
    int wt = front.second.second;
     maxi.pop();
     if(capcity>=wt){
       totalans+=gain;
       capcity= capcity-wt;
     }
     else {
        int valueinclude = ratio * capcity;
        totalans+=valueinclude;
        capcity=0;
        break;
     }
     
    }
    return totalans;
}
int main (){
    vector<int>profit;
    vector<int>itemW;
    int n;
    cin>>n;
    int capcity;
     cin>>capcity;
     cout<<"profit"<<endl;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        profit.push_back(x);
     }
     cout<<"wt"<<endl;
     for(int i=0;i<n;i++){
        int y;
        cin>>y;
        itemW.push_back(y);
     }
     cout<<fractional(profit,itemW,capcity,n)<<endl;
     return 0;
}
     
// }
// #include<bits/stdc++.h>
// using namespace std;
// int slove(string a , string b , int i ,int j, vector<vector<int>>&dp){
//     if(i>=a.length()) {return 0;}
//     if(j>=b.length()){return 0;}
//     if(dp[i][j]!=-1){return dp[i][j];   }
//     int ans=0;
//     if(a[i]==b[j]){
//         ans = 1 + slove(a,b,i+1,j+1,dp);
//     }
//     else{
//         ans = 0 + max(slove(a,b,i,j+2,dp),slove(a,b,i+1,j,dp));
//     }
//     dp[i][j]=ans;
//     return dp[i][j];
// }
//  int main(){
//     string s1;
//     string s2;
//      cout<<"Enter the two string ::"<<endl;
//       cin>>s1;
//       cin>>s2;
//       int i=0; int j=0;
//       vector<vector<int>>dp(s1.length()+1 ,vector<int>(s2.length()+1,-1));
//       cout<<slove(s1,s2,i,j,dp);
//  }