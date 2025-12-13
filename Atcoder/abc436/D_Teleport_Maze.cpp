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
using pii = pair<int,int>;
constexpr int dx[]={+0,+0,+1,-1};
constexpr int dy[]={+1,-1,+0,+0};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(auto &s: A) cin >> s;

    vector<set<pii>> wrap_cell(26);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] >= 'a' and A[i][j] <= 'z') {
                wrap_cell[A[i][j]-'a'].insert(pii{i,j});
            }
        }
    }

    queue<pii> q;
    vector<vector<int>> dist(n, vector<int>(m, inf));
    dist[0][0] = 0;
    q.push(pii{0,0});

    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(x < 0 or x >= n or y < 0 or y >= m) continue;
            if(A[x][y] == '#') continue;

            if(dist[x][y] > 1 + dist[i][j]) {
                dist[x][y] = 1 + dist[i][j];
                q.push(pii{x,y});
            }
        }

        if(A[i][j] >= 'a' and A[i][j] <= 'z') {
            char c = A[i][j]-'a';

            for(auto &[x,y]: wrap_cell[c]) {
                if(dist[x][y] > 1 + dist[i][j]) {
                    dist[x][y] = 1 + dist[i][j];
                    q.push(pii{x,y});
                }
            }

            wrap_cell[c].clear();
        }
    }
    cout << (dist[n-1][m-1] == inf?-1:dist[n-1][m-1]);
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
