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
using pii = pair<int,int>;
using pip = pair<int,pii>;
void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    s1 -= 1, s2 -= 1;

    int m1, m2;
    cin >> m1;
    vector<vector<int>> g1(n), g2(n);
    for(int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    cin >> m2;
    for(int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    vector<vector<int>> dist(n, vector<int> (n,inf));
    dist[s1][s2] = 0;
    priority_queue<pip> pq; // distance, node
    pq.push(pip{-0,pii{s1,s2}});

    while(!pq.empty()) {
        int d = pq.top().first;
        pii u = pq.top().second;
        d = -d;
        pq.pop();

        if(d > dist[u.first][u.second])
            continue;
        
        for(auto v1: g1[u.first]) {
            for(auto v2: g2[u.second]) {
                if(u.first == u.second and v1 == v2) {
                    cout << d << "\n";
                    return;
                }

                if(dist[v1][v2] >  d + abs(v1-v2)) {
                    dist[v1][v2] = d + abs(v1-v2);
                    pq.push(pip{-(d+abs(v1-v2)),pii{v1,v2}});
                }
            }
        }
    }

    cout << -1 << "\n";
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
