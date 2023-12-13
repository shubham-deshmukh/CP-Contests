#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N, K;
    cin >> N >> K;
    
    if(N%(K+1) == 0) {
        cout << N / (K+1);
    }
    else {
        int share = N / (K+1);
        cout << N - K*share;
    }
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
