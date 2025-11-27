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
constexpr int inf = 1e9;

vector<int> parent, sz;
int comp = 0;
int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v) return false;

    if(sz[u] < sz[v]) {
        swap(u,v);
    }

    sz[u] += sz[v];
    parent[v] = u;
    comp -= 1;
    
    return true;
}


void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    if(n == 2) {
        // 2 1
        if(A[0] > A[1]) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        cout << A[1] << " " << A[0] << "\n";
        return;
    }
    parent.assign(n,0);
    sz.assign(n,1);
    comp = n;

    iota(parent.begin(), parent.end(), 0);

    vector<int> pfx_min = A, sfx_max = A;
    for(int i = 1; i < n; i++) pfx_min[i] = min(pfx_min[i],pfx_min[i-1]);
    for(int i = n-2; i >= 0; i--) sfx_max[i] = max(sfx_max[i],sfx_max[i+1]);

    using pii = pair<int,int>;
    vector<pii> ans;
    for(int i = 1; i+1<n; i++) {
        if(pfx_min[i-1] > sfx_max[i+1]) {
            cout << "No\n";
            return;
        }
        int left = pfx_min[i-1];
        int right = sfx_max[i+1];

        // large --> small
        if(left < A[i] and find(left-1) != find(A[i]-1)) {
            unite(left-1,A[i]-1);
            ans.push_back(pii{left,A[i]});
        }

        if(A[i] < right and find(right-1) != find(A[i]-1)) {
            unite(right-1,A[i]-1);
            ans.push_back(pii{A[i], right});
        }

        if(find(right-1) != find(left-1)) {
            unite(right-1, left-1);
            ans.push_back(pii{left,right});
        }
    }
    
    cout << "Yes\n";
    for(auto &[u,v]: ans) {
        if(u < v) swap(u,v);
        cout << u << " " << v << "\n";
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
