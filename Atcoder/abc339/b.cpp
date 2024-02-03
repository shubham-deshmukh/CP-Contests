#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> g(n, string(m,'.'));
    int i = 0, j = 0;
    char dir = 'u';

    auto paintBlack = [&]()->void {
        int ii = 0, jj = 0;
        if(dir == 'u') { // up
            dir = 'r';
            jj = 1;
        }
        else if(dir == 'r') {
            dir = 'd';
            ii = 1;
        }
        else if(dir == 'd') {
            dir = 'l';
            jj = -1;
        }
        else if(dir == 'l') {
            dir = 'u';
            ii = -1;
        }

        g[i][j] = '#';
        i += ii, j += jj;
        i = (i+n)%n;
        j = (j+m)%m;        
        if(i+ii >= 0 && i+ii <= n && j+jj >= 0 && j+jj <= m) {
            // i += ii, j += jj;
        }
        else {
            // cout << "error";
        }
        
    };

    auto paintWhite = [&]()->void {
        int ii = 0, jj = 0;
        if(dir == 'u') { // up
            dir = 'l';
            jj = -1;
        }
        else if(dir == 'r') {
            dir = 'u';
            ii = -1;
        }
        else if(dir == 'd') {
            dir = 'r';
            jj = 1;
        }
        else if(dir == 'l') {
            dir = 'd';
            ii = 1;
        }

        g[i][j] = '.';
        i += ii, j += jj;
        i = (i+n)%n;
        j = (j+m)%m;
        
        if(i+ii >= 0 && i+ii <= n && j+jj >= 0 && j+jj <= m) {
        }
        else {
            // cout << "error";    
        }    
    };    

    while(q--) {
        if(g[i][j] == '.') { // white
            paintBlack();

    // for(auto s: g) cout << s << endl;  cout << endl;  
    // cout << dir << endl;        
        }
        else { // black
            paintWhite();
            // for(auto s: g) cout << s << endl;  cout << endl;  
            // cout << dir << endl;
        }
    }
    for(auto s: g)
        cout << s << endl;
}

signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}