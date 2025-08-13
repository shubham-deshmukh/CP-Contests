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
using pii = pair<int,int>;
struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); 
    }
};
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    auto getSlop = [&](int i, int j)->pii {
        // (y2-y1) / (x2-x1)
        int num = points[j][1] - points[i][1];
        int den = points[j][0] - points[i][0];

        // parallel to x-axis : slop = 0 => num = 0
        if(num == 0) return pii{0,1};

        // parallel to y-axis : slop = inf => den = 0
        if(den == 0) return pii{1,0};
        // 2,4 ==> 1/2
        int g = gcd(num,den);
        num /= g;
        den /= g;

        if(den < 0) {
            den = -den;
            num = -num;
        }

        return pii{num,den};
    };

    auto getMid = [&](int i, int j)->pii {
        int x_2 = points[j][0] + points[i][0];
        int y_2 = points[j][1] + points[i][1];
        
        return pii{x_2,y_2};
    };

    long long ans = 0;
    unordered_map<pii,int,PairHash> trap, pgram;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pii slope = getSlop(i,j);
            pii mid = getMid(i,j);

            ans += trap[slope];
            ans -= pgram[mid];

            trap[slope] += 1;
            pgram[mid] += 1;
        }
    }
    cout << ans;
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
