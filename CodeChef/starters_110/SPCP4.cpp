#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int N, X, K;
    cin >> N >> X >> K;
    
    int boys = X, girls = N-X;
    boys %= K;
    girls %= K;
    
    int pairs = min(boys, girls);
    cout << boys + girls - 2 * pairs;
}

int main() {
	// your code goes here
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}
