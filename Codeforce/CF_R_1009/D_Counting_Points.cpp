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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int>centers(n);
    for(auto &c: centers) cin >> c;

    vector<int> raddi(n);
    for(auto &r: raddi) cin >> r;

    map<int,int> X; 
    auto getCnt = [&](long long x, long long radius, long long center)->long long {
        auto isOk = [&](long long y)->bool {
            return (y*y + (x-center) * (x-center)) <= 1LL * radius * radius;
        };

        int l = 0, r = radius+1;
        while(r-l>1) {
            int mid = l + (r-l) / 2;
            if(isOk(mid))
                l = mid;
            else 
                r = mid;
        }
        return 2*l+1;
    };

    for(int i = 0; i < n; i++) {
        for(int x = centers[i]-raddi[i]; x <= centers[i]+raddi[i]; x++) {
            if(X.find(x) == X.end()) {
                X[x] = getCnt(x,raddi[i],centers[i]);
            }
            else {
                int currCnt = getCnt(x,raddi[i],centers[i]);
                if(currCnt >= X[x]) {
                    X[x] = currCnt;
                }
            }
        }
    }



    long long cnt = 0;
    for(auto &[x,pts]: X) {
        cnt += pts;
    }
    cout << cnt << "\n";
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
