#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    
    int n, x, y;
    cin >> n >> x >> y;
    
    string ans = "NO";
    
    if(n <= x && n <= x/3) ans = "YES";
    else if(n <= x / 2) ans = "YES";
    else {
        int mn = min(x, y/3);
        if(n-mn <= (x-mn) / 2) ans ="YES";
    }
    cout << ans;
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