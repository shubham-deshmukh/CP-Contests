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
    long long modify, query;
};

template<typename T>
struct SegmentTree {
    int size;
    vector<T> tree, arr;
    // vector<T> queryTree;
    int n;
    using ll = long long;

    ll modify_op(ll a, ll b, ll len) {
        return b*len;
    }

    ll query_op(ll a, ll b) {
        return (a+b);
    }

    T e() {
        return {0LL,0LL};
    }

    ll NOOP() {
        return LLONG_MIN;
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v].modify == NOOP()) // leaf
            return;
        
        int mid = (lv + rv) / 2;
        tree[2*v+1].modify = modify_op(tree[2*v+1].modify, tree[v].modify, 1); 
        tree[2*v+2].modify = modify_op(tree[2*v+2].modify, tree[v].modify, 1);

        tree[2*v+1].query = modify_op(tree[2*v+1].query, tree[v].modify, mid - lv); 
        tree[2*v+2].query = modify_op(tree[2*v+2].query, tree[v].modify, rv - mid); 

        // queryTree[2*v+1] = modify_op(queryTree[2*v+1], tree[v], mid - lv); 
        // queryTree[2*v+2] = modify_op(queryTree[2*v+2], tree[v], rv - mid); 


        tree[v].modify = NOOP();
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,{});
        // queryTree.assign(size,{});

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            // queryTree[v] = arr[lb];
            tree[v] = arr[lb];
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid, rb);

            // queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
            tree[v].query = query_op(tree[lv].query, tree[rv].query);            
            tree[v].modify = modify_op(tree[lv].modify,tree[rv].modify,1);
        }
    }

    void modify(int v, int lb, int rb, int l, int r, T new_value) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v].modify = modify_op(tree[v].modify, new_value.modify, 1);
            // queryTree[v] = modify_op(queryTree[v], new_value, rb-lb);
            tree[v].query = modify_op(tree[v].query, new_value.modify, rb-lb);            
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;
        
        modify(lv, lb, mid,l,r, new_value);
        modify(rv,mid,rb,l,r, new_value);

        // queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
        tree[v].query = query_op(tree[lv].query, tree[rv].query);
    }

    T query(int v, int lb, int rb, int l, int r) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return e();
  
        if(lb >= l && rb <= r) {
            return tree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        T s1, s2;
        s1 = query(lv,lb,mid,l,r);
        s2 = query(rv,mid,rb,l,r);
        
        T res;
        res.query = query_op(s1.query,s2.query);
        return res;
    }

    // [l,r)
    void modify(int l, int r, T new_value) {
        modify(0,0,n,l, r,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    T query(int l, int r) { 
        return query(0,0,n,l,r);
    }

};

void solve() {
    // Instead of creating two seperate tree: tree, queryTree
    // single tree is used with node as element
    int n, m;
    cin >> n >> m;

    vector<node> A(n, {0,0});
    SegmentTree<node> st(n, A);

    while(m--) {
        int type;
        cin >> type;

        if(type == 1) { // range update
            int l, r, v;
            cin >> l >> r >> v;
            st.modify(l,r,{v,0});
        }
        else if(type == 2) { // range query
            int l, r;
            cin >> l >> r;
            cout << st.query(l,r).query;
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
    
    long long t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
        
        // if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
