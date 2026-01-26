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
    int n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<int> X(n);
    for(auto &x: X) cin >> x;

    vector<int> Y(n);
    for(auto &y: Y) cin >> y;


    map<int,vector<int>> vert;
    for(int i = 0; i < n; i++) vert[X[i]].push_back(Y[i]);

    vert[Bx].push_back(By);

    for(auto &[x,v]: vert) ranges::sort(v);
    unordered_map<int,int> xTime;

    for(auto &[x,v]: vert) {
        xTime[x] = abs(v[0]-v.back());
    }

    int px1 = Ax, px2 = Ax;
    int py1 = Ay, py2 = Ay;

    int d1 = 0, d2 = 0;
    auto getDist = [&](int x1, int y1, int x2, int y2)->int {
        return abs(x2-x1) + abs(y2-y1);
    };

    auto get = [&](int x, int y, int t)->int {
        int dist1 = t + getDist(x,y,px1,py1) + d1;
        int dist2 = t + getDist(x,y,px2,py2) + d2;

        return min(dist1,dist2);
    };

    for(auto &[x, v]: vert) {
        int cd1 = get(x,v.back(),xTime[x]);
        int cd2 = get(x,v[0], xTime[x]);

        px1 = x, px2 = x;
        py1 = v[0], py2 = v.back();

        d1 = cd1;
        d2 = cd2;

    }
    cout << d1 << "\n";

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
