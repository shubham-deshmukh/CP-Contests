#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m;
    cin >> n >> m;

    multiset<int> ms;
    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        ms.insert(price);
    }

    vector<int> max_price(m);
    for(auto &p: max_price) cin >> p;

    for(auto p: max_price) {
        auto it = ms.upper_bound(p);

        if(it == ms.begin()) cout << -1;
        else {
            it--;
            cout << *it;
            ms.erase(it);
        }
        cout << endl;
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