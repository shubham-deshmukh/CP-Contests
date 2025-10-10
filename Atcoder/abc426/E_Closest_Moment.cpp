#include <bits/stdc++.h>

using namespace std;

// #ifndef ONLINE_JUDGE
// #include "./debug.h"
// #else
// #define debug(x...)
// #endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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
- two person, 2-D plane
- start and end points for each person 

- both started from start and moves toward end with
speed of 1. stops when reach to end points
- depart at the same time, may not stop at the same time

- walk straight -> relative motion

Obj
===
- shortest distance between them at any moment

- distance : Euclidean distance

task:
1. How to move toward goal?
straing line


Obs:

*/
using ftype = long double;

struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};
point2d operator*(ftype a, point2d b) {
    return b * a;
}
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
ftype norm(point2d a) {
    return dot(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
using ld = long double;
void print(point2d &P) {
    cout << "{x,y} : " << "{ ";
    cout << P.x << " , " << P.y;
    cout << " }\n";
}

void solve() {
    // T0----T1
    // A0----A1
    vector<point2d> T(2), A(2);
    for(int i = 0; i < 2; i++) cin >> T[i].x >> T[i].y;
    for(int i = 0; i < 2; i++) cin >> A[i].x >> A[i].y;

    // magnitude of vector T[0]-->T[1]
    ld t1 = abs(T[1]-T[0]);
    // magnitude of vector A[0]-->A[1]
    ld t2 = abs(A[1]-A[0]);

    // 0...t1..t2 (timeframe)
    // where t2 >= t1
    if(t1 > t2) swap(t1,t2);

    // get point on line segment V at distance of x
    auto get_point = [&](vector<point2d> &V, ld x)->point2d {
        ld mag = abs(V[1]-V[0]);
        if(mag < x) { // point is outside of line seg
            return V[1];
        }

        point2d unit_vector = (V[1]-V[0]) / mag;
        point2d p = V[0] + x * unit_vector;
        return p;
    };

    auto f = [&](ld t)->ld {
        // point at distance of t on line segment T
        point2d p1 = get_point(T,t);
        // point at distance of t on line segment A
        point2d p2 = get_point(A,t);
        
        // distance between p1 an p2
        return abs(p1-p2);
    };

    // time at which both are at shortest distance
    auto calc = [&](ld l, ld r)->ld {  
        for(int it = 0; it < 50; it++) {
            ld mid1 = l + (r-l) / 3.0;
            ld mid2 = r - (r-l) / 3.0;

            if(f(mid1) > f(mid2)) l = mid1;
            else r = mid2;
        }
        return f(l);
    };

    ld min_dist = min(calc(0,t1),calc(t1,t2));
    cout << fixed << setprecision(20);
    cout << min_dist << "\n";
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
