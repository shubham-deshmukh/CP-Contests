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
    // Approach: Based on linear scanning
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &aa: a) cin >> aa;

    vector<bool> colored(n,false);
    ll i = 0;
    ll coins = 0;
    while(i < n) {
        ll cnt = 0;
        int j = i;
        bool has_two = false;
        while(j < n && a[j]) {
            cnt++;
            colored[j] = true;
            // Check if two is in the segment or not
            has_two = has_two || (a[j] == 2);
            j++;
        }
        int available = has_two ? 2 : 1;
        if(cnt) {
            coins++;
            // color on the left side
            if(i > 0 && colored[i-1] == false) {
                colored[i-1] = true;
                available--;
            }
            // color on the right side
            if(j < n && colored[j] == false && available > 0) {
                colored[j] = true;
                available--;
            } 
        }
        i = j+1;
    }
    for(int i = 0; i < n; i++) 
        if(colored[i] == false) coins++;
    cout << coins;

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
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}