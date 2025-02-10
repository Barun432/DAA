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
 void bfs (int src){
     unordered_map<int,bool>vis;
     queue<int>q;
     //push into queue & mark visited true..
     q.push(src);
     vis[src]=true;
     // pop the node in queue. untill empty.
     cout<<"BFS ORDER::";
    while(!q.empty()){
         int frontnode = q.front();
           cout << frontnode;
             q.pop();
         // traverse neighbour of node.
         for(auto nbr : adjlist[frontnode]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr]=true;
            }
         }

    }
 }
};
int main(){
    Graph g;
    g.addedge(0,1,0);
    g.addedge(0,2,0);
    g.addedge(1,2,0);
    g.addedge(1,3,0);
    g.addedge(2,4,0);
    g.addedge(3,4,0);
     g.addedge(3,5,0);
    g.addedge(4,5,0);
    g.bfs(0);
}