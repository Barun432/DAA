#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<limits.h>
#include<vector>
using namespace std;
class A {
    public:
    unordered_map<int,list<pair<int,int>>> adjlist;
     void addedge(int u , int v ,int wt, bool direction){
        if(direction==1){
            adjlist[u].push_back({v,wt});   }
        else{
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});
        }   }
	void dijkstra(int n , int src , int dest){
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>> st;  
         st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto topelement = st.begin();
         pair<int,int>topPair = *topelement;
          int topnode = topPair.second;
          int topdist = topPair.first;
           st.erase(st.begin());

          for(auto nbr : adjlist[topnode]){
              int nbrnode = nbr.first;
              int nbrdist = nbr.second;
                if(topdist+nbrdist <dist[nbrnode]){
                auto preventry = st.find({dist[nbrnode],nbrnode});
                if(preventry!= st.end()){
                  st.erase(preventry);
                }
                dist[nbrnode]=topdist+nbrdist;
                st.insert({dist[nbrnode],nbrnode});
              }  }}
        cout<<"Shortest Distance from SRC to Dest::" << dist[dest];
  }   
};
// int main(){
//    A g;
//    g.addedge(1,3,5,0);
//    g.addedge(1,5,4,0);
//    g.addedge(2,5,1,0);
//    g.addedge(2,3,3,0);
//    g.addedge(5,4,2,0);
//    g.addedge(3,4,4,0);
//     int n=4;
//     int src =5;
//     int dest = 2;
//     g.dijkstra(n,src,dest);

   
// }
// #include<bits/stdc++.h>
// using namespace std;
// class Graph {
//     public:
//     unordered_map<int,list<pair<int,int>>> adjlist;
//      void addedge(int u , int v ,int wt, bool direction){
//         if(direction==1){
//             adjlist[u].push_back({v,wt});   }
//         else{
//             adjlist[u].push_back({v,wt});
//             adjlist[v].push_back({u,wt});
//         }   }
//          void dijkasrta(int src , int dest , int n){
//            vector<int> dist(n,-1);
//            set<pair<int,int>>st;
             
//              st.insert({0,src});
//              dist[src]=0;
             
//               while(!st.empty()){
//                 auto topelement = st.begin();
//                 pair<int,int>topnode = *topelement;
//                 int frontnode = topnode.second;
//                 int frontdist = topnode.first;
//                 st.erase(st.begin());

//                 for(auto nbr : adjlist[frontnode]){
//                   int nbrnode = nbr.first;
//                   int nbrdist = nbr.second;

//                   if(frontdist+nbrdist <dist[nbrnode]){
//                     auto preventry = st.find({dist[nbrnode],nbrnode});
//                     if(preventry!=st.end()){
//                       st.erase(preventry);
//                     }
//                     dist[nbrnode]= frontdist+nbrdist;
//                     st.insert({dist[nbrnode],nbrnode});
//                   }
//                 }
//               }
//            cout<<"src to dest"<<dist[dest];

//          }
//          0 1 10
// 0 2 3
// 0 3 2
// 1 3 7
// 2 3 6
// };
int main(){
  // A g;
  // cout<<"Enter the no of vertices"<<endl;
  // int n; // no of vertices
  // cin>>n;
  // cout<<"Enter the no of Edges"<<endl;
  // int m;
  // cin>>m;

  // for(int i=0;i<m;i++){
  //   int x,y,wt;
  //   cin>>x>>y>>wt;
  //   g.addedge(x,y,wt,0);
  // }
  // g.dijkstra(1,4,n);
    A g;
   g.addedge(1,3,5,0);
   g.addedge(1,5,4,0);
   g.addedge(2,5,1,0);
   g.addedge(2,3,3,0);
   g.addedge(5,4,2,0);
   g.addedge(3,4,4,0);
    int n=4;
    int src =5;
    int dest = 2;
    g.dijkstra(n,src,dest);

}