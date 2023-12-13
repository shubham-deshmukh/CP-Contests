#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

const int mod = 1e9 + 7;

void solve() {
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    vector<long long> freq(26,0);
    
    for(auto ch: S) 
        freq[ch-'a']++;
    
    long long cnt = 1;
    for(int i = 0; i < 26; i++) {
        if(freq[i]) {
            cnt *= (freq[i]+1);
            cnt %= mod;
        }
    }
    
    cout << cnt - 1;
    
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
