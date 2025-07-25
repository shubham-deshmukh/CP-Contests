#include <bits/stdc++.h>

using namespace std;

// #ifndef ONLINE_JUDGE
// #include "./debug.h"
// #else
// #define debug(x...)
// #endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.


const int MAX_N = 1e5;
const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

vector<int> parent, sz;
int comp = 0;

int find(int u) {
    if(parent[u] == u)
        return u;
    
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if(root_u == root_v) 
        return false;
    
    if(sz[root_u] < sz[root_v]) {
        swap(root_u, root_v);
        swap(u, v);
    }

    parent[root_v] = root_u;
    sz[root_u] += sz[root_v];
    comp -= 1;

    return true;
}

void solve() {
    int n, q;
    cin >> n >> q;

    parent.assign(n+1,0);
    sz.assign(n+1,1);
    comp = n;

    iota(parent.begin(), parent.end(), 0);

    vector<int> A(n+1);
    vector<int> in_deg(n+1);
    vector<vector<int>> adj(n+1), revAdj(n+1);

    for(int i = 1; i <= n; i++) {
        // i --> A[i]
        cin >> A[i]; 
        
        adj[i].push_back(A[i]);
        revAdj[A[i]].push_back(i);

        unite(i,A[i]);
        in_deg[A[i]] += 1;
    }

    // Find out cycles if exists in each components
    // since each components can have atmost 1 cycle
    vector<int> vis(n+1), isCyclicNode(n+1), par(n+1), cycleInComp(n+1), len(n+1);
    auto dfs = [&](const auto &self, int u)->void {
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(!vis[v]) {
                par[v] = u;
                self(self,v);
            }
            else {
                // Found the cycle
                int x = u;
                int sz = 1;
                while(x != v) {
                    isCyclicNode[x] = 1;
                    x = par[x];
                    sz += 1;
                }
                isCyclicNode[v] = 1;
                int root_v = find(v);
                cycleInComp[root_v] = 1;
                
                // update the length of cycle
                x = u;
                while(x != v) {
                    len[x] = sz;
                    x = par[x];
                }
                len[v] = sz;
            }
        }
    };

    for(int i = 1; i <= n; i++) {
        int root_i = find(i);
        if(cycleInComp[root_i]) continue;

        dfs(dfs,i);
    }

    fill(vis.begin(), vis.end(),0);

    // compute depth for cyclic nodes
    vector<int> depth(n+1,-1);
    auto cycle_getDepth = [&](const auto &self, int u)->void {
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(vis[v]) continue;
            depth[v] = 1 + depth[u];
            self(self,v);
        }
    };

    for(int i = 1; i <= n; i++) {
        if(isCyclicNode[i]) {
            if(depth[i] == -1) {
                depth[i] = 0;
                cycle_getDepth(cycle_getDepth,i);
            }
        }
    }

    // Processing for chains
    // Find out root/nearest node to the chain
    vector<int> rootId(n+1);
    vector<int> nearestCyclicNode(n+1);

    auto chain_getRoot = [&](const auto &self, int u)->void {
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self,v);
                rootId[u] = rootId[v];
                nearestCyclicNode[u] = nearestCyclicNode[v];                
            }
            else {
                if(isCyclicNode[v]) {
                    rootId[u] = u;
                    nearestCyclicNode[u] = v;
                }
                else {
                    rootId[u] = rootId[v];
                    nearestCyclicNode[u] = nearestCyclicNode[v];
                }
            }

        }
    };



    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        chain_getRoot(chain_getRoot,i);
    }

    set<int> distictRoots(rootId.begin(),rootId.end());
    distictRoots.erase(0);
    fill(vis.begin(),vis.end(),0);
    
    vector<int> inTime(n+1,-1), outTime(n+1,-1);
    int timer = 0;
    auto chain_getDepth = [&](const auto &self, int u, int p)->void {
        inTime[u] = timer;
        timer += 1;
        vis[u] = 1;
        for(auto v: revAdj[u]) {
            if(vis[v]) continue;

            depth[v] = depth[u] + 1;
            self(self,v,u);
        }

        outTime[u] = timer;
        timer += 1;
    };

    for(auto &root: distictRoots) {
        timer = 0;
        depth[root] = 0;
        chain_getDepth(chain_getDepth,root,0);
    }

    for(int qi = 0; qi < q; qi++) {
        int a, b;
        cin >> a >> b;
        // a--> b
        if(find(a) != find(b)) { // Different compoenents
            cout << -1 << "\n";
            continue;
        }

        if(isCyclicNode[a] and isCyclicNode[b]) { // Both nodes belongs to cycle
            int steps = (depth[b] - depth[a] + len[a]) % len[a];
            cout << steps << "\n";
            continue;
        }
        else if(!isCyclicNode[a] and !isCyclicNode[b]) { // Both nodes belongs to chain
            
            if(rootId[a] != rootId[b]) { // Different chain
                cout << -1 << "\n";
                continue;
            }
            else { 
                
                if(inTime[b] <= inTime[a] and outTime[a] <= outTime[b]) { // Same chain
                    int steps = depth[a] - depth[b];
                    cout << steps << "\n";
                }
                else { // a and b are siblings
                    cout << -1 << "\n";
                }
                continue;
            }
        }
        else {
            if(isCyclicNode[a]) { // cycle to chain
                cout << -1 << "\n";
                continue;
            }
            
            // chain to cycle 
            int steps = depth[a] + 1;
            int u = nearestCyclicNode[a];
            steps += (depth[b]-depth[u] + len[u])%len[u];
            cout << steps << "\n";
            continue;
        }

    }
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
