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

const int N = 2e5 + 10;
vector<int> factorial(N);
vector<int> inverse_factorial(N);
// const int mod = (int)1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void get_fact(long long n, long long m) {
    factorial[0] = 1;
    for (long long i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

void get_inverse_fact(long long n, long long m) {
    for (long long i = 0; i <= n; i++) {
        inverse_factorial[i] = binpow(factorial[i],m-2,m);
    }
}

long long nCr(long long n, long long k, long long m) {
    return (factorial[n] * (inverse_factorial[k] % m) * (inverse_factorial[n - k] % m))%m;
}


vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u, vector<int> &elt) {
    vis[u] = true;
    elt.push_back(u);

    for(auto v: adj[u]) {
        if(!vis[v]) {
            dfs(v,elt);
        }
    }
}

void solve() {

    int n,m;
    cin >> n >> m;

    vis.clear();
    adj.clear();

    adj.assign(n,vector<int>());
    vis.assign(n,false);

    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> a(n);
    for(auto &x: a) cin >> x;

    // find connected components
    int sz = 0;
    vector<vector<int>> comp;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            vector<int> elt;
            dfs(i,elt);
            sz++;
            comp.push_back(elt);
            elt.clear(); 
        }
    }

    // display the component elements
    // cout << "Display the component elements:\n";
    // for(auto &v: comp) {
    //     for(auto &x: v) cout << x << " ";
    //     cout << endl;
    // }

    int non_occ = n;
    long long cnt = factorial[n]%mod;
    for(int i = 0; i < sz; i++) {
        vector<int> elt = comp[i];
        int c_sz = (int)elt.size();

        // long long temp = nCr(non_occ,c_sz,mod);
        // cnt *= temp;
        cnt %= mod;

        map<long long, int> freq;
        for(auto &x: elt) freq[a[x]]++;
        for(auto [_,v]: freq) {
            cnt *= factorial[v];
            cnt %= mod;
        }

        cnt *= inverse_factorial[c_sz];
        cnt %= mod;

        non_occ -= c_sz;

    }
    
    cnt %= mod;
    cout << cnt;



}
int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    

    get_fact(N,mod);
    get_inverse_fact(N,mod);

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