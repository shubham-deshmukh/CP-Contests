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
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> pre(n+1,0);
    set<string> rst;
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '1') pre[i] = 1 + pre[i-1];
        else pre[i] = pre[i-1];
    }
    vector<string> pre_str(n), suff_str(n);
    pre_str[0] = s[0];
    for(int i = 1; i < n; i++) {
        pre_str[i] = pre_str[i-1] + s[i];
    }
    suff_str[n-1] = s[n-1];
    for(int i=n-2; i >=0; i--) {
        suff_str[i] = s[i+1] + suff_str[i+1];
    }

    for(int i = 0; i < m; i++) {
        ll l,r;
        cin >> l >> r;
        if(l != r) {
            ll ones = pre[r]-pre[l-1];
            ll sz = r-l+1;
            string ss = "";
            for(int i = 0; i < (sz-ones); i++) ss += "0";
            for(int i = 0; i < ones; i++) ss += "1";
            string left = "", right = "";
            // if(l-2 >= 0) left = s.substr(0,l-1);
            if(l-2 >= 0) left = pre_str[l-2];
            // if(r < n) right = s.substr(r,n-r);
            if(r < n) right = suff_str[r];
            string t = left + ss + right;
            if(!t.empty()) rst.insert(t);
        }
        else {
            rst.insert(s);
        }
    }
    cout << (ll)rst.size();
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