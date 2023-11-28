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
    int n,req_freq;
    cin >> n >> req_freq;

    string s;
    cin >> s;

    map<char,int> freq;
    for(auto &ch: s) freq[ch]++;

    const char A = 'A', B = 'B';
    
    int op = 0;
    
    if(req_freq == freq[B]) {
        cout << 0;
        return;
    }
    else if(req_freq > freq[B]) { // 3 2
        // ADD B's
        // 3 AABAB
        // How many B's needed to add
        int need = req_freq - freq[B];

        // replace that many A's from the start
        assert(need <= freq[A]);

        int A_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == A) 
                A_cnt++;
            
            if(A_cnt == need) {
                cout << 1 << endl;
                cout << i+1 << " " << B;
                return;
            }
        }
    }
    else {
        // Remove B's
        // 0 BBBBB
        // How many B's needed to replace
        int unwanted = freq[B] - req_freq;
        int B_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == B)
                B_cnt++;
            
            if(B_cnt == unwanted) {
                cout << 1 << endl;
                cout << i+1 << " " << A;
                return;
            }
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