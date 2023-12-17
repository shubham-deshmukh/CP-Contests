#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define lld long double
#define ull unsigned long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(i = start; start < end ? i < end : i > end; start < end ? i += 1 : i -= 1)
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

inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define int int64_t

struct Assistant {
    int t, z, y;
};


void solve() {
    int M, N; // M : balloons, N : assistant
    cin >> M >> N;

    vector<Assistant> A(N);
    for(int i = 0; i < N; i++)  {
        cin >> A[i].t >> A[i].z >> A[i].y;
    }

    auto getBalloons = [&](const Assistant &a, int t)->int {
        int balloons = 0;

        int timeFrame = a.t * a.z + a.y;
        int remTime = t % timeFrame;
        balloons += a.z * (t / timeFrame) + min(remTime / a.t, a.z);

        return balloons;
    };

    auto isInflate = [&](const int t)->bool {

        int totalballoons = 0;    

        for(const Assistant a: A) {
            totalballoons += getBalloons(a, t);
        }

        return (totalballoons >= M);
    };

    int left = -1;
    int right = 2e9+1;
    while(!isInflate(right)) {
        right <<= 1;
    }

    while(right - left > 1) {

        int mid = left + (right - left) / 2;

        if(isInflate(mid)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << right << endl;
    
    int remBalloons = M;
    for(const auto &a : A) {
        int balloons = getBalloons(a, right);
        int inflatedBalloons = min(remBalloons, balloons);
        cout << inflatedBalloons << " ";
        remBalloons -= inflatedBalloons;
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
    
    ll t = 1;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}

