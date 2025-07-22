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
constexpr int inf = int(2e18+1);
void solve() {
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    map<int,set<int>> xMap, yMap;

    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        xMap[X[i]].insert(Y[i]);
        yMap[Y[i]].insert(X[i]);
    }

    if(n == 1) {
        cout << 1 << "\n";
        return;
    }

    using t3 = array<int,3>;
    auto getArea = [&]()->t3 {
        int xMin = xMap.begin()->first;
        int xMax = xMap.rbegin()->first;
    
        int yMin = yMap.begin()->first;
        int yMax = yMap.rbegin()->first;
    
        int l = xMax - xMin + 1;
        int h = yMax - yMin + 1;
    
        int ans = l * h;
        if(ans == n-1) {
            ans = min(l,h) * (max(l,h)+1);
        }
        return t3{ans,l,h};
    };

    int ans = getArea()[0];
    
    auto erasePointAndGetArea = [&](int x, int y)->int {
        assert(x >= 0 and y >= 0);

        int area = inf;
        xMap[x].erase(y);
        if(xMap[x].empty()) xMap.erase(x);
    
        yMap[y].erase(x);
        if(yMap[y].empty()) yMap.erase(y);
    
        area = getArea()[0];

        xMap[x].insert(y);
        yMap[y].insert(x);

        return area;
    };

    for(int i = 0; i < n; i++) {
        ans = min(ans,erasePointAndGetArea(X[i],Y[i]));
    }
    cout << ans << "\n";
}   
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
