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
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n+1);
    vector<int> in_deg(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
 
        // u-->v
        adj[u].push_back(v);
        in_deg[v] += 1;
    }
 
    // find out topological order using queue
    vector<int> order;
    queue<int> q;
    for(int i = 2; i <= n; i++) {
        if(in_deg[i] == 0) {
            q.push(i);
        }
    }
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v: adj[u]) {
            in_deg[v] -= 1;
            if(in_deg[v] == 0 and v != 1) q.push(v);
        }
    }
 
    assert(in_deg[1] == 0);
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
 
        for(auto v: adj[u]) {
            in_deg[v] -= 1;
            if(in_deg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    vector<int> parent(n+1), cnt(n+1);
    vector<int> vis(n+1);
 
    cnt[1] = 1;
    for(auto &u: order) {
        for(auto v: adj[u]) {
            if(cnt[v] < 1 + cnt[u]) {
                cnt[v] = 1 + cnt[u];
                parent[v] = u;
            }
        }
    }
 
    if(cnt[n] == 0) {
        cout << "IMPOSSIBLE";
        return;
    }
 
    cout << cnt[n] << "\n";
    // print the path
    vector<int> path;
    int u = n;
    while(u != 0) {
        path.push_back(u);
        u = parent[u];
    }
 
    reverse(path.begin(), path.end());
    for(auto &p: path) cout << p << " ";
 
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