#include<iostream>
#include<list>
#include<vector>
#include<limits.h>
#include<algorithm>

#include<unordered_map>
using namespace std;
 class Graph{
    public:
      unordered_map<int , list<pair<int,int>>>adjlist;

       void addegde(int u,int v,int wt, bool direction){
        if(direction==0){
            adjlist[u].push_back({v,wt});
        }
        else{
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});

        }
       }
    //     void print() {
    //     for(auto i : adjlist){
    //         cout<<i.first<<"->";
    //         for(auto j : i.second){
    //             cout<<"{"<<j.first<<","<<j.second<<"}";
    //         }
    //         cout<<endl;
    //     }
        
    //    }
    static bool mycomp(vector<int>&a , vector<int>&b){
        return a[2]<b[2];
    }
    int findparents(vector<int>&parents , int node){
        if(parents[node]==node){
            return node;
        }
        return parents[node]=findparents(parents,parents[node]); // path compression.
    }
    void unionsSet(int u, int v , vector<int>&parents, vector<int>&rank){
        u = findparents(parents,u);
        v= findparents(parents,v);

        if(rank[u]<rank[v]){
            parents[u]=v;
            rank[v]++;
        }
        else{
            parents[v]=u;
            rank[u]++;
        }
    }
   void kruskal(int v){
    vector<int>parents(v);
    vector<int>rank(v,0);

    //make all the node have own comp.
    for(int u=0;u<v;u++){
        parents[u]=u;
    }
    // make a edge linear data.. (u,v,wt).
    vector<vector<int>>edges;
    for(int u=0;u<v;u++){
     for(auto edge :adjlist[u]){
        int v = edge.first;
        int wt = edge.second;
        edges.push_back({u,v,wt});
     }
    }
    sort(edges.begin(),edges.end(),mycomp);
int ans=0;
    for(auto a : edges ){
        int u = a[0];
        int v = a[1];
        int wt = a[2];
         u = findparents(parents,u);
         v = findparents(parents , v);
        if(u!=v){
            
           unionsSet(u,v,parents,rank);
            ans= ans+wt;
        }
    }
    cout<<" MINIMUM SPANNING TREE :: "<<ans;
   }
       
 };

 int main(){
    Graph g;
    g.addegde(0,1,2,1);
    g.addegde(0,3,6,1);
    g.addegde(1,3,8,1);
    g.addegde(1,2,3,1);
    g.addegde(1,4,5,1);
    g.addegde(2,4,7,1);
        g.kruskal(5);
  

 }