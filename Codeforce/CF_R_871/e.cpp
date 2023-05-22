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
ll r,c,vol;
ll g[1001][1001], vis[1001][1001];
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

void dfs(ll x, ll y) {
    if(x < 0 || x >= r || y < 0 || y >= c || vis[x][y] == 1 || g[x][y] == 0) return ;

    vis[x][y] = 1;
    vol += g[x][y];
    ll i;
    rep(i,0,4) {
        ll x1 = x+dx[i];
        ll y1 = y+dy[i];
        dfs(x1,y1);
    }

}
void solve() {
    ll i,j;
    cin >> r >> c;
    rep(i,0,r) rep(j,0,c) vis[i][j] = 0;
    rep(i,0,r) rep(j,0,c) g[i][j] = 0;

    rep(i,0,r) rep(j,0,c) cin >> g[i][j];
    ll max_vol = 0;
    rep(i,0,r) {
        rep(j,0,c) {
            if(g[i][j] && vis[i][j] == 0) {
                vol = 0;
                dfs(i,j);
                max_vol = max(max_vol,vol);
            }
        }
    }
    cout << max_vol;

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
