#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    multiset<int> left, right;
    
    auto adjust = [&](multiset<int> &left, multiset<int> &right)->void {
        int left_SZ = (int)left.size();
        int right_SZ = (int)right.size();
        if(left_SZ - right_SZ == 2) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        } 
        else if(right_SZ - left_SZ >= 1)  {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };

    int l = 0, r = 0;
    while(r < n) {

        if(left.empty()) {
            left.insert(A[r]);
        }
        else {
            if(*left.rbegin() <= A[r])
                right.insert(A[r]);
            else 
                left.insert(A[r]);
        }

        // adjust the size after insertion
        adjust(left, right);

        // print the median
        if((int)left.size() + (int)right.size() == k) {
            cout << *left.rbegin() << " ";

            // shift the window
            if(left.find(A[l]) != left.end()) {
                left.erase(left.find(A[l]));
            }
            else {
                right.erase(right.find(A[l]));
            }
            
            // adjust the size after removal
            adjust(left,right);
            l++;
        }
        r++;

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