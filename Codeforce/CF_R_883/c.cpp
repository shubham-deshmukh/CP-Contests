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

bool cmp1(vector<ll> x, vector<ll> y) {
    if(x[0] != y[0]) return x[0] > y[0]; // decreasing order of score
    else {
        if(x[1] != y[1]) return x[1] < y[1] ; // increasing order of penalty
        else return x[2] < y[2]; // increasing order of person id
    }
}

void solve() {
    ll n,m,h;
    cin >> n >> m >> h;
    vector<vector<ll>> a(n,vector<ll>(m));

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
    
    vector<vector<ll>> rank;
    for(int i = 0; i < n; i++) {
        sort(all(a[i]));
        ll t = 0;
        ll score = 0;
        ll penalty = 0;
        for(auto s: a[i]) {
            t += s;
            if(t <= h) {
                score++;
                penalty += t;
            }
            else {
                break;
            }
        }
        vector<ll> rst;
        rst.push_back(score);
        rst.push_back(penalty);
        rst.push_back(i);
        rank.push_back(rst);
    }
    sort(all(rank),cmp1);
    for(int i = 0; i < n; i++) 
        if(rank[i][2]==0) {
            cout << i+1;
            break;
        }
    
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
