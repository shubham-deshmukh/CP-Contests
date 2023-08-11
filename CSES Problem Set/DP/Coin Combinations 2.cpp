#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const ll inf = 1e18;
void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);

    for(auto &c: coins) cin >> c;

    vector<vector<int>> ways(n+1,vector<int> (x+1,0));

    ways[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int sum = 0; sum <= x; sum++) {
            ways[i][sum] = ways[i-1][sum] + (sum >= coins[i-1]?ways[i][sum-coins[i-1]]:0);
            ways[i][sum] %= mod; 
        }
    }

    cout << ways[n][x];
   
    
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