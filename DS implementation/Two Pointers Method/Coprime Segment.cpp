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

        // TODO
        // Maximum memory required is 4*n
        // For memory efficient solution 
        // make the size to powers of 2
        
        // size = 1;
        // while(size < n) size *= 2;
    
        // tree.assign(2*size,0);        
        
        size = 4*n;
        tree.assign(size,0);
        
        build(0,0,n-1);
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
            tree[v] = arr[lb];
        }
        else {
            int mid = (lb + rb) / 2;
            
            // 0-based indexing
            int lv = 2*v+1; // left child index
            int rv = 2*v+2; // right child index

            build(lv, lb, mid);
            build(rv, mid+1, rb);
            
            
            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = __gcd(tree[lv],tree[rv]);
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

            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = __gcd(tree[lv],tree[rv]);
        }
    }


    /*
    Objective: query of the elements in the segment arr[l..r]
    Parameters:
        v : Index of the current vertex
        lb : left boundry of the current segment
        rb : right boundry of the current segment
        l : left boundry of the target segment
        r : right boundry of the target segment
    */
    long long query(int v, int lb, int rb, int l, int r) {


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

        // Modify the return value (INVALID case) as per the 
        // function on which segment tree is building
        if(r < lb || rb < l) 
            return 0;
        
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

        // Modify the following as per the 
        // function on which segment tree is building
        return __gcd(query(lv,lb,mid,l,r),query(rv,mid+1,rb,l,r));
    }

    void update(int pos, int new_value) {
        update(0,0,n-1,pos,new_value);
    }
    long long query(int l, int r) { 
        return query(0,0,n-1,l,r); // [l..r] : both included
    }

};


void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    SegmentTree st(n, A);

    // cout << st.query(0,2);
    int g = 0;
    int minLen = n+1;
    for(int r = 0, l = 0; r < n; r++) {
        g = __gcd(g,A[r]);

        while(g == 1) {
            minLen = min(minLen, r-l+1);

            l += 1;
            //update the gcd from A[l...r]
            g = st.query(l,r);
        }
    }

    if(minLen == n+1)
        minLen = -1;
    
    cout << minLen;

    
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