#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> movies;
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        movies.push_back({start,end});
    }

    sort(movies.begin(), movies.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        }
    );

    int cnt = 0;
    int prev_end = 0;

    for(int i = 0; i < n; i++) {
        if(prev_end <= movies[i].first) {
            cnt++;
            prev_end = movies[i].second;
        }
    }
    cout << cnt;

}

int main() {
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