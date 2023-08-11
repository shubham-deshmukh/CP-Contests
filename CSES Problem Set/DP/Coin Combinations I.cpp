#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);

    for(auto &c: coins) cin >> c;

    sort(all(coins));
    
    vector<int64_t> ways(x+1,0);

    ways[0] = 1; // ways to get sum '0' is do not pick any coins

    for(int sum = 1; sum <= x; sum++) {
        for(auto &coin: coins) {
            if(sum-coin < 0) 
                break;
            ways[sum] += ways[sum-coin];
            ways[sum] %= mod;
        }
    }
    cout << ways[x];

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