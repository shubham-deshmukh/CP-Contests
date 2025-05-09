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
    int q;
    cin >> q;

    int tot = 0, sum = 0, revSum = 0;
    deque<int> dq, revDq;
    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) { // cyclic shift
            int currSize = (int)dq.size();
            int bk = dq.back();
            dq.pop_back();
            dq.push_front(bk);

            sum -= bk * currSize;
            sum += tot;

            int front = revDq.front();
            revDq.pop_front();
            revDq.push_back(front);

            revSum -= tot;
            revSum += currSize * front;
        }
        else if(ch == 2) { // rev
            swap(dq,revDq);
            swap(sum,revSum);
        }
        else if(ch == 3) { // append
            int k;
            cin >> k;

            tot += k;

            int currSize = (int)dq.size();

            dq.push_back(k);
            revDq.push_front(k);


            sum += (currSize + 1) * k;
            revSum += tot;
        }
        cout << sum << endl;
    }
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
