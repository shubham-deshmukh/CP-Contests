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
const int dx[] = {+0,+0,+1,-1};
const int dy[] = {+1,-1,+0,+0};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for(auto &gi: g) cin >> gi;

    // multisource bfs
    vector vis(n, vector<int> (m));
    queue<pii> q;

    auto check = [&](int i, int j)->bool {
        // cell is black
        if(g[i][j] == '#') return false;

        // cell is white and exactly 1 black adj
        int adjCnt = 0;
        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(x < 0 or x >= n or y < 0 or y >= m) continue;
            adjCnt += (g[x][y] == '#');
        }

        return adjCnt == 1;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(check(i,j)) {
                q.push(pii{i,j});
                vis[i][j] = 1;
            }
            ans += g[i][j] == '#';
        }
    }

    while(!q.empty()) {
        int sz = (int)q.size();
        vector<pii> cand;
        for(int idx = 0; idx < sz; idx++) {
            auto [i,j] = q.front();
            cand.push_back(pii{i,j});
            q.pop();

            g[i][j] = '#';
            ans += 1;
        }

        for(auto [i,j]: cand) {
            for(int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];

                if(x < 0 or x >= n or y < 0 or y >= m) continue;            

                if(check(x,y) and !vis[x][y]) {
                    q.push(pii{x,y});
                    vis[x][y] = 1;
                }
            }            
        }
    }
    cout << ans;
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
