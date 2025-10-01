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
constexpr int inf = 1e9;
using t4 = array<int,4>;
struct ArrayHasher {
    std::size_t operator()(const std::array<int, 4>& a) const {
        std::size_t h = 0;
        for (int i : a) {
            h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &g: grid) cin >> g;

    auto check = [&](int i, int j, int prv, int curr)->bool {
        if(j-1 < 0 or i-1 < 0) return true;
        int cnt = 0;
        // i,j
        if(curr & (1<<j)) cnt += 1;
        // i,j-1
        if(curr & (1<<(j-1))) cnt += 1;
        // i-1,j
        if(prv & (1<<j)) cnt += 1;
        // i-1,j-1
        if(prv & (1<<(j-1))) cnt += 1;
        
        return cnt < 4;
    };
    unordered_map<t4,int,ArrayHasher> dp;

    auto f = [&](const auto &self, int i, int j, int prv, int curr)->int {
        if(i == n and j == 0) {
            return 0;
        }

        if(j == m) {
            return self(self,i+1,0,curr,0);
        }

        t4 state = t4{i,j,prv,curr};
        if(dp.contains(state)) return dp[state];

        int ways = inf;
        // assert(i >= 0 and i < n);
        // assert(j >= 0 and j < m);
        if(grid[i][j] == '.') { // current cell is white
            ways = self(self,i,j+1,prv,curr);
        }
        else { // current cell is black
            int paint = inf, notPaint = inf;
            int newCurr = curr | (1<<j);
            paint = 1 + self(self,i,j+1,prv,curr);
            if(check(i,j,prv,newCurr)) {
                notPaint = self(self,i,j+1,prv,newCurr);
            }
            ways = min(paint,notPaint);
        }
        return dp[state] = ways;
    };

    int ans = f(f,0,0,(1<<m)-1,0);
    cout << ans << "\n";
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
