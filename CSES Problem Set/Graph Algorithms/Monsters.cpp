#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;


void solve() {
    int n,m; // n : row, m : columns
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &s: grid) cin >> s;

    int sr,sc;

    vector<vector<int>> dist(n,vector<int>(m,-1)); // initially no one is reachable (-1)
    
    // find the position of A
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                sr = i, sc = j;
                break;
            }
        }

    // cerr << "start : " << sr << " end: " << sc << endl;
    // shortest distance from start to each boundry square
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<int,int>> q;

    dist[sr][sc] = 0;
    vis[sr][sc] = true;
    q.push({sr,sc});

    // left, right, top, bottom
    int dr[] = {0,0,1,-1}; 
    int dc[] = {-1,1,0,0};

    while(!q.empty()) {
        int parent_r = q.front().first;
        int parent_c = q.front().second;

        q.pop();

        for(int k = 0; k < 4; k++) {
            int child_r = parent_r + dr[k];
            int child_c = parent_c + dc[k];

            bool isValidHB = (child_r >= 0 && child_r < n);
            bool isValidVB = (child_c >= 0 && child_c < m);

            bool isVis = vis[child_r][child_c];
            char child_ch = grid[child_r][child_c];
            bool isValidSqr = (child_ch != 'M' && child_ch != '#');

            if(isValidHB && isValidVB && !isVis && isValidSqr) {
                vis[child_r][child_c] = true;
                dist[child_r][child_c] = 1 + dist[parent_r][parent_c];
                q.push({child_r,child_c});
            }
        }
    }


    // // display the distance from the start 
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cerr << dist[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    bool isValidPath = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            char ch = grid[i][j];
            if(ch != 'M') continue;

            queue<vector<int>> mq;
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            mq.push({i,j,0});

            while(!q.empty()) {
                int pi = mq.front()[0];
                int pj = mq.front()[1];
                int dis = mq.front()[2];

                mq.pop();

                bool isEqualDistance = (dis == dist[pi][pj]);
                bool isBoundry = (pi == 0 || pi == (n-1) || pj == 0 || pj == (m-1));

                if(isEqualDistance && isBoundry) {
                    isValidPath = false;
                    cout << "NO";
                    return;
                }

                for(int k = 0; k < 4; k++) {
                    int child_r = pi + dr[k];
                    int child_c = pj + dc[k];

                    bool isValidHB = (child_r >= 0 && child_r < n);
                    bool isValidVB = (child_c >= 0 && child_c < m);

                    bool isVis = vis[child_r][child_c];
                    char child_ch = grid[child_r][child_c];
                    bool isValidSqr = (child_ch != 'M' && child_ch != '#');

                    if(isValidHB && isValidVB && !isVis && isValidSqr) {
                        vis[child_r][child_c] = true;
                        // dist[child_r][child_c] = 1 + dist[parent_r][parent_c];
                        mq.push({child_r,child_c, dis+1});
                    }
                }



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
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}