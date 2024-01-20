#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

#define int int64_t
void solve() {
        using ll = long long;
        int n;
        cin>>n;

        vector<ll> a(n);
        for (ll i=0;i<n;i++){
            cin>>a[i];
        }

        if (n<3){
            cout<<0<<endl;
            return;
        }        
        // sort(a.begin(),a.end());
        map<ll,ll> mp;
        for (ll i=0;i<n;i++){
            mp[a[i]]++;
        }
        ll count = 0;
        ll small = 0;
        for (auto i:mp){
            ll a = i.second;
            if (a>=3){
                count += (ll)(a*(a-1))*(a-2)/6;
            }
            if (a>=2){
                count += (ll)(a*(a-1))*(small)/2;
            }
            small+=a;
        }
        cout<<count<<endl;
}

void solve1() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    map<int,int> freq;
    for(auto a: A)
        freq[a]++;
    
    int cnt = 0;
    int seq = 0;
    for(auto [_,v]: freq) {
        cnt += v * (v-1) * (v-2) / 6;

        cnt += seq * v * (v-1) / 2;
        seq += v;
    }

    cout << cnt;
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
