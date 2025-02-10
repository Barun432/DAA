#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
using  namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adjlist;
    void addedge (int u,int v,bool direction){
        if(direction==1){
            adjlist[u].push_back(v);
        }
        else{
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        }
    }
   void print(){
    for(auto i : adjlist){
    cout<<i.first<<"->{";
    for(auto nbr : i.second){
        cout<<nbr<<",";
    }
    cout<<"}"<<endl;
    }
   }
bool checkcycle(int src){
    queue<int>q;
    unordered_map<int,bool> vis;
    unordered_map<int,int>parents;
    q.push(src);
     vis[src]=true;
     parents[src]=-1;
     while(!q.empty()){
     int frontnode = q.front();
     q.pop();
      
      for(auto nbr : adjlist[frontnode]){
           if(!vis[nbr]){
            q.push(nbr);
            vis[nbr]=true;
            parents[nbr]=frontnode;
           }
        else if(vis[nbr]==true && nbr !=parents[frontnode]){
            return true;
      }
     
      }
     }
      return false;
   }
  
};
int main(){
    graph g;
    g.addedge(1,2,0);
   g.addedge(2,5,0);
   g.addedge(2,3,0);
   g.addedge(5,4,0);
   g.addedge(3,4,0);
   g.addedge(5,6,0);
   g.print();
   bool iscycle = g.checkcycle(1);
 if(iscycle){
    cout<<"cycle present";

 }
 else
    cout<<"not prsent";


}