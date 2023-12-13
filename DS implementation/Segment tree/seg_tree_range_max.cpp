#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define lld long double
#define ull unsigned long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(i = start; start < end ? i < end : i > end; start < end ? i += 1 : i -= 1)
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


const int MAX_N = 1e5;
const int mod = 1e9+7;

inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}


bool cmp(pair<ull,ull> x, pair<ull,ull> y) {
    if(x.ss != y.ss) return (x.ss > y.ss); // descresing order of 2nd elt
    else return (x.ff < y.ff); // incresing order of 1st elt
}

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

    void range_max(int v, int lb, int rb, int l, int r, long long value) {

        if(r < lb || rb < l) 
            return;
            
        if(lb >= l && rb <= r) {
            // modification 2
            tree[v] = max(tree[v], value);
            return;
        }

        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        range_max(lv,lb,mid,l,r,value);
        range_max(rv,mid+1,rb,l,r,value);
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
        return max(res,tree[v]);

    }

    void range_max(int l, int r, long long value) {
        range_max(0,0,n-1,l,r-1,value);
    }

    long long get_value(int pos) {
        return get_value(0,0,n-1,pos);
    }

};



void solve() {
    long long N, Q;
    cin >> N >> Q;

    vector<long long> A(N);

    SegmentTree st(N, A);

    while(Q--) {
        int type;
        cin >> type;

        if(type == 1) {
            // apply max to segment
            int l, r;
            long long value;
            cin >> l >> r >> value;

            st.range_max(l,r,value);
        }
        else if(type == 2) {
            // get value at index pos
            int pos;
            cin >> pos;

            cout << st.get_value(pos) << endl;
        }
    }
}
int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    ll t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}