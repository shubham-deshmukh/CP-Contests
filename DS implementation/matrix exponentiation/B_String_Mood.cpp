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
- either happy or sad
- S and D makes him sad
- H makes him happy
- vowels (AEIOU) flips the mood
- Other letters do nothing

- currently happy
- among all possible (26^n) strings with length n
count strings that makes him happy after reading the 
string 
- answer module 1e9+7

- n is very large

- counting problem -> DP or math?
// base case
i == n : if prevMood == happy return 1 else 0
f(i,prevMood (sad/happy)) :
    for(currLetter from A..Z) :
        if(currLetter == S or D)
            f(i+1,sad)
        if(currLetter H)
            f(i+1,happy)
        if(currLetter from {AEIOU})
            f(i+1,1-prevMood)

TC : n * 2 * 26
*/
#define int int64_t
using int64 = long long;

vector<vector<int64>> operator*(const vector<vector<int64>> &A, const vector<vector<int64>> &B)  {
    int r1 = (int)A.size(), c1 = (int)A[0].size();
    int r2 = (int)B.size(), c2 = (int)B[0].size();

    assert(c1 == r2);
    vector ans(r1, vector<int64>(c2));

    for(int j = 0; j < c2; j++) {
        for(int i = 0; i < r1; i++) {
            for(int k = 0; k < c1; k++) {
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j])%mod; 
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

void solve() {
    int n;
    cin >> n;

    set<char> sad = {'S','D'};
    set<char> vow = {'A','E','I','O','U'};

    // // recursive dp
    // // 1 : bad, 0 : good
    // auto f = [&](const auto &self, int i, int prevMood)->int {
    //     if(i == n) {
    //         if(prevMood == 1) return 0;
    //         return 1; 
    //     }

    //     int ways = 0;
    //     for(int j = 0; j < 26; j++) {
    //         char ch = j + 'A';
    //         if(sad.contains(ch)) { // curr mod becomes sad
    //             ways += self(self,i+1,1);
    //         }
    //         else if(vow.contains(ch)) { // flip the mood
    //             ways += self(self,i+1,1-prevMood);
    //         }
    //         else if(ch == 'H') {
    //             ways += self(self,i+1,0);
    //         }
    //         else { // mood stays same
    //             ways += self(self,i+1,prevMood);
    //         }
    //     }
    //     return ways;
    // };
    // cout << f(f,0,0);

    // // Iterative DP with constant space
    // // 0 : happy, 1 : sad
    // vector dp(2, vector<int>(2,0));
    // for(int i = n; i >= 0; i--) {
    //     for(int prevMood : {0,1}) {
    //         if(i == n) {
    //             if(prevMood == 0) 
    //                 dp[i&1][prevMood] = 1;
    //             continue;
    //         }
    //         int ways = 0;
    //         for(int j = 0; j < 26; j++) {
    //             char ch = j + 'A';
    //             if(sad.contains(ch)) { // curr mod becomes sad
    //                 ways = (ways + dp[(i+1)&1][1]) % mod;
    //             }
    //             else if(vow.contains(ch)) { // flip the mood
    //                 ways = (ways + dp[(i+1)&1][1-prevMood]) % mod;
    //             }
    //             else if(ch == 'H') {
    //                 ways = (ways + dp[(i+1)&1][0]) % mod;
    //             }
    //             else { // mood stays same
    //                 ways = (ways + dp[(i+1)&1][prevMood]) % mod;
    //             }
    //         }
    //         dp[i&1][prevMood] = ways;
    //     }
    // }
    // cout << dp[0][0];

    // using matrix exponentiation
    vector<vector<int64>> X = {{1,0}};
    vector<vector<int64>> Y = {{19,7},{6,20}};

    X = X * matpow(Y,n);
    cout << X[0][0];
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
