#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    auto BinarySearch = [&](int x)->string {

        string isPresent = "NO";

        // int low = 0, high = N-1;
        // while(low <= high) {
        //     int mid = low + (high - low) / 2;
        //     if(A[mid] == x) {
        //         isPresent = "YES";
        //         break;
        //     }
        //     else if(x > A[mid]) 
        //         low = mid + 1;
        //     else 
        //         high = mid - 1;
        // }

        int l = -1; // a[l] <= k
        int r = N; // a[r] > k
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(x < A[m]) {
                r = m; 
            } else {
                l = m; 
            }
        } 

        if(l != -1 && A[l] == x) isPresent = "YES"; 
        return isPresent;
    };

    while(Q--) {
        int x;
        cin >> x;

        cout << BinarySearch(x) << endl;
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