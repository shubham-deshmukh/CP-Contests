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

struct manacher {
    vector<int> p;

    void run(string s) {
        int n = (int)s.size();
        p.assign(n,1);

        // l and r are excluded
        int l = 1, r = 1;
        for(int i = 1; i < n; i++) {
            p[i] = max(0,min(r-i, p[l + (r-i)]));
            while(i+p[i] < n && i-p[i] >=0 && s[i+p[i]] == s[i-p[i]])
                p[i] += 1;
            
            if(i+p[i] > r) {
                l = i-p[i];
                r = i+p[i];
            }
        }
        for(auto v: p) cout << v << " "; cout << endl;
    }
    void build(string s) {
        string t;
        for(auto c: s) {
            t += string("#")+c;
        }
        run(t+"#");
    }

    // Get the longest palindrome substring 
    string getLongPal(string s) {
        string pal = "";
        int mx = *max_element(p.begin(), p.end());
        for(int i = 0; i < (int)p.size(); i++) {
            if(p[i] == mx) {
                if(i&1) {
                    int len = (mx-1);
                    debug(i,i-mx/2,len);
                    pal = s.substr(i/2-len/2,len);
                }
                else {
                    pal = s.substr(i/2-mx/2,mx-1);
                }
                break;
            }
        }
        return pal;
    }
    // Get the length of the longest palindrome
    // int getLongestPalindrome(int centre, bool isOdd) {
    //     int pos = 2*centre + 1 + (!isOdd);
    //     return p[pos]-1;
    // }


    // Check weather palindrome exist or not in the range [l,r]
    // bool isPalindrome(int l, int r) {
    //     if((l+r-1) <= getLongestPalindrome((l+r)/2,r%2 == l%2))
    //         return true;
        
    //     return false;
    // }
};

void solve() {
    string S;
    cin >> S;

    manacher m;

    m.build(S);
    cout << m.getLongPal(S); 

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
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
