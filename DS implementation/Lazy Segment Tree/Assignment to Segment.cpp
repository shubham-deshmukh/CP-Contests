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

template<typename T>
struct SegmentTree {
    int size;
    vector<T> tree, arr;
    int n;
    const int NO_OPERATION = INT_MAX;

    T op(T a, T b) {
        if(b == NO_OPERATION) return a;
        return b;
    }

    T e() {
        return 0;
    }

    void propogate(int x, int lx, int rx) {
        if(lx != rx) { // x is not the leaf
            tree[2*x+1] = op(tree[2*x+1], tree[x]);
            tree[2*x+2] = op(tree[2*x+2], tree[x]);
            tree[x] = NO_OPERATION;
        }
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,0); // update the value (0) in case custom data structure is used like struct etc.
        
        build(0,0,n-1);
    }

    void build(int v, int lb, int rb) {
        if(lb == rb) {
            tree[v] = arr[lb];
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid+1, rb);

            tree[v] = op(tree[lv], tree[rv]);
        }
    }

    void set(int v, int lb, int rb, int l, int r, T new_value) {
        if(r < lb || rb < l) 
            return;
  
        propogate(v,lb,rb);

        if(lb >= l && rb <= r) {
            tree[v] = op(tree[v], new_value); 
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        set(lv,lb,mid,l,r, new_value);
        set(rv,mid+1,rb,l,r, new_value);
    }

    T get(int v, int lb, int rb, int pos) {
        if(lb == rb) {
            return tree[v];
        }

        propogate(v, lb, rb);

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        T res;
        if(pos <= mid) { // element lies in the left segment
            res = get(lv, lb, mid, pos);
        }
        else { // element lies in the right segment
            res = get(rv, mid+1, rb, pos);
        }
        
        return op(res, tree[v]);
        
    }

    // l included and r is excluded i.e. [l,r) 
    void set(int l, int r, T new_value) {
        set(0,0,n-1,l,r-1,new_value);
    }
    // pos is 0-based indexing
    T get(int pos) { 
        return get(0,0,n-1,pos);
    }

};



void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n, 0);
    SegmentTree<int> st(n, A);

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) { // set (assign) the value over the segment [l,r)
            int l, r, v;
            cin >> l >> r >> v;
            st.set(l,r,v);
        }
        else if(type == 2) { // get the value at position pos
            int pos;
            cin >> pos;
            cout << st.get(pos);
            if(q) cout << endl;
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
    
    long long t = 1;
    while(t--) {
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
