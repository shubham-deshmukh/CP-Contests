#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, amount;
    cin >> n >> amount;

    vector<int> price(n), pages(n);

    for(auto &p: price) cin >> p;
    for(auto &p: pages) cin >> p;

    vector<vector<int>> count(n+1,vector<int> (amount+1,0));

    for(int i = 0; i <= n; i++) {
        for(int sum = 0; sum <= amount; sum++) {
            if(i == 0 || sum == 0) 
                count[i][sum] = 0;
            else {
                if(sum >= price[i-1])
                    count[i][sum] = count[i-1][sum-price[i-1]] + pages[i-1];
                count[i][sum] = max(count[i][sum], count[i-1][sum]);

            }
        }
    }  
    cout << count[n][amount];

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