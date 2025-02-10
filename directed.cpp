// #include<bits/stdc++.h>
// using namespace std;
// class Graph {
//     public:
//     unordered_map<int,list<int>>adj;
//      void addedge(int u , int v , bool direction){
//         if(direction==1){
//             adj[u].push_back(v);
//         }
//      }
// //      bool check(int src){
// //         unordered_map<int,bool>vis;
// //         unordered_map<int,int>parents;
// //         queue<int>q;
// //         q.push(src);
// //         vis[src]=true;
// //         parents[src]=-1;
// //          while(!q.empty()){
// //             int frontnode = q.front();
// //             q.pop();

// //             for(auto nbr : adj[frontnode]){
                
// //                 if(!vis[nbr]){
// //                     q.push(nbr);
// //                     vis[nbr]=true;
// //                     parents[nbr]=frontnode;
// //                 }
// //              else if( vis[nbr]==true && nbr != parents[frontnode]){
// //                 return true;
// //              }
// //             }

// //          }
// //          return false;
// //      }
//          bool check(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfs) {
//         vis[src] = true;
//         dfs[src] = true;

//         for (auto nbr : adj[src]) {
//             if (!vis[nbr]) {
//                 bool ans = check(nbr, vis, dfs);
//                 if (ans) return true;
//             } else if (dfs[nbr]) {
//                 return true;
//             }
//         }
//         dfs[src] = false;
//         return false;
//     }

// };

//  int main(){
//     Graph g;
//     int edge;
//    cin>>edge; // no of edge...

//     for(int i=0;i<edge;i++){
//          int x,y,z;
//         cin>>x>>y;
//         g.addedge(x,y,1);

// //     }
// //     // g.addedge(0,1,1);
// //     // g.addedge(1,2,1);
// //     // g.addedge(1,3,1);
// //     // g.addedge(2,5,1);
// //     // g.addedge(2,4,1);

   
//         int src;
//         cin>>src;
//          unordered_map<int, bool> dfs;
//          unordered_map<int, bool> vis;
//             bool iscyclic = g.check(src,vis,dfs);
//             if(iscyclic){
//                 cout<<"yes cycle present";
            
//             }
//             else{
//                 cout<<"No cycle Exits";
               
//             }
//         }
//  }
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool direction) {
        if (direction == 1) {
            adj[u].push_back(v);
        }
    }

    bool check(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfs) {
        vis[src] = true;
        dfs[src] = true;

        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                bool ans = check(nbr, vis, dfs);
                if (ans==true) return true;
            } else if (dfs[nbr]==true && vis[nbr]==true) {
                return true;
            }
        }
        dfs[src] = false;
        return false;
    }
};

int main() {
    Graph g;
    int n; // Number of edges
    cout << "Enter the number of edges: ";
    cin >> n;

    cout << "Enter the edges (format: u v for a directed edge from u to v):" << endl;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 1);
    }

    int src;
    cout << "Enter the source vertex to start cycle detection: ";
    cin >> src;

    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfs;
    bool iscyclic = g.check(src, vis, dfs);

    if (iscyclic) {
        cout << "Yes, cycle present" << endl;
    } else {
        cout << "No cycle exists" << endl;
    }

    return 0;
}


 