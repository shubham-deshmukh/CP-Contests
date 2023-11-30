#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
/*
A - x B + x
*/
void solve() {
    int A, B;
    cin >> A >> B;
    
    

    // A % B == 0
    int cnt1 = 0;
    int X = A, Y = B;
    auto get = [&](int a, int b)->int {
        int cnt = 0;
        while(a%b) {
            a++;
            b--;
            cnt++;
        }
        return cnt;
    };
    auto give = [&] (int a, int b)->int {
        int cnt = 0;
        while(a%b) {
            a--;
            b++;
            cnt++;
        }
        return cnt;
    };
    
    if(A == B) {
        cout << 0;
    }
    else if(A < B) {
        cout << get(A,B);  
    }
    else {
        cout << min(get(A,B),give(A,B));
    }
    
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