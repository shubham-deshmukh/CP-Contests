#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    /** 
     * Closest to the Right (Without Equality)
     * Upper bound
     * Find out upper bound i.e min i such that a[i] > k
    */
    auto UpperBound = [&](int k)->void {

        
        int l = -1;
        int r = N; 
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(A[m] > k) {
                r = m; 
            } else {
                l = m; 
            }
        } 

        if(r == N) cout << "Invalid\n";
        else cout << A[r] << "\n";
    };

    /**
     * Closest to the Right (With equality) / Lower Bound
     * Find out the minimum index of an array element not less than the give one.
     * i.e. a[i] >= k such that i is minimum.
     * It is nothing but the lower bound
     */   
    auto LowerBound = [&](int k)->void {

        int l = -1;
        int r = N;
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(A[m] >= k) {
                r = m; 
            } else {
                l = m; 
            }
        } 
        if(r == N) cout << "Invalid\n";
        else cout << A[r] << "\n";
    };    

    /**
     * Closest to the Left
     * Find out the maximum index of an array element not greater than the give one.
     * i.e. a[i] <= k such that i is maximum.
     * 
     */
    auto MaxIndexNotGreaterThan_K = [&](int k)->void {

        int l = -1;
        int r = N;
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(A[m] <= k) {
                l = m; 
            } else {
                r = m; 
            }
        } 
        
        if(l == -1) cout << "No such element\n";
        else cout << A[l] << "\n";
    };   
     

    /** Binary Search
     * Find out whether element is present in the array or not
     * i.e. a[mid] == k
     * here any condition is sufficient. 
     * Return index should be the one which contains equality condition.
     * Check BinarySearch1 and BinarySearch2 to understand the meaning of above line.
     */

    auto BinarySearch1 = [&](int k)->void {

        int l = -1;
        int r = N;
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(A[m] >= k) {
                r = m; 
            } else {
                l = m; 
            }
        } 
        if(r != N && A[r] == k) cout << "Found at index: " << r << endl;
        else cout << "Not Found\n";
    }; 

    auto BinarySearch2 = [&](int k)->void {

        int l = -1;
        int r = N;
        while(r - l > 1) {
            int m = l + (r-l) / 2;
            if(A[m] <= k) {
                l = m; 
            } else {
                r = m; 
            }
        } 
        
        if(l != -1 && A[l] == k) cout << "Found at index: " << l << endl; 
        else cout << "No Found\n";
    };     

    while(Q--) {
        int x;
        cin >> x;
        // UpperBound(x);
        // LowerBound(x);
        // BinarySearch1(x);
        // BinarySearch2(x);
        // MaxIndexNotGreaterThan_K(x);

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
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}