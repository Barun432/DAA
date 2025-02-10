// #include<iostream>
// #include<list>
// #include<vector>
// #include<limits.h>
// #include<unordered_map>
// using namespace std;
//  class Graph{
//     public:
//       unordered_map<int , list<pair<int,int>>>adjlist;

//        void addegde(int u,int v,int wt, bool direction){
//         if(direction==0){
//             adjlist[u].push_back({v,wt});
//         }
//         else{
//             adjlist[u].push_back({v,wt});
//             adjlist[v].push_back({u,wt});

//         }
//        }
//     int minvalue(vector<int>&key,vector<int>&mst){
//       int minans=INT_MAX;
//       int index = -1;
//        for(int i=0;i<key.size();i++){
//          if(key[i]<minans && mst[i]==false){
//             minans=key[i]; // minans=(key[i],minans);
//             index=i;
//          }
//        }
//        return index;
//     }
//         void prim(int n){
//          //prims aglo
//            vector<int>key(n,INT_MAX);
//            vector<int>mst(n,false);
//            vector<int>parents(n,-1);
           
//            key[0]=0;
           
//          while(true){
//            //step 1: find min. value from key..
//            int u = minvalue(key,mst);
//            if(u==-1)break;
//            //step 2:  mst true marked..
//            mst[u]=true;
//            //step 3: process all the adj of u.
//             for( auto i : adjlist[u]){
//                int v=i.first;
//                int wt=i.second;
//                if(mst[v]==false && wt<key[v]){
//                   parents[v]=u;
//                   key[v]=wt;
//                }
//             }

//           }
//           //find the sum of nth of edge of MST..
//           int sum =0;
//          for(int i=0;i<parents.size();i++){
//              for(auto nbr : adjlist[i]){
//                if(parents[i]==-1)continue;
//                int v = nbr.first;
//                int wt = nbr.second;
//                if(v== parents[i]){
//                   cout<<i<<"->";
//                   cout<<"{"<<v<<","<<wt<<"}";
//                   cout<<endl;
//                   sum +=wt;
//                }
//              }
//          }
//         cout<<" MINIMUM SPANING TREE:"<< sum;
//        }
       
//  };

//  int main(){
//     Graph g;
//     g.addegde(0,1,2,1);
//     g.addegde(0,3,6,1);
//     g.addegde(1,3,8,1);
//     g.addegde(1,2,3,1);
//     g.addegde(1,4,5,1);
//     g.addegde(2,4,7,1);
//         g.prim(5);

///////////////////////////////maximum no spannig tree..........................
#include<bits/stdc++.h>
using namespace std;
class Graph{
   public:
     unordered_map<int , list<pair<int,int>>>adjlist;
   void addegde(int u,int v,int wt ,bool direction){
      if(direction==1){
         adjlist[u].push_back({v,wt});
      }
      else{
         adjlist[u].push_back({v,wt});
         adjlist[v].push_back({u,wt});

      }
   }
   int minval(vector<int>&key, vector<int>&mst){
      int index=-1;
      int minans= INT_MIN;
       for(int i=0;i<key.size();i++){
         if(key[i]>minans && mst[i]==false){
            index = i;
         }
       }
       return index;
   }
   void prim(int n){
      vector<int>key(n,INT_MIN);
      vector<int>mst(n,false);
      vector<int>parents(n,-1);
       
       key[0]=0;
      
   while(true){
       //find the min value from key..
        int u = minval(key,mst);
         if(u==-1){break;}
         //marked true.
         mst[u]=true;
         //nbr...
          for(auto nbr : adjlist[u]){
            int v= nbr.first;
            int wt = nbr.second;
            if( mst[v]==false  && key[v]<wt){
               parents[v]=u;
               key[v]=wt;
            }
          }
   }
   // for sum 
   int sum=0;
   for(int i=0;i<parents.size();i++){
       for(auto nbr : adjlist[i]){
         int v = nbr.first;
         int wt = nbr.second;
         if(parents[i]==v){
          sum+=wt;
         }
       }
   }
   cout<<"maxiumu no: spanning tree::"<<sum;
   }
};
int main(){
Graph g;
cout<<"Enter the number of vertices"<<endl;
 int n; // no of vertices..
 cin>>n;
cout<<"Enter the no : of Edges::"<<endl;
int m;
cin>>m;
// edge list create
for(int i=0;i<m;i++){
   int x,y,wt;
   cin>>x>>y>>wt;
   g.addegde(x,y,wt,0);
}
g.prim(n);
}