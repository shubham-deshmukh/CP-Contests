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
using pii = pair<int,int>;
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    set<pii> edges;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u] += 1;
        deg[v] += 1;

        if(u > v) swap(u,v);
        edges.insert(pii{u,v});
    }

    if(n == 0) {
        cout << 0 << endl;
        return;
    }

    map<int,int> freq;
    for(auto &d: deg)
        freq[d] += 1;
    
    int mx = *max_element(deg.begin(), deg.end());
    if(freq[mx] > 2) {
        cout << mx + mx - 1 << endl;
    }
    else if(freq[mx]==2) {
        int u = -1, v = -1;
        for(int i = 0; i < n; i++) {
            if(deg[i] == mx) {
                if(u == -1)
                    u = i;
                else 
                    v = i;
            }
        }
        int ans = mx + mx - 1 - edges.count(pii{u,v});
        if(ans < 0) {
            cout << 0 << endl;
        }
        else 
            cout << ans << endl;
    }
    else {
        int mx1 = -1, mx2 = -1;
        int u = -1;
        for(int i = 0; i < n; i++) {
            if(deg[i] >= mx1) {
                mx2 = mx1;
                mx1 = deg[i];
                u = i;
            }
            else if(deg[i] >= mx2) {
                mx2 = deg[i];
            }
        }

        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(deg[i] == mx2)
                temp.push_back(i);
        }

        bool isPos = false;
        for(auto v: temp) {
            int x = u;
            if(x > v)
                swap(x,v);
            
            isPos |= !edges.count(pii{x,v});
        }

        int ans =  mx1 + mx2 - 1 - (isPos==true?0:1);
        if(ans < 0) {
            cout << 0 << endl;
        }
        else 
            cout << ans << endl;
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
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
