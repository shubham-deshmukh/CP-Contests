#include <iostream>
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

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int sum = accumulate(A.begin(), A.end(), int(0));

    auto isOk = [&](const int &sm)->bool {
        int tot = 0;
        int need = 1;
        for(auto &a: A) {
            if(sm < a)
                return false;
            if(a+tot > sm) {
                need += 1;
                tot = a;

                if(need > k)
                    return false;
                
                continue;
            }

            tot += a;
        }
        return need <= k;
    };

    int l = -1, r = sum;
    while(r-l>1) {
        int mid = l + (r-l) / 2;
        if(isOk(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << r;
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