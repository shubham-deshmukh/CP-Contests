#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
/*
Obs
- xor == 0 => both numbers has to be same

*/
void solve() {
    // Approach : Bruteforce
    int n, m;
    cin >> n >> m;
    string s1 = to_string(n);
    string s2 = to_string(m);
    set<int> st1,st2;
    string num = "";
    auto rec = [&](const auto &self, int i, string &s1, set<int> &st1)->void {
        if(i == (int)s1.size()) {
            if(!num.empty() and num[0] != '0') {
                st1.insert(stoi(num));
            }
            return;
        }
        self(self,i+1,s1,st1);
        num.push_back(s1[i]);
        self(self,i+1,s1,st1);
        num.pop_back();
    };
    rec(rec,0,s1,st1);
    num = "";
    rec(rec,0,s2,st2);

    // for(auto &i: st1) cout << i << " "; cout << endl;
    // for(auto &i: st2) cout << i << " "; cout << endl;

    if((int)st1.size() > (int)st2.size())
        swap(st1,st2);
    
    int ans = 0;
    for(auto &i: st1) {
        if(st2.find(i) != st2.end()) {
            ans += 1;
            cout << i << " ";
        }
    }
    cout << endl;
    cout << ans << endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        
    long long t = 1;
    cin >> t;
    while(t--) {
        solve();
        // if(t) cout << endl;
    }
    return 0;
}