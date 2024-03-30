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
// https://www.thejoboverflow.com/problem/405/
/*
Common Mistakes: 
1. Base case : A is already on the boundry
2. Multiple monsters can be present
*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(auto &s: g) cin >> s;

    using pii = pair<int,int>;
    vector<pii> boundry;
    vector<pii> A, M;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '.' and (i == 0 or j == 0 or i == n-1 or j == m-1))
                boundry.emplace_back(i,j);
            if(g[i][j] == 'A')
                A.emplace_back(i,j);
            if(g[i][j] == 'M')
                M.emplace_back(i,j);
        }
    }
    // Base cases : A is already on the boundry
    int ai = A.back().first;
    int aj = A.back().second;

    if(ai == 0 or ai == n-1 or aj == 0 or aj == m-1) {
        cout << "YES";
        return;
    }


    if(boundry.empty()) {
        cout << "NO";
        return;
    }
    auto bfs = [&](vector<pii> start)->vector<vector<int>> {
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        vector<vector<int>> dist(n, vector<int> (m,INT_MAX));
        queue<pii> q;

        const int dx[] = {+0,+0,-1,+1};
        const int dy[] = {-1,+1,+0,+0};

        for(auto src: start) {
            q.push(src);
            vis[src.first][src.second] = true;
            dist[src.first][src.second] = 0;
        }

        while(!q.empty()) {
            pii u = q.front();
            q.pop();

            for(int dir = 0; dir < 4; dir++) {
                int x = u.first + dx[dir];
                int y = u.second + dy[dir];

                if(x >=0 and x < n and y >= 0 and y < m and !vis[x][y] and g[x][y] == '.') {
                    q.push(pii{x,y});
                    vis[x][y] = true;
                    dist[x][y] = 1 + dist[u.first][u.second];
                }
            }
        }
        return dist;
    };

    vector<vector<int>> distA = bfs(A);
    vector<vector<int>> distM = bfs(M);

    for(auto [i,j]: boundry) {
        if(distA[i][j] < distM[i][j]) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
