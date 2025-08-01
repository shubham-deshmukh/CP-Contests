#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.h"
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

template<typename T>
struct segtree {
	int size;
	vector<T> tree;

	T IDENTITY_ELEMENT = 0;

	T op(T a, T b) {
		return a+b;
	}

    segtree (int n, vector<T> &a) {
        init(n);
        build(a);
    }

	void init(int n) {
		size = 1;
		while(size < n) 
			size *= 2;
		tree.resize(2*size);
	}

	void build(vector<T> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size()) {
                tree[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x+1,lx,m);
		build(a, 2*x+2,m,rx);
		tree[x] = op(tree[2*x+1], tree[2*x+2]);
	}

	void build(vector<T> &a) {
		build(a, 0, 0, size);
	}

	void set(int i, T v, int x, int lx, int rx) {
		if(rx - lx == 1) {
            tree[x] = v;
			return;
		}

		int m = (lx + rx) / 2;
		if(i < m) {
			set(i, v, 2*x+1, lx, m);
		}
		else {
			set(i, v, 2*x+2, m, rx);
		}
		tree[x] = op(tree[2*x+1], tree[2*x+2]);
	}

    // pos : 0-based indexing
	void set(int pos, T v) {
		set(pos, v, 0, 0, size);
	}

	T query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return IDENTITY_ELEMENT;
		if(lx >= l && rx <= r) return tree[x];

		int m = (rx + lx) / 2;
		T s1 = query(l, r, 2*x+1, lx, m);
		T s2 = query(l, r, 2*x+2, m, rx);

		return op(s1, s2);
	}

    // [l,r) : l is included and r is excluded
	T query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

int getInversion(vector<int> A) {
    // get current inversion
	for(auto &a: A) a -= 1;
	int n = (int)A.size();
	vector<int> D(n,0);
    segtree<int> st(n,D);
    vector<int> curr(n);
	int ans = 0;
    for(int i = 0; i < n; i++) {
        curr[i] = st.query(A[i],n);
		ans += curr[i];
        st.set(A[i],1);
    }
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);

	for(auto &a: A) 
		cin >> a;

	int best = n;
	vector<int> B = A;
	auto f = [&](const auto &self, int i)->void {
		if(i == n) {
			// for(auto &b: B) cout << b << " "; cout << endl;
			// cout << "inv: " << getInversion(B) << endl;
			best = min(best,getInversion(B));
			return;
		}

		self(self,i+1);
		int org = B[i];
		B[i] = 2*n-B[i];
		self(self,i+1);
		B[i] = org;
	};
	f(f,0);
	cout << best;
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
        // freopen("../input.txt", "r", stdin);
        // freopen("../output.txt", "w", stdout);
        // freopen("../error.txt", "w", stderr);
    // #endif
    
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
