#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    // sentinals
    A.push_back(INT_MAX);
    B.push_back(INT_MAX);

    int i = 0, j = 0;
    while(i < n || j < m) {
        if(A[i] < B[j]) {
            cout << A[i];
            i++;
        }
        else {
            cout << B[j];
            j++;
        }
        cout << " ";   
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