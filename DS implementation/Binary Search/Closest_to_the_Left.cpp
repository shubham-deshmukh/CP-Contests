#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    auto max_index = [&](int k)->int {

        int l = -1, r = N;
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(k < A[m]) {
                r = m; // a[l] <= k < a[m] <= a[r]
            } else {
                l = m; // a[l] <= a[m] <= k < a[r]
            }
        }      

        return l+1;  
    };

    while(Q--) {
        int x;
        cin >> x;
        cout << max_index(x) << endl;
    }
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