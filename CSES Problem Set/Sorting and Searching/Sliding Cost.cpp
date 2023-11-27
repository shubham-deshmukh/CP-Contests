#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto &a: A) cin >> a;

    multiset<int> lower, upper;
    long long lower_sum = 0, upper_sum = 0;

    auto adjust = [&](multiset<int> &lower, multiset<int> &upper)->void {
        int lower_SZ = (int)lower.size();
        int upper_SZ = (int)upper.size();

        // Lower has 1 extra element than upper
        if(lower_SZ - upper_SZ == 2) {
            int elt = *lower.rbegin();
            upper.insert(elt);
            lower.erase(lower.find(elt));

            upper_sum += elt;
            lower_sum -= elt;
        }
        else if(upper_SZ - lower_SZ >= 1) { // upper has 1 extra element
            int elt = *upper.begin();
            lower.insert(elt);
            upper.erase(upper.begin());

            lower_sum += elt;
            upper_sum -= elt;
        }
    };

    int l = 0, r = 0;
    while(r < N) {
        // insert the element in the window
        if(lower.empty() || *lower.rbegin() >= A[r]) {
            lower.insert(A[r]);
            lower_sum += A[r];
        }
        else {
            upper.insert(A[r]);
            upper_sum += A[r];
        }
        
        // adjust the elements in the lower and upper parts of the window
        adjust(lower, upper);

        // slide the window
        if((int)lower.size() + (int)upper.size() == K) {
            // calculate the cost
            cout << upper_sum - lower_sum + (K&1?*lower.rbegin():0)<< " ";

            if(lower.find(A[l]) != lower.end()) {
                lower.erase(lower.find(A[l]));
                lower_sum -= A[l];
            }
            else {
                upper.erase(upper.find(A[l]));
                upper_sum -= A[l];
            }

            adjust(lower,upper);
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