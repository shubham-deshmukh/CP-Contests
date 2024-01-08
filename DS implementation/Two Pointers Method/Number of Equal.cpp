#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
#define int int64_t
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    map<int,int> mpA, mpB;
    for(auto a: A)
        mpA[a]++;
    
    for(auto b: B) 
        mpB[b]++;

    int ans = 0;
    for(auto [u,v]: mpA) {
        if(mpB.count(u)) ans += v * mpB[u];
    }
    cout << ans;
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