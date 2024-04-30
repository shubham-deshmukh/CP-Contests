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
    long long seg = 0, pref = 0, suff = 0, sum = 0, len = 1;
};

template<typename modifyType,typename queryType>
struct SegmentTree {
    int size;
    vector<modifyType> tree;
    vector<queryType> queryTree, arr;
    int n;

    // update identity element
    queryType IDENTITY_ELEMENT() {
        return {0LL,0LL,0LL,0LL,0LL};
    }

    // choose proper no_op element
    modifyType NO_OPERATION() {
        return LLONG_MAX;
    }

    // operation between modifyTypes
    modifyType modify_op(modifyType a, modifyType b) {
        return b;
    }

    // operation between queryTypes
    queryType query_op(queryType a, queryType b) {
        queryType c;
        c.seg = max({a.seg, b.seg, a.suff + b.pref});
        c.pref = max(a.pref, a.sum + b.pref);
        c.suff = max(b.suff, b.sum + a.suff);
        c.sum = a.sum + b.sum;
        c.len = a.len + b.len;
        return c;
    }

    // operation between a queryType and a modifyType
    queryType composite(queryType a, modifyType b) {
        a.sum = b * a.len;
        a.seg = a.pref = a.suff = 0;
        if(b > 0) {
            a.seg = a.pref = a.suff = b * a.len;
        }
        return a;
    }



    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v] == NO_OPERATION()) // leaf or no propagation is required
            return;
        
        tree[2*v+1] = modify_op(tree[2*v+1], tree[v]); 
        tree[2*v+2] = modify_op(tree[2*v+2], tree[v]);

        queryTree[2*v+1] = composite(queryTree[2*v+1], tree[v]); 
        queryTree[2*v+2] = composite(queryTree[2*v+2], tree[v]); 

        tree[v] = NO_OPERATION();
    }

    // type of arr must be of queryType
    SegmentTree(int n, vector<queryType> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        // update as per requirement
        tree.assign(size,NO_OPERATION());
        queryTree.assign(size,IDENTITY_ELEMENT());

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            queryTree[v] = arr[lb];
            tree[v] = NO_OPERATION();
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid, rb);

            queryTree[v] = query_op(queryTree[lv], queryTree[rv]);
            tree[v] = modify_op(tree[lv],tree[rv]);
        }
    }

    void modify(int v, int lb, int rb, int l, int r, modifyType new_value) {
        propagate(v, lb, rb);

        if(r <= lb || rb <= l) 
            return;

        if(lb >= l && rb <= r) {
            tree[v] = modify_op(tree[v], new_value);
            queryTree[v] = composite(queryTree[v], new_value);
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

};
// Remove length parameter
void solve() {
    int n, m;
    cin >> n >> m;

    vector<node> A(n, node{});
    SegmentTree<long long,node> st(n, A);

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
