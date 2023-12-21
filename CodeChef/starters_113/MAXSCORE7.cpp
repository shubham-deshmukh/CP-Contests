#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"


void solve() {
    int N;
    cin >> N;
    
    int zero = 0;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        zero += (x == 0);
    }
    
    cout << min(zero, N-zero);
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
