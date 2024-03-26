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
        
        int c = 0;
        if(x & (1 << i))
            c = 1;
        
        if(trie[v].next[c] == -1) {
            trie[v].next[c] = int(trie.size());
            trie.emplace_back();
            trie.back().cnt += 1;
        }
        else 
            trie[trie[v].next[c]].cnt += 1;

        v = trie[v].next[c];
    }
}

long long query(int x, int k) {
    int v = 0;
    long long ans = 0;
    for(int i = BITS-1; i >= 0; i--) {
        int xi = 0, ki = 0;
        if(x & (1 << i))
            xi = 1;
        if(k & (1 << i))
            ki = 1;

        // x ^ y < k
        if(xi == ki) {
            // 0 ^ y < 0
             
            if(ki) { // 1 ^ y < 1 => y = 1
                if(trie[v].next[1] != -1) {
                    ans += trie[trie[v].next[1]].cnt;
                }
            }
            v = trie[v].next[0];
        }
        else {
            // 0 ^ y < 1 => y = 0
            // 1 < y < 0
            if(ki) {
                if(trie[v].next[0] != -1) {
                    ans += trie[trie[v].next[0]].cnt;
                }
            }
            v = trie[v].next[1];
        }

        if(v == -1)
            break;
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    trie.clear();
    trie.emplace_back();

    add_number(0);
    
    int pre = 0;
    long long ans = 0;
    for(auto a: A) {
        pre ^= a;
        ans += query(pre,k);
        add_number(pre);
    }
    cout << ans;
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
