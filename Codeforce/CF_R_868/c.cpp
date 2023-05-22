#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
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
    rep(i,2,n+1) {
        if(lpf[i] == 0) { 
            
            lpf[i] = i;
            for(ll j = i*i; j <= n; j = j + i) {
                if(lpf[j] == 0)
                    lpf[j] = i;
            }
        }
        
    }   
}

void solve() {
    ll i,j;
    ll n;
    cin >> n;
    ll a[n];
    rep(i,0,n) cin >> a[i];

    unordered_map<ll,ll> buff;
    buff.clear();
    ll ans = 0;
    rep(i,0,n) {
        ll x = a[i];
        while(x > 1) {
            ll p = lpf[x]; // get the least/smallest prime factor of n 
            ll cnt = 0;
            while(x%p == 0) {
                x /= p;
                buff[p]++;
            }
        }        
    }
    ll rem = 0;
    for(auto [u,v] : buff) {
        ans += v/2;
        rem += v%2;
    }
    cout << ans + rem / 3;
    

}
int main() {
	// your code goes here
	fast;
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt", "w", stderr);
    #endif
    sieve_lpf(10000007);
    // solve();
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
