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

struct state {
    long long start, diff;
    state(int _start, int _diff) : start(_start), diff(_diff) {};
};

template<typename modifyType,typename queryType>
struct SegmentTree {
    int size;
    vector<modifyType> tree;
    vector<queryType> queryTree, arr;
    int n;

    queryType IDENTITY_ELEMENT() {
        return 0;
    }

    // operation between modifyTypes
    modifyType modify_op(modifyType a, modifyType b) {
        return state(a.start+b.start,a.diff+b.diff);
    }

    // operation between queryTypes
    queryType query_op(queryType a, queryType b) {
        return a+b;
    }

    // operation between a queryType and a modifyType
    // [lb,rb)
    queryType composite(queryType a, modifyType b, int lv, int rv) {
        long long len = rv-lv;
        long long tot = (2*b.start + (len-1)*b.diff) * (len) / 2;

        return a+tot;
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or (tree[v].diff == 0 and tree[v].start == 0)) // leaf or no propagation is required
            return;
        
        int mid = (lv+rv) / 2;

        tree[2*v+1] = modify_op(tree[2*v+1], tree[v]); 
        tree[2*v+2] = modify_op(tree[2*v+2], modifyType(tree[v].start + (mid-lv) * tree[v].diff, tree[v].diff));

        // 4 5 6 7
        queryTree[2*v+1] = composite(queryTree[2*v+1], tree[v], lv, mid); 
        queryTree[2*v+2] = composite(queryTree[2*v+2], modifyType(tree[v].start + (mid-lv) * tree[v].diff, tree[v].diff), mid, rv); 

        tree[v] = modifyType(0,0);
    }

    // type of arr must be of queryType
    SegmentTree(int n, vector<queryType> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,modifyType(0,0));
        queryTree.assign(size,IDENTITY_ELEMENT());

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            queryTree[v] = arr[lb];
            tree[v] = modifyType(0,0);
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
        modify(rv,mid,rb,l,r, modifyType(mid-l+1,1));

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

};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> A(n);
    for(auto &a: A) cin >> a;

    SegmentTree<state, long long> st(n, A);

    while(q--) {
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        if(type == 1) { // update
            st.modify(a,b+1,state(1,1));
        }
        else if(type == 2) { // query
            cout << st.query(a,b+1) << "\n";
        }
    }
}
signed main() {
    // your code goes here
    fast;
    solve();
    
    return 0;
}
