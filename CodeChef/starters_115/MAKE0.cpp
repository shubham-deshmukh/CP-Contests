#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto &a: A) cin >> a;
    
    vector<int> dseq;
    
    int mn = A[0];
    
    for(int i = 0; i < n; i++) 
        if(A[i] <= mn) {
            dseq.push_back(A[i]);
            mn = A[i];
        }
       
    int N = (int)dseq.size();
    int ans = n;
    for(int i = 0; i < N; i++) {
        int type1 = dseq[i];
        int elt = N-i;
        int type2 = n - elt;
        
        ans = min(ans,type1 + type2);
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