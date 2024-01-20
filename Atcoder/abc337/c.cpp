#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
/*
10
-1 1 2 3 4 5 6 7 8 9
*/
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    map<int,int> m1; // pos -> value
    map<int,int> m2; // value ->pos

    for(int i = 0; i < n; i++) {
        m1[i+1] = A[i];
        m2[A[i]] = i+1;
    }
    int pos = 0, value = -1, i = 0;
    while(1) {

        int pos = m2[value];
        cout << pos;
        value = pos;
        i++;
        if(i == n) break;
        else cout << " ";
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