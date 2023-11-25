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

    stack<pair<int,int>> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        if(st.empty()) 
            cout << 0;
        else {
            cout << st.top().second;
        }
        st.push({a[i],i+1});
        if(i < n-1) cout << " ";
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