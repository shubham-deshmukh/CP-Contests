#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
vector<long long> topological_sort(vector<vector<long long>> &adj) {
    vector<long long> ans;
    long long n = (long long) adj.size();
    vector<long long> ind(n,0);

    // Calculate the indegree of each node
    for(int u = 0; u < n; u++) {
        for(auto v: adj[u]) {   
            ind[v]++;
        }
    }

    queue<long long> q;
    // start the sort from nodes which has 0 indegree
    for(int i = 0; i < n; i++) {
        if(ind[i] == 0) 
            q.push(i);
    }

    if(q.empty()) {
        cout << "No Directed Acyclic Graph";
        return {-1};
    }

    while(!q.empty()) {
        long long u = q.front();
        q.pop();

        ans.push_back(u); // store the order

        for(auto v: adj[u]) {
            ind[v]--; // remove the edge
            if(ind[v]==0) // Do all edges removed from parent?
                q.push(v);
        }
    }

    if((long long)ans.size() != n) {
        cout << "No Directed Acyclic Graph";
        return {-1};
    }

    return ans;
}

void solve() {
    // Approach : Dynamic Programming + Topological sort
    /*
    TODO: 
    Couldn't figure out why remaining test cases are failing.
    */
    int n,m;
    cin >> n >> m;

    vector<vector<long long>> adj(n);
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        
        from--;to--;
        adj[from].push_back(to);
    }

    vector<long long> order = topological_sort(adj);
    // for(auto o: order) cout << o << " ";

    if((long long) order.size() != n) {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<long long> len(n,0);
    vector<long long> parent(n,-1);

    // len[v] : longest length of the path to node v from src (0)
    
    for(auto u: order) {
        for(auto v: adj[u]) {
            // len[v] = max(len[v],len[u]+1);
            if(len[v] < len[u]+1) {
                len[v] = len[u]+1;
                parent[v] = u;
            }
        }
    }

    // cout << len[n-1];
    int x = n-1, src = 0;
    vector<long long> path;
    bool unreachable = false;
    while(x != src) {
        path.push_back(x);
        x = parent[x];
        if(x == -1) {
            unreachable = true;
            break;
        }
    }

    if(unreachable) { // is target unreachable?
        cout << "IMPOSSIBLE";
        return;
    }

    path.push_back(src);
    reverse(path.begin(), path.end());

    cout << (long long) path.size() << endl;
    for(auto p: path) cout << p+1 << " ";

}

int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}