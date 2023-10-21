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
long long get_distance_square(int x, int y, int px, int py) {
    long long distSqr = (x-px)*(x-px) + (y-py)*(y-py);
    return distSqr;
}
void solve() {
    // Math -> case analysis
    
    int px,py; // house
    cin >> px >> py; 

    int ax, ay; // first lattern
    cin >> ax >> ay;

    int bx,by;
    cin >> bx >> by; // second lattern

    double ds1, de1; // square distance of start and end from 1st circle
    ds1 = get_distance_square(ax,ay,0,0);
    de1 = get_distance_square(ax,ay,px,py);

    double ds2, de2;
    ds2 = get_distance_square(bx,by,0,0);
    de2 = get_distance_square(bx,by,px,py);

    double ab = get_distance_square(ax,ay,bx,by) / 4.0;
    double ansSqr = 1e9;
    // // Both, start and end lies inside 1st lattern circle
    // if(ds1 <= ds2 && de1 <= de2) ansSqr = max(ds1,de1);
    // // Both, start and end lies inside 2nd lattern circle
    // else if(ds1 > ds2 && de1 > de2) ansSqr = max(ds2,de2);
    // // start lies inside 1st lattern and end lies in 2nd lattern circle
    // else if(ds1 < ds2 && de1 > de2) {
    //     ansSqr = max({ansSqr, ds1, de2});
    // }
    // // start lies inside 2nd lattern annd end lies in 1st lattern circle
    // else {
    //     ansSqr = max({ansSqr, ds2, de1});
    // }
    ansSqr = min(ansSqr,max(ds1,de1));
    ansSqr = min(ansSqr,max(ds2,de2));
    ansSqr = min(ansSqr,max({ab,ds1,de2}));
    ansSqr = min(ansSqr,max({ab,ds2,de1}));
    cout<<fixed<<setprecision(10);
    cout << sqrt(ansSqr);
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