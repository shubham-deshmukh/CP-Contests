#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    int p,q;
	    cin >> p >> q;
	    
	    vector<long long> a(n);
	    for(auto &x: a) cin >> x;
	    
	    sort(a.begin(), a.end());
	    long long mn = a.front(), mx = a.back(); 
	    
	    if(n == 1) cout << 0;
	    else {
	        a.erase(a.begin());
	        a.pop_back();
	        for(auto &x: a) if(x < 0) x *= -1;
	        
	        sort(a.begin(), a.end());
	        reverse(a.begin(), a.end());
	        
	        int sz = a.size();
	        long long sum = 0;
	        for(int i = 0; i < sz && i < (p+q); i++)
	            sum += a[i];
	           
	        cout << sum + mx - mn;
	        
	    }
	    
	    if(t) cout << "\n";
	}
	return 0;
}
