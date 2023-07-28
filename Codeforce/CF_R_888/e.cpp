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
const int MAX = 1e6;
vector<vector<ll>> adj;
vector<bool> vis;
vector<int> order;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    order.push_back(v);
}

void solve() {
    // Approach 1: Using topological sort
    ll n,k;
    cin >> n >> k;
    vector<ll> cost(n),min_cost(n, 0);
    adj.assign(n,vector<ll>());
    vis.assign(n,false);
    vector<ll> in_deg(n,0);
    order.clear();

    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
        
    for(int i = 0; i < k; i++) {
        ll kk;
        cin >> kk;
        kk--;
        cost[kk] = 0;
        min_cost[kk] = 0;
    }

    
    for(int i = 0; i < n; i++) {
        ll req; cin >> req;
        for(int j = 0; j < req; j++) {
            ll v;
            cin >> v;
            v--;
            adj[v].push_back(i);
            in_deg[i]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(),order.end());

    for(auto &x: order) {
        if(in_deg[x])
            min_cost[x] = min(min_cost[x],cost[x]);
        else 
            min_cost[x] = cost[x];

        for(auto v: adj[x]) {
            min_cost[v] += min_cost[x];
        }
    }

    for(auto &c: min_cost) cout << c << " ";
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
