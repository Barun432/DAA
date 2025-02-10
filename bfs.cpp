#include<bits/stdc++.h>
using namespace std;
void bfs(int src){
    unordered_map<int,bool>vis;
    queue<int>pq;
    pq.push(src);
    vis[src]=true;
    while(!q.empty()){
        int frontnode = q.front();
        cout<<frontnode;
        q.pop();
        for(auto nbr : adjlist[frontnode]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr]=true;
            }
        }
    }

}
// DFS...........
int dfs(int src){
    vis[src]=true;
    cout<<src;
   for(auto nbr : adjlist[frontnode]){
            if(!vis[nbr]){
             dfs(nbr);
            }
}