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
        // update the value (0) in case custom data structure is used like struct etc.
        tree.assign(size,{});
        
        // comment the build procedure if not required
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

};
using t4 = array<int,4>;
using t2 = array<int,2>;
// val, isStart/isEnd, type, pos in seq
void solve() {
    int n, m;
    cin >> n >> m;

    vector<t4> A;
    vector<t2> D;
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        A.push_back(t4{s,0,0,i}); 
        A.push_back(t4{e,1,0,i});
        D.push_back(t2{s,e});
    }

    int q;
    cin >> q;

    vector<t2> C;
    for(int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;

        A.push_back(t4{s,0,1,i});
        A.push_back(t4{e,1,1,i});
        C.push_back(t2{s,e});
    }

    sort(A.begin(), A.end());
    vector<int> B(2*n+1);
    
    SegmentTree<int> st(2*n+1,B);
    vector<int> ans(q);
    for(auto [x,f,t,idx]: A) {
        if(t == 0) { // segments
            if(f == 0) { // start
                st.update(x,1);
            }
            else { // end
                int s = D[idx][0];
                int e = D[idx][1];
                st.update(s,-1);
                st.update(e,+1);
            }
        }
        else { // query segments
            if(f == 0) {

            }
            else { // end
                int s = C[idx][0];
                int e = C[idx][1];
                int seg = st.query(s,e+1);
                ans[idx] = seg;
            }
        }
    }

    for(auto &a: ans) cout << a << endl;

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
