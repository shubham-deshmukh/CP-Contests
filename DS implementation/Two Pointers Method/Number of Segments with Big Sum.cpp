#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

#define int int64_t 

void solve() {
    int n,s;
    cin >> n >> s;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int currSum = 0;
    int cnt = 0;
    int l = 0;
    for(int r = 0; r < n; r++) {
        currSum += A[r];

        while(currSum >= s) {
            cnt += (n-r);
            currSum -= A[l];
            l += 1;
        }
    }

    cout << cnt;
}

signed main() {
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