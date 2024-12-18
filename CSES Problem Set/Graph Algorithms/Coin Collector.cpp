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
int n, m;
vector<int> vis, in, out;
vector<vector<int>> adj,revAdj,dag;
vector<int> coins, order, color;
vector<long long> coins2;
int col = 0;
void dfs(int u) {
    vis[u] = 1;
    for(auto v: adj[u]) {
        if(!vis[v])
            dfs(v);
    }

    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    color[u] = col;
    for(auto v: revAdj[u]) {
        if(!vis[v])
            dfs2(v);
    }
}

void solve() {
    cin >> n >> m;

    coins.resize(n);
    adj.resize(n);
    revAdj.resize(n);
    vis.assign(n,0);

    for(auto &c: coins) cin >> c;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());
    vis.assign(n,0);
    color.assign(n,-1);

    for(auto i: order) {
        if(!vis[i]) {
            dfs2(i);
            col += 1;
        }
    }

    dag.resize(col);
    coins2.assign(col,0);
    in.assign(col,0);
    out.assign(col,0);

    for(int i = 0; i < n; i++) {
        coins2[color[i]] += coins[i];
        for(auto v: adj[i]) {
            if(color[v] != color[i]) {
                dag[color[i]].push_back(color[v]);
                out[color[i]] += 1;
                in[color[v]] += 1;
            }
        }
    }

    vector<long long> maxCoins = coins2;
    queue<int> q;
    for(int i = 0; i < col; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: dag[u]) {
            maxCoins[v] = max(maxCoins[v], coins2[v] + maxCoins[u]);
            in[v] -= 1;

            if(in[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << *max_element(maxCoins.begin(), maxCoins.end());

}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
