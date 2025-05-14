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

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}
const int N = 4e6+2;
vector<long long> factorial(N);
vector<long long> inverse_factorial(N);
constexpr long long mod = 998244353;;
// Binary Exponentiation with modulas
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Calculation of factorials
void get_fact(long long n, long long m) {
    factorial[0] = 1;
    for (long long i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

// Calculation of inverses
void get_inverse_fact(long long n, long long m) {
    for (long long i = 0; i <= n; i++) {
        inverse_factorial[i] = binpow(factorial[i],m-2,m);
    }
}

// Calculation of binomial coefficients
long long nCr(long long n, long long k, long long m) {
    return ((factorial[n] * (inverse_factorial[k] % m)) % m * (inverse_factorial[n - k] % m))%m;
}
#define int long long

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int tot = 0;
    for(int bLeft = 0; bLeft <= b; bLeft++) {
        int curr = nCr(a-1+bLeft,bLeft,mod);
        curr *= nCr(b-bLeft+c+d,c,mod);
        curr %= mod;
        tot += curr;
        tot %= mod;
    }
    cout << tot;
}
signed main() {
    // your code goes here
    fast;
    get_fact(N,mod);
    get_inverse_fact(N,mod);
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
