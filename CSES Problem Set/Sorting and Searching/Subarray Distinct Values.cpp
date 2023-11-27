#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    // approach : Sliding window (two pointer)
    int N,k;
    cin >> N >> k;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    int l = 0, r = 0;
    map<int,int> mp; // distinct elements in the current window
    long long cnt = 0;
    while(r < N) {
        mp[A[r]]++;

        // check the #distinct elements
        // make the windows with at most k distinct elements if not
        while((int)mp.size() > k) {
            mp[A[l]]--;
            if(mp[A[l]] == 0) 
                mp.erase(A[l]);
            l++;
        }

        cnt += r - l + 1;
        r++;
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