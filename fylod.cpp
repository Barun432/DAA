#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addegde(int u, int v, int wt, bool direction) {
        if (direction == 0) {
            adjlist[u].push_back({v, wt});
        } else {
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }
    }

    void flyod(int n,vector<vector<int>>&dist) {
      

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto a : adjlist) {
            for (auto b : a.second) {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
           for (int helper = 0; helper < n; helper++){
                for (int src = 0; src < n; src++) {
           
                for (int dest = 0; dest < n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
               }
            
             }
              cout << "PRINT" << endl;
        for (int src = 0; src < n-1; src++) {
            for (int dest = 0; dest < n-1; dest++) {
                cout << dist[src][dest] << " ";
            }
            cout << endl;
        } 

       
        }
    
};

int main() {
    Graph g;
    int m;
    cout<<"enter the no vertices";
    cin>>m;
    int n; // Number of edges
    cout << "Enter number of edges: ";
    cin >> n;
    int x,y;
    cout<<"src to dest";
    cin>> x>>y;
     vector<vector<int>> dist(n, vector<int>(n, 1e9));

    cout << "Enter edges (u v wt) format:" << endl;
    for (int i = 0; i < n; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addegde(u, v, wt, 0);
    }

    g.flyod(n,dist);
    cout<<"from src to dest"<<dist[x][y];
    return 0;
}
