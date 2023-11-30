#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int mod = 1e9+7;
const int MX = 1e5+5; 
vector<int> turn_A, turn_B;

/* Number of ways s.t. i lines are crossed and its A's turn(turn_A)

Answer: 
turn_A(L-1) +  turn_A(L-2) +  turn_A(L-3) + turn_A(L-4) 
*/

void pre() {
    turn_A.assign(MX,0);
    turn_B.assign(MX,0);
    
    
    turn_A[0] = 1;
    turn_B[0] = 0;
    
    auto get = [&](vector<int> &turn, int i)->int {
        if(i < 0) return 0;
        
        return turn[i];
    };
    
    for(int i = 1; i <= MX; i++) {
        int x = 0;
        x += get(turn_A,i-2);
        x %= mod;
        x += get(turn_A,i-3);
        x %= mod;
        x += get(turn_A,i-4);
        x %= mod;
        x += get(turn_B,i-1);
        x %= mod;
        
        turn_A[i] = x;
        
        x = 0;
        x += get(turn_B,i-2);
        x %= mod;
        x += get(turn_B,i-3);
        x %= mod;
        x += get(turn_B,i-4);
        x %= mod;
        x += get(turn_A,i-1);
        x %= mod;
        
        turn_B[i] = x;
    }

}

void solve() {
    int L;
    cin >> L;
    
    auto get = [&](vector<int> &turn, int i)->int {
        if(i < 0) return 0;
        
        return turn[i];
    };
    
    int x = 0;
    x += get(turn_A,L-1);
    x %= mod;
    x += get(turn_A,L-2);
    x %= mod;
    x += get(turn_A,L-3);
    x %= mod;
    x += get(turn_A,L-4);
    x %= mod;
    
    cout << x;
    
}

int main() {
	// your code goes here
	pre();
	int T = 1;
	cin >> T;
	while(T--) {
	   solve();
	   if(T) cout << endl;
	}
	return 0;
}