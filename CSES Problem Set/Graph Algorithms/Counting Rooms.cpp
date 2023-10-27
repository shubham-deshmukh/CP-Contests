#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;


void solve() {
    int r,c;
    cin >> r >> c;

    vector<string> grid(r);
    for(auto &s: grid) cin >> s;

    vector<vector<bool>> vis(r,vector<bool>(c,false));

    //direction vector
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

    auto dfs = [&](const auto &self, int i, int j) -> void {
        vis[i][j] = true;
        
        for(int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if((x >= 0 && x < r) && (y >=0 && y < c) && !vis[x][y] && grid[x][y] == '.') 
                self(self,x,y);
        }
        
    }; 

    int rooms = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!vis[i][j] && grid[i][j]=='.') {
                dfs(dfs,i,j);
                rooms++;
            }
        }
    }

    cout << rooms;


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