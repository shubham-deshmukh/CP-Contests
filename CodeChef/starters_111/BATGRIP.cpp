#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int long long
void solve() {
    int N;
    cin >> N;
    
    vector<int> wickets(N-1);
    for(auto &w: wickets) cin >> w;
    
    int not_out = N*(N+1) / 2 - accumulate(wickets.begin(), wickets.end(), 0LL);
    
    // cout << "Not out player: " << not_out << endl;
    
    vector<int> seq(N);
    for(int i = N-2; i >= 0; i--) {
        seq[i+1] = min(not_out, wickets[i]);
        not_out = max(not_out, wickets[i]);
    }
    
    seq[0] = not_out;
    int max_score = 0;
    for(int i = 0; i < N; i++) {
        max_score += max(i+1, seq[i]);
    }
    
    cout << max_score;
}

signed main() {
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