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

const int MAX_N = 1e5;
const int mod = 1e9+7;

struct node {
    long long seg = 0, pref = 0, suff = 0, sum = 0;
};

template<typename T>
struct SegmentTree {
    int size;
    vector<long long> tree, arr;
    vector<node> queryTree;
    int n;

    using ll  = long long;

    ll modify_op(ll a, ll b, ll len) {
        return b;
    }

    node modify_op(node a, ll b, ll len) {
        a.sum = b * len;
        a.seg = a.pref = a.suff = 0;
        if(b > 0) {
            a.seg = a.pref = a.suff = b * len;
        }
        return a;
    }

    node query_op(node a, node b) {
        node c;
        c.seg = max({a.seg, b.seg, a.suff + b.pref});
        c.pref = max(a.pref, a.sum + b.pref);
        c.suff = max(b.suff, b.sum + a.suff);
        c.sum = a.sum + b.sum;
        return c;
    }

    node e() {
        return {0LL,0LL,0LL,0LL};
    }

    ll NOOP() {
        return LLONG_MAX;
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v] == NOOP()) // leaf
            return;
        
        int mid = (lv + rv) / 2;
        tree[2*v+1] = modify_op(tree[2*v+1], tree[v], 1); 
        tree[2*v+2] = modify_op(tree[2*v+2], tree[v], 1);

        queryTree[2*v+1] = modify_op(queryTree[2*v+1], tree[v], mid - lv); 
        queryTree[2*v+2] = modify_op(queryTree[2*v+2], tree[v], rv - mid); 

        tree[v] = NOOP();
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,{});
        queryTree.assign(size,{});

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            queryTree[v] = {arr[lb],arr[lb],arr[lb],arr[lb]};
            tree[v] = arr[lb];
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid, rb);

            queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
            tree[v] = modify_op(tree[lv],tree[rv],1);
        }
    }

    void modify(int v, int lb, int rb, int l, int r, ll new_value) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v] = modify_op(tree[v], new_value, 1);
            queryTree[v] = modify_op(queryTree[v], new_value, rb-lb);
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;
        
        modify(lv, lb, mid,l,r, new_value);
        modify(rv,mid,rb,l,r, new_value);

        queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
        // queryTree[v] = modify_op(queryTree[v],tree[v], rb-lb+1);
    }

    node query(int v, int lb, int rb, int l, int r) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return e();
  
        if(lb >= l && rb <= r) {
            return queryTree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        node s1 = query(lv,lb,mid,l,r);
        node s2 = query(rv,mid,rb,l,r);
        
        node res = query_op(s1,s2);
        // res = modify_op(res,tree[v],min(rb,r)-max(lb,l)+1);
        return res;
    }

    // [l,r)
    void modify(int l, int r, ll new_value) {
        modify(0,0,n,l, r,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    node query(int l, int r) { 
        return query(0,0,n,l,r);
    }

};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> A(n, 0);
    SegmentTree<long long> st(n, A);

    while(m--) {
        int l, r, v;
        cin >> l >> r >> v;
        st.modify(l,r,v);
        cout << st.query(0,n).seg;
        if(m) cout << endl;
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
