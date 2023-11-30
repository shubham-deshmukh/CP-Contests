// Here is the implementation of segment tree
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

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

            // 1st modification
            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = tree[lv] + tree[rv];
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

            // 2nd modification
            // Modify the following as per the 
            // function on which segment tree is building
            tree[v] = tree[lv]+tree[rv];
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
    long long sum(int v, int lb, int rb, int l, int r) {


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

        // 4-th modification
        // Modify the following as per the 
        // function on which segment tree is building
        return sum(lv,lb,mid,l,r) + sum(rv,mid+1,rb,l,r);
    }

    void update(int pos, int new_value) {
        update(0,0,n-1,pos,new_value);
    }
    long long sum(int l, int r) {
        return sum(0,0,n-1,l,r-1);
    }

};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif    
    
    int n,Q;
    cin >> n >> Q;

    vector<long long> a(n);
    for(auto &x: a) cin >> x;

    SegmentTree st(n, a);


    while(Q--) {
        int type;
        cin >> type;
        if(type == 1) {
            // point update
            int pos, new_value;
            cin >> pos >> new_value;
            st.update(pos,new_value);
        }
        else if(type == 2) {
            // range sum
            int lb, rb; // rb not included
            cin >> lb >> rb;
            cout << st.sum(lb,rb) << endl;
        }
    }

    return 0;
}