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
    int n;
    cin >> n;

    vector<long long> a(n);
    for(auto &x: a) cin >> x;

    auto get_max_sum = [&](int l, int r)->long long {
        assert(l<=r);
        int sz = r-l+1;
        vector<long long> pre(sz+1), min_pre(sz+1);

        for(int i = 0; i < sz; i++) {
            pre[i+1] = pre[i] + a[i+l];
            min_pre[i+1] = min(min_pre[i], pre[i+1]);
        }

        long long mx_sum = a[l];
        for(int i = 1; i <= sz; i++) {
            mx_sum = max(mx_sum, pre[i]-min_pre[i-1]);
        }
        return mx_sum;
    };

    
    long long ans = LLONG_MIN;
    int i = 0;
    while(i < n) {
        int j = i+1;
        while(j < n && ((a[j]&1)^(a[j-1] & 1))) j++;
        ans = max(ans,get_max_sum(i,j-1));
        i = j;
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