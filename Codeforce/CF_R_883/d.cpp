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
/*
Area of triangle in terms of height and base
Area = 1 / 2 (h * b)

Area of triangle in terms of height and angle
tan(0) = b / 2h => b = 2h * tan0
Area = 1 / 2 (h * 2h * tan0) = h^2 * tan0
Area = h^2 * tan0

Total area = 
*/
void solve() {
    ll n,b,h;
    cin >> n >> b >> h;

    vector<ll> y(n);
    for(auto &x: y) cin >> x;

    double area = 0.0;

    for(ll i = 0; i < n; i++) {
        area += 1.0 * h * b / 2.0;
        if(i != n-1) {
            if(y[i] + h > y[i+1]) {
                ll hh = h - (y[i+1]-y[i]);
                // 2*(1/2) * (hh) * (2*hh*(b/2*h))
                area -= 1.0 * hh * hh * b / (2.0*h);
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout << area;
}
int main() {
	// your code goes here
	fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
	ll t = 1;
	cin >> t;
	
	while(t--) {
         solve();
	    
	    if(t > 0) cout << endl;
	}
	// cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
	return 0;
}
