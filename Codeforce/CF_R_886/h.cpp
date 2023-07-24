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


const int MAX_N = 1e6;
const int mod = 1e9+7;
const ll INF = 1e18;

inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}


bool cmp(pair<ull,ull> x, pair<ull,ull> y) {
    if(x.ss != y.ss) return (x.ss > y.ss); // descresing order of 2nd elt
    else return (x.ff < y.ff); // incresing order of 1st elt
}

vector<pair<ll,ll>> adj[MAX_N+1];
vector<bool> vis;
vector<ll> dist;


int dfs(ll u) {
    vis[u] = true;
    for(auto [v,d] : adj[u]) {
        if(vis[v] == false) {
            dist[v] = dist[u]+d;
            if(dfs(v) == 0) return 0; // not a valid partition 
        }
        else {
            if(dist[v] != dist[u]+d) {
                return 0; // not a valid partition
            }
        }
    }
    return 1; // valid partition
}

void solve() {
    ll n,m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    vis.assign(n+1, false);
    dist.assign(n+1, INF);

    for(ll i = 0; i < m; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,-w});
    }
    int valid = 1;
    for(ll i = 1; i <= n; i++) {
        if(vis[i] == false) {
            dist[i] = 0;
            valid = valid && dfs(i);
        }   
    }

    cout << (valid?"YES":"NO");

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
