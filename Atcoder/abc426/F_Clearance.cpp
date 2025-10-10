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
using int64 = long long;

namespace type1 {
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
}
int64 op1(int64 a, int64 b) {return (a+b);}
int64 e1() {return 0;}    

template<typename modifyType,typename queryType>
struct SegmentTree {
    int size;
    vector<modifyType> tree;
    vector<queryType> queryTree, arr;
    int n;

    queryType IDENTITY_ELEMENT() {
        return LLONG_MAX;
    }

    modifyType NO_OPERATION() {
    //         return LLONG_MAX;
        return numeric_limits<long long>::lowest(); 
    }

    // operation between modifyTypes
    modifyType modify_op(modifyType a, modifyType b) {
        if(a == NO_OPERATION())
            return b;
        return a+b;
    }

    // operation between queryTypes
    queryType query_op(queryType a, queryType b) {
        return min(a,b);
    }

    // operation between a queryType and a modifyType
    // [lb,rb)
    queryType composite(queryType a, modifyType b, int lv, int rv) {
        return a+b;
    }

    void propagate(int v, int lv, int rv) {
        if(lv+1== rv or tree[v] == NO_OPERATION()) // leaf or no propagation is required
            return;
        
        tree[2*v+1] = modify_op(tree[2*v+1], tree[v]); 
        tree[2*v+2] = modify_op(tree[2*v+2], tree[v]);

        int mid = (lv+rv) / 2;
        queryTree[2*v+1] = composite(queryTree[2*v+1], tree[v], lv, mid); 
        queryTree[2*v+2] = composite(queryTree[2*v+2], tree[v], mid, rv); 

        tree[v] = NO_OPERATION();
    }

    // type of arr must be of queryType
    SegmentTree(int n, vector<queryType> &arr) {

        this->n = n;
        this->arr = arr;       
        
        size = 4*n;
        tree.assign(size,NO_OPERATION());
        queryTree.assign(size,IDENTITY_ELEMENT());

        // comment build procedure if not required
        build(0,0,n);
    }

    void build(int v, int lb, int rb) {
        if(lb+1 == rb) {
            queryTree[v] = arr[lb];
            tree[v] = NO_OPERATION();
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

    queryType search(int v, int lb, int rb, queryType x, queryType l) {
        propagate(v, lb, rb);
        if(rb <= l)
            return -1;

        if(lb+1 == rb) {
            if(queryTree[v] >= x)
                return lb;
            return -1;
        }

        
        int mid = (lb + rb) / 2;
        int idx = -1;
        if(x <= queryTree[2*v+1]) { // 
            idx = search(2*v+1, lb, mid, x, l);
        }

        if(idx == -1)
            idx = search(2*v+2, mid, rb, x, l);
        return idx;
    }
    
    queryType search(queryType x, queryType l) {
        return search(0,0,n,x,l);
    }

    queryType findKth(int v, int lb, int rb, int k) {
        if(lb+1 == rb) {
            if(k == 0)
                return lb;
            
            return -1;
        }

        int idx = -1;
        int mid = (lb+rb) / 2;
        if(k < queryTree[2*v+1])
            idx = findKth(2*v+1,lb,mid,k);
        else 
            idx = findKth(2*v+2,mid,rb,k-queryTree[2*v+1]);
        
        return idx;
    }
    // 0-based indexing
    int findKth(int k) {
        return findKth(0,0,n,k);
    }

    int find_leftmost_negative(int v, int lb, int rb, int l, int r) {
        propagate(v, lb, rb);
        if(r <= lb or rb <= l) return -1; // no overlapping segment

        if(queryTree[v] >= 0) return -1; // no negative value exists in the current segment

        if(lb+1 == rb) return lb;

        int mid = (lb+rb) / 2;
        int idx = find_leftmost_negative(2*v+1,lb,mid,l,r);
        if(idx == -1)
            idx = find_leftmost_negative(2*v+2,mid,rb,l,r);

        return idx;
    }

    // [l,r)
    int find_leftmost_negative(int l, int r) {
        return find_leftmost_negative(0,0,n,l,r);
    }
 
};

void solve() {
    int n;
    cin >> n;

    vector<int64> A(n);
    for(auto &a: A) cin >> a;

    vector<int64> arr1(n,1);
    type1::segtree<int64,op1,e1> stock_count(n, arr1);
    
    SegmentTree<int64,int64> stock(n, A);

    auto get = [&](int lb, int rb)->int {
        // [lb,rb]
        // int l = lb-1;
        // int r = rb+1;

        // auto check = [&](int mid)->bool {
        //     return stock.query(l+1,mid+1) < 0;
        // };

        // while(r-l>1) {
        //     int mid = l + (r-l) / 2;
        //     if(check(mid)) r = mid;
        //     else l = mid;
        // }
        // if(r == rb+1) r = -1;

        // return r;
        return stock.find_leftmost_negative(lb,rb+1);
    };
    

    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++) {
        int l, r, k;
        cin >> l >> r >> k;

        l -= 1, r -= 1;

        int64 answer =  k * stock_count.query(l,r+1);
        // range update
        stock.modify(l,r+1,-k);

        while(stock.query(l,r+1) < 0) {
            // find the leftmost -ve index
            int idx = get(l,r);
            assert(idx != -1);
            answer = answer + stock.query(idx,idx+1);
            stock.modify(idx,idx+1,int64(1e18));

            stock_count.update(idx,0);
        }
        cout << answer << "\n";
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
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
