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

vector<int> primes;
bool isPrimeCalculated = false; 
void sieve_getPrimes(int n) { 
    if(isPrimeCalculated) 
        return;
    
    isPrimeCalculated = true; // To avoid multiple pre-computation
    
    primes.clear();
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) if(is_prime[i]) primes.push_back(i);

}
// 17984

#define int int64_t
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    int ans = 0;
    int one= 0, zero = 0, sqrs = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    

    auto isSquare = [&](const int num)->bool {
        int sr = sqrtl(num);
        while(sr*sr<num)sr++;
        while(sr*sr>num)sr--;

        return (sr*sr == num);
    };

    auto pf = [&](int num)->int{
        vector<int>pri;
        map<int,int> mp;
        for(int i=2;i*i<=num;i++){
            while(num%i==0){
                mp[i] += 1;
                num/=i;
            }
        }
        if(num > 1){
            mp[num] += 1;
        }
        int hash = 1;
        for(auto [u,v]: mp) {
            if(v&1) {
                pri.push_back(u);
                hash *= u;
            }
        }
        return hash;
    };


    map<int,int> f; // hash, count

    for(int i = 0; i < n; i++) {
        
        if(A[i] == 0) {
            ans += i;
            zero += 1;
            continue;
        }

        if(A[i] == 1) {
            ans += zero + one + sqrs;
            one += 1;
            continue;
        }

        if(isSquare(A[i])) {
            ans += zero + one + sqrs;
            sqrs += 1;
            continue;
        }


        int hash = pf(A[i]);

        if(f.count(hash)) {
            ans += f[hash];
        }
        ans += zero;
        f[hash] += 1;
    }

    cout << ans;
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
    sieve_getPrimes(2e5+1);
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
