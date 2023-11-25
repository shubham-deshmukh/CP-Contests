#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for(auto &x: machines) cin >> x;

    auto f = [&](const long long m)->long long {
        long long product = 0;
        for(auto tt: machines) {
            product += m/tt;
            if(product >= t) 
                break;
        }
        return product;
    };

    long long low = 0, high = 2e18;
    while(low <= high) {
        long long mid = low + (high-low) / 2;
        long long f_value = f(mid);

        if(t <= f_value) {
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    cout << low; 
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