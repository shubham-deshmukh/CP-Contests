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

struct node {
    long long ones = 0, len = 1;
    bool inv = false;
};

template<typename modifyType,typename queryType>
struct SegmentTree {
    int size;
    vector<modifyType> tree, arr;
    int n;

    // operation between modifyTypes
    modifyType modify_op(modifyType a, modifyType b) {
        a.ones = a.len - a.ones;
        a.inv = !a.inv;
        return a;
    }

    modifyType modify_op1(modifyType a, modifyType b) {
        return {
            a.ones + b.ones,
            a.len + b.len,
            a.inv
        };
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v].inv == false) // leaf or no propagation is required
            return;
        
        tree[2*v+1] = modify_op(tree[2*v+1], tree[v]); 
        tree[2*v+2] = modify_op(tree[2*v+2], tree[v]);

        tree[v].inv = false;
    }

    SegmentTree(int n, vector<modifyType> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,modifyType());

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            tree[v] = modifyType();
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid, rb);

            tree[v] = modify_op1(tree[lv],tree[rv]);
        }
    }

    void modify(int v, int lb, int rb, int l, int r, modifyType new_value) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v].ones = tree[v].len - tree[v].ones;
            tree[v].inv = true;
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;
        
        modify(lv, lb, mid,l,r, new_value);
        modify(rv,mid,rb,l,r, new_value);

        tree[v].ones = tree[lv].ones + tree[rv].ones;
    }

    // [l,r)
    void modify(int l, int r, modifyType new_value) {
        modify(0,0,n,l, r,new_value);
    }

    int find(int v, int lb, int rb, int k) {
        propagate(v, lb, rb);
        if(lb+1 == rb) {
            return lb;
        }

        int mid = (lb+rb) / 2;
        int lv = 2*v + 1;
        int rv = 2*v + 2;

        if(tree[lv].ones > k) {
            return find(lv,lb,mid,k);
        }
         
        return find(rv,mid,rb,k-tree[lv].ones);
    }

    int find(int k) {
        return find(0,0,n,k);
    }
};



void solve() {
    int n, m;
    cin >> n >> m;

    vector<node> A(n, node());
    SegmentTree<node, long long> st(n, A);
    while(m--) {
        int type;
        cin >> type;

        if(type == 1) { // range update
            int l, r;
            cin >> l >> r;
            st.modify(l,r,{});
        }
        else if(type == 2) { // find 
            int k;
            cin >> k;
            cout << st.find(k);
            if(m) cout << endl;
        }
    }
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
