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

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    // prefix sum
    vector<long long> preSum(N+1);
    for(int i = 1; i <= N; i++) {
        preSum[i] = preSum[i-1] + A[i-1];
    }

    // Calculate number of prefixes with possible reminders
    long long cnt = 0;
    vector<int> reminder(N);
    for(int i = 0; i <= N; i++) {
        int rem = (preSum[i]%N+N)%N;
        cnt += 1LL*reminder[rem];
        reminder[rem] += 1;
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