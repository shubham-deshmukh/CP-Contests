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
    
    sort(all(coins));

    vector<ll> used(x+1,inf);

    used[0] = 0; // min zero coins used to get the sum '0'

    for(int sum = 1; sum <= x; sum++) {
        for(auto &coin: coins) {
            if(sum-coin < 0) 
                break;
            used[sum] = min(used[sum],1+used[sum-coin]);
        }
    }

    cout << (used[x]==inf?-1:used[x]);

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