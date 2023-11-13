#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(auto &sz: a) cin >> sz;

    vector<int> b(m);
    for(auto &sz: b) cin >> sz;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int allocated = 0;
    while(i < n && j < m) {
        if(a[i]-k > b[j]) {
            j++;
        }
        else if(a[i]+k < b[j]) {
            i++;
        }
        else {
            allocated++;
            i++;
            j++;
        }
    }

    cout << allocated;
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