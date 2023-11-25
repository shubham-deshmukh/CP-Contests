#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
struct Task {
    int duration, deadline;
};

void solve() {
    int n;
    cin >> n;

    vector<Task> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].duration >> a[i].deadline;
    }

    // sort based on duration
    sort(a.begin(), a.end(), [&](const Task &a, const Task &b) {
        if(a.duration != b.duration)
            return a.duration < b.duration;
        return a.deadline > b.deadline;
    });

    long long reward = 0;
    long long finish_time = 0;
    for(auto &t: a) {
        finish_time += t.duration;
        reward += t.deadline - finish_time;
    }

    cout << reward;
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