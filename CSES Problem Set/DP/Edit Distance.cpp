#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int inf = 6000;
void solve() {
    string s,t;
    cin >> s >> t;

    int n = (int) s.size();
    int m = (int) t.size();

    vector<vector<int>> count(n+1,vector<int> (m+1,inf));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0) count[i][j] = 0;
            else if(i == 0) count[i][j] = 1 + count[i][j-1];
            else if(j == 0) count[i][j] = 1 + count[i-1][j];
            else {
                if(s[i-1]==t[j-1]) {
                    count[i][j] = count[i-1][j-1];
                }
                else {
                    count[i][j] = 1+min({count[i][j-1],count[i-1][j],count[i-1][j-1]});
                }
            }
        }
    }
    cout << count[n][m];
}

int main() {
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