#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    
    vector<int> types(N), values(N);
    for(auto &t: types) cin >> t;
    for(auto &v: values) cin >> v;
    
    map<int, vector<int>> mp;
    for(int i = 0; i < N; i++) {
        mp[types[i]].push_back(values[i]);
    }
    
    long long max_score = 0;
    for(auto [_,v]: mp) {
        int mx = *max_element(v.begin(), v.end());
        if(mx > 0) max_score += mx;
    }
    
    cout << max_score;
}

int main() {
	// your code goes here
	fast;
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}
