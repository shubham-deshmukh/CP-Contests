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
// const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}
using int64 = unsigned int;
// constexpr int64 mod = (1LL<<32);
vector<vector<int64>> operator*(const vector<vector<int64>> &A, const vector<vector<int64>> &B)  {
    int r1 = (int)A.size(), c1 = (int)A[0].size();
    int r2 = (int)B.size(), c2 = (int)B[0].size();

    assert(c1 == r2);
    vector ans(r1, vector<int64>(c2));

    for(int j = 0; j < c2; j++) {
        for(int i = 0; i < r1; i++) {
            for(int k = 0; k < c1; k++) {
                // ans[i][j] = (ans[i][j] + A[i][k] * B[k][j])%mod; 
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]); 
            }
        }
    }

    return ans;
}

vector<vector<int64>> matpow(vector<vector<int64>> mat, int b) {
    int n = (int)mat.size();
    vector rst(n, vector<int64>(n));
    for(int i = 0; i < n; i++) rst[i][i] = 1; // Identity matrix

    while(b>0) {
        if(b&1) rst = rst * mat;
        mat = mat * mat;
        b >>= 1;
    }
    return rst;
}

constexpr int dx[] = {-2,-2,+2,+2,+1,-1,+1,-1};
constexpr int dy[] = {+1,-1,+1,-1,-2,-2,+2,+2};
// constexpr int dx[] = {-2,-2,-1,-1};
// constexpr int dy[] = {+1,-1,-2,+2};
void solve() {
    int n;
    cin >> n;

    // auto f = [&](const auto &self, int i, int j, int rem)->int {
    //     if(rem == 0) return 1;

    //     int ways = 0;
    //     // move 
    //     for(int dir = 0; dir < 8; dir++) {
    //         int ii = i + dx[dir];
    //         int jj = j + dy[dir];
    //         if(ii < 0 or ii >= 8 or jj < 0 or jj >= 8) continue;

    //         if(rem-1 >= 0)
    //             ways += self(self,ii,jj,rem-1);
    //     }
    //     return ways;
    // };
    // int tot = 0;
    // for(int rem = 0; rem <= n; rem++)
    //     tot += f(f,0,0,rem);

    // cout << tot;

    // Iterative DP with constant space
    // vector dp(8, vector(8, vector<int64>(n+1,0)));
    // vector dp(8, vector<int64>(8,0));

    // int64 tot = 1;
    // dp[0][0] = 1;

    // for(int rem = 1; rem <= n; rem++) {    
    //     vector ndp(8, vector<int64>(8,0));
    //     for(int i = 0; i < 8; i++) {
    //         for(int j = 0; j < 8; j++) {
    //             int ways = 0;
    //             for(int dir = 0; dir < 8; dir++) {
    //                 int x = i + dx[dir];
    //                 int y = j + dy[dir];

    //                 if(x < 0 or x >= 8 or y < 0 or y >= 8) continue;

    //                 // ways = (ways + dp[x][y][rem-1])%mod;
    //                 ways = (ways + dp[x][y])%mod;
    //             }
    //             // dp[i][j][rem] = ways;
    //             ndp[i][j] = ways;
    //             tot = (tot + ways) % mod;
    //         }
    //     }
    //     dp = ndp;
    // }
    // cout << tot;

    // using matrix exponentiation
    // Number of variables (state parameters)
    // 8 * 8 (grid) + 1 (answer) = 65

    // [0][65] = 1
    // Z = X * Y^k
    vector<vector<int64>> X(65, vector<int64>(65));
    vector<vector<int64>> Y(65, vector<int64>(65));

    Y[0][64] = 1;
    // transition matrix : Y
    // for(int rem = 1; rem <= n; rem++) {    
        // vector ndp(8, vector<int64>(8,0));
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                // int ways = 0;
                for(int dir = 0; dir < 8; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if(x < 0 or x >= 8 or y < 0 or y >= 8) continue;
                    // ndp[i][j] = (ndp[i][j] + dp[x][y]) % mod;
                    // transition from (x,y) --> (i,j)
                    Y[x * 8 + y][i * 8 + j] = 1;
                    // ways = (ways + dp[x][y][rem-1])%mod;
                    // ways = (ways + dp[x][y])%mod;
                }
                // dp[i][j][rem] = ways;
                // ndp[i][j] = ways;
                // tot = (tot + ways) % mod;
            }
        }
        for(int i = 0; i < 65; i++) {
            // transition from 0..63,64(previous answer) to current answer (64)
            Y[i][64] = 1;
        }
        // dp = ndp;
    // }

    X = matpow(Y,n+1);
    cout << X[0][64];
    // cout << tot;    
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
