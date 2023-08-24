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

    ll sum = n*(n+1) / 2;

    if(sum % 2 != 0) {cout << 0; return;}

    ll W = sum / 2;

    vector<vector<ll>> ways(n+1,vector<ll> (W+1,0));

    
    for(int i = 0; i <= n; i++) {
        for(int sum = 0;  sum <= W; sum++) {
            if(i == 0 && sum == 0) ways[i][sum] = 1; // base case
            else if(sum == 0) ways[i][sum] = 0; // base case
            else if(i == 0) ways[i][sum] = 0; // base case
            else {
                ways[i][sum] = ways[i-1][sum];
                if(sum-i >= 0)
                    ways[i][sum] += ways[i-1][sum-i];
                ways[i][sum] %= mod;
            }
        }
    }
    cout << ways[n][W];

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