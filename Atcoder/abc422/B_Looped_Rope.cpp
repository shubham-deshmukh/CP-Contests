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
constexpr int dx[] = {+0,+0,+1,-1};
constexpr int dy[] = {+1,-1,+0,+0};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &g: grid) cin >> g;

    auto check = [&](int i, int j)->bool {
        int cnt = 0;
        for(int dir = 0; dir < 4; dir++) {
            int x = dx[dir] + i;
            int y = dy[dir] + j;

            if(x < 0 or x >= n or y < 0 or y >= m) continue;
            cnt += (grid[x][y] == '#');
        }

        return cnt == 2 or cnt == 4;
    };
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#' and !check(i,j)) {
                cout << "No\n";
                return;
            } 
        }
    }
    cout << "Yes\n";
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
