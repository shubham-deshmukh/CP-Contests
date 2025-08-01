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
constexpr int inf = 1e18;
const int dx[] = {+0,+1};
const int dy[] = {+1,+0};
void solve() {
    int n, m;
    cin >> n >> m;

    vector A(n, vector<int>(m));
    for(auto &v: A) {
        for(auto &vi: v) cin >> vi;
    }

    vector<int> p(n+m-1);
    for(auto &pi: p) cin >> pi;

    using pii = pair<int,int>;

    auto isOk = [&](int rem)->bool {
        vector dist(n, vector<int>(m,-inf));
        vector vis(n, vector<int>(m));

        queue<pii> q;
        dist[0][0] = rem + A[0][0] - p[0];
        if(dist[0][0] >= 0) {
            q.push(pii{0,0});
            vis[0][0] = 1;
        }
        
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(int dir = 0; dir < 2; dir++) {
                int x = dx[dir] + i;
                int y = dy[dir] + j;

                if(x < 0 or x >= n or y < 0 or y >= m) continue;

                dist[x][y] = max(dist[x][y], dist[i][j]+A[x][y]-p[x+y]);
                if(!vis[x][y] and dist[x][y] >= 0) {
                    vis[x][y] = 1;
                    q.push(pii{x,y});
                }
            }
        }
        return vis[n-1][m-1];
    };

    int l = -1, r = inf;

    while(r-l>1) {
        int mid = l + (r-l) / 2;
        if(isOk(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << r;
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
