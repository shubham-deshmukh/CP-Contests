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
 
    vector<int> a(n);
    for(auto &x: a) cin >> x;
 
    // Approach: Dynamic programming
    /*
    1. Define the state (In terms of length)
    minOp[i] : minimum number op needed to make seq of LENGTH i beautiful
    minOP[0,1,...n] - total states
    then answer is 
    minOp[n] :  minimum number op needed to make seq of LENGTH n beautiful
 
        
    2. Transitions => 
    // base case (trivial case): 
    What is the minimum operation needed to make seq of length 0 beautiful ? 
    minOp[0] = 0
 
    // Non-trivial case : 
    [.......a[i]......]
              i
    if(i+ai+1 <= n) // If length of element just after the block is valid
        minOp[i+ai+1] = min(minOp[i+ai+1],minOp[i]);
    minOp[i+1] = min(minOp[i+1],minOp[i]+1)
 
    Note: Another way to define state, then there will be different transitions
    e.g. (In terms of index)
    minOp[i] : minimum number op needed to make seq beautiful till INDEX i
    */
 
    vector<int> minOp(1+n,1e9);
    minOp[0] = 0;
 
    for(int i = 0; i < n; i++) {
        
        minOp[i+1] = min(minOp[i+1],minOp[i]+1); // state transition after ith element is removed
 
        if(1+a[i]+i <= n) { // jump state after the block 
            minOp[i+a[i]+1] = min(minOp[i+a[i]+1], minOp[i]);
        }
        
    }
    cout << minOp[n];
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