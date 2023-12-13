#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    bool no = false;
    for(int i = 0; i < N; i++) {
        if(S[i]=='0') {
            cout << "NO";
            no = true;
        }
        else {
            if(no) {
                cout << "NO";
            }
            else {
                if(i != N-1) {
                    cout << "IDK";
                }
                else cout << "YES";
            }
        }
        
        cout << endl;
    }
}

int main() {
	// your code goes here
	fast;
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   //if(T) cout << endl;
	}
	return 0;
}
