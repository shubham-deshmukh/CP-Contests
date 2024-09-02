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

#define int int64_t
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n&1) {
        // n is odd 
        vector<int> oddLeft(26), oddRight(26), evenLeft(26), evenRight(26);
        int minOp = n;
        auto getOp = [&](vector<int> oddLeft, vector<int> evenLeft, vector<int> oddRight, vector<int> evenRight)->int {
            vector<int> even(26), odd(26);
            for(int i = 0; i < 26; i++) {
                even[i] = evenLeft[i] + oddRight[i];
                odd[i] = oddLeft[i] + evenRight[i];
            }

            int op = accumulate(even.begin(), even.end(), int(0)) - *max_element(even.begin(), even.end());
            op += accumulate(odd.begin(), odd.end(), int(0)) - *max_element(odd.begin(), odd.end());
            
            return op;
        };

        // It is forced to make a deletion
        for(int i = 0; i < n; i++) {
            if(i&1)
                oddRight[s[i]-'a'] += 1;
            else 
                evenRight[s[i]-'a'] += 1;
        }
        for(int i = 0; i < n; i++) { 
            // If ith char is deleted then
            // number of min operation needed
            // to make string good

            int x = s[i]-'a';
            if(i&1) {
                oddRight[x] -= 1;
            }
            else 
                evenRight[x] -= 1;
            
            // compute the operations
            int op = getOp(oddLeft,evenLeft,oddRight,evenRight) + 1;
            minOp = min(minOp, op);
            if(i&1)
                oddLeft[x] += 1;
            else
                evenLeft[x] += 1;


        }
        cout << minOp;
    }
    else {
        // n is even
        int odd = 0, even = 0;
        vector<int> evenCnt(26), oddCnt(26);
        for(int i = 0; i < n; i++) {
            if(i%2 == 0)
                evenCnt[s[i]-'a'] += 1;
            else 
                oddCnt[s[i]-'a'] += 1;
        }
        int op = accumulate(evenCnt.begin(), evenCnt.end(), int(0)) - *max_element(evenCnt.begin(), evenCnt.end());
        op += accumulate(oddCnt.begin(), oddCnt.end(), int(0)) - *max_element(oddCnt.begin(), oddCnt.end());

        cout << op;
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
