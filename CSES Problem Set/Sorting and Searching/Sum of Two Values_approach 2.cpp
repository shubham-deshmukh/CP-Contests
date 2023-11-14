#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,x;
    cin >> n >> x;

    // online processing
    // unordered_map<int,int> um;
    map<int,int> um; // num --> index
    for(int i = 0; i < n; i++) {
        int num1, num2;
        cin >> num1;
        num2 = x - num1;
        if(um.count(num2)) {
            cout << i+1 << " " << um[num2];
            return;
        }
        um[num1] = i+1;
    }

    cout << "IMPOSSIBLE";
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