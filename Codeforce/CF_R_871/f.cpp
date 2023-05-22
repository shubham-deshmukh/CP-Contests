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


void solve() {
    ll n,m,i,j;
    cin >> n >> m;
    map<ll,ll> deg; // degree to cnt (number of vertices)
    ll d[201];
    memset(d,0,sizeof(d));
    rep(i,0,m) {
        ll u,v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    rep(i,1,n+1) {
        if(d[i]) deg[d[i]]++;
    }
    ll x,y;
    /**
    for(auto [u,v]:deg) {
        if(v==1) {
            x=u;
            y=m/x-1;
        }
    }
    */
    for(auto [u,v]:deg) {
        if(u == 1) {
            // m = x+x*y
            x = m-v;
            y = m/x-1;
        }
    }
    cout << x << " " << y;

}
int main() {
	// your code goes here
	fast;
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt", "w", stderr);
    #endif
    
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
