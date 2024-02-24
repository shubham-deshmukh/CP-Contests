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

    string s;
    cin >> s;

    vector<vector<int>> f(26);
    vector<int> pos(26);
    iota(pos.begin(), pos.end(), 0);
    for(int i = 0; i < n; i++) {
        f[s[i]-'a'].push_back(i);
    }

    int q;
    cin >> q;
    while(q--) {
        char x, y; // replace x with y
        cin >> x >> y;
        for(auto &v: pos)
            if(v == x-'a')
                v = y-'a';
    }

    for(int i = 0; i < 26; i++) {
        for(auto id: f[i]) {
            s[id] = pos[i]+'a';
        }
    }

    cout << s;
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