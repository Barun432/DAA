#include<bits/stdc++.h>
using namespace std;
int slove(vector<pair<int,int>>&ajdM){
    int n = ajdM.size()-1;
 vector<vector<int>>adj(n,vector<int>(n,0));
 for(auto i : ajdM){
    int u = i.first;
    int v = i.second;
    adj[u][v]=1;
 }
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<adj[i][j];
    }
    cout<<endl;
}
}
 int main (){
    vector<pair<int,int>>ajdM;
    ajdM.push_back({0,1});
    ajdM.push_back({0,2});
    ajdM.push_back({1,3});
    ajdM.push_back({1,2});
    ajdM.push_back({2,3});
    slove(ajdM);
 }