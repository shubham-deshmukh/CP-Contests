// Ref: 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
 
const int nmax = 2e5 + 5;
bool vis[nmax];
int up[nmax][22], n, q, h[nmax];
void dfs (int u) {
    if(vis[u]) return;
    vis[u] = true;
    dfs(up[u][0]);
    h[u] = h[up[u][0]] + 1;
}
int jump (int u, int k) {
    if(k <= 0) return u;
    for (int i = 20; i >= 0; i--){
        if(k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int p, i = 1; i <= n; i++) {
        cin >> p;
        up[i][0] = p;
    }
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    while (q --) {
        int u, v;
        cin >> u >> v;
        if(jump(u, h[u] - h[v]) == v) {
            cout << h[u] - h[v] << '\n';
            continue;
        }
        int k = jump(u, h[u]);
        if(jump(k, h[k] - h[v]) == v) {
            cout << h[k] - h[v] + h[u] << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
}
