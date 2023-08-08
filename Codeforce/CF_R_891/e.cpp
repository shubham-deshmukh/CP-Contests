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

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    vector<ll> prefix_sum(n), suffix_sum(n+1,0);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = {x,i};
    }

    sort(all(a));

    prefix_sum[0] = a[0].first;
    for(int i = 1; i < n; i++) 
        prefix_sum[i] = prefix_sum[i-1] + a[i].first;
    
    suffix_sum[n-1] = a[n-1].first;
    for(int i = n-2; i >= 0; i--) 
        suffix_sum[i] = suffix_sum[i+1] + a[i].first;
    
    vector<pair<ll,ll>> ans;
    for(int i = 0; i < n; i++) {
        ll tsum = 0;
        tsum = n + a[i].first * (2*(i+1) - n) - prefix_sum[i] + suffix_sum[i+1];
        ans.push_back({a[i].second, tsum});
    }
    sort(all(ans));
    for(auto [_,x] : ans) cout << x << " ";
    
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