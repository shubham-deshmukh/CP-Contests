#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
#define int int64_t

void solve() {
    int n, k;
    cin >> n >> k;

    using pii = pair<int,int>;
    vector<pii> A(n);
    for(auto &[u,v]: A) cin >> u >> v;

    // Number of elements less than x
    auto isGood = [&](const int mid)->bool {
    
       int cnt = 0;
        for(auto [u,v]: A) {
            if(mid <= u) 
                cnt += 0;
            else if(mid > v) 
                cnt += v-u+1;
            else {
                cnt += mid-u;
            }
        }
        return cnt <= k;        
    };

    // Ob-1: every element in the segment is sorted.
    int l = -2e9; // good;
    int r = 1; // bad 

    while(isGood(r)) r <<= 1;

    while(r - l > 1) {
        int mid = l + (r-l) / 2;
        if(isGood(mid))
            l = mid;
        else    
            r = mid;
    }
    cout << l;
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