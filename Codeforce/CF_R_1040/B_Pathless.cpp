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
void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int sm = accumulate(A.begin(), A.end(),int(0));
    if(s == sm) {
        cout << -1 << "\n";
        return;
    }

    if(s < sm) {
        for(auto &a: A) cout << a << " "; cout << endl;
        return;
    }

    int rem = s - sm;
    // 2*x + 3 * y == rem 
    for(int x = 0; x <= 1000; x++) {
        for(int y = 0; y <= 1000; y++) {
            if(2*x + 3*y == rem) {
                cout << -1 << "\n";
                return;
            }
            else if(2*x+3*y > rem) break;
        }
    }

    int zero = count(A.begin(),A.end(),0);
    int one = count(A.begin(),A.end(),1);
    int two = count(A.begin(),A.end(),2);

    for(int i = 0; i < zero; i++) cout << 0 << " ";
    for(int i = 0; i < two; i++) cout << 2 << " ";
    for(int i = 0; i < one; i++) cout << 1 << " ";

    cout << "\n";


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
