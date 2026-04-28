#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
void dfs(ll u, ll &size, vector<vector<ll>>&adj, vector<bool>&vis){
    vis[u] = true;
    size++;
    for(auto a : adj[u]){
        if(!vis[a]) dfs(a,size,adj,vis);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n,false);
    ll u; cin >> u; u--;
    if(adj[u].size()==1){
        ll size = 0;
        dfs(u,size,adj,vis);
        if(size%2==0){
            cout << "Ron" << "\n";
        }else{
            cout << "Hermione" << "\n";
        }
    }else{
        ll a = adj[u][0], b = adj[u][1];
        vis[u] = true;
        ll size1 = 0, size2 = 0;
        dfs(a,size1,adj,vis);
        dfs(b,size2,adj,vis);
        if(size1%2==1 || size2%2==1){
            cout << "Ron" << "\n";
        }else{
            cout << "Hermione" << "\n";
        }
    }
}