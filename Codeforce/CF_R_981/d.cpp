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

#define int int64_t
using pii = pair<int,int>;
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    map<int,int> mp;
    vector<int> start, end;
    vector<pii> seg;
    mp[0] = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
        if(mp.count(sum)) {
            int l = mp[sum]+1;
            int r = i + 1;
            start.push_back(l);
            end.push_back(r);
            seg.push_back(pii{l,r});
        }
        mp[sum] = i+1;
    }

    // debug(start);
    // debug(end);
    {
        int n = (int)start.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int i, int j) {
            return start[i] < start[j];
        });


        auto getNext = [&](const int &i)->int {

            auto isOk = [&](const int &j)->bool {
                // [is...ie]
                //	 		[js...je]
                return end[order[i]] < start[order[j]];
            };

            int l = i, r = n;
            while(r-l>1) {
                int mid = l + (r-l) / 2;
                if(isOk(mid))
                    r = mid;
                else 
                    l = mid;
            }
            return r;
        };

        vector<int> dp(n,-1);
        auto rec = [&](const auto &self, int i)->int {
            if(i == n)
                return 0;

            auto &ans = dp[i];
            if(ans != -1)
                return ans;	
            int notTake = self(self,i+1);
            int take = 1 + self(self,getNext(i));

            return ans = max(notTake, take);
        };
        cout << rec(rec,0);

    }
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
