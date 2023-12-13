#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    string S;
    cin >> S;
    
    auto isVowel = [&](char ch)->bool {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch  == 'U')
            return true;
            
        return false;
    };
    
    string dst = "CODETOWN";
    
    string ans = "YES";
    for(int i = 0; i < 8; i++) {
        if(isVowel(S[i]) != isVowel(dst[i])) {
            ans = "NO";
            break;
        }
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
