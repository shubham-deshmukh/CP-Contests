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

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int prv = 0;
    vector<int> ans;
    string s;
    int l = 0, r = n-1;
    while(l < r) {
        int mn = min(A[l],A[r]);
        int mx = max(A[l],A[r]);

        if(prv < mn) {
            ans.push_back(mx);
            ans.push_back(mn);

            if(mx == A[l]) {
                s.push_back('L');
                s.push_back('R');
            }
            else {
                s.push_back('R');
                s.push_back('L');
            }

            prv = mn;
            l += 1;
            r -= 1;
        }
        else if(prv > mx) {
            ans.push_back(mn);
            ans.push_back(mx);

            if(mn== A[l]) {
                s.push_back('L');
                s.push_back('R');
            }
            else {
                s.push_back('R');
                s.push_back('L');
            }            

            prv = mx;
            l += 1;
            r -= 1;            
        }
        else {
            ans.push_back(mn);
            ans.push_back(mx);

            if(mn== A[l]) {
                s.push_back('L');
                s.push_back('R');
            }
            else {
                s.push_back('R');
                s.push_back('L');
            }            
            
            prv = mx;
            l += 1;
            r -= 1;              
        }
    }

    if(l == r) {
        ans.push_back(A[l]);
        s.push_back('L');
    }

    cout << s << "\n";
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
