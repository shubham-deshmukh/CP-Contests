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

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    vector<long long> pre_sum(n+1,0), min_pre_sum(n+1,0);

    // Calculate prefix sum
    for(int i = 1; i <= n; i++)
        pre_sum[i] = pre_sum[i-1]+a[i-1];
    
    // Minimum prefix sum
    for(int i = 1; i <= n; i++) {
        min_pre_sum[i] = min(pre_sum[i], min_pre_sum[i-1]);
    }

    // maximum subarray sum
    // pre[i] - min_pre_sum[i-1]
    long long max_sum = a[0];
    for(int i = 1; i <=n; i++) {
        max_sum = max(max_sum, pre_sum[i]-min_pre_sum[i-1]);
    }

    cout << max_sum;


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