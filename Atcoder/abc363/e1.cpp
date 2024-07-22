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


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.


const int MAX_N = 1e5;
const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

void solve() {
    int n, m, year;
    cin >> n >> m >> year;

    using t3 = array<int,3>;
    vector<vector<int>> A(n, vector<int> (m));
    vector<vector<int>> vis(n, vector<int> (m));

    priority_queue<t3,vector<t3>, greater<t3>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];

            if(i == 0 or i == n-1 or j == 0 or j == m-1) {
                vis[i][j] = 1;
                q.push({A[i][j],i,j});
            }
        }
    }

    const int dx[] = {+0,+0,+1,-1};
    const int dy[] = {+1,-1,+0,+0};

    auto isValid = [&](int i, int j)->bool {
        if(i >= 0 and i < n and j >= 0 and j < m)
            return true;
        
        return false;
    };

    int rem = n * m;
    for(int k = 1; k <= year; k++) {
        while(!q.empty() and q.top()[0] <= k) {
            int val = q.top()[0];
            int i = q.top()[1];
            int j = q.top()[2];

            q.pop();
            rem -= 1;

            for(int dir = 0; dir < 4; dir++) {
                int x = dx[dir] + i;
                int y = dy[dir] + j;

                if(isValid(x,y) and !vis[x][y]) {
                    vis[x][y] = 1;
                    q.push({A[x][y],x,y});
                }
            }

        }
        cout << rem  << endl;
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
