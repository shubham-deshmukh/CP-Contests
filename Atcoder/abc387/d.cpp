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

const int inf = 1e18;

int n, m;
vector<string> A;

int sx, sy, tx, ty;
using pii = pair<int,int>;

const int dx[] = {+0,+0,+1,-1};
const int dy[] = {-1,+1,+0,+0};


int bfs(int direction) {
    vector<vector<int>> dist(n, vector<int> (m, inf));
    vector<vector<int>> dir(n, vector<int> (m, -1));

    queue<pii> q;
    dist[sx][sy] = 0; 
    q.push(pii{sx,sy});
    dir[sx][sy] = direction; // d : 0 --> horizontal, 1 : vertical

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        int d = dir[i][j];

        if(d == 0) { // move vertically
            for(int dd = 2; dd < 4; dd++) {
                int x = i + dx[dd];
                int y = j + dy[dd];

                if(x < 0 or x >= n or y < 0 or y >= m or A[x][y] == '#')
                    continue;
                
                if(dist[x][y] > 1 + dist[i][j]) {
                    dist[x][y] = 1 + dist[i][j];
                    dir[x][y] = 1 - d;
                    q.push(pii{x,y});
                }
            }
        }
        else if(d == 1) { // move horizontally
            for(int dd = 0; dd < 2; dd++) {
                int x = i + dx[dd];
                int y = j + dy[dd];

                if(x < 0 or x >= n or y < 0 or y >= m or A[x][y] == '#')
                    continue;
                
                if(dist[x][y] > 1 + dist[i][j]) {
                    dist[x][y] = 1 + dist[i][j];
                    dir[x][y] = 1 - d;
                    q.push({x,y});
                }
            }
        }
        // int sz = (int)q.size();
        // debug(sz);
    }
    
    return dist[tx][ty];
}

void solve() {
    n, m;
    cin >> n >> m;

    A.resize(n);
    // vector<string> A(n);
    for(auto &s: A) cin >> s;
    // Find out start and goal
    sx = -1, sy = -1;
    tx = -1, ty = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 'S') {
                sx = i, sy = j;
            }
            else if(A[i][j] == 'G') {
                tx = i, ty = j;
            }
        }
    }

    int ans = 0;
    ans = min(bfs(0), bfs(1));
    // ans = bfs(0);
    if(ans == inf)
        ans = -1;
    
    cout << ans;
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
