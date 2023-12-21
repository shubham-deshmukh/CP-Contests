#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int A[100000];
void solve() {
    int N;
    cin >> N;
        
    string ans = "NO";
    if(A[N]) ans = "YES";
    
    cout << ans;
}

int main() {
	// your code goes here
	fast;
	A[0] = 1;
	for(int i = 0; i <= 10020; i++) 
	    if(A[i]) {
	        A[i+3] = 1;
	        A[i+4] = 1;
	    }
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}
