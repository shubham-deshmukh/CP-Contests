#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    
    if(N < 3 or (N&(N-1))==0 ) {
        cout << -1;
        return;
    }
    
    if(N&1) {
        cout << 1 << " " << 1 << " " << (N-1)/2;
    }
    else {
        if((N/2)&1) {
            cout << 1 << " " << 2 << " " << N/2 - 1;
        }
        else {
            
            // take out powers of 2 
            int x = 1;
            while(N%2 == 0) {
                x <<=1;
                N /= 2;
            }
            
            cout << 1 << " " << x << " " << x*(N-1)/2;
        }
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
