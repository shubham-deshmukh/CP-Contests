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
    ll n;
    cin >> n;
    map<int64_t,int64_t> freq;
    for(ll i = 0; i < n; i++) {
       int64_t x;
       cin >> x;
       freq[x]++; 
    }
    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++) {
        int64_t x,y;
        cin >> x >> y;

        int64_t D = x*x - 4*y;


        if(D < 0) cout << "0";
        else {
            int64_t sqr_root = sqrt(D);
            if(sqr_root * sqr_root != D) cout << "0";
            else {
                
                if(((x+sqr_root) % 2 != 0) || ((x-sqr_root)%2 != 0)) cout << "0";
                else {
                    int64_t a = (x+sqr_root) / 2, b = (x-sqr_root) / 2;
                    if(a == b) cout << freq[a] * (freq[a]-1) / 2;
                    else cout << freq[a] * freq[b];    
                }
            }
        }
        cout << " ";

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