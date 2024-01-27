#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    string s;
    cin >> s;

    int n = (int) s.size();
    bool f = true;

    for(int i = 0; i < n; i++) {
        if(i == 0 && !(s[i] >= 'A' && s[i] <= 'Z')) {
            f = false;
            break;
        }
        if(i > 0 && !(s[i] >= 'a' && s[i] <= 'z')) {
            f = false;
            break;
        }
    }
    if(f) cout << "Yes";
    else cout << "No";

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