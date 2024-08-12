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


inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

// Required definations
const long long N = 2e5 + 10;
vector<long long> factorial(N);
vector<long long> inverse_factorial(N);
const long long mod = (long long)(1e9 + 7);

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



void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> A(n);
    for(auto &a: A) cin >> a;

    long long ones = 0, zeros = 0;
    for(auto a: A) {
        ones += (a == 1);
        zeros += (a == 0);
    }
    long long half = (k+1) / 2;
    long long sum = 0;
    if(ones < half) {
        cout << sum;
        return;
    }

    for(long long r = half; r <= min(ones, k); r++) {
        long long zeroNeeded = k - r;
        if(zeroNeeded > zeros) {
            continue;
        }

        long long y = nCr(zeros,zeroNeeded, mod);
        long long x = nCr(ones,r,mod);
        x = (x + mod) % mod;
        sum += (x * y)%mod;
        sum %= mod;
    }

    cout << (sum+mod)%mod;
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif

    get_fact(N,mod);
    get_inverse_fact(N,mod);
    
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
