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


const int CHAR_SET = 26;
struct Vertex {
    array<int,CHAR_SET> next;
    vector<int> words;

    Vertex() {
        fill(next.begin(), next.end(), -1);
    }
};

vector<Vertex> trie;
vector<string> dict;

void add_string(string const& s, int i) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
            trie.back().words.emplace_back(i);
        }
        else {
            trie[trie[v].next[c]].words.emplace_back(i);
        }

        v = trie[v].next[c];
    }
}

void query(string s, int k) {
    int n = (int)s.size();
    int v = 0;
    vector<int> ans;
    int i;
    for(i = 0; i < n; i++) {
        int c = s[i] - 'a';
        // no word is present
        if(trie[v].next[c] == -1)
            break;

        v = trie[v].next[c];
        // print the suggested words 
        ans = trie[v].words;
        sort(ans.begin(), ans.end(), [&](int wi, int wj){
            return dict[wi] < dict[wj];
        });

        int sz = min(k, (int)ans.size());
        // debug(i,ans);
        // debug(sz);
        for(int j = 0; j < sz; j++) {
            // debug(j, ans[j], dict[ans[j]]);
            cout << dict[ans[j]] << " \n"[j == sz-1];
        }
        ans.clear();
    }

    if(ans.empty()) {
        for(;i < n; i++) {
            cout << i;
            // if(i < n-1)
                cout << endl;
        }
    }
}


void solve() {
    int N, maxLen, Q;
    cin >> N >> maxLen >> Q;

    trie.clear();
    dict.clear();
    trie.emplace_back();

    
    for(int i = 0; i < N; i++) {
        int x;
        string s;
        cin >> x >> s;
        dict.push_back(s);
        add_string(s,i);
    }
    debug(dict);
    while(Q--) {
        int x, k;
        string s;
        cin >> x >> s >> k;

        query(s,k);
        // if(Q) cout << endl;

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

    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
