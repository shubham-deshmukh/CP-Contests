#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(auto &row: grid) cin >> row;

    vector<vector<int>> path(n+1,vector<int>(n+1,0));

    if(grid[0][0] != '*') path[1][1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) 
                continue;
            if(grid[i-1][j-1] == '*')
                continue;
            
            path[i][j] = path[i-1][j] + path[i][j-1];
            path[i][j] %= mod;
        }
    }

    cout << path[n][n];
    
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