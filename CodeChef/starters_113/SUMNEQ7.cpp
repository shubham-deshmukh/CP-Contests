#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(auto &a: A) cin >> a;
    
    
    string ans = "YES";
    if(N == 4 && A[0] + A[1] == A[2]+A[3]) {
        ans = "NO";
    }
    else {
        sort(A.begin(), A.end());
        
        if(A[0] == A[N-1]) 
            ans = "NO";
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
