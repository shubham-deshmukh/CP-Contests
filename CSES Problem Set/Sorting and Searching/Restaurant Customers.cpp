#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int c;
    cin >> c;

    vector<pair<int,int>> entries;
    for(int i = 0; i < c; i++) {
        int start, end;
        cin >> start >> end;

        entries.push_back({start,+1});
        entries.push_back({end,-1});
    }

    sort(entries.begin(), entries.end());

    int cnt = 0;
    int mxCnt = 0;
    for(auto [u,v] : entries) {
        cnt += v;
        mxCnt = max(mxCnt, cnt);
    }
    cout << mxCnt;
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