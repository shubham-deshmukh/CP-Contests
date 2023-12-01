#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

#define int long long

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

            tree[v] = tree[lv] + tree[rv];
        }
    }

    void update(int v, int lb, int rb, int pos, int new_value) {
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

            tree[v] = tree[lv]+tree[rv];
        }
    }

    long long sum(int v, int lb, int rb, int l, int r) {

        if(r < lb || rb < l) 
            return 0;
     
        if(lb >= l && rb <= r) {
            return tree[v];
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        return sum(lv,lb,mid,l,r) + sum(rv,mid+1,rb,l,r);
    }

    void update(int pos, int new_value) {
        update(0,0,n-1,pos-1,new_value);
    }
    long long sum(int l, int r) {
        return sum(0,0,n-1,l-1,r-1);
    }

};

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    SegmentTree st(N,A);

    while(Q--) {
        int type; 
        cin >> type;

        if(type == 1) {
            int pos, new_value;
            cin >> pos >> new_value;

            // point update
            st.update(pos, new_value);
        }
        else if (type == 2) {
            int lb, rb;
            cin >> lb >> rb;

            // range sum
            cout << st.sum(lb,rb) << endl;
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