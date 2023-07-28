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
    vector<pair<ll,ll>> values(n);
    
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        values[i] = {x,i};
    }
    

    // Find a and b
    sort(values.begin(),values.end());


    // Find the adjacent pairs of numbers so that their xor is mininum
    // i.e. maximum numbers of bits matches between two number
    ll min_xor = values[0].first ^ values[1].first;
    ll min_idx = 0;
    for(int i = 0; i < n-1; i++) {
        if((values[i].first ^ values[i+1].first) < min_xor) {
            min_xor = values[i].first ^ values[i+1].first;
            min_idx = i;
        }
    }
    // Find value of x
    // choose x st xor with found a and b will be maximum 
    // To achieve that just flip the bits of 'a' to obtain x
    ll a = values[min_idx].first;
    ll b = values[min_idx+1].first;
    ll x = ((1 << k)- 1) ^ values[min_idx].first;
    // cout << "Max value: " << ((a^x)&(b^x)) << endl;
    cout << values[min_idx].second + 1<< " " << values[min_idx+1].second + 1 << " " << (((1 << k)- 1) ^ values[min_idx].first);
     

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