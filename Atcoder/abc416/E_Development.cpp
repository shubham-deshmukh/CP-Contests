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
constexpr int inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n+2, vector<int> (n+2,inf));
    for(int i = 1; i <= n+1; i++) dist[i][i] = 0;
    
    for(int i=0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    int k, t;
    cin >> k >> t;

    for(int i = 0, u; i < k; i++) {
        cin >> u;

        dist[u][n+1] = min(dist[u][n+1],t);
        dist[n+1][u] = min(dist[n+1][u],int(0));
    }

    for(int k = 1; k <= n+1; k++) {
        for(int u = 1; u <= n+1; u++) {
            for(int v = 1; v <= n+1; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    auto update = [&](int u, int v, int c)->void {
        for(int i = 1; i <= n+1; i++) {
            for(int j = 1; j <= n+1; j++) {
                dist[i][j] = min(dist[i][j], dist[i][u] + c + dist[v][j]);
            }
        }
    };

    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++) {
        int ch;
        cin >> ch;

        if(ch == 1) {
            int a, b, c;
            cin >> a >> b >> c;

            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c); 
            
            update(a,b,c);
            update(b,a,c);
            
        }
        else if(ch == 2) {
            int u;
            cin >> u;

            dist[u][n+1] = min(dist[u][n+1],t);
            dist[n+1][u] = min(dist[n+1][u],int(0));   
            
            update(u,n+1,t);
            update(n+1,u,0);         
        }
        else {
            int total = 0;
            for(int u = 1; u <= n; u++) {
                for(int v = 1; v <= n; v++) {
                    if(dist[u][v] < inf) {
                        total += dist[u][v];
                    } 
                }
            }
            cout << total << "\n";
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
