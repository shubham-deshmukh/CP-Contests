#include <iostream>
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

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

void solve() {
    string high;
    cin >> high;

    int n = (int)high.size();
    string low(n, '0');
    low.back() = '1';

    int d;
    cin >> d;

    // dp(i,mask,sum) : number of integers such that
    // type mask and sum
    // mask : 0,1,2,3

    viii dp(n+1, vii(4, vi(d,-1)));
    auto rec = [&](const auto &self, int i, int mask, int sum)->int {
        if(i == n) {
            if(sum == 0)
                return 1;

            return 0;
        }

        auto &ans = dp[i][mask][sum];
        if(ans != -1)
            return ans;
        
        int cnt = 0;
        if(mask == 0) { // 00
            for(char digit = '0'; digit <= '9'; digit++) {
                (cnt += self(self,i+1,mask,(sum + digit - '0')%d)) %= mod;
            }
        }
        else if(mask == 1) { // 01
            for(char digit = '0'; digit <= high[i]; digit++) {
                int nextSum = (sum+digit-'0')%d;
                if(digit == high[i]) { // 01
                    (cnt += self(self,i+1,1,nextSum)) %= mod;
                    continue;
                }
                // 00
                (cnt += self(self,i+1,0,nextSum)) %= mod;
            }
        }
        else if(mask == 2) { // 10
            for(char digit = low[i]; digit <= '9'; digit++) {
                int nextSum = (sum+digit-'0')%d;
                if(digit == low[i]) { // 10
                    (cnt += self(self,i+1,2,nextSum)) %= mod;
                    continue;
                }
                // 00
                (cnt += self(self,i+1,0,nextSum)) %= mod;
            }
        }
        else if(mask == 3) { // 11
            
            if(low[i] == high[i]) {
                (cnt += self(self,i+1,3,(sum + low[i]-'0')%d)) %= mod;
            }
            else {
                for(char digit = low[i]; digit <= high[i]; digit++) {
                    int nextSum = (sum + digit - '0')%d;
                    if(digit == low[i]) { // 10
                        cnt += self(self,i+1,2,nextSum);  
                    }
                    else if(digit == high[i]) { // 01
                        cnt += self(self,i+1,1,nextSum);  
                    }
                    else { // 00
                        cnt += self(self,i+1,0,nextSum);  
                    }
                    cnt %= mod;
                }
            }
        }
        return ans = cnt%mod;
    };

    cout << rec(rec,0,3,0);

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
