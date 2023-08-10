#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {

    vector<int> face_value = {1,2,3,4,5,6};
    int n;
    cin >> n;

    vector<int64_t> ways(n+1,0);
    ways[0] = 1;
    for(int64_t sum = 1; sum <= n; sum++)
        for(auto &fv: face_value) {
            if(sum-fv >= 0) {
                ways[sum] += ways[sum-fv];
                ways[sum] %= mod;
            }
            else 
                break;
        }

    cout << ways[n]%mod;
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