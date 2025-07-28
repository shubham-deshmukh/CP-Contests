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
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(n);

    multiset<int> freq;
    for(auto &a: A) {
        cin >> a;
        freq.insert(a);
    }

    for(auto &b: B) cin >> b;

    vector<int> rem;
    for(auto &b: B) {
        int need = (m - b)%m;
        auto it = freq.find(need);
        if(it != freq.end()) {
            freq.erase(it);
        }
        else {
            rem.push_back(b);
        }
    }
    sort(rem.rbegin(), rem.rend());
    // for(auto &r: rem) cout << r << " "; cout << endl;
    int ans = 0;
    for(auto &r: rem) {
        if(freq.empty()) {
            break;
        }

        int need = (m-r)%m;
        auto it = freq.lower_bound(need);
        int prv_val = -1;
        auto prv = it;
        if(it != freq.begin()) {
            prv = prev(it);
            prv_val = *prv;
        }

        int curr_val = -1;
        if(it != freq.end()) curr_val = *it;

        if(prv_val != -1 and curr_val != -1) {
            int p = (prv_val+r)%m;
            int c = (curr_val+r)%m;

            if(p <= c) {
                ans += p;
                freq.erase(prv);
            }
            else {
                ans += c;
                freq.erase(it);
            }
        }
        else if(prv_val != -1) {
            ans += (prv_val + r) % m;
            freq.erase(prv);
        }
        else {
            assert(curr_val != -1);
            ans += (curr_val+r)%m;
            freq.erase(it);
        }

    }

    cout << ans << "\n";
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
