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

void solve() {
    int n, q;
    cin >> n >> q;

    int left = 1, right = 2;
    vector<int> pos = {1,2}; // 0 : left, 1 : right
    
    int op = 0;
    auto clock = [&](int c, int target)->int {
        int op = 0;
        int curr = pos[c];
        while(curr != target) {
            if(curr == n)
                curr = 1;
            else 
                curr += 1;
            
            op += 1;
            if(curr == pos[1-c])
                return -1;
        }

        return op;
    };

    auto anti = [&](int c, int target)->int {
        int op = 0;
        int curr = pos[c];
        while(curr != target) {
            if(curr == 1)
                curr = n;
            else 
                curr -= 1;
            
            op += 1;
            if(curr == pos[1-c])
                return -1;
        }

        return op;
    };    

    while(q--) {
        char ch;
        int target;
        cin >> ch >> target;

        int curr = 0;
        if(ch != 'L')
            curr = 1;

        int p1 = clock(curr, target);
        if(p1 != -1) {
            op += p1;
            pos[curr] = target;
        }

        int p2= anti(curr,target);
        if(p2 != -1) {
            op += p2;
            pos[curr] = target;
        }
    }
    cout << op;
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
