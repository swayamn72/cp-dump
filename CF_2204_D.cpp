#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
bool bfs(ll node, vector<vector<ll>> &adj, vector<bool> &vis){
    
    q.push(node);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> adj(n);
        while(m--){
            ll u,v; cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        for(auto a : adj){
            for(auto b : a) cout << b << " ";
            cout << "\n";
        } 
        vector<bool> vis(n,false);

    }
}
// 1 - 3,4
// 2 - 3,4
// 3 - 1,2
// 4 - 1,2
// 5 - 6,8
// 6 - 5,7,8
// 7 - 6,8
// 8 - 5,6,7
