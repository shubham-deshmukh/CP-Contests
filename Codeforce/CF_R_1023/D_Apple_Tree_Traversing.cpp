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

#define int int64_t
const int inf = 1e18;
using t3 = array<int,3>;
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n), dist(n, inf);
    vector<int> parent(n,-1);
    vector<t3> ans;
    auto getDia = [&](int u)->vector<int> {
        dist[u] = 0;
        vector<int> currNodes;
        int maxDist = 0; int start = -1;
        queue<int> q;
        q.push(u);
        currNodes.push_back(u);
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto v: adj[u]) {
                if(!vis[v] and dist[v] > dist[u]+1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    currNodes.push_back(v);
                }
            }
        }

        maxDist = 0, start = -1;
        for(auto &v: currNodes) {
            if(dist[v] > maxDist) {
                maxDist = dist[v];
                start = v;
            }
            else if(dist[v] == maxDist) 
                start = max(start,v);
        }

        // reset dist
        for(auto &v: currNodes)
            dist[v] = inf;
        
        int end = -1;
        q.push(start);
        dist[start] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto v: adj[u]) {
                if(!vis[v] and dist[v] > dist[u]+1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        maxDist = 0;
        for(auto &v: currNodes) {
            if(dist[v] > maxDist) {
                maxDist = dist[v];
                end = v;
            }
            else if(dist[v] == maxDist) 
                end = max(end,v);
        }

        // get the diameter
        vector<int> path;
        int x = end;
        while(x != -1) {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());

        //ToDo reset dist 
        for(auto &v: currNodes) {
            dist[v] = inf;        
            parent[v] = -1;
        }

        // path is visited
        for(auto &v: path) vis[v] = 1;
        return path;
    };

    // vector<int> dia = getDia(n-1);
    // for(auto &v: dia) cout <<v+1 << " "; cout << endl;
    auto f =[&](const auto &self, int u)->void {
        // find the diameter
        vector<int> dia = getDia(u);
        int sz = (int)dia.size();
        int start = dia[0];
        int end = dia.back();
        if(start < end)
            swap(start,end);

        ans.push_back(t3{sz,start,end});
        
        for(auto &u : dia) {
            for(auto &v: adj[u]) {
                if(!vis[v]) {
                    self(self,v);
                }
            }
        }
    };

    f(f,n-1);
    sort(ans.begin(), ans.end(), [&](const t3 &a, const t3 &b) {
        if(a[0] != b[0])
            return a[0] > b[0];
        
        if(a[1] != b[1])
            return a[1] > b[1];
        
        return a[2] > b[2];
    });
    vector<int> rst;
    for(auto &a: ans) {
        rst.push_back(a[0]);
        rst.push_back(a[1]+1);
        rst.push_back(a[2]+1);
    }

    for(auto &a: rst) cout << a << " "; cout << endl;
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
