#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 2;
const int BITS = 31;
struct Vertex {
    array<int, N> next;
    int cnt = 0;
    Vertex() {
        fill(next.begin(), next.end(), -1);
    }
};

vector<Vertex> trie;
void add_number(int x) {
    int v = 0;
    for(int i = BITS-1; i >= 0; i--) {
        
        trie[v].cnt += 1;
        int c = 0;
        if(x & (1 << i))
            c = 1;
        
        if(trie[v].next[c] == -1) {
            trie[v].next[c] = int(trie.size());
            trie.emplace_back();
        }

        v = trie[v].next[c];
    }

    trie[v].cnt += 1;
}


int query(int x) {
    int v = 0;
    int ans = 0;

    for(int i = BITS-1; i >= 0; i--) {
        int c = 0;

        if(x & (1 << i))
            c = 1;
        
        if(trie[v].next[1-c] == -1 || trie[trie[v].next[1-c]].cnt == 0) {
            v = trie[v].next[c];
        }
        else {
            ans += (1 << i);
            v = trie[v].next[1-c];
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    trie.clear();
    trie.emplace_back();

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    add_number(0);

    int mx = 0;
    int pre = 0;
    for(auto a: A) {
        pre ^= a;
        int q = query(pre);
        mx = max(mx, q);
        add_number(pre);
    }

    cout << mx;
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
