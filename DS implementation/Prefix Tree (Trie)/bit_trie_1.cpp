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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

const int MAX_N = 1e5;
const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

const int N = 2;
const int BITS = 31;
struct Vertex {
    array<int, N> next;
    int cnt = 0;
    Vertex() {
        fill(next.begin(), next.end(), -1);
    }
};

vector<Vertex> trie(1);

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

void erase_number(int x) {
    int v = 0;
    for(int i = BITS - 1; i >= 0; i--) {
        trie[v].cnt -= 1;

        int c = 0;
        if(x & (1 << i))
            c = 1;

        v = trie[v].next[c];      
    }

    trie[v].cnt -= 1;
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
    int Q;
    cin >> Q;

    add_number(0);
    while(Q--) {
        char op;
        int x;
        cin >> op >> x;
        if(op == '+') {
            add_number(x);
        }
        else if(op == '-') {
            erase_number(x);
        }
        else if(op == '?') {
            cout << query(x);
            if(Q) cout << endl;
        }
    }
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
    // cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
