#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

void solve() {
    // R : Rock , P : Paper , S : Scissors
    
    // P -> R -> S 
    
    int N;
    cin >> N;
    
    string s;
    cin >> s;
    
    int need = N / 2 + 1;
    string ans(N, 'X');
    
    int cnt = 0;
    for(int i = 0; i < N; i++)
        if(s[i] == 'R') {
            cnt++;
            ans[i] = 'P';
        }
    
    auto getWin = [&](const char ch)->char {
        char win = 'X';
        if(ch == 'S') win = 'R';
        if(ch == 'P') win = 'S';
        if(ch == 'R') win = 'P';
        
        return win;
        
    };
    
    int i = N-1;
    while(cnt < need) {
        if(s[i] != 'R') {
            cnt++;
            ans[i] = getWin(s[i]);
        }
        i--;
    }
    
    
    for(int i = 0; i < N; i++) 
        if(ans[i] == 'X')
            ans[i] = 'P';
            
    
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
