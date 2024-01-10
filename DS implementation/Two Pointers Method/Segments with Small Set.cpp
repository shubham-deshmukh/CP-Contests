#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    map<int,int> mp;
    long long cnt = 0;
    for(int r  = 0, l = 0; r < n; r++) {
        mp[A[r]]++;

        while(mp.size() > k) {
            if(mp[A[l]] <= 1)
                mp.erase(A[l]);
            else
                mp[A[l]]--;
            l += 1;
        }

        cnt += (r-l+1);
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