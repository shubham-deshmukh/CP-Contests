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

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt = 0, cnt1 = 0;
    vector<int> zero, one;
    int start = 0;
    int len = 0;
    for(int i = 0; i < n; i++) {
        char ch = s[i];
        if(ch == '0') {
            if(cnt) {
                one.push_back(cnt);
                if((int)one.size() == k-1) {
                    start = i;
                }
            }
            cnt = 0;
        }
        else 
            cnt += 1;


        if(ch == '1') {
            if(cnt1) {
                if(one.size() == k-1)
                    len = cnt1;
                zero.push_back(cnt1);
            }
            cnt1 = 0;
        }
        else 
            cnt1 += 1;
    }

    if(cnt) one.push_back(cnt);
    if(cnt1) zero.push_back(cnt1);
    // debug(one);
    // debug(zero);

    int sz = one[k-1];
    for(int i = start; i < start + sz; i++) {
        s[i] = '1';
        s[i+len] = '0';
    }
    cout << s;
    // string ans;

    // if(s[0] == '0') {
    //     int i = 0;
    //     for(auto x: zero) {
    //         ans += string(x,'0');
    //         if(i < (int)one.size()) {

    //             ans += string(one[i],'1');
    //             i += 1;
    //             if(i == k-1) {
    //                 ans += string(one[i],'1');
    //                 i += 1;
    //             }
    //         }
    //     }
            
    // }
    // else {

    // }

    // cout << ans;

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
