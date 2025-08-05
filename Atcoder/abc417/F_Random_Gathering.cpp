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
using ll = long long;
constexpr ll mod = 998244353;
template<typename modifyType,typename queryType>
struct SegmentTree {
    int size;
    vector<modifyType> tree;
    vector<queryType> queryTree, arr;
    int n;

    queryType IDENTITY_ELEMENT() {
        return 0;
    }

    modifyType NO_OPERATION() {
    //         return LLONG_MAX;
        return numeric_limits<long long>::lowest(); 
    }

    // operation between modifyTypes
    modifyType modify_op(modifyType a, modifyType b) {
        if(a == NO_OPERATION())
            return b;
        return b;
    }

    // operation between queryTypes
    queryType query_op(queryType a, queryType b) {
        return (a+b)%mod;
    }

    // operation between a queryType and a modifyType
    // [lb,rb)
    queryType composite(queryType a, modifyType b, int lv, int rv) {
        return (b * (rv-lv))%mod;
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v] == NO_OPERATION()) // leaf or no propagation is required
            return;
        
        tree[2*v+1] = modify_op(tree[2*v+1], tree[v]); 
        tree[2*v+2] = modify_op(tree[2*v+2], tree[v]);

        int mid = (lv+rv) / 2;
        queryTree[2*v+1] = composite(queryTree[2*v+1], tree[v], lv, mid); 
        queryTree[2*v+2] = composite(queryTree[2*v+2], tree[v], mid, rv); 

        tree[v] = NO_OPERATION();
    }

    // type of arr must be of queryType
    SegmentTree(int n, vector<queryType> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,NO_OPERATION());
        queryTree.assign(size,IDENTITY_ELEMENT());

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            queryTree[v] = arr[lb];
            tree[v] = NO_OPERATION();
            return;
        }
        
        int mid = (lb + rb) / 2;
            
        // 0-based indexing
        int lv = 2*v+1; // left child index
        int rv = 2*v+2; // right child index

        build(lv, lb, mid);
        build(rv, mid, rb);

        queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
        tree[v] = modify_op(tree[lv],tree[rv]);
    }

    void modify(int v, int lb, int rb, int l, int r, modifyType new_value) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v] = modify_op(tree[v], new_value);
            queryTree[v] = composite(queryTree[v], new_value, lb, rb);
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;
        
        modify(lv, lb, mid,l,r, new_value);
        modify(rv,mid,rb,l,r, new_value);

        queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
    }


    queryType query(int v, int lb, int rb, int l, int r) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return IDENTITY_ELEMENT();
  
        if(lb >= l && rb <= r) {
            return queryTree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        queryType s1 = query(lv,lb,mid,l,r);
        queryType s2 = query(rv,mid,rb,l,r);
        
        queryType res = query_op(s1,s2);
        return res;
    }

    // [l,r)
    void modify(int l, int r, modifyType new_value) {
        modify(0,0,n,l, r,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    queryType query(int l, int r) { 
        return query(0,0,n,l,r);
    }

    queryType search(int v, int lb, int rb, queryType x, queryType l) {
        propagate(v, lb, rb);
        if(rb <= l)
            return -1;

        if(lb+1 == rb) {
            if(queryTree[v] >= x)
                return lb;
            return -1;
        }

        
        int mid = (lb + rb) / 2;
        int idx = -1;
        if(x <= queryTree[2*v+1]) { // 
            idx = search(2*v+1, lb, mid, x, l);
        }

        if(idx == -1)
            idx = search(2*v+2, mid, rb, x, l);
        return idx;
    }
    
    queryType search(queryType x, queryType l) {
        return search(0,0,n,x,l);
    }

    queryType findKth(int v, int lb, int rb, int k) {
        if(lb+1 == rb) {
            if(k == 0)
                return lb;
            
            return -1;
        }

        int idx = -1;
        int mid = (lb+rb) / 2;
        if(k < queryTree[2*v+1])
            idx = findKth(2*v+1,lb,mid,k);
        else 
            idx = findKth(2*v+2,mid,rb,k-queryTree[2*v+1]);
        
        return idx;
    }
    // 0-based indexing
    int findKth(int k) {
        return findKth(0,0,n,k);
    }
 
};

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n, Q;
    cin >> n >> Q;

    vector<ll> A(n);
    for(auto &a: A) cin >> a;

    SegmentTree<ll,ll> st(n, A);
    for(int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;

        l -= 1;
        // E(x) : sum[l,r-1] / len
        int len = r-l;
        ll val = st.query(l,r)%mod;
        val = (val * binpow(len,mod-2,mod)) % mod;
        st.modify(l,r,val);
    }
    for(int i = 0; i < n; i++) cout << st.query(i,i+1) << " ";
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
