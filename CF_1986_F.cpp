#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> adj(n);
        while(m--){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll timer = 0;
        vi tin(n,-1), low(n,-1), size(n,1);
        vector<bool> vis(n,false);
        ll res = n*(n-1)/2;
        auto dfs = [&] (auto &&self, ll u, ll p) -> void{
            tin[u] = low[u] = timer++;
            vis[u] = true;
            for(auto v : adj[u]){
                if(v==p) continue;
                if(vis[v]){
                    low[u] = min(low[u],tin[v]);
                }else{
                    self(self, v, u);
                    size[u] += size[v];
                    low[u] = min(low[u],low[v]);
                    if(tin[u]<low[v]){
                        ll size1 = size[v];
                        ll temp = n-size1;
                        res = min(res, (size1*(size1-1))/2 + (temp*(temp-1))/2);
                    }
                }
            }
        };

        dfs(dfs,0,-1);

        cout << res << "\n";
    }
}