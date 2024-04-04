#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {

  int n, m; // cities, roads
  cin >> n >> m;
  
  int src, target;
  cin >> src >> target;
  
  vector<int> mines(n);
  for(auto &mine: mines) cin >> mine;
  
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    
    if(mines[u] or mines[v])
      continue;
    
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  
  auto bfs = [&](int src)->vector<int> {
    queue<int> q;
    vector<bool> vis(n,false);
    vector<int> dist(n, INT_MAX);
    
    vis[src] = true;
    dist[src] = 0;
    q.push(src);
    
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      
      for(auto v: g[u]) {
        if(!vis[v]) {
          vis[v] = true;
          dist[v] = 1 + dist[u];
          q.push(v);
        }
      }
    }
    return dist;
  };

  vector<int> dist = bfs(src);
  if(dist[target] == INT_MAX) cout << -1;
  else cout << dist[target];
  return 0;

}