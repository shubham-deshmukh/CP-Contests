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
    ll r,c,i,j,k;
    cin >> r >> c;
    vector<string> g(r);
    rep(i,0,r) cin >> g[i];
    string check = "snuke";
    vector<pair<ll,ll>> ans;
    bool found = false;
    rep(i,0,r) {
        rep(j,0,c) {
            if(g[i][j] == 's') {
                
                
                string target = "";
                // check right
                if(j+4 < c) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i][j+k]);
                        ans.pb({i,j+k});
                    }
                    if(target == check) {found = true;break;}
                }
                // left
                if(j-4 >= 0) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i][j-k]);
                        ans.pb({i,j-k});
                    }
                    if(target == check) {found = true;break;}
                }
                // up
                if(i-4 >= 0) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i-k][j]);
                        ans.pb({i-k,j});
                    }
                    if(target == check) {found = true;break;}                   
                }   
                // down
                if(i+4 < r) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i+k][j]);
                        ans.pb({i+k,j});
                    }
                    if(target == check) {found = true;break;}
                }
                // up-left
                if(i-4 >= 0 && j-4 >= 0) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i-k][j-k]);
                        ans.pb({i-k,j-k});
                    }
                    if(target == check) {found = true;break;}
                }   

                // up-right  
                if(i-4 >= 0 && j+4 < c) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i-k][j+k]);
                        ans.pb({i-k,j+k});
                    }
                    if(target == check) {found = true;break;}
                }   

                // down-left    
                if(i+4 < r && j-4 >= 0) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i+k][j-k]);
                        ans.pb({i+k,j-k});
                    }
                    if(target == check) {found = true;break;}
                } 

                // down-right  
                if(i+4 < r && j+4 < c) {
                    ans.clear();
                    rep(k,0,5) {
                        target += to_string(g[i+k][j+k]);
                        ans.pb({i+k,j+k});
                    }
                    if(target == check) {found = true;break;}
                }                                                                              
            }
        }
        if(found) break;
    }

    for(auto [x,y]: ans) cout << x+1 << " " << y+1 << endl;


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
