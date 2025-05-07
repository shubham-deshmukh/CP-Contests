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
constexpr int inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m; // n : zoo, m : types of animals

    vector<int> fee(n);
    for(auto &f: fee) cin >> f;

    vector<int> sz(m);
    vector<vector<int>> animals(m);
    vector<vector<int>> zoo(n);
    for(int i = 0; i < m; i++) {
        cin >> sz[i];

        for(int j = 0; j < sz[i]; j++) {
            int x;
            cin >> x;

            x -= 1;

            animals[i].push_back(x);
            zoo[x].push_back(i);
        }
    }

    vector<int> freq(m);
    vector<int> seq(2*n);
    iota(seq.begin(), seq.begin()+n,0);
    for(int i = n; i < 2*n; i++) {
        seq[i] = seq[i-n];
    }

    auto f = [&](const auto &self, int i)->int {
        if(i == 2*n) {
            bool isOk = true;
            for(auto &f: freq)
                isOk &= (f >= 2);
            
            if(isOk)
                return 0;
            
            return inf;
        }

        // do not visit ith zoo
        int notVisit = self(self,i+1);
        for(auto &a: zoo[i%n]) {
            freq[a] += 1;
        }
        int visit = fee[i%n] + self(self,i+1);
        for(auto &a: zoo[i%n]) {
            freq[a] -= 1;
        }

        return min(notVisit,visit);
    };
    cout << f(f,0);
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
