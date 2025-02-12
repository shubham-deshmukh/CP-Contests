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

vector<int> getPrimeFactors(int a) {
    // 12 : 2 2 3
    vector<int> factors;
    for(int i = 2; i*i <= a; i++) {
        while(a%i==0) {
            factors.push_back(i);
            a /= i;
        }
    }
    if(a>1) factors.push_back(a);
    return factors;
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int primeCnt = 0;
    int ans = 0;
    map<int,int> freq;
    map<int,int> mp;
    for(auto &a: A) {
        // get prime factors
        vector<int> primeFactors = getPrimeFactors(a);
        int sz = (int)primeFactors.size();
        if(sz > 2)
            continue;
        
        if(sz == 1) { // a_j is prime
            ans += primeCnt - freq[a]; // a_i = prime
            ans += mp[primeFactors[0]]; // a_i = a_j * some_prime
            primeCnt += 1;
        }
        else if(sz == 2) { // a_j is product of two primes
            ans += freq[a]+1; // a_i = p*q 
            ans += freq[primeFactors[0]]; // a_i = p 
            mp[primeFactors[0]] += 1;
            if(primeFactors[0] != primeFactors[1]) {
                ans += freq[primeFactors[1]]; // a_i = q
                mp[primeFactors[1]] += 1;
            }   
        }
        
        freq[a] += 1;
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
