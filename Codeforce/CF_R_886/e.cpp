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
    // Approach 0: Using Quadratic formula 
    /*
    Calculationg value of w using formula causes following issues
    1. Precision
    2. Overflow
    */

    // Approach 1: Using binary Search
    // Why to use BS: Quadratic Equation is monotonously increasing
    // Taking minimum possible upper limit
    /*
    Login behind considering minimum possible upper limit
    SUMMATION (2w + x)^2 = c
    SUMMATION (4w^2 + 4w * x + x^2) = c
    4n * w^2 + 4w * sum(x) + sum(x^2) = c
    4n * w^2 + 4w * sum(x) = c - sum(x^2)
    Let's say A + B = C
    Then we can say that A < C 
    Therefore,
    4n * w^2  < c - sum(x^2)
    w^2 < (s - sum(x^2)) / 4n = constant
    w < sqrt(constant)
    */
    int n,i;
    int64_t c;
    cin >> n >> c;
    int64_t sum_s = 0, sum_s2 = 0;
    for(int i = 0 ; i < n; i++) {
        int64_t s;
        cin >> s;
        sum_s += s;
        sum_s2 += s * s;
    }
    int64_t low = 0;
    int64_t constant = (c-sum_s2) / 4;
    int64_t high = int64_t(sqrt(constant / n)) + 1;
    while(low <= high) {
        int64_t mid = low + (high - low) / 2;
        int64_t t = n * mid * mid + mid * sum_s;
        if(t < constant)
            low = mid + 1;
        else if(t > constant)
            high = mid - 1;
        else {
            cout << mid;
            break;
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
