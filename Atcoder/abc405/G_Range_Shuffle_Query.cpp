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

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

#define int int64_t
constexpr int mod = 998244353;
using pii = pair<int,int>;
vector<int> inv;
vector<int> fact, inv_fact;

void solve() {
    int n, Q;
    cin >> n >> Q;

    vector<int> A(n);
    for(auto &a: A) cin >> a, a -= 1;

    vector<int> start(Q), end(Q), X(Q);
    for(int q = 0; q < Q; q++) {
        int l, r, x;
        cin >> l >> r >> x;

        l -= 1; r -= 1, x -= 1;
        start[q] = l, end[q] = r, X[q] = x;
    }

    int block_size = (int)sqrt(n + .0) + 1;
    // Mo\'s algorithm
    vector<int> order(Q);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j) {
        int li = start[i] / block_size;
        int lj = start[j] / block_size;

        return pii{li,end[i]} < pii{lj,end[j]};
    });

    vector<int> ans(Q);
    vector<int> freq(n+1);
    vector<int> blockFreq(n/block_size+1);
    vector<int> blockProduct(n/block_size+1,1);

    int currL = 0, currR = -1;

    auto add = [&](int i)->void {
        freq[A[i]] += 1;
        blockFreq[A[i]/block_size] += 1;
        (blockProduct[A[i]/block_size] *= inv[freq[A[i]]]) %= mod;
    };

    auto remove = [&](int i)->void {
        blockFreq[A[i]/block_size] -= 1;        
        (blockProduct[A[i]/block_size] *= freq[A[i]]) %= mod;
        freq[A[i]] -= 1;
    };

    auto getAnswer = [&](int x)->int {
        int blockIdx = x / block_size;
        int rem = x % block_size;
        
        int tot = 0, product = 1;
        for(int idx = 0; idx < blockIdx; idx++) {
            tot += blockFreq[idx];
            (product *= blockProduct[idx]%mod) %= mod;
        }

        for(int i = 0; i < rem; i++) {
            tot += freq[blockIdx * block_size + i];
            (product *= inv_fact[freq[blockIdx * block_size + i]]%mod) %= mod;
            product %= mod;
        }
        int ans = (fact[tot%mod] * product)%mod;
        return ans;
    };
    
    for(auto i: order) {
        int l = start[i];
        int r = end[i];
        // left expand
        while(currL > l) {
            currL -= 1;
            add(currL);
        }

        // right expand
        while(currR < r) {
            currR += 1;
            add(currR);
        }

        // left shrink
        while(currL < l) {
            remove(currL);
            currL += 1;
        }

        // right shrink
        while(currR > r) {
            remove(currR);
            currR -= 1;
        }

        ans[i] = getAnswer(X[i]);
    }

    for(auto &a: ans) cout << a << "\n";
}

int binpow(int a, int b, int mod) {
    int rst = 1;
    a %= mod;

    while(b) {
        if(b&1) {
            rst = (rst * a) % mod;
        }

        a = (a * a) % mod;
        b >>= 1; 
    }

    return rst;
}

void pre() {
    int N = 3e5;
    fact.assign(N,0);
    inv.assign(N,0);
    inv_fact.assign(N,0);

    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    for(int i = 0; i < N; i++) {
        inv_fact[i] = binpow(fact[i],mod-2,mod);
    }
    
    for(int i = 1; i < N; i++) {
        inv[i] = binpow(i,mod-2,mod);
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
    pre();
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
