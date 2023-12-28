#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int int64_t

void solve() {
    int N;
    cin >> N;
    
    vector<int> piles(N);
    for(auto &p: piles) cin >> p;
    
    // total stones
    int total;
    total = accumulate(piles.begin(), piles.end(), (int)0);
    
    string winner;
    
    if(N == 1) { // trivial cases
        if(piles[0] > 1) winner = "ALICE";
        else winner = "BOB";
    }
    else {
        if(total&1) { // odd number of stones then Bob will win
            winner = "BOB";            
        }
        else {
            int odd = 0, even = 0;
            for(int i = 0; i < N; i++) {
                if(i&1) odd += piles[i];
                else even += piles[i];
            }
            
            int moves = total / 2;
            if(moves%2 == odd%2) winner = "BOB";
            else winner = "ALICE";
        }
    }
    
    cout << winner;
    
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
