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

const int cmod = 998244353;

class DisjointSetUnion {
    vector<long long> parent, rank, size;
public:
    DisjointSetUnion(long long n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(long long i = 0; i <=n; i++) {
            make_set(i);
        }

    }
    void make_set(long long v) {
        parent[v] = v;
        size[v] = 1;
        rank[v] = 0;
    }

    long long find_set(long long v) {
        if(parent[v] == v) 
            return v;
        return parent[v] = find_set(parent[v]);
    }
    long long get_size(long long v) {
        v = find_set(v);
        return size[v];
    }

    void union_set_by_size(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    void union_set_by_rank(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }    
};

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

void solve() {
    ll n,s;
    cin >> n >> s;
    vector<vector<ll>> edges;

    for(int i = 0; i < n-1; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w,u,v});
    }
    sort(all(edges));

    DisjointSetUnion dsu(n);

    ll ans = 1;
    for(auto &e: edges) {
        ll w = e[0], u = e[1], v = e[2];
        ll s1 = dsu.get_size(u), s2 = dsu.get_size(v);
        dsu.union_set_by_size(u,v);

        ll paths = s1 * s2 - 1;
        ll choices = s-w+1;

        ans *= binpow(choices,paths,cmod);
        ans %= cmod;
    }
    cout << ans;

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