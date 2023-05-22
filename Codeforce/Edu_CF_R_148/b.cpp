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
    ll i,n,k, sum = 0;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i,0,n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    vector<ll> pre = a, post = a;
    rep(i,1,n) pre[i] += pre[i-1];
    rep(i,n-2,-1) post[i] += post[i+1];

    ll max_sum = 0, type1_sum = 0, type2_sum = 0;
    
    
    rep(i,0,k+1) {
        type1_sum = type2_sum = 0;
        if(i) type1_sum = pre[(i-1)*2+1];
        if(k-i)type2_sum = post[n-(k-i)];
        max_sum = max(max_sum, sum - type1_sum - type2_sum);
    }
    cout << max_sum;
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
