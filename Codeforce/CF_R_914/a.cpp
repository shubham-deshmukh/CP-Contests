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
    long long a,b;
    cin >> a >> b;

    long long xk, yk;
    cin >> xk >> yk;

    long long xq, yq;
    cin >> xq >> yq;

    long long dx[] = {-a,-a,a,a,-b,-b,b,b};
    long long dy[] = {-b,b,-b,b,-a,a,-a,a};

    long long dir = 8;
    if(a == b) dir = 4;

    auto check = [&](int x, int y, int xt, int yt)->bool {

        for(int d = 0; d < dir; d++) {
            long long xe = x + dx[d];
            long long ye = y + dy[d];

            // Is target reachable?
            if(xe == xt && ye == yt) 
                return true;
        }
    
        return false;
    };

    long long ans = 0;


    for(int d = 0; d < dir; d++) {
        long long xe = xk + dx[d];
        long long ye = yk + dy[d];

        // Is queen is reachable from expected pos of knight from king's position?
        if(check(xe, ye, xq, yq)) {
            ans++;
            cerr << xe << " " << ye << endl;
        }
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