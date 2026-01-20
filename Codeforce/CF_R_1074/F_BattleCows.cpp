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

#define int int64_t

#if __cplusplus >= 201703L

template <class T, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                  "op must work as T(T, T)");
    static_assert(std::is_convertible_v<decltype(e), std::function<T()>>,
                  "e must work as T()");

#else

template <class T, T (*op)(T, T), T (*e)()> struct segtree {

#endif
    int size;
    vector<T> tree, arr;
    int n;

    segtree(int n, vector<T> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        // update the value (0) in case custom data structure is used like struct etc.
        tree.assign(size,e());
        
        // comment the build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            tree[v] = arr[lb];
            return;
        }
        
        int mid = (lb + rb) / 2;
        
        // 0-based indexing
        int lv = 2*v+1; // left child index
        int rv = 2*v+2; // right child index

        build(lv, lb, mid);
        build(rv, mid, rb);

        tree[v] = op(tree[lv], tree[rv]);
    }

    void update(int v, int lb, int rb, int pos, T new_value) {
        if(lb+1 == rb) {
            tree[v] = new_value; // update the value
            return;
        }
        // recomputation
        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        if(pos < mid) { // element lies in the left segment
            update(lv, lb, mid, pos, new_value);
        }
        else { // element lies in the right segment
            update(rv, mid, rb, pos, new_value);
        }

        tree[v] = op(tree[lv],tree[rv]);
    }

    T query(int v, int lb, int rb, int l, int r) {
        // lb ... rb
                        // l .....r
        if(r <= lb || rb <= l) 
            return e();
  
        if(l <= lb && rb <= r) {
            return tree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        return op(query(lv,lb,mid,l,r),query(rv,mid,rb,l,r));
    }

    // [l,r)
    int search(int v, int lb, int rb, T val) {
        if(lb+1 == rb) {
            if(tree[v] >= val) return lb;
        
            return -1;
        }

        int mid = (lb+rb) / 2;
        int idx = -1;
        if(tree[2*v+1] >= val) idx = search(2*v+1,lb,mid,val);
        else if(tree[2*v+2] >= val) idx = search(2*v+2,mid,rb,val);

        return idx;
    }
    int search(T val) {
        return search(0,0,n,val);
    }
    // pos is 0-based indexing
    void update(int pos, T new_value) {
        update(0,0,n,pos,new_value);
    }
    // l included and r is excluded i.e. [l,r) 
    T query(int l, int r) { 
        return query(0,0,n,l,r);
    }

};
/*
Define S, op and e
S: Data type, op : merge operation, e : Identity element
*/
int op(int a, int b) {return a^b;}
int e() {return int(0);}

void solve() {
    int nn, Q;
    cin >> nn >> Q;

    int n = (1<<nn);

    vector<int> A(n);
    for(auto &a: A) cin >> a;
    segtree<int,op,e> st(n, A);

    for(int q = 0; q < Q; q++) {
        int b, c;
        cin >> b >> c;

        b -= 1;
        int org = A[b];
        A[b] = c;
        st.update(b, c);
        // // prefix xor
        // vector<int> pfx(n+1);
        // for(int i = 1; i <= n; i++) pfx[i] = pfx[i-1] ^ A[i-1];
        // auto get = [&](int l, int r)->int {
        //     l += 1, r += 1;
        //     if(l > r) return 0;

        //     return pfx[r] ^ pfx[l-1];
        // };

        int cnt = 0;
        int l = 0, r = n-1;
        while(r-l >= 1) {
            int mid = (r+l) / 2;
            // [l..mid] [mid+1..r]
            // int left = get(l,mid);
            // int right = get(mid+1,r);
            int left = st.query(l,mid+1);
            int right = st.query(mid+1,r+1);
            if(b <= mid) { // cow lies in left half
                if(left < right) { // right wins
                    cnt += (r-(mid+1)+1);
                }
                r = mid;
            }
            else { // cow lies in right half
                if(left >= right) { // left wins
                    cnt += (mid-l+1);
                }
                l = mid+1;
            }
        }
        cout << cnt << "\n";
        A[b] = org;
        st.update(b, org);
    }
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
