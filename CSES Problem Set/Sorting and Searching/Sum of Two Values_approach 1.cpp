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

    vector<pair<int,int>> a;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back({t,i+1});
    }

    sort(a.begin(), a.end());

    int start = 0, end = n-1;
    while(start < end) {
        int num1 = a[start].first;
        int num2 = a[end].first;

        if(num1 + num2 == x) {
            cout << a[start].second << " " << a[end].second;
            return;
        }
        else if(num1 + num2 < x) {
            start++;
        }
        else {
            end--;
        }
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