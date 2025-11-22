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
- order does not matter

*/
#define int int64_t
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int max_digit = 0;
    for(auto &a: A) {
        string s = to_string(a);
        max_digit = max(max_digit, (int)s.size());
    }

    vector<map<int,int>> freq(max_digit+1);
    auto add = [&](int a)->void {
        for(int i = 1; i <= max_digit; i++) {
            int mul = powl(10,i);
            mul %= m;
            // a * mul
            int num = ((a % m) * mul) % m;
            freq[i][num] += 1;
        }
    };

    auto with_itself = [&](int a)->bool {
        string s = to_string(a);
        s += s;

        int num = stoll(s);
        return num%m == 0;
    };

    int ans = 0;
    for(auto &a: A) add(a);

    for(int i = 0; i < n; i++) {
        int r2 = A[i] % m;
        r2 = (m - r2)%m;
        
        int d = (int)to_string(A[i]).size();
        if(freq[d].contains(r2)) {
            ans += freq[d][r2];
        }
    }

    cout << ans;
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
