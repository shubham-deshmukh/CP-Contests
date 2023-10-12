#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define lld long double
#define ull unsigned long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(i = start; start < end ? i < end : i > end; start < end ? i += 1 : i -= 1)
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


const int MAX_N = 1e5;
const int mod = 1e9+7;

inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}


bool cmp(pair<ull,ull> x, pair<ull,ull> y) {
    if(x.ss != y.ss) return (x.ss > y.ss); // descresing order of 2nd elt
    else return (x.ff < y.ff); // incresing order of 1st elt
}

vector<ll> lpf;
void sieve_lpf(ll n) { 
    
    lpf.assign(n+1,0);
    
    lpf[0] = 0, lpf[1] = 1;
    ll i;
    rep(i,2,n+1) { // starts from 2 since 0 and 1 are not primes
        if(lpf[i] == 0) { // i is prime
            // mark all the multiples of prime i, i as lpf 
            lpf[i] = i;
            for(ll j = i*i; j <= n; j = j + i) {
                if(lpf[j] == 0)
                    lpf[j] = i;
            }
        }
        // otherwise i is not prime and already (marked) found the lpf
    }   
}

vector<ll> prime_fact(ll n) {
    
    vector<ll> ans;
    while(n > 1) {
        ll p = lpf[n]; // get the least/smallest prime factor of n 
        while(n%p == 0) n /= p; // remove powers of prime p 
        ans.pb(p);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    sort(all(a));

    string ans = "";
    unordered_map<ll,ll> powers;
    if(a[0]==a[n-1]) ans = "YES";
    else {
        for(auto &x: a) {
            while(x > 1) {
                ll p = lpf[x]; // get the least/smallest prime factor of n 
                int cnt = 0;
                while(x%p == 0) {
                    x /= p; // remove powers of prime p  
                    cnt++;
                }
                powers[p] += cnt;                   
            }
        }
        ans = "YES";
        for(auto [c,p] : powers) {
            if(p%n != 0) ans = "NO";
        }
    }
    cout << ans;
}
int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    sieve_lpf(1000000);
    ll t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}