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
const long long SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

#define int int64_t
using pii = pair<int,int>;
constexpr int inf = 2e18;

int rand(int l,int r) {
    return uniform_int_distribution<long long>(l,r)(rng);
}
pair<int,int> get(int n) {
    int i = rand(1,n);
    int j = i;
    while(j == i) {
        j = rand(1,n);
    }
    return pair<int,int>{i,j};
}

void solve() {
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];

    for(int q = 0; q < 50; q++) {
        auto [i,j] = get(n);
        i -= 1, j -= 1;

        int a = Y[i]-Y[j];
        int b = -(X[i]-X[j]);
        int c = -(a*X[i]+b*Y[i]);
        int cnt = 0;
        for(int k = 0; k < n; k++) {
            // ax+by+c = 0;
            cnt += (a*X[k]+b*Y[k]+c == 0);
        }

        if(2*cnt > n) { // Found
            cout << "Yes\n";
            cout << a << " " << b << " " <<  c;
            return;
        }
    }
    cout << "No\n";
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
