#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int W, H;
    cin >> W >> H;
    
    bool isPos = (60 <= W && 130 >= H);
    cout << (isPos?"YES":"NO");
}

int main() {
	// your code goes here
	int T = 1;
// 	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}
