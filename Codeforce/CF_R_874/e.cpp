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
ll n;
vector<vector<ll>> adj;
vector<ll> vis;
bool isCycle(ll node, ll parent) {
    vis[node] = 1;
    for(auto v: adj[node]) {
        if(vis[v] == 0) {
            if(isCycle(v,node)) return true;
        }
        else if (v != parent){
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n;
    adj.assign(n,vector<ll>());
    vis = vector<ll>(n,0);
    ll i;
    rep(i,1,n+1) {
        ll x;
        cin >> x;
        adj[i-1].pb(x-1);
        adj[x-1].pb(i-1);
    }
    ll mn = 0, mx = 0, no_cyclic_component = 0;
    rep(i,0,n) {
        if(vis[i] == 0) {
            if(isCycle(i,-1)) {
                mn++;
                mx++;
            }
            else {
                no_cyclic_component++;
            }
        }
    }
    if(no_cyclic_component) {
        mn++;
        mx += no_cyclic_component;
    }
    cout << mn << " " << mx;

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
