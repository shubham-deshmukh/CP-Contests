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


#define int int64_t
using t3 = array<int,3>;
const int dx[] = {+0,+0,+1,-1};
const int dy[] = {+1,-1,+0,+0};
void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    int sx, sy;
    cin >> sx >> sy;

    sx -= 1;
    sy -= 1;

    vector<vector<int>> A(n, vector<int> (m));
    for(auto &a: A)
        for(auto &b: a)
            cin >> b;

    vector<vector<int>> vis(n, vector<int> (m));
        
    int currScore = A[sx][sy];

    priority_queue<t3> pq;
    pq.push(t3{0,sx,sy});
    vis[sx][sy] = 1;
    while(!pq.empty()) {
        auto [score,i,j] = pq.top();
        pq.pop();

        score *= -1;
        int lim = (currScore + x-1) / x;
        // debug(i,j);
        // debug(score,lim);
        if(score >= lim)
            break;

        currScore += score;
        // debug(currScore);
        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(x < 0 or x >= n or y < 0 or y >= m or vis[x][y])
                continue;
            
            vis[x][y] = 1;
            pq.push(t3{-A[x][y],x,y});
        }
    }

    cout << currScore;
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
