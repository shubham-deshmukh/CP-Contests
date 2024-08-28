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
void bf() {
    // Grundy values
    vector<int> nim(101);

    auto getNim = [&](vector<int> &states)-> int {
        if(states.empty()) // unable to make a move
            return 0;
        
        set<int> s;
        for(auto x: states)
            s.insert(x);
        
        int j = 0;
        while(s.count(j)) j += 1;
    
        return j;
    };
    for(int i = 1; i <= 100; i++) {
        // find all the number whose gcd(x,i) == 1
        vector<int> states;
        for(int j = 1; j <= i; j++) {
            if(__gcd(j,i)== 1) {
                states.push_back(nim[i-j]);
            }
        }
        nim[i] = getNim(states);
        // debug(i,nim[i]);
    }

    for(int i = 0; i <= 100; i++) {
        if(i%2 == 0) {
            assert(nim[i] == 0);
            continue;
        }
        debug(i, nim[i]);
    }
    
}
const int N = 1e7;
vector<int> lp(N+1);
vector<int> pr;
vector<int> sg(N+1);
void pre() {
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 0;
    int cnt = 0;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) { // i is prime
            cnt += 1;
            lp[i] = i;
            pr.push_back(i);

            if(i > 2) {
                sg[i] = cnt;
            }
        }
        else 
            sg[i] = sg[lp[i]];

        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            sg[i*pr[j]] = sg[i];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }    

    // for(int i = 0; i <= N; i++) {
    //     debug(i, sg[i]);
    // }
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int Xor = 0;
    for(auto a: A) {
        Xor ^= sg[a];
    }

    cout << (Xor?"Alice":"Bob");

}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    // bf();
    pre();
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