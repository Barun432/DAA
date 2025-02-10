#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
public:
unordered_map<int,list<int>> adjlist;
 void addedge (int u , int v , bool direction ) {
  //0->directed graph
  //1->undirected graph.
   if(direction==0){
    adjlist[u].push_back(v);
   }
   else{
   adjlist[u].push_back(v);
   adjlist[v].push_back(u);
   }
 }
 void dfs (int src){
     unordered_map<int,bool> vis;
     //marks visted.
     vis[src]=true;
     //print
     cout<<src<<" ";
     //move to neighbour of node
     for(auto nbr : adjlist[src]){
        if(!vis[nbr]){
            dfs(nbr);
        }
     }
 }
};
int main(){
    Graph g;
    g.addedge(0,1,0);
    g.addedge(0,2,0);
    g.addedge(2,3,0);
    g.addedge(2,4,0);
    g.addedge(4,5,0);
    g.dfs(0);
}