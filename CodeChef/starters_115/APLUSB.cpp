#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &a: B) cin >> a;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    
    int sum = A[0] + B[0];
    for(int i = 0; i < n; i++) {
        if(A[i] + B[i] != sum) {
            cout << -1;
            return;
        }
    }
    
    for(auto a: A) cout << a << " ";
    cout << endl;
    for(auto a: B) cout << a << " ";
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