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

using pii = pair<int,int>;
const int inf = 1e9;
const int dx[] = {+0,+0,+1,-1};
const int dy[] = {+1,-1,+0,+0};
void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<string> A(n);
    for(auto &a: A) cin >> a;

    auto bfs = [&](int si, int sj)->set<pii> {
        vector<vector<int>> dist(n, vector<int> (m,inf));
        queue<pii> q;
        q.push({si,sj});
        dist[si][sj] = 0;

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];

                if(x < 0 or x >= n or y < 0 or y >= m)
                    continue;
                
                if(dist[x][y] > dist[i][j] + 1) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push(pii{x,y});
                }
            }
        }

        // debug(dist);
        set<pii> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == '.' and dist[i][j] <= d) {
                    ans.insert(pii{i,j});
                }
            }
        }
        // debug(ans);
        return ans;
    };

    // bfs(0,0);
    vector<pii> src;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]=='.')
                src.push_back(pii{i,j});
        }
    }

    int sz = (int)src.size();
    int best = 0;
    for(int i = 0; i < sz; i++) {
        set<pii> s1 = bfs(src[i].first, src[i].second);
        for(int j = i + 1; j < sz; j++) {
            set<pii> s2 = bfs(src[j].first, src[j].second);
            for(auto a: s1) {
                s2.insert(a);
            }
            best = max(best,(int)s2.size());
            
        }
    }
    cout << best;
}
signed main() {
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
