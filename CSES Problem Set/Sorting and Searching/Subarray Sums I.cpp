#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int N;
    cin >> N;

    long long x;
    cin >> x;

    long long psum = 0;
    long long cnt = 0;

    map<long long, long long> freq;
    freq[0] = 1;

    for(int i = 0; i < N; i++) {
        long long a;
        cin >> a;

        psum += a;
        cnt += freq[psum-x];

        freq[psum]++;
    }

    cout << cnt;

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