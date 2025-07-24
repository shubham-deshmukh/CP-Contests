#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void solve() {
    int r,c;
    cin >> r >> c;

    vector<string> grid(r);
    for(auto &s: grid) cin >> s;

    vector<vector<bool>> vis(r,vector<bool>(c,false));
    bool found = false;
    string ans = "NO";
    vector<char> path;

    auto get_dir = [&](int k) -> char {
        char dir = 'N';

        if(k == 0) dir = 'U';
        else if(k == 1) dir = 'D';
        else if(k == 2) dir = 'R';
        else if(k == 3) dir = 'L';

        return dir;
    };
    
    // auto dfs = [&] (const auto &self, int i, int j) -> void {
    //     vis[i][j] = true;

    //     if(grid[i][j] == 'B') found = true;

    //     if(found) {
    //         ans = "YES";
    //         return;
    //     }

    //     for(int k = 0; k < 4; k++) {
    //         int x = i + dx[k];
    //         int y = j + dy[k];

    //         if((x >= 0 && x < r) && (y >=0 && y < c) && !vis[x][y] && (grid[x][y]=='.' || grid[x][y]=='B')) {
    //             char dir;
    //             if(k == 0) dir = 'L';
    //             else if(k == 1) dir = 'R';
    //             else if(k == 2) dir = 'U';
    //             else if(k == 3) dir = 'D';

    //             path.push_back(dir);
    //             self(self,x,y);
    //         }

    //     }

    // };

    queue<pair<int,int>> q;
    vector<vector<char>> dir(r,vector<char>(c));
    int ax,ay,bx = -1,by = -1;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 'A') {
                // dfs(dfs,i,j);
                ax = i;
                ay = j;
                q.push({i,j});
                while(!q.empty()) {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    vis[i][j] = true;
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        

                        bool c1 = (x >= 0 && x < r);
                        bool c2 = (y >=0 && y < c);
                        bool c3 = (grid[x][y]=='.' || grid[x][y]=='B'); 
                        bool c4 = (vis[x][y] == false);

                        if(c1 && c2 && c3 && c4) {
                            dir[x][y] = get_dir(k);
                            if(grid[x][y] == 'B') {
                                ans = "YES";
                                bx = x;
                                by = y;
                                break;
                            }
                            q.push({x,y});
                        }
                    }
                }
                break;
            }
        }
    }

    cout << ans;
    if(ans == "YES" ) {
        cout << endl;
        int x = bx, y = by;
        int k;
        while(x != ax && y != ay) {
            path.push_back(dir[x][y]);
            if(dir[x][y] == 'U') {
                k = 1;
            }
            else if(dir[x][y] == 'D') {
                k = 0;
            }
            else if(dir[x][y] == 'L') {
                k = 2;
            }
            else if(dir[x][y] == 'R') {
                k = 3;
            }

            x = x + dx[k];
            y = y + dy[k];

        }
        cout << (int)path.size() << endl;
        reverse(path.begin(), path.end());
        for(auto &ch: path) cout << ch;
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
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}