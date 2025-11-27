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
- 0-based indexing
- A moves on even turn 0, 2, ..
- M moves on odd turn 1, 3, ..

obs:
- two player game
- both are 1's or both are 0's
    - swap does not matter


approach:
- constructive
- game theory
- greedy
- dp

*/
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<int> B(n);
    for(auto &a: B) cin >> a;

    // using dp
    vector dp(n, vector(2, vector<int>(2,-1)));
    auto f = [&](const auto &self, int i, int score1, int score2)->int {
        if(i == n) {
            if(score1 > score2) return 0; // 1st wins
            else if(score1 < score2) return 1; // 2nd wins

            return 2; // tie
        }
        auto &ans = dp[i][score1][score2];
        if(ans != -1) return ans;

        ans = 2;
        if(i&1) { // 2nd player turn
            int swap = self(self,i+1,B[i]^score1, A[i]^score2);
            int not_swap = self(self,i+1,A[i]^score1, B[i]^score2);

            if(swap == 1 or not_swap == 1) {
                return ans = 1;
            } 

            if(swap == 2 or not_swap == 2) {
                return ans = 2;
            }

            return ans = 0;
        }
        else { // 1st player turn
            int swap = self(self,i+1,B[i]^score1, A[i]^score2);
            int not_swap = self(self,i+1,A[i]^score1, B[i]^score2);

            if(swap == 0 or not_swap == 0) {
                return ans = 0;
            } 

            if(swap == 2 or not_swap == 2) {
                return ans = 2;
            }

            return ans = 1;
        }
        return ans = 2;
    };

    int ans = f(f,0,0,0);
    if(ans == 0) {
        cout << "Ajisai\n";
    }
    else if(ans == 1) {
        cout << "Mai\n";
    }
    else cout << "Tie\n";
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
