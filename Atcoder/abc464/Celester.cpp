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
/*
- N days weather as S
    - si
        - S : Sunny
        - R : Rainy
- current happiness : 0
- op (0)
    - choose i
    - swap the weather
    - change in happiness
    - happiness descrease by Xi 

        - for each day i (< N)
            - si == R (after modification) and s_i+1 == S (after modification)
                - happiness +Yi

obj:
- max value of happiness 

S R 
R -- > S : inc happiness

*/
const long long inf = 1e18;
const int N = 2e5+1;
long long dp[N][3];
int vis[N][3];

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<long long> X(n);
    for(auto &x: X) cin >> x;

    vector<long long> Y(n-1);
    for(auto &y: Y) cin >> y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            vis[i][j] = -1;
        }
    }
    // 0 : S, 1 : R
    auto f = [&](const auto &self, int i, int prev)->long long {
        if(i == n) return 0;
        auto &ans = dp[i][prev+1];
        if(vis[i][prev+1] != -1) return ans;
        vis[i][prev+1] = 1;

        int c = (s[i] == 'S'?0:1);
        long long noChange = ((prev != -1 and prev == 1 and c == 0)?Y[i-1]:0) + self(self,i+1,c);
        long long change = -X[i] + ((prev != -1 and prev == 1 and c == 1)?Y[i-1]:0) + self(self,i+1,1-c);
        
        return ans = max(noChange, change);

    };
    long long ans = f(f,0,-1);
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
