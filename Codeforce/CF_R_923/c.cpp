#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(n), B(m);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    A.resize(unique(A.begin(), A.end())-A.begin());
    B.resize(unique(B.begin(), B.end())-B.begin());

    set<int> sa, sb;
    for(auto a: A) 
        sa.insert(a);
    
    for(auto b: B)
        sb.insert(b);
    


    n = A.size();
    m = B.size();

    int i = 0, j = 0;

    int a_cnt = 0, b_cnt = 0, comm = 0;

    for(int t = 0; t < k; t++) {
        if(!sa.empty() && !sb.empty() && *sa.begin() == t+1 && *sa.begin() == *sb.begin()) {
            comm++;
            sa.erase(sa.begin());
            sb.erase(sb.begin());
        }
        else if(!sa.empty() && *sa.begin() == t+1) {
            a_cnt++;
            sa.erase(sa.begin());
        }
        else if(!sb.empty() && *sb.begin() == t+1) {
            b_cnt++;
            sb.erase(sb.begin());
        }
    }


    int req = a_cnt + b_cnt + comm;

    if(a_cnt > k/2 || b_cnt > k/2) {
        cout << "NO";
        return;
    }
    if(req == k) 
        cout << "YES";
    else 
        cout << "NO";

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
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
