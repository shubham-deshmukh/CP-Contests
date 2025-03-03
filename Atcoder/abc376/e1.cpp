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

#define int int64_t
const int inf  = 1e18;

using pii = pair<int,int>;
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j) {
        return B[i] < B[j];
    });

    set<pii> rem, curr;
    int remSum = 0, currSum = 0;
    for(int j = 0; j < n; j++) {
        int i = order[j];
        if(j < k) {
            curr.insert(pii{B[i],i});
            currSum += B[i];
        }
        else {
            rem.insert(pii{B[i],i});
            remSum += B[i];
        }
    }

    sort(order.begin(), order.end(), [&](int i, int j) {
        return A[i] > A[j];
    });

    auto erase = [&](const int &i)->void {
        // present in curr set 
        auto it = curr.find(pii{B[i],i});
        if(it != curr.end()) {
            currSum -= B[i];
            curr.erase(it);
        }
        else {
            it = rem.find(pii{B[i],i});
            remSum -= B[i];
            assert(it != rem.end());
            rem.erase(it);
        }
    };

    auto fix = [&]()->void {
        int currSize = curr.size();
        if(currSize == k-1)
            return;
        
        // if curr size is k 
        if(currSize > k-1) {
            int i = curr.rbegin()->second;

            curr.erase(pii{B[i],i});
            currSum -= B[i];

            rem.insert(pii{B[i],i});
            remSum += B[i]; 
            
        }

        if(currSize < k-1 and !rem.empty()) {
            int i = rem.begin()->second;

            rem.erase(pii{B[i],i});
            remSum -= B[i];

            curr.insert(pii{B[i],i});
            currSum += B[i];
        }

    };

    int minVal = inf;
    for(int j = 0; j < n; j++) {
        // curr element is max then find out 
        // min k-1 sum from remaining elements
        int i = order[j];
        int sum = B[i];

        erase(i);
        fix();
        
        if(curr.size() != k-1)
            break;

        
        sum += currSum;
        minVal = min(minVal, A[i]*sum); 
    }  

    cout << minVal;
    
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
