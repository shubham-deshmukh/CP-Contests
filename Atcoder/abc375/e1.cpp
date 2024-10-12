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

// #define int int64_t
const int inf = 1e9;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using viiii = vector<viii>;
void solve() {
    int n;
    cin >> n;

    vector<int> team(n), cost(n);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < n; i++) {
        cin >> team[i] >> cost[i];
        if(team[i] == 1)
            sum1 += cost[i];
        
        if(team[i] == 2)
            sum2 += cost[i];
        
        if(team[i] == 3)
            sum3 += cost[i];
    }

    int goal = accumulate(cost.begin(), cost.end(),int(0));
    if(goal % 3 != 0) {
        cout << -1;
        return;
    }

    viii dp(n+1, vii(goal+1, vi(goal+1, -1)));

    auto rec = [&](const auto &self, int i, int sum1, int sum2)->int {
        int sum3 = goal - sum1 - sum2;
        if(sum1 < 0  or sum2 < 0 or sum3 < 0)
            return inf;

        if(i == n) {
            if(sum1 == sum2 and sum1 == sum3) {
                return 0;
            }

            return inf;
        }

        auto &ans = dp[i][sum1][sum2];
        if(ans != -1)
            return ans;

        int minCost = self(self,i+1,sum1,sum2);
        if(team[i] == 1) {
            int switch1 = 1 + self(self,i+1,sum1-cost[i],sum2 + cost[i]);
            int switch2 = 1 + self(self,i+1,sum1-cost[i],sum2);
            minCost = min({minCost,switch1,switch2});
        }
        
        if(team[i] == 2) {
            int switch1 = 1 + self(self,i+1,sum1+cost[i],sum2 - cost[i]);
            int switch2 = 1 + self(self,i+1,sum1,sum2 - cost[i]);
            minCost = min({minCost,switch1,switch2});
        }

        
        if(team[i] == 3) {
            int switch1 = 1 + self(self,i+1,sum1+cost[i],sum2);
            int switch2 = 1 + self(self,i+1,sum1,sum2 + cost[i]);
            minCost = min({minCost,switch1,switch2});
        }
        return ans = minCost;
    };

    int ans = rec(rec,0,sum1,sum2);
    cout << (ans >= inf?-1:ans);
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
