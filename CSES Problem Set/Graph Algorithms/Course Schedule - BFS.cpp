#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> ind(n,0);

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
        ind[to]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(ind[i] == 0) 
            q.push(i);
    }

    if(q.empty()) { // No node with indegree zero
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> order;
    while(!q.empty()) {
        int from = q.front();
        q.pop();
        order.push_back(from);
        for(auto to: adj[from]) {
            ind[to]--;
            if(ind[to] == 0)
                q.push(to);
        }
    }

    if((int)order.size() != n) {
        cout << "IMPOSSIBLE";
        return;
    }

    for(auto o: order) cout << o+1 << " ";





}

int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}