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

struct hash61 {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;
 
  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }
 
  void ensure_pw(int sz) {
    int cur = (int) pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }
 
  vector<uint64_t> pref;
  int n;
 
  template<typename T>
  hash61(const T& s) {
    n = (int) s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }
 
  inline uint64_t operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
 
const long long SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
 
uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);


void solve() {
    // Check all possible length [1..n]
    string S;
    cin >> S;

    int n = (int)S.size();
    hash61 pH(S);
    for(int len = 1; len <= n; len++) {
        int i;
        uint64_t hash = pH(0,len-1);
        bool isPeriod = true;
        for(i = 0; i+len-1 < n; i += len) {
            if(hash != pH(i,i+len-1)) {
                isPeriod = false;
                break;
            }
        }
        if(isPeriod && i < n) {
            int len = n-i;
            if(pH(0,len-1) != pH(i,i+len-1))
                isPeriod = false;
        }
        if(isPeriod)
            cout << len << " ";
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
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
