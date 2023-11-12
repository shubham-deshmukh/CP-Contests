#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;


struct Edge {
    int u,v, weight;
};

class DisjointSetUnion {
    vector<long long> parent, rank, size;
public:
    DisjointSetUnion(long long n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(long long i = 0; i <=n; i++) {
            make_set(i);
        }

    }
    void make_set(long long v) {
        parent[v] = v;
        size[v] = 1;
        rank[v] = 0;
    }

    long long find_set(long long v) {
        if(parent[v] == v) 
            return v;
        return parent[v] = find_set(parent[v]);
    }

    long long get_size(long long v) {
        v = find_set(v);
        return size[v];
    }
    
    void union_set_by_size(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    void union_set_by_rank(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }    
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.weight < b.weight;
    });
    
    // for(auto e: edges) {
    //     cout << e.u << " " << e.v << " " << e.weight << endl;
    // }

    DisjointSetUnion dsu(n);
    long long cost = 0;
    vector<Edge> mst;
    for(Edge e: edges) {
        if(dsu.find_set(e.u) != dsu.find_set(e.v)) {
            dsu.union_set_by_rank(e.u,e.v);
            cost += e.weight;
            mst.push_back(e);
        }
    }

    if((int)mst.size() != n-1) {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << cost;
    
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