#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
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
    ll n,k,i,j;
    cin >> n >> k;
    /* Approach 1: Solving the quadratic equation using 
    formula and get the integer roots (solution). 
    Time Complexity : O(log(n)) + O(n) = O(n)
    Space Complexity : O(1)
    */ 

    /*
    ll d = -(n*n)+2*n+4*k;
    ll r = sqrt(d);
    if(r*r == d) {
        cout << "YES" << endl;
        ll x = (n+r) / 2;
        ll y = (n-r) / 2;
        ll i;
        rep(i,0,x) cout << -1 << " ";
        rep(i,0,y) cout << 1 << " ";
    } 
    else cout << "NO";
    */

    /*  
    Approach 2: Using brute force
    Unlike approach 1, instead of solving the equation using formula
    brute force each value and check if equation satisfies or not
    Time Complexity : O(n)
    Space Complexity : O(1)
    */

    ll x = -1,y = -1;
    bool isPos = false;
    rep(x,0,n+1) {
        y = n-x;
        ll val = x*(x-1) / 2 + y*(y-1) / 2;
        if(val == k) {
            isPos = true;
            break;
        }
    }

    if(!isPos) cout << "NO";
    else {
        cout << "YES" << endl;
        rep(i,0,x) cout << -1 << " ";
        rep(i,0,y) cout << 1 << " ";
    }
}
int main() {
	// your code goes here
	fast;
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt", "w", stderr);
    #endif
    // solve();
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
