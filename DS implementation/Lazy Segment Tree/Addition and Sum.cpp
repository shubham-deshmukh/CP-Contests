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
const long long mod = 1e9+7;

template<typename T>
struct SegmentTree {
    int size;
    vector<T> tree, arr;
    vector<T> queryTree;
    int n;

    T modify_op(T a, T b, T len) {
        return (a+b*len);
    }

    T query_op(T a, T b) {
        return (a+b);
    }

    T e() {
        return 0;
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,{}); // modify the value (0) in case custom data structure is used like struct etc.
        queryTree.assign(size,{});

        build(0,0,n-1);
    }

    void build(int v, int lb, int rb) {
        if(lb == rb) {
            queryTree[v] = arr[lb];
            tree[v] = arr[lb];
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid+1, rb);

            queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
            tree[v] = modify_op(tree[lv],tree[rv],rb-lb+1);
        }
    }

    void modify(int v, int lb, int rb, int l, int r, T new_value) {
        if(r < lb || rb < l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v] = modify_op(tree[v], new_value,1);
            queryTree[v] = modify_op(queryTree[v], new_value,rb-lb+1);
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;
        
        modify(lv, lb, mid,l,r, new_value);
        modify(rv,mid+1,rb,l,r, new_value);

        queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
        queryTree[v] = modify_op(queryTree[v],tree[v],rb-lb+1);
    }

    T query(int v, int lb, int rb, int l, int r) {

        if(r < lb || rb < l) 
            return e();
  
        if(lb >= l && rb <= r) {
            return queryTree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        T s1 = query(lv,lb,mid,l,r);
        T s2 = query(rv,mid+1,rb,l,r);
        
        T res = query_op(s1,s2);
        res = modify_op(res,tree[v],min(rb,r)-max(lb,l)+1);
        return res;
    }

    // [l,r)
    void modify(int l, int r, T new_value) {
        modify(0,0,n-1,l, r-1,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    T query(int l, int r) { 
        return query(0,0,n-1,l,r-1);
    }

};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> A(n, 0);
    SegmentTree<long long> st(n, A);

    while(m--) {
        int type;
        cin >> type;

        if(type == 1) { // range modify
            int l, r, v;
            cin >> l >> r >> v;
            st.modify(l,r,v);
        }
        else if(type == 2) { // range query
            int l, r;
            cin >> l >> r;
            cout << st.query(l,r);
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
