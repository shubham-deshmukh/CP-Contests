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
string get_winner(char ch) {
    string winner;
    
    if(ch == 'X') winner = "X";
    else if(ch == 'O') winner = "O";
    else if (ch == '+') winner = "+";
    else winner = '.';

    return winner;
}
void solve() {
    int n = 3;
    vector<string> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    for(int row = 0; row < n; row++) {
        if(a[row][0] != '.' && a[row][0] == a[row][1] && a[row][1] == a[row][2]) {
            cout << get_winner(a[row][0]);
            return;
        }
    }

    for(int col = 0; col < n; col++) {
        if(a[0][col] != '.' && a[0][col] == a[1][col] && a[1][col] == a[2][col]) {
            cout << get_winner(a[0][col]);
            return;
        }
    }

    if(a[0][0] != '.' && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
        cout << get_winner(a[0][0]);
        return;
    }

    if(a[2][0] != '.' && a[2][0] == a[1][1] && a[1][1] == a[0][2]) {
        cout << get_winner(a[2][0]);
        return;
    }

    cout << "DRAW";
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
