#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
/*
1 2 3 4 5 6 7

*/
struct Node {
    int value;
    struct Node * next;
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

void solve() {
    int n;
    cin >> n;

    struct Node * head = new Node(1);
    struct Node * temp = head, * prev, * curr;
    
    for(int i = 2; i <= n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head;

    prev = head;
    curr = prev->next;

    while(prev != curr) {
       cout << curr->value << " ";
       // delete curr
       prev->next = curr->next;

       delete(curr);

       prev = prev->next;
       curr = prev->next; 
    }
    cout << prev->value;
    delete(prev);
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