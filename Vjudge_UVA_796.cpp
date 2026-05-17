#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
vector<int> art;

void dfs(int u, int p = -1){
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for(auto v : adj[u]){
        if(v == p) continue;
        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && p != -1){
                art.push_back(u);
            }
            children++;
        }
    }
    if(p == -1 && children > 1){
        art.push_back(u);
    }
}
// void dfs(...){
//     vis[u] = true;
//     tin[u] = low[u] = timer++;
//     for(auto v : adj[u]){
//         if(v==p) continue;
//         if(vis[v]){
//             low[u] = min(low[u],tin[v]);
//         }else{
//             dfs(v,u,vis,tin,low,timer,adj,res);
//             low[u] = min(low[u],low[v]);
//             if(low[v]>tin[u]) res.push_back({min(u,v),max(v,u)});
//         }
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; 
    while(cin >> n){
        vector<vector<ll>> adj(n);
        for(ll j=0; j<n; j++){
            ll a,m; char c1,c2; cin >> a >> c1 >> m >> c2;
            for(ll i=0; i<m; i++){
                ll v; cin >> v;
                adj[a].push_back(v);
            }
        }

        ll timer = 0;
        vi tin(n,-1), low(n,-1);
        vector<bool> vis(n,false);
        vector<vector<ll>> res;

        auto dfs = [&](auto &&self, ll u, ll p) -> void {
            vis[u] = true;
            tin[u] = low[u] = timer++;
            for(auto v : adj[u]){
                if(v==p) continue;
                if(vis[v]){
                    low[u] = min(low[u],tin[v]);
                }else{
                    self(self,v,u);
                    low[u] = min(low[u],low[v]);
                    if(low[v]>tin[u]) res.push_back({min(u,v),max(v,u)});
                }
            }
        };

        for(ll i=0; i<n; i++){
            if(!vis[i]) dfs(dfs,i,-1);
        }
        sort(res.begin(),res.end());
        cout << res.size() << " critical links" << "\n";
        for(ll i=0; i<res.size(); i++){
            cout << res[i][0] << " - " << res[i][1] << "\n";
        }
        cout << "\n";
    }
}