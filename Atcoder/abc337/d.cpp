#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> g(n);
    for(auto &s: g) cin >> s;

    // horizontal processing
    int op = max(n,m) + 1;
    for(auto s: g) {
        int sz = (int)s.size();
        int start = 0;
        while(start < sz) {
            while(start < sz && s[start] == 'x') start++;
            // calculate . and o in the segment
            int dot = 0, zero = 0;
            while(start < sz && s[start] != 'x') {
                dot += (s[start]=='.');
                zero += (s[start]=='o');
                start += 1;
            }

            if(zero >= k) {
                cout << 0;
                return;
            }

            if(dot + zero >= k) {
                op = min(op, k-zero);
            }
        }
    }


    // vertical processing
    for(int c = 0; c < m; c++) {
        string s;
        for(int r = 0; r < n; r++)
            s.push_back(g[r][c]);

        int sz = (int)s.size();
        int start = 0;
        while(start < sz) {
            while(start < sz && s[start] == 'x') start++;
            // calculate . and o in the segment
            int dot = 0, zero = 0;
            while(start < sz && s[start] != 'x') {
                dot += (s[start]=='.');
                zero += (s[start]=='o');
                start += 1;
            }

            if(zero >= k) {
                cout << 0;
                return;
            }

            if(dot + zero >= k) {
                op = min(op, k-zero);
            }
        }        
    }

    if(op == max(n,m)+1) op = -1;
    cout << op;
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