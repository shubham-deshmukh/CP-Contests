#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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

    ordered_set<pair<int,int>> s;
    int l = 0, r = 0;
    int id = 0;
    while(r < N) {
        // insertion
        s.insert({A[r],id++});

        //print the median
        if((int)s.size() == K) {
            int mid_idx = K/2;
            if(K%2 == 0) mid_idx -= 1;

            cout << (*s.find_by_order(mid_idx)).first << " ";

            // slide the window
            s.erase(s.lower_bound({A[l],-1}));
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