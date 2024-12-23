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

vector<int> boss, sz;
vector<int> reward, pCost;
vector<set<int>> team;

int find(int u) {
    if(boss[u] == u) {
        return u;
    }
    
    return boss[u] = find(boss[u]);
}

int unite(int u, int v) {
    int boss_u = find(u);
    int boss_v = find(v);

    if(boss_u == boss_v)
        return false;
    
    // size of team u is greater than v
    if(sz[boss_u] < sz[boss_v])
        swap(boss_u, boss_v);
    
    boss[boss_v] = boss_u;
    sz[boss_u] += sz[boss_v];

    // reward[boss_v] -= reward[boss_u];
    for(auto &s: team[boss_v]) {
        team[boss_u].insert(s);
        pCost[s] = pCost[s] + reward[boss_v] - reward[boss_u];
    }

    team[boss_v].clear();
    reward[boss_v] = 0;

    return true;
}

void solve() {
    int n, Q;
    cin >> n >> Q;

    boss.assign(n,-1);
    sz.assign(n,1);
    team.assign(n, set<int>());
    reward.assign(n,0);
    pCost.assign(n,0);

    iota(boss.begin(), boss.end(), 0);

    for(int i = 0; i < n; i++)
        team[i].insert(i);

    for(int i = 0; i < Q; i++) {
        string op;
        cin >> op;

        if(op == "join") {
            int u, v;
            cin >> u >> v;

            u -= 1, v -= 1;

            unite(u,v);
        }
        else if(op == "add") {
            int u, x;
            cin >> u >> x;

            u -= 1;
            u = find(u);
            reward[u] += x;
        }
        else if(op == "get") {
            int u;
            cin >> u;

            u -= 1;
            int boss_u = find(u);
            cout << reward[boss_u] + pCost[u] << endl;
        }
    }
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
