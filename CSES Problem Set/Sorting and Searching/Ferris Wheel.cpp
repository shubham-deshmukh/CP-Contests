#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> w(n);
    for(auto &x: w) cin >> x;

    sort(w.begin(), w.end());

    int cnt = 0;
    int i = 0, j = n-1;
    while(i < j) { 
        if(w[i]+w[j] <= m) {
            cnt++;
            i++;j--;
        }
        else {
            cnt++;
            j--;
        }
    }
    if(i == j) cnt++;
    cout << cnt;
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