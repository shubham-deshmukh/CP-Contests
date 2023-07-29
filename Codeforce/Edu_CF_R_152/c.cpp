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
1 0 0 1 1 1

0 0 0 1 
*/
void solve() {
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    // left boundry and right boundry
    
    // vector<ll> left(n),right(n);
    // s[n-1] = n-1;
    // if(s[n-1] == '0') left[n-1] = n;
    
    // for(int i = n-2; i >= 0; i--) {
    //     left[i] = ((s[i] == '1') ? i : left[i+1]);
    // }

    // right[0] = 0;
    // if(s[0] == '1') right[0] = -1;

    // for(int i= 1; i < n; i++) {
    //     right[i] = ((s[i] == '0') ? i : right[i-1]);
    // }

    // Issue : Use the correct indices for 
    // calculationg left and right 

    vector<ll> start(n+1,n), end(n+1,-1);
    for(int i = n-1; i >=0; i--) {
        if(s[i] == '1') start[i] = i;
        else start[i] = start[i+1];
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') end[i+1] = i;
        else end[i+1] = end[i];
    }

    set<pair<ll,ll>> op;
    for(int i = 0; i < m; i++) {
        ll l,r;
        cin >> l >> r;
        l--;
        l = start[l];
        r = end[r];

        if(l > r) {
           l = r = -1;
        }
        op.insert({l,r});
    }
    cout << (ll)op.size();
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