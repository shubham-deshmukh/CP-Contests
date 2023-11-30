#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int X,N;
    cin >> X >> N;
    int ans = 0;
    if(100*X < N) {
        N -= 100*X;
        ans = (int)ceil(N*1.0/100);
    }
    cout << ans;
}

int main() {
	// your code goes here
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}
