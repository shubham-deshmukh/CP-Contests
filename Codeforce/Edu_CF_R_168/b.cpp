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
    int n;
    cin >> n;

    vector<string> A(2);
    for(auto &a: A) cin >> a;

    const int dx[] = {+0,+0,+1,-1};
    const int dy[] = {+1,-1,+0,+0};

    auto isValid = [&](int i, int j)->bool {
        if(i >= 0 and i < 2 and j >= 0 and j < n)
            return true;
        
        return false;
    };

    // get the components
    vector<vector<int>> vis(2, vector<int> (n));
    auto dfs = [&](const auto &self, int i, int j)->void {
        vis[i][j] = 1;

        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(isValid(x,y) and !vis[x][y] and A[x][y] == '.') {
                self(self, x, y);
            }
        }
    };
    int cnt = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] and A[i][j] == '.') {
                dfs(dfs, i, j);
                cnt += 1;
            }
        }
    }

    if(cnt >= 3 or cnt == 0 or n < 3) {
        cout << 0;
        return;
    }

    if(cnt == 2) {
        int ans = 0;
        if(A[0][0] == 'x' and A[1][0] == '.' and A[1][1] == '.')
            ans += 1;
        
        if(A[1][0] == 'x' and A[0][0] == '.' and A[0][1] == '.')
            ans += 1;

        if(A[0][n-2] == '.' and A[0][n-1] == '.' and A[1][n-1] == 'x')
            ans += 1;

        if(A[1][n-1] == '.' and A[1][n-2] == '.' and A[0][n-1] == 'x')
            ans += 1;
        
        for(int j = 1; j < n-1; j++) {
            if(A[0][j-1] == '.' and A[0][j] == '.' and A[0][j+1] == '.' and A[1][j] == 'x')
                ans += 1;
        }
        for(int j = 1; j < n-1; j++) {
            if(A[1][j-1] == '.' and A[1][j] == '.' and A[1][j+1] == '.' and A[0][j] == 'x')
                ans += 1;
        } 
        cout << ans;
        return;       
    }

    // if cnt == 1
    int ans = 0;
    for(int j = 1; j < n-1; j++) {
        bool isRow = true;
        for(int k = -1; k < 2; k++) {
            isRow &= (A[0][j+k] == '.');
        }

        if(isRow and A[1][j-1] == 'x' and A[1][j] == '.' and A[1][j+1] == 'x')
            ans += 1;
    }
    for(int j = 1; j < n-1; j++) {
        bool isRow = true;
        for(int k = -1; k < 2; k++) {
            isRow &= (A[1][j+k] == '.');
        }

        if(isRow and A[0][j-1] == 'x' and A[0][j] == '.' and A[0][j+1] == 'x')
            ans += 1;
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
