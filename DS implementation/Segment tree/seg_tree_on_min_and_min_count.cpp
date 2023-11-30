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
    vector<pair<long long, long long>> tree;
    vector<long long> arr;
    long long n;


    SegmentTree(long long n, vector<long long> &arr) {

        this->n = n;
        this->arr = arr;

        // TODO
        // Maximum memory required is 4*n
        // For memory efficient solution 
        // make the size to powers of 2
        
        // size = 1;
        // while(size < n) size *= 2;
    
        // tree.assign(2*size,0);        
        
        size = 4*n;
        tree.clear();
        tree.resize(size, pair<long long, long long>());
        
        build(0,0,n-1);
    }

    pair<long long, long long> get_min_pair(pair<long long, long long> left, pair<long long, long long> right) {
        if(left.first == right.first) {
            return {left.first, left.second + right.second};
        }
        
        if(left.first < right.first)
            return left;
        
        return right;
    }

    /*
    Objective: Construct the segment tree
    Parameters:
        v : Index of the current vertex
        lb : left boundry of the current segment
        rb : right boundry of the current segment
    */


    void build(int v, int lb, int rb) {
        if(lb == rb) {
            tree[v] = {arr[lb],1};
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid+1, rb);

            // 1st modification
            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = get_min_pair(tree[lv],tree[rv]);
        }
    }


    /*
    Objective : Update query (arr[pos] = new_value)
    Parameters:
        v : Index of the current vertex
        lb : left boundry of the current segment
        rb : right boundry of the current segment
        pos: position of the element
        new_value : new value 
        // operation
        i.e. arr[pos] = new_value
    */
    void update(int v, int lb, int rb, int pos, int new_value) {
        if(lb == rb) {
            tree[v] = {new_value,1}; // update the value
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

            // 2nd modification
            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = get_min_pair(tree[lv],tree[rv]);
        }
    }


    /*
    Objective: Sum of the elements in the segment arr[l..r]
    Parameters:
        v : Index of the current vertex
        lb : left boundry of the current segment
        rb : right boundry of the current segment
        l : left boundry of the target segment
        r : right boundry of the target segment
    */
    pair<long long, long long> get_min_count(int v, int lb, int rb, int l, int r) {


        // Target segment does not lies with the current segment
        /*
        CASE 1.1 : target segment is on the left of current segment
                        lb      rb
                        |_______|    --> current segment
        l         r        
        |_________|                  --> target segment


                            OR

        CASE 1.2 : target segment is on the right of current segment
                lb      rb
                |_______|                --> current segment
                            l         r        
                            |_________|  --> target segment          
        */

        // 3rd modification
        // Modify the return value (INVALID case) as per the 
        // function on which segment tree is building
        if(r < lb || rb < l) 
            return {LLONG_MAX,1};
        
        // Target segment completely contains the current segment   
        /*
        CASE 2: 
                lb      rb
                |_______|       --> current segment
            l              r        
            |______________|    --> target segment           
        */     
        if(lb >= l && rb <= r) {
            return tree[v];
        }


        // Target segment partially contains the current segment
        /*
                lb      rb
                |_______|          --> current segment
                    l         r        
                    |_________|    --> target segment        
        */
        int mid = (lb + rb) / 2;

        // 0-based indexing
        int lv = 2*v+1;
        int rv = 2*v+2;

        // 4-th modification
        // Modify the following as per the 
        // function on which segment tree is building
        pair<long long, long long> lpair = get_min_count(lv,lb,mid,l,r);
        pair<long long, long long> rpair = get_min_count(rv,mid+1,rb,l,r);
        return get_min_pair(lpair, rpair);
    }

    void update(int pos, int new_value) {
        update(0,0,n-1,pos,new_value);
    }
    pair<long long, long long> get_min_count(int l, int r) {
        return get_min_count(0,0,n-1,l,r-1);
    }

};


void solve() {
    long long N,Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for(auto &a: A) cin >> a;
    SegmentTree st(N,A);

    while(Q--) {
        int type;
        cin >> type;
        if(type == 1) {
            long long i, v;
            cin >> i >> v;

            // update 
            st.update(i,v);
        }
        else if(type == 2) {
            long l,r;
            cin >> l >> r;
            pair<long long, long long> p = st.get_min_count(l,r);
            cout << p.first << " " << p.second;
            if(Q)
                cout << endl;
            
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