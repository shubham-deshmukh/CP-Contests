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

    T op(T a, T b) {
        return (a + b);
    }

    T e() {
        return 0;
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,0);
        
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

    void update(int v, int lb, int rb, int pos, T new_value) {
        if(lb == rb) {
            tree[v] = new_value; // update the value
        }
        else { // recomputation
            int mid = (lb + rb) / 2;

            // 0-based indexing
            int lv = 2*v+1;
            int rv = 2*v+2;

            if(pos <= mid) { // element lies in the left segment
                update(lv, lb, mid, pos, new_value);
            }
            else { // element lies in the right segment
                update(rv, mid+1, rb, pos, new_value);
            }

            tree[v] = op(tree[lv],tree[rv]);
        }
    }

    T query(int v, int lb, int rb, int l, int r) {

        if(r < lb || rb < l) 
            return e();
  
        if(lb >= l && rb <= r) {
            return tree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        return op(query(lv,lb,mid,l,r),query(rv,mid+1,rb,l,r));
    }

    // pos is 0-based indexing
    void update(int pos, T new_value) {
        update(0,0,n-1,pos,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    T query(int l, int r) { 
        return query(0,0,n-1,l,r-1);
    }

    int find(int x, int lx, int rx, int k) {
        if(lx == rx) { // leaf
            return lx;
        }

        int mid = (lx + rx) / 2;
        int left = 2*x + 1;
        int right = 2*x + 2;

        int lCnt = tree[left];

        if(k < lCnt) {
            return find(left, lx, mid, k);
        }
        else {
            return find(right, mid+1, rx, k - lCnt);
        }
    }
    int find(int k) {
        return find(0,0,n-1,k);
    }

};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    SegmentTree<int> st(n, A);

    while(m--) {
        int type, x;
        cin >> type >> x;

        if(type == 1) { // update the xth pos
            A[x] = 1 - A[x];
            st.update(x, A[x]);
        }
        else if(type == 2) { // Find the index of xth one
            cout << st.find(x) << endl;
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