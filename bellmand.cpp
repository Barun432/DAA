#include<bits/stdc++.h>
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
      void bellmanFord(int n, int src,int dest) {
		//initial state
		vector<int> dist(n+1,INT_MAX);
		dist[src] = 0;
		//N-1 times -> RELAXATION
		for(int i=1; i<n; i++) {
			//tarverse on entire edge list
			for(auto a: adjlist) {
				for(auto b: a.second) {
					int u = a.first;
					int  v = b.first;
					int wt = b.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
			}
		}
        //    cout << "PRINT DISTANCE ARRAY:" << endl;
        // for (int i = 1; i <= n; i++) {
        //     if (dist[i] == INT_MAX) {
        //         cout << "INF ";
        //     } else {
        //         cout << dist[i] << " ";
        //     }
        // }
        // cout << endl;
        cout<<"from src to des"<< dist[dest];
    }
           
    
 };
//  1 2 4
// 1 3 1
// 2 5 4
// 3 2 2
// 3 4 41 2 4
// 4 5 4
 int main (){
     Graph g;
    int n; // Number of edges
    cout << "Enter number of edges: ";
    cin >> n;
    
    cout << "Enter edges (u v wt) format:" << endl;
    for (int i = 0; i < n; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addegde(u, v, wt, 0);
    }
//     0 1 10 
// 0 2 3
// 0 3 2
// 1 3 7
// 2 3 6
    
    int src;
    cout << "Enter source node: ";
    cin >> src;
    int dest;
    cin>>dest;
   g.bellmanFord(src,n,dest);

 }

