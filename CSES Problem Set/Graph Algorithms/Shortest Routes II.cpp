#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const long long INF = LLONG_MAX;

void solve() {
    int n,m,q;
    cin >> n >> m >> q; // n : cities, m : roads, q : queries

    vector<vector<long long>> dist(n,vector<long long>(n,INF));
    for(int i = 0; i < m; i++) {
        int a,b;
        long long c;
        cin >> a >> b >>c;
        // two-way
        a--;
        b--;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[a][b],c);
    }

    for(int i = 0; i < n; i++) 
        dist[i][i] = 0;
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }   

    while(q--) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        cout << (dist[u][v] == INF?-1:dist[u][v]);
        if(q) cout << endl;
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