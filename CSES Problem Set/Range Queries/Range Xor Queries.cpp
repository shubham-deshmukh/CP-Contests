#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

#define int long long

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    vector<int> pre_xor(N+1);
    pre_xor[0] = 0;

    for(int i = 1; i <= N; i++)
        pre_xor[i] = pre_xor[i-1] ^ A[i-1]; 

    while(Q--) {
        int lb, rb;
        cin >> lb >> rb;

        // range xor sum
        cout << (pre_xor[rb] ^ pre_xor[lb-1]);
        if(Q)
            cout << endl;
    }
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