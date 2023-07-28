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
    vector<ll> psum(n-1);
    for(auto &x: psum) cin >> x;

    map<ll,ll> freq;
    if(n*(n+1) / 2 != psum[n-2]) { // last element is missing
        freq[psum[0]]++; 
        freq[n*(n+1)/ 2  - psum[n-2]]++;
        for(int i = 1; i < n-1; i++) {
            freq[psum[i]-psum[i-1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(freq[i] != 1) {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    }
    else { 
        freq.clear();
        // 1st element is missing
        for(int i = 1; i < n-1; i++) {
            freq[psum[i]-psum[i-1]]++;
        }   
        ll tsum = 0;
        for(int i = 1; i <= n; i++) {
            if(freq[i] != 1) {
                tsum += i;
            }
        }    
        if(tsum == psum[0]) { // 1st element is missing
            cout << "YES";
            return ;
        } 
        else {  // middle element is missing
            freq.clear();
            for(int i = 1; i < n-1; i++) {
                freq[psum[i]-psum[i-1]]++;
            }        
            freq[psum[0]]++;
            tsum = 0;
            ll cnt = 0;
            for(auto [u,v] : freq) {
                if(u >= 1 && u <= n) cnt++;
            }
            if(cnt == n-2) {
                cout << "YES";
                return ;
            }
        }
        cout << "NO";
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
