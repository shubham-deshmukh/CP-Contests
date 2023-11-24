#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
struct Customer {
    int id, start, end;
};
void solve() {
    int n;
    cin >> n;
    vector<Customer> a(n);
    vector<int> room(n,0);
    for(int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].end;
        a[i].id = i;
    }

    sort(a.begin(), a.end(), [&](const auto &a, const auto &b){
        return a.start < b.start;
    });

    // check the sorted customers
    // for(int i = 0; i < n; i++) {
    //     cout << a[i].start << " " << a[i].end << endl;
    // }

    int room_number = 1;
    set<pair<int,int>> available_rooms;
    // 1st customer got the 1st room;
    room[a[0].id] = room_number;
    
    available_rooms.insert({a[0].end,a[0].id});

    // room allocation for incoming customers
    for(int i = 1; i < n; i++) {
        auto it = available_rooms.lower_bound({a[i].start,-1});

        if(it == available_rooms.begin()) {
            // allocate new room
            room_number++;
            room[a[i].id] = room_number;
            available_rooms.insert({a[i].end, a[i].id}); 
        }
        else {
            // allocate available room
            it--;
            room[a[i].id] = room[it->second];
            available_rooms.erase(it);
            available_rooms.insert({a[i].end, a[i].id});
        }
    }
    cout << room_number << endl;
    for(auto d: room) cout << d << " ";




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