#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

const int mod = 1e9+7;

void solve() {
    int n,k;
    cin >> n >> k;

    ordered_set<int> people;
    for(int i = 1; i <= n; i++) 
        people.insert(i);
    
    int jump = 0;
    while(!people.empty()) {
        // get the position of next person going to be killed
        jump = (jump+k)%(int)people.size();

        // get the person going to be killed
        int person = *people.find_by_order(jump);
        
        // kill the person
        people.erase(person);

        cout << person;
        if(!people.empty())
            cout << " ";
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