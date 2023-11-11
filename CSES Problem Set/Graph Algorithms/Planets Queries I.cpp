#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,q; // n: number of planets, q: queries
    cin >> n >> q;

    vector<int> t(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    int BITS = ceil(log2(1e9));
    
    // vector<vector<int>> parent(2e5+5, vector<int>(BITS,0));
    int parent[int(2e5+5)][BITS];

    // parent[i][j] : 2^j th ancestor of i
    // j : 0 => 2^0 = 1st ancestor (i.e. parent[i])
    for(int v = 1; v <= n; v++) {
        parent[v][0] = t[v];
    }

    for(int j = 1; j < BITS; j++) {
        for(int v = 1; v <= n; v++) {
            parent[v][j] = parent[ parent[v][j-1] ][j-1]; 
        }
    }

    while(q--) {
        int x,k; // Kth ancestor of node x
        cin >> x >> k;

        for(int b = 0; b < BITS; b++) {
            if(k & (1 << b)) {
                x = parent[x][b];
            }
        }

        cout << x;
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