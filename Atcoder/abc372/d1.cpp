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

struct SegmentTree {
    long long size;
    vector<long long> tree, arr;
    long long n;


    SegmentTree(long long n, vector<long long> &arr) {

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

            // modification 1
            tree[v] = 0;
        }
    }

    void range_update(int v, int lb, int rb, int l, int r, int new_value) {

        if(r < lb || rb < l) 
            return;
            
        if(lb >= l && rb <= r) {
        
            // modification 2
            tree[v] += new_value;
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        range_update(lv,lb,mid,l,r,new_value);
        range_update(rv,mid+1,rb,l,r,new_value);
    }

    long long get_value(int v, int lb, int rb, int pos) {
        if(lb == rb) {
            return tree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        long long res;
        if(pos <= mid) {
            res = get_value(lv, lb, mid, pos);
        }
        else {
            res = get_value(rv, mid+1, rb, pos);
        } 

        // modification 3
        return res + tree[v];

    }

    // [l,r)
    void range_update(int l, int r, int new_value) {
        range_update(0,0,n-1,l,r-1,new_value);
    }

    long long get_value(int pos) {
        return get_value(0,0,n-1,pos);
    }

};


#define int long long
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<int> reach(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() and A[st.top()] <= A[i]) {
            st.pop();
        }

        reach[i] = (st.empty()?0:st.top());
        st.push(i);
    }

    // debug(reach);
    vector<int> B(n);
    SegmentTree seg(n,B);

    for(int i = 0; i < n; i++) {
        if(reach[i] == i)
            continue;

        seg.range_update(reach[i],i,1);
    }

    for(int j = 0; j < n; j++)
        cout << seg.get_value(j) << " ";
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
