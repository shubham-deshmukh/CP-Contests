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
    vector<int> coins(n);
    int max_denom = 0;
    for(auto &c: coins) {
        cin >> c;
        max_denom = max(max_denom,c);
    }
    int w = n*max_denom;
    vector<vector<bool>> isSumPos(n+1,vector<bool>(w+1,false));

    for(int i = 0; i <= n; i++) {
        for(int sum = 0; sum <= w; sum++) {
            if(sum == 0) isSumPos[i][sum] = true;
            else if(i == 0) isSumPos[i][sum] = false;
            else {
                isSumPos[i][sum] = isSumPos[i-1][sum] || (sum >= coins[i-1]?isSumPos[i-1][sum-coins[i-1]]:false);
            }
        }
    }

    vector<int> sums;
    for(int i = 1; i <= w; i++) {
        if(isSumPos[n][i]) sums.push_back(i);
    }

    cout << (int) sums.size() << endl;
    for(auto &e: sums) cout << e << " ";

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