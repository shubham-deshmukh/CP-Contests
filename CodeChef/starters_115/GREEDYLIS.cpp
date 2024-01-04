#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int n, x;
    cin >> n >> x;
  
/*  
    1 2 3 4
    4 3 2 1 : 1
    4 3 1 2 : 2 
    4 1 2 3 : 3 
    1 2 3 4 : 4
                LIS  Alic 
    1 4 2 3 :   3   2  1 
    1 2 4 3 :   3   3  0
    1 2 3 4 :   4   4  0
    
*/

    if(n == 1) {
        if(!x) cout << 1;
        else cout << -1;
        return;
    }
    
    if(n == 2) {
        if(x == 0) {
            cout << 1 << " " << 2;
        }
        else cout << -1;
        return;
    }
    
    if(x == n || x == n-1) {
        cout << -1;
        return;
    }
    

    int pos = n-1-x;
    
    for(int i = 1; i <= n-1; i++) {
        if(i == pos) {
            cout << n << " " << i << " ";
            continue;
        }
        cout << i << " ";
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