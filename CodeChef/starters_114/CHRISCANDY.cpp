#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(auto &a: A) cin >> a;
    
    vector<int> pre(N);
    pre[0] = A[0];
    
    for(int i = 1; i < N; i++)
        pre[i] = max(pre[i-1],A[i]);
    
    int cnt = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < pre[i-1])
            cnt++;
    }
    
    cout << cnt;
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
