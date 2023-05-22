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
    set<ll> one,two,three,zero;
    ll i,n;
    cin >> n;
    rep(i,0,n) {
        ll x;
        string s;
        cin >> x >> s;
        // cout << x << s << endl;
        if(s == "00") zero.insert(x);
        else if(s=="01") one.insert(x);
        else if(s=="10") two.insert(x);
        else three.insert(x);
    }
    ll ans1 = INT_MAX,ans2 = INT_MAX;
    if(!three.empty()) ans1 = *three.begin();
    if(!one.empty() && !two.empty()) ans2 = *one.begin() + *two.begin();
    ll ans = min(ans1,ans2);
    if(ans != INT_MAX) cout << ans;
    else cout << -1;
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
