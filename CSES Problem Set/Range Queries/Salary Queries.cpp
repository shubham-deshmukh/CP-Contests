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
    long long mn = 0, mx = 0;
};

template<typename T>
struct SegmentTree {
    int size;
    vector<T> tree, arr;
    int n;

    T op(T a, T b) {
        T c;
        c.mn = min(a.mn, b.mn);
        c.mx = max(a.mx, b.mx);
        return c;
    }

    T e() {
        return {LLONG_MAX,LLONG_MIN};
    }

    SegmentTree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,node()); // update the value (0) in case custom data structure is used like struct etc.
        
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
    long long count(int v, int lb, int rb, long long a, long long b) {
        if(tree[v].mx < a or tree[v].mn > b)
            return 0;
        
        if(tree[v].mn >= a and tree[v].mx <= b)
            return rb-lb+1;
        
        int mid = (lb+rb) / 2;
        long long s1 = count(2*v+1, lb, mid, a, b);
        long long s2 = count(2*v+2,mid+1, rb, a, b);

        return s1 + s2;
    }
    long long count(long long a, long long b) {
        return count(0,0,n-1,a,b);
    }
};

void solve() {
    // Wrong solution
    // Think and solve using segment tree only
    int n, m; // number of employees and queries
    cin >> n >> m;

    vector<long long> salary(n);
    for(auto &si: salary) cin >> si;

    vector<node> A;
    for(auto si: salary) {
        A.push_back({si,si});
    }
    SegmentTree<node> st(n, A);
    while(m--) {
        char type;
        cin >> type;

        if(type == '?') { // count
            long long a, b; // [a,b]
            cin >> a >> b; 
            cout << st.count(a,b);
            if(m) cout << endl;
        }
        else if(type == '!') { // point update
            long long k, x;
            cin >> k >> x;
            k -= 1;
            st.update(k,{x,x});
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
