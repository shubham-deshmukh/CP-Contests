#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(i = start; start < end ? i < end : i > end; start < end ? i += 1 : i -= 1)
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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

struct People {
    int x,v;
};

#define int int64_t
// #define double long double
const double eps = 1e-6;

void solve() {
    int N;
    cin >> N;

    vector<People> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i].x >> A[i].v;

    double left = -1; // invalid
    double right = 1; // valid

    auto isValid = [&](const double time)->bool {
        double min_end = A[0].x + time * A[0].v;
        double max_start = A[0].x - time * A[0].v;

        for(auto &a: A) {
            min_end = min(min_end, a.x + time * a.v);
            max_start = max(max_start, a.x - time * a.v);
        }
        return (max_start <= min_end);
    };

    int mx = 1;
    while(!isValid( (double)mx )) { // find out valid time for right
        mx <<= 1;
    }
    right = mx;

    while(right - left > eps) {

        double mid = left + (right - left) / 2.0;

        if(isValid(mid)) 
            right = mid;
        else 
            left = mid;
    }
    cout << setprecision(20);
    cout << right;



}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
