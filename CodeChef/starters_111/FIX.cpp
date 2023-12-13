#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(auto &a: A) cin >> a;
    
    int mx = *max_element(A.begin(), A.end());
    set<int> s;
    
    vector<int> B(N);
    B[0] = A[0];
    
    s.insert(A[0]);
    
    for(int i = 1; i < N; i++) {
        if(s.find(A[i]) != s.end()) { // element is present in the set 
            // prefix condition is satisfied
            B[i] = mx;
        }
        else {
            B[i] = A[i];
            s.insert(A[i]);
        }
    }
    
    for(auto b: B) cout << b << " ";
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
