#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    if(n!=m){
        cout << "NO" << "\n";
        return 0;
    }
    vector<vector<ll>> adj(n);
    for(ll i=0; i<m; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found = false;
    vector<bool> vis(n,false);
    auto dfs = [&](auto &&self, ll u, ll p)->void{
        for(auto v : adj[u]){
            if(v==p) continue;
            if(vis[v]){
                found = true;
                continue;
            }
            vis[v] = true;
            self(self,v,u);
        }
    };
    dfs(dfs,0,-1);
    for(ll i=1; i<n; i++) if(!vis[i]) found = false;


    cout << (found ? "FHTAGN!" : "NO");
}
