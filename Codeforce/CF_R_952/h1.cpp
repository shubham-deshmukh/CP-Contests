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


#define int int64_t
class DisjointSetUnion {
private:
public:
    vector<int> rank, par, size;
 
    DisjointSetUnion(int n = 0) {
        rank.resize(n + 1);
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }
 
    int find_set(int node) {
        if (node == par[node])
            return node;
        return par[node] = find_set(par[node]);//path comp
    }
 
    void unionbyRank(int u, int v) {
        int UparU = find_set(u);
        int UparV = find_set(v);
        if (UparU == UparV)
            return;
        if (rank[UparU] < rank[UparV]) {
            par[UparU] = UparV;
        } else {
            par[UparV] = UparU;
            rank[UparU] += (rank[UparU] == rank[UparV]);
        }
    }
 
    void union_set_by_size(int u, int v) {
        int UparU = find_set(u);
        int UparV = find_set(v);
        if (UparU == UparV)
            return;
        if (size[UparU] < size[UparV]) {
            par[UparU] = UparV;
            size[UparV] += size[UparU];
        } else {
            par[UparV] = UparU;
            size[UparU] += size[UparV];
        }
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(auto &a: A) cin >> a;

    int N = n*m;
    DisjointSetUnion dsu = DisjointSetUnion(N);

    //Get the connected components
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i+1 < n and A[i][j] == '#' and A[i+1][j] == '#')
                dsu.union_set_by_size((i*m+j),((i+1)*m+j));
            
            if(j+1 < m and A[i][j] == '#' and A[i][j+1] == '#')
                dsu.union_set_by_size((i*m+j), (i*m+j+1));
        }
    } 


    int maxSize = 0;
    //Check for each row
    for(int i = 0; i < n; i++) {
        // vector<int> vis(N);
        set<int> st;
        int sz = 0;
        for(int j = 0; j < m; j++) {
            if(A[i][j] == '.') {
                sz += 1;
                // r-1 row
                if(i-1 >= 0 and A[i-1][j] == '#') {
                    int parent = dsu.find_set((i-1)*m+j);
                    st.insert(parent);
                } 

                // i+1 row
                if(i+1 < n and A[i+1][j] == '#') {
                    int parent = dsu.find_set((i+1)*m+j);
                    st.insert(parent);
                }                
            }
            else {
                int parent = dsu.find_set(i*m+j);
                st.insert(parent);
            }

        }
        for(auto s: st) sz += dsu.size[s];
        maxSize = max(maxSize, sz);
    }

    //Check for each column
    for(int j = 0; j < m; j++) {
        // vector<int> vis(N);
        set<int> st;
        int sz = 0;
        for(int i = 0; i < n; i++) {
            if(A[i][j] == '.') {
                sz += 1;
                // check j-1 column
                if(j-1 >= 0 and A[i][j-1] == '#') {
                    int parent = dsu.find_set(i*m+j-1);
                    st.insert(parent);
                }

                // check j+1 column
                if(j+1 < m and A[i][j+1] == '#') {
                    int parent = dsu.find_set(i*m+j+1);
                    st.insert(parent);
                }                
            }
            else {
                int parent = dsu.find_set(i*m+j);
                st.insert(parent);
            }

        }
        for(auto s: st) sz += dsu.size[s];
        maxSize = max(maxSize, sz);        
    }
    cout << maxSize;

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
