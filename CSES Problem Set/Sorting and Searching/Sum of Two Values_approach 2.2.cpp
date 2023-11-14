#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,sum;
    cin >> n >> sum;

    map<int,int> freq;
    map<int, vector<int>> value_to_index;

    // Offline processing
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(freq[x] < 2) {
            freq[x]++;
            value_to_index[x].push_back(i+1);
        }    
    }
    
    for(auto [k,v]: freq) {
        int k2 = sum - k;
        if(k2 < 0) break;

        if(k != k2 && freq.count(k2)) {
            cout << value_to_index[k].front() <<" "<<value_to_index[k2].back();
            return;
        }
        if(k == k2 && freq.count(k2) && freq[k2] == 2) {
            cout << value_to_index[k].front() <<" "<<value_to_index[k2].back();
            return;
        }
    }

    cout << "IMPOSSIBLE";
    
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