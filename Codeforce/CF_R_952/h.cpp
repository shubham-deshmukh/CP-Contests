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
/*
- Find out all connected components
    - which element is belongs to which component.
- For each row or column check if it is possible to get the max size componenet
    - if '.' then size += 1 and check all four direction for the component
        - if component is not visited then add the size to answer
        - if visited do not add the size to the answer and mark the component as visited
    - if '#' then check if component is visited or not
        - if not visited then add the size to the component and mark the component as visited
*/
void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(auto &a: A) cin >> a;

    vector<vector<int>> B(n, vector<int> (m,-1));
    vector<vector<int>> vis(n, vector<int> (m,0));

    const int dx[] = {+0,+0,+1,-1};
    const int dy[] = {+1,-1,+0,+0};

    int k = 0;
    unordered_map<int,int> compSize;
    auto isValid = [&](int i, int j)->bool {
        if(i >= 0 and i < n and j >= 0 and j < m)
            return true;
        
        return false;
    };

    auto dfs = [&](const auto &self, int i, int j, int& sz)->void {
        vis[i][j] = 1;
        B[i][j] = k;
        sz += 1;

        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(isValid(x,y) and A[x][y] != '.' and !vis[x][y]) {
                self(self,x,y,sz);
            }
        }
    };


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] != '.' and !vis[i][j]) {
                int sz = 0;
                dfs(dfs,i,j, sz);
                compSize[k] = sz;
                k += 1;
            }
        }
    }

    // check for each row
    int maxSize = 0;
    for(int i = 0; i < n; i++) {
        // vector<int> vis(k);
        set<int> st;
        int sz = 0;
        for(int j = 0; j < m; j++) {
            if(A[i][j] == '.') {
                sz += 1;
                for(int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if(isValid(x,y) and A[x][y] != '.') {
                        st.insert(B[x][y]);
                        // sz += compSize[B[x][y]];
                        // vis[B[x][y]] = 1;
                    }
                }
            }
            else {
                st.insert(B[i][j]);
                // if(!vis[B[i][j]]) {
                //     vis[B[i][j]] = 1;
                //     sz += compSize[B[i][j]];
                // }
            }
        }
        for(auto s: st) sz += compSize[s];
        maxSize = max(maxSize, sz);
    }

    // check for each column
    for(int j = 0; j < m; j++) {
        // vector<int> vis(k);
        set<int> st;
        int sz = 0;
        for(int i = 0; i < n; i++) {
            if(A[i][j] == '.') {
                sz += 1;
                for(int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if(isValid(x,y) and A[x][y] != '.') {
                        st.insert(B[x][y]);
                        // sz += compSize[B[x][y]];
                        // vis[B[x][y]] = 1;
                    }
                }
            }
            else {
                st.insert(B[i][j]);
                // if(!vis[B[i][j]]) {
                //     vis[B[i][j]] = 1;
                //     sz += compSize[B[i][j]];
                // }
            }
        }
        for(auto s: st) sz += compSize[s];
        maxSize = max(maxSize, sz);
    }

    cout << maxSize;
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
