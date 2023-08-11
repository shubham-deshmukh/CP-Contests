#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int inf = 1e9;
void solve() {
    int n;
    cin >> n;

    vector<int> steps(n+1,inf);

    steps[0] = 0;

    for(int i = 1; i <= n; i++) {
        int x = i;
        while(x) {
            int rem = x%10;
            x /= 10;
            if(rem)
                steps[i] = min(steps[i],1+steps[i-rem]);
        }
    }
    cout << steps[n];
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