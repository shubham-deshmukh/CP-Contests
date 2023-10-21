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
    long long n;
    cin >> n;

    if(n%3 == 0) {
        /*
        n = 5 + n-5
          = 1 + 4 + n-5
        
        n-5 != 1 and n-5 != 4 and n-5 >0
        => n != 6 and n != 9 and n > 5
        */
        if(n !=6 && n != 9 && n > 5) {
            cout << "YES\n";
            cout << 1 << " " << 4 << " " << n-5;
        }
        else {
            cout << "NO";
        }
    }
    else {
        /*
        n = 3 + n-3
          = 1 + 2 + n-3
        n-3 != 1 and n-3 != 2 and n-3 > 0
        => n != 4 and n != 5 and n > 3
        */
        if(n != 4 and n != 5 && n > 3) {
            cout << "YES\n";
            cout << 1 << " " << 2 << " " << n-3;
        }
        else {
            cout << "NO";
        }

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