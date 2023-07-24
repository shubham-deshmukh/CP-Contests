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
There are four alignments
1. Vertical (same x co-ordinate)
2. Horizontal (same y co-ordinate)
3. / (slope with 1 : x-y=c)
4. \ (slope with -1: x+y=c)

*/
void solve() {
    int n,i;
    cin >> n;

    vector<map<ll,ll>> a(4);
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ll x,y;
        cin >> x >> y;
        
        ++a[0][x];
        ++a[1][y];
        ++a[2][x-y];
        ++a[3][x+y];
    }
    for(int i = 0; i < 4; ++i) {
        for(auto x: a[i]) {
            total += x.ss * (x.ss-1);
        } 
    }
    cout << total;
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
	cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
	return 0;
}
