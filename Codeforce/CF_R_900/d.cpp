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
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> l(k),r(k);
    for(auto &x: l) cin >> x;
    for(auto &x: r) cin >> x;

    int q;
    cin >> q;

    vector<int> freq(n,0);

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        freq[x-1]++;
    }

    for(int i = 0; i < k; i++) {
        int lb = l[i], rb = r[i];
        int sz = rb-lb+1;
        int sum = 0;
        for(int idx = lb; idx < (lb + sz/2); idx++) {
            sum += freq[idx-1] + freq[rb+lb-idx-1];
            if(sum & 1) {
                swap(s[idx-1],s[rb+lb-idx-1]);
            }
        }
    }
    cout << s;

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
    // t = 1;
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}