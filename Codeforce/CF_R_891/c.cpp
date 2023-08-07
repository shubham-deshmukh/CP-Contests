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
[2,3,5,1]

1,2,3,5
1 1 1 2 2 3
1 -> 3
2 -> 2
3 -> 1
1 2 3 4

1 1 3
1 -> 2
3 -> 1
1 3 4
*/
void solve() {
    int n;
    cin >> n;
    int nn = n*(n-1) / 2;
    map<ll,ll> freq;
    vector<ll> ans;
    ll t = n-1;
    for(int i = 0; i < nn; i++) {
        ll x;
        cin >> x;
        freq[x]++;
    }

    for(auto [u,v] : freq) {
        while(v) {
            ans.push_back(u);
            v -= t;
            t--;
        }
    }
    int sz = (int) ans.size();
    for(int i = 0; i < sz; i++) cout << ans[i] << " ";
    cout << ans[sz-1];
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