#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<unordered_map>
#include<list>
using namespace std;
class A{
  public:
  unordered_map<int,list<pair<int,int>>>adjlist;
  void addedge(int u,int v,int wt,bool direction){
    if(direction==0){
        adjlist[u].push_back({v,wt});
    }
    else{
         adjlist[u].push_back({v,wt});
          adjlist[v].push_back({u,wt});
    }}
  void bellmanford(int n ,int src){
    //intial state ..
    vector<int>dist (n+1,INT_MAX);
    dist[src]=0;
    // n-1 time<->relaxation..
    for(int i=0;i<n;i++){
        for(auto a : adjlist){
            for(auto b : a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                if(dist[u]!=INT_MAX && dist[u]+wt <dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }} }
    //print the distance...
    for(auto i : dist){
        if(INT_MAX==i){continue;}
        else{
            cout << i << " ";
        }
    }}
};
int main (){
    A d;
    d.addedge(0,1,-1,0);
    d.addedge(0,4,4,0);
    d.addedge(1,2,2,0);
    d.addedge(1,3,1,0);
    d.addedge(1,4,3,0);
    d.addedge(2,3,-3,0);
    d.addedge(3,1,2,0);
    d.addedge(3,4,5,0);
    d.bellmanford(5,0);
    return 0;
}
