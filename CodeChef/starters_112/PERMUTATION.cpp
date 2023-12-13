#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N, X;
    cin >> N >> X;
    
    if(N&1) {
        if((N+1) / 2 == X) {
            cout << -1;
        }
        else {
            // for(int i = 1; i <= N; i++) cout << i << " ";
        int Y = 1+N-X;
        int mn = min(X,Y);
        int mx = max(X,Y);
        
        vector<int> ans;
        ans.push_back(mn);
        for(int i = 1; i <= N; i++) {
            if(i == mn or i == mx) continue;
            
            // cout << i << " ";
            ans.push_back(i);
        }
        // cout << mx;
        ans.push_back(mx);
        
        if(ans[0] != X) 
            reverse(ans.begin(), ans.end());
        
        for(auto d: ans) cout << d << " ";            
            
        }
    }
    else {
        // always possible
        int Y = 1+N-X;
        int mn = min(X,Y);
        int mx = max(X,Y);
        
        vector<int> ans;
        ans.push_back(mn);
        for(int i = 1; i <= N; i++) {
            if(i == mn or i == mx) continue;
            
            // cout << i << " ";
            ans.push_back(i);
        }
        // cout << mx;
        ans.push_back(mx);
        
        if(ans[0] != X) 
            reverse(ans.begin(), ans.end());
        
        for(auto d: ans) cout << d << " ";
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
