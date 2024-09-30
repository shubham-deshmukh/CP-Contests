#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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


class DisjointSetUnion {
    vector<long long> parent, rank, size;
public:
    DisjointSetUnion(long long n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(long long i = 0; i <=n; i++) {
            make_set(i);
        }

    }
    void make_set(long long v) {
        parent[v] = v;
        size[v] = 1;
        rank[v] = 0;
    }

    long long find_set(long long v) {
        if(parent[v] == v) 
            return v;
        return parent[v] = find_set(parent[v]);
    }

    long long get_size(long long v) {
        v = find_set(v);
        return size[v];
    }
    
    void union_set_by_size(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    void union_set_by_rank(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }    
};

#define int long long
void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> state(11, vector<int> (n+1, 0));

    DisjointSetUnion dsu(n+1);

    while(q--) {
        int a, d, k;
        cin >> a >> d >> k;
        state[d][a] = max(state[d][a],k);
    }

    for(int d = 1; d <= 10; d++) {

        for(int i = 1; i <= n; i++) {
            if(state[d][i] == 0)
                continue;
            
            int next = i + d;
            if(i+d > n)
                continue;
            
            dsu.union_set_by_rank(i,next);
            state[d][next] = max(state[d][next], state[d][i]-1);
        }
    }

    set<int> st;
    for(int i = 1; i <= n; i++)
        st.insert(dsu.find_set(i));
    
    cout << (int)st.size();
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
