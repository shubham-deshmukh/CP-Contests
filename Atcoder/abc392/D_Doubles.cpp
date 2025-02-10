#include <bits/stdc++.h>

using namespace std;

// #ifndef ONLINE_JUDGE
// #include "./debug.h"
// #else
// #define debug(x...)
// #endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.


const int MAX_N = 1e5;
const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}
#define int int64_t
void solve() {
    // Brute force
    int n;
    cin >> n;

    vector<map<int,int>> freq(n);
    vector<int> len(n);
    for(int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        len[i] = sz;
        for(int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            freq[i][x] += 1;
        }
    }

    auto getProb = [&](int i, int j)->double {
        // i is smaller than j
        if(len[i] > len[j])
            swap(i,j);
        
        double prob = 0;
        for(auto [v,f]: freq[i]) {
            if(freq[j].find(v) != freq[j].end()) {
                prob += (freq[j][v] * freq[i][v] * 1.0) / (len[i] * len[j]);
            }
        }
        return prob;
    };

    double maxProb = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            maxProb = max(maxProb,getProb(i,j));
        }
    }

    
    cout << fixed << setprecision(15) << maxProb;
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
