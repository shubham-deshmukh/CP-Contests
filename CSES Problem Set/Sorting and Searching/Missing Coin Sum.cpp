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

    vector<long long> a(n);
    for(auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    long long curr_sum = 0; // prefix sum till i
    for(int i = 0; i < n; i++) {
        if(curr_sum+1 < a[i])
            break;
        curr_sum += a[i];
    }
    cout << curr_sum+1;
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