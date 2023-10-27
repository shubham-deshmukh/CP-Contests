#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    long long n;
	    cin >> n;
	    cout << n << " " << n-1;
	    if(t > 0) cout << "\n";
	}
	return 0;
}

