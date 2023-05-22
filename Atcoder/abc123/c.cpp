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

bool check(ll i) {
    if(i == ('a'-'a') || i == ('t'-'a') || i == ('c'-'a') || i == ('o'-'a') || i==('d'-'a') || i==('e'-'a') || i==('r'-'a')) return true;
    return false;
}
void solve() {
    ll i,j;
    string s,t;
    cin >> s >> t;
    if((ll)s.size() != (ll)t.size()) {cout << "No";return;}

    vector<ll> s_freq(26,0), t_freq(26,0);
    ll s_cnt = 0, t_cnt = 0;

    for(auto c: s) {
        if(c == '@') s_cnt++;
        else s_freq[c-'a']++;
    }
    for(auto c: t) {
        if(c =='@') t_cnt++;
        else t_freq[c-'a']++;
    }
    ll s_req = 0, t_req = 0;
    rep(i,0,26) {
        ll diff = s_freq[i] - t_freq[i];
        if(diff < 0) {
            // s_req += (-1)*diff;
            if(check(i) == false) {
                cout << "No";return;
            }
            else {
                s_cnt += diff;
            }
        }
        else if(diff > 0) {
            // t_req += diff;
            if(check(i) == false) {
                cout << "No";return;
            }
            else {
                t_cnt -= diff;
            }
        }
    }

    if(s_cnt == t_cnt && s_cnt >= 0) cout << "Yes";
    else cout << "No";
}
int main() {
	// your code goes here
	fast;
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt", "w", stderr);
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
