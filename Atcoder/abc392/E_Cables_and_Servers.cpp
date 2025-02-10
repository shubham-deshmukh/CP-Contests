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
    
    // path compression
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if(root_u == root_v) {
        return false;
    }

    // root u larger
    if(sz[root_u] < sz[root_v]) {
        swap(u,v);
        swap(root_u, root_v);
    }

    parent[root_v] = root_u;
    sz[root_u] += sz[root_v];
    comp -= 1;
    return true;
}
using pii = pair<int,int>;
using t3 = array<int,3>;
void solve() {
    int n, m;
    cin >> n >> m;


    parent.assign(n, 0);
    sz.assign(n,1);
    comp = n;

    iota(parent.begin(), parent.end(), 0);
    vector<t3> extra;
    vector<pii> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        edges.push_back(pii{u,v});
        if(!unite(u,v)) {
            extra.push_back(t3{i,u,v});
        }
    }

    if(comp == 1) {
        cout << 0;
        return;
    }
    int minOp = 0;
    set<int> rem;
    // for(auto i: extra) {
    //     rem.insert(find(edges[i].first));
    //     rem.insert(find(edges[i].second)); 
    // }
    for(int i = 0; i < n; i++)
        rem.insert(find(i));

    int i = 0;
    
    vector<t3> ans;
    while(comp > 1 and i < (int)extra.size()) {
        int u = extra[i][1];
        int v = extra[i][2];

        int root_u = find(u);
        rem.erase(root_u);

        int root_v = *rem.begin();
        rem.erase(root_v);

        unite(root_u, root_v);

        ans.push_back(t3{extra[i][0],u,root_v});
        rem.insert(find(root_u));

        minOp += 1;
        i += 1;
    }
    
    cout << (int)ans.size() << endl;
    for(auto &e: ans) cout << e[0]+1 << " " << e[1]+1 << " " << e[2]+1 << endl;

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
