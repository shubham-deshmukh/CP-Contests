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
const int N = 1e5+1;
vector<vector<int>> divisors;
void pre() {
    divisors.assign(N, vector<int>());
    divisors[1].push_back(1);
    for(int i = 2; i < N; i++) {
        for(int j = 1; j*j <= i; j++) {
            if(i%j == 0) {
                int k = i / j;
                divisors[i].push_back(j);
                if(k != j)
                    divisors[i].push_back(k);
            }
        }
    }


}
vector<vector<int>> pos;
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    // Find out positions of divisors
    for(int i = 0; i < n; i++) {
        pos[A[i]].push_back(i);
    }
    auto getLoc = [&](int d, int lb, int rb)->int {
        auto isOk = [&](int mid)->bool {
            return pos[d][mid] >= lb and pos[d][mid] <= rb;
        };

        // int l = -1;
        // int r = (int)pos[d].size();
        int left = lower_bound(pos[d].begin(), pos[d].end(),lb) - pos[d].begin();
        int right = upper_bound(pos[d].begin(), pos[d].end(),rb) - pos[d].begin();
        if(left <= rb and left < right)
            return pos[d][left];
        
        return -1;
        // int l = left - 1;
        // l -= 1;
        // int r = right;

        // while(r-l>1) {
        //     int mid = l + (r-l) / 2;
        //     if(isOk(mid))
        //         r = mid;
        //     else 
        //         l = mid;
        // }

        // if(r == right)
        //     return -1;

        // return pos[d][r];
    };

    auto query = [&](int k, int l, int r)->int {
        vector<int> loc;
        for(auto &d: divisors[k]) {
            if(pos[d].empty())
                continue;
            
            int idx = getLoc(d,l,r);
            if(idx != -1)
                loc.push_back(idx);
        }
        sort(loc.begin(), loc.end());
        int prv = l;
        // 2 3 4
        int ans = 0;
        for(auto &i: loc) {
            ans += (i - prv) * k;
            int d = A[i];
            while(k%d == 0) k /= d;
            prv = i;
        }
        ans += (r-prv+1) * k;
        return ans;
    };

    while(q--) {
        int k, l, r;
        cin >> k >> l >> r;

        l -= 1;
        r -= 1;

        cout << query(k,l,r) << "\n";
    }

    // clean up
    // sort(A.begin(), A.end());
    // A.resize(unique(A.begin(), A.end()) - A.begin());

    for(auto &a: A) {
        pos[a].clear();
    }
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    pre();
    pos.assign(N, vector<int>());
    // for(auto &i: divisors[30]) cout << i << " "; cout << endl;
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
