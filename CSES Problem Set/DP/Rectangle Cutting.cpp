#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int inf = 500*500+10;

void solve() {
    int a,b;
    cin >> a >> b;

    vector<vector<int>> moves(a+1,vector<int> (b+1,inf));

    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(i == 0 || j == 0) moves[i][j] = 0;
            if(i == j) moves[i][j] = 0;
            else {
                
                // horizontal cuts
                int min_moves = inf;
                for(int k = 1; k < i; k++) {
                    min_moves = min(min_moves, 1+moves[k][j]+moves[i-k][j]);
                }
                // vertical cuts
                for(int k = 1; k < j; k++) {
                    min_moves = min(min_moves, 1+moves[i][k]+moves[i][j-k]);
                }       
                moves[i][j] = min_moves;
            }
        }
    }
    cout << moves[a][b];

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