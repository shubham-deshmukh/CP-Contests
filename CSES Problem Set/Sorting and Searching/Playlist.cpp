#include <iostream>
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

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    set<int> s;
    int i = 0, j = 0;
    int max_playlist = 0;
    while(j < n) {
        if(s.count(a[j]) == 0) {
            s.insert(a[j]);
            max_playlist = max(max_playlist, (int)s.size());
        }
        else {
            while(a[i] != a[j]) {
                s.erase(s.find(a[i]));
                i++;
            }
            i++;
        }
        j++;
    }
    cout << max_playlist;
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